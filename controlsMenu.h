#pragma once
#include <SDL.h>

#include "SDL_wrappers.h"
#include "uiNavigation.h"
#include "inputs.h"
#include "appSettings.h"
#include "audioManager.h"

struct controlsMenu {
	audioManager* audioManager = NULL;
	appSettings* appSettings = NULL;

	//////////////////////////////
	// Title: Options
	//////////////////////////////
	float titleWidth = 320;
	float titleHeight = 120;
	float titleX = 640 - titleWidth / 2;
	float titleY = 45;
	SDL_FRect titleRect = {
		titleX,
		titleY,
		titleWidth,
		titleHeight
	};

	uiText title = {
		"Controls",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		titleRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Button 1: UI Controls
	//////////////////////////////
	float uiControlsTextWidth = 90;
	float uiControlsTextHeight = 90;
	float uiControlsTextX = 640 - uiControlsTextWidth / 2;
	float uiControlsTextY = 270;
	SDL_FRect uiControlsTextRect = {
		uiControlsTextX,
		uiControlsTextY,
		uiControlsTextWidth,
		uiControlsTextHeight
	};

	uiText uiControlsButtonText = {
		"UI",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		uiControlsTextRect,
		white,
		NULL,
		false
	};

	float uiControlsButtonWidth = 320;
	float uiControlsButtonHeight = 90;
	float uiControlsButtonX = 640 - uiControlsButtonWidth / 2;
	float uiControlsButtonY = 270;
	SDL_FRect uiControlsButtonRect = {
		uiControlsButtonX,
		uiControlsButtonY,
		uiControlsButtonWidth,
		uiControlsButtonHeight
	};

	uiButton uiControlsButton = {
		uiControlsButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&uiControlsButtonText
	};

	//////////////////////////////
	// Button 2: Gameplay Controls
	//////////////////////////////
	float gameplayControlsTextWidth = 240;
	float gameplayControlsTextHeight = 90;
	float gameplayControlsTextX = 640 - gameplayControlsTextWidth / 2;
	float gameplayControlsTextY = 360;
	SDL_FRect gameplayControlsTextRect = {
		gameplayControlsTextX,
		gameplayControlsTextY,
		gameplayControlsTextWidth,
		gameplayControlsTextHeight
	};

	uiText gameplayControlsButtonText = {
		"Gameplay",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		gameplayControlsTextRect,
		white,
		NULL,
		false
	};

	float gameplayControlsButtonWidth = 320;
	float gameplayControlsButtonHeight = 90;
	float gameplayControlsButtonX = 640 - gameplayControlsButtonWidth / 2;
	float gameplayControlsButtonY = 360;
	SDL_FRect gameplayControlsButtonRect = {
		gameplayControlsButtonX,
		gameplayControlsButtonY,
		gameplayControlsButtonWidth,
		gameplayControlsButtonHeight
	};

	uiButton gameplayControlsButton = {
		gameplayControlsButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&gameplayControlsButtonText
	};

	//////////////////////////////
	// Menu Navigation
	//////////////////////////////
	uiButton* nav[2] = { &uiControlsButton, &gameplayControlsButton};
	uiNavigation uiNavigation = {
		0,
		0,
		NULL,
		NULL,
		nav,
		2
	};
};

void init(controlsMenu* controlsMenu);
void processInput(inputs* inputs, controlsMenu* controlsMenu);
void update(float deltaTime, inputs* inputs, controlsMenu* controlsMenu);
void render(SDL_Renderer* renderer, controlsMenu* controlsMenu);
void free(controlsMenu* controlsMenu);