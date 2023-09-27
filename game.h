#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include "gameState.h"
#include "appSettings.h"
#include "mainMenu.h"
#include "optionsMenu.h"
#include "controlsMenu.h"
#include "videoMenu.h"
#include "audioMenu.h"
#include "winMenu.h"
#include "gameplay.h"

struct game {
	//app* app;
	bool quit = false;
	appSettings* appSettings;
	bool changeAppSettings = false;

	gameState gameState = gameState::mainMenu;
	mainMenu mainMenu;
	optionsMenu optionsMenu;
	controlsMenu controlsMenu;
	videoMenu videoMenu;
	audioMenu audioMenu;
	winMenu winMenu;
	gameplay gameplay;
	
};

void init(game* game);
void processInput(inputs* inputs, game* game);
void preUpdate(game* game);
void update(float deltaTime, inputs* inputs, game* game);
void render(SDL_Renderer* renderer, game* game);