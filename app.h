#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "game.h"
#include "appSettings.h"
#include "fpsCounter.h"
#include "inputs.h"

struct app {
	SDL_Window* window = NULL;
	SDL_Surface* windowSurface = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* texture = NULL;
	TTF_Font* font = NULL;

	appSettings* appSettings;

	Uint32 appStartTime = SDL_GetTicks();
	float deltaTime = 0.0f; // in seconds
	Uint32 startTicks = appStartTime;
	Uint32 lastTicks = 0;
	 
	inputs inputs;
	
	bool quit = false;
	bool restart = true;

	fpsCounter fpsCounter;
	Uint32 frameCount = 0;
	float deltaTimes[5] = {0.0f,0.0f, 0.0f, 0.0f, 0.0f};
	int deltaTimeIndex = 0;

	game* game;
};

int appMain(int argc, char* argv[]);

int init(app* app);
int run(app* app);
int free(app* app);

void preUpdate(app* app);
void update(app* app);

void render(app* app);

void updateDeltaTime(app* app);
void applyFrameDelay(app* app);
void processInput(app* app);