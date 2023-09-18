#pragma once
#include <SDL.h>
#include "gameState.h"
#include "mainMenu.h"
#include "optionsMenu.h"
#include "controlsMenu.h"
#include "videoMenu.h"
#include "appSettings.h"

struct game {
	//app* app;
	bool quit = false;
	appSettings* appSettings;
	bool changeAppSettings = false;

	gameState gameState = gameState::videoMenu;
	mainMenu mainMenu;
	optionsMenu optionsMenu;
	controlsMenu controlsMenu;
	videoMenu videoMenu;
};

void init(game* game);
void processInput(inputs* inputs, game* game);
void update(float deltaTime, inputs* inputs, game* game);
void render(SDL_Renderer* renderer, game* game);