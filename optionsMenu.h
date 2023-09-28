#pragma once
#pragma once
#include <SDL.h>

#include "uiText.h"
#include "color.h"
#include "uiNavigation.h"
#include "inputs.h"
#include "appSettings.h"
#include "audioManager.h"

struct optionsMenu {
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
		"Options",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		titleRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Button 1: Video
	//////////////////////////////
	//videoButton videoButton;
	float videoTextWidth = 150;
	float videoTextHeight = 90;
	float videoTextX = 640 - videoTextWidth / 2;
	float videoTextY = 270;
	SDL_FRect videoTextRect = {
		videoTextX,
		videoTextY,
		videoTextWidth,
		videoTextHeight
	};

	uiText videoButtonText = {
		"Video",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		videoTextRect,
		white,
		NULL,
		false
	};

	float videoButtonWidth = 320;
	float videoButtonHeight = 90;
	float videoButtonX = 640 - videoButtonWidth / 2;
	float videoButtonY = 270;
	SDL_FRect videoButtonRect = {
		videoButtonX,
		videoButtonY,
		videoButtonWidth,
		videoButtonHeight
	};

	uiButton videoButton = {
		videoButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&videoButtonText
	};

	//////////////////////////////
	// Button 2: Audio
	//////////////////////////////
	float audioTextWidth = 150;
	float audioTextHeight = 90;
	float audioTextX = 640 - audioTextWidth / 2;
	float audioTextY = 360;
	SDL_FRect audioTextRect = {
		audioTextX,
		audioTextY,
		audioTextWidth,
		audioTextHeight
	};

	uiText audioButtonText = {
		"Audio",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		audioTextRect,
		white,
		NULL,
		false
	};

	float audioButtonWidth = 320;
	float audioButtonHeight = 90;
	float audioButtonX = 640 - audioButtonWidth / 2;
	float audioButtonY = 360;
	SDL_FRect audioButtonRect = {
		audioButtonX,
		audioButtonY,
		audioButtonWidth,
		audioButtonHeight
	};

	uiButton audioButton = {
		audioButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&audioButtonText
	};

	//////////////////////////////
	// Button 3: Controls
	//////////////////////////////
	float controlsTextWidth = 262.5;
	float controlsTextHeight = 90;
	float controlsTextX = 640 - controlsTextWidth / 2;
	float controlsTextY = 450;
	SDL_FRect controlsTextRect = {
		controlsTextX,
		controlsTextY,
		controlsTextWidth,
		controlsTextHeight
	};

	uiText controlsButtonText = {
		"Controls",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		controlsTextRect,
		white,
		NULL,
		false
	};

	float controlsButtonWidth = 320;
	float controlsButtonHeight = 90;
	float controlsButtonX = 640 - controlsButtonWidth / 2;
	float controlsButtonY = 450;
	SDL_FRect controlsButtonRect = {
		controlsButtonX,
		controlsButtonY,
		controlsButtonWidth,
		controlsButtonHeight
	};

	uiButton controlsButton = {
		controlsButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&controlsButtonText
	};

	//////////////////////////////
	// Menu Navigation
	//////////////////////////////
	uiButton* nav[3] = { &videoButton, &audioButton, &controlsButton };
	uiNavigation uiNavigation = {
		0,
		0,
		NULL,
		NULL,
		nav,
		3
	};
};

void init(optionsMenu* optionsMenu);
void processInput(inputs* inputs, optionsMenu* optionsMenu);
void update(float deltaTime, inputs* inputs, optionsMenu* optionsMenu);
void render(SDL_Renderer* renderer, optionsMenu* optionsMenu);