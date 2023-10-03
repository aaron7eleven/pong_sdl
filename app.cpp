#pragma once
#include <cstdlib>
#include <sstream>
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "SDL_wrappers.h"
#include "app.h"
#include "game.h"
#include "ui.h"
int appMain(int argc, char* argv[]) {
	app app;
	appSettings appSettings;
	app.appSettings = &appSettings;

	while(!app.quit) {
		if (init(&app)) {
			return 1;
		}

		run(&app);
		free(&app);

		if (app.restart) {
			app.quit = false;
		}
	}

	
	return 0;
}

int init(app* app) {
	if (!app->initialize) {
		// https://www.gamedev.net/forums/topic/336190-possible-to-call-sdl_init-more-than-once/3187085/
		if (SDL_Init(SDL_INIT_EVERYTHING))
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			return 1;
		}
	}	

	//Create window
	Uint32 windowFlags = SDL_WINDOW_SHOWN;
	windowFlags = app->appSettings->fullscreen ? windowFlags | SDL_WINDOW_FULLSCREEN : windowFlags;
	app->window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, app->appSettings->screenWidth, app->appSettings->screenHeight, windowFlags);
	if (app->window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	// Create Renderer
	Uint32 renderFlags = SDL_RENDERER_ACCELERATED;
	renderFlags = app->appSettings->vSync ? renderFlags | SDL_RENDERER_PRESENTVSYNC : renderFlags;
	app->renderer = SDL_CreateRenderer(app->window, -1, renderFlags);
	if (app->renderer == NULL) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return 1;
	}

	//Get window surface
	app->windowSurface = SDL_GetWindowSurface(app->window);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return 1;
	}

	// Load text library
	if (TTF_Init() == -1) {
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return 1;
	}

	//// Load Font
	//app->font = TTF_OpenFont("assets/font/DotGothic16-Regular.ttf", app->fontPointSize);
	//if (app->font == NULL) {
	//	printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
	//	return 1;
	//}
	
	if (!app->initialize) {
		int mixerFlags = MIX_INIT_MP3 | MIX_INIT_OGG;
		if (!Mix_Init(mixerFlags)) {
			printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
			return 1;
		}

		//Initialize SDL_mixer
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			printf("SDL_Mixer Open Audio could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
			return 1;
		}
	}

	srand((unsigned)time(NULL));

	init(&app->fpsCounter.uiText);
	app->restart = false;
	app->initialize = true;

	return 0;
}

int free(app* app) {
	free(app->game);

	// Quit additional SDL subsystems

	if (app->quit && !app->restart) {
		Mix_Quit();
	}
	//Mix_Quit();
	TTF_Quit();
	IMG_Quit();

	SDL_FreeSurface(app->windowSurface);
	app->windowSurface = NULL;

	SDL_DestroyRenderer(app->renderer);
	app->renderer = NULL;

	SDL_DestroyWindow(app->window);
	app->window = NULL;

	//Quit SDL subsystems
	//SDL_Quit();
	if (app->quit && !app->restart) {
		SDL_Quit();
	}
	return 0;
}

void updateDeltaTime(app* app) {
	app->deltaTime = (SDL_GetTicks() - app->startTicks) / 1000.0f;
	app->startTicks = SDL_GetTicks();
}

void applyFrameDelay(app* app) {
	Uint32 frameTicks = SDL_GetTicks() - app->startTicks;
	if (frameTicks < app->appSettings->ticksPerFrame)
	{
		//Wait remaining time
		SDL_Delay(app->appSettings->ticksPerFrame - frameTicks);
	}
}

void processInput(app* app) {
	app->inputs.uiSelected = false;
	app->inputs.uiBack = false;
	app->inputs.keyStates = SDL_GetKeyboardState(NULL);

	// Event Based Inputs (Handle events on queue)
	while (SDL_PollEvent(&app->inputs.e) != 0)
	{
		//User requests quit
		if (app->inputs.e.type == SDL_QUIT)
		{
			app->quit = true;
		}
		else {
			processInput(&app->inputs, app->game);
			if (app->game->quit) {
				app->quit = true;
			}
			else if (app->game->changeAppSettings) {
				//app->game->changeAppSettings = false; // should get reset when restarted
				app->restart = true;
				app->quit = true;
			}
		}
	}
}


void preUpdate(app* app) {
	preUpdate(app->game);
}

void update(app* app) {

	// https://stackoverflow.com/questions/16605967/set-precision-of-stdto-string-when-converting-floating-point-values
	
	std::ostringstream out;
	out.precision(2);
	//out << std::fixed << 1.0f / (app->deltaTime / 1000.0f);
	//app->fpsCounter.uiText.text = "FPS = " + std::move(out).str();

	app->deltaTimes[app->deltaTimeIndex] = app->deltaTime;
	app->deltaTimeIndex++;
	if (app->deltaTimeIndex > 10) {
		app->deltaTimeIndex = 0;
	}
	float avgDeltaTime = 0.0f;
	for (int i = 0; i < 10; i++) {
		avgDeltaTime += app->deltaTimes[i];
	}
	avgDeltaTime /= 10.0f;

	out << std::fixed << 1.0f / avgDeltaTime;
	app->fpsCounter.uiText.text = "Avg. FPS = " + std::move(out).str();

	update(app->deltaTime, &app->inputs, app->game);
}


void render(app* app) {
	//Clear screen to Black
	SDL_SetRenderDrawColor(app->renderer, black);
	SDL_RenderClear(app->renderer);
	render(app->renderer, app->game);

	render(app->renderer, &app->fpsCounter.uiText);

	SDL_RenderPresent(app->renderer);
}


int run(app* app) {
	// Load all textures
	// Check all the textures (if not NULL)

	game game;
	game.appSettings = app->appSettings;
	app->game = &game;

	init(&game);

	while (!app->quit) {
		updateDeltaTime(app);

		//getInput(app);
		processInput(app);

		preUpdate(app);
		update(app);
		
		render(app);
		
		//applyFrameDelay(app);
		//app->frameCount++;
	}

	return 0;
}

