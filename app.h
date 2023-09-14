#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "game.h"
#include "fpsCounter.h"


struct app {
	SDL_Window* window = NULL;
	SDL_Surface* windowSurface = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* texture = NULL;
	TTF_Font* font = NULL;

	Uint32 appStartTime = SDL_GetTicks();
	float deltaTime = 0.0f; // in seconds
	Uint32 startTicks = appStartTime;
	Uint32 lastTicks = 0;
	 

	SDL_Event e;
	const Uint8* keyStates;
	
	bool quit = false;
	bool restart = false;

	int screenWidth = 1280;
	int screenHeight = 720;
	Uint32 fps = 60;
	Uint32 ticksPerFrame = 1000 / fps; // 1000 ms / X frames
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
void getInput(app* app);