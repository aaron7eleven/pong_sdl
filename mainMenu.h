#pragma once
#include <SDL.h>

#include "ui.h"
#include "inputs.h"
#include "SDL_wrappers.h"
#include "appSettings.h"
#include "audioManager.h"

struct mainMenu {
	audioManager* audioManager = NULL;
	appSettings* appSettings = NULL;

	//////////////////////////////
	// Title: Pong
	//////////////////////////////
	float titleWidth = 320;
	float titleHeight = 180;
	float titleX = 640 - titleWidth / 2;
	float titleY = 45;
	SDL_FRect titleRect = {
		titleX,
		titleY,
		titleWidth,
		titleHeight
	};

	uiText title = {
		"Pong",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		titleRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Button: Play
	//////////////////////////////
	// Play Button Text
	float playButtonTextWidth = 150;
	float playButtonTextHeight = 90;
	float playButtonTextX = 640 - playButtonTextWidth / 2;
	float playButtonTextY = 270;
	SDL_FRect playButtonTextRect = {
		playButtonTextX,
		playButtonTextY,
		playButtonTextWidth,
		playButtonTextHeight
	};

	uiText playButtonText = {
		"Play",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		playButtonTextRect,
		white,
		NULL,
		false
	};

	// Play Button Button
	float playButtonWidth = 320;
	float playButtonHeight = 90;
	float playButtonX = 640 - playButtonWidth / 2;
	float playButtonY = 270;
	SDL_FRect playButtonRect = {
		playButtonX,
		playButtonY,
		playButtonWidth,
		playButtonHeight
	};

	uiButton playButton = {
		playButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&playButtonText
	};

	//////////////////////////////
	// Button: Options
	//////////////////////////////
	// Options Button Text
	float optionsButtonTextWidth = 262.5;
	float optionsButtonTextHeight = 90;
	float optionsButtonTextX = 640 - optionsButtonTextWidth / 2;
	float optionsButtonTextY = 360;
	SDL_FRect optionsButtonTextRect = {
		optionsButtonTextX,
		optionsButtonTextY,
		optionsButtonTextWidth,
		optionsButtonTextHeight
	};

	uiText optionsButtonText = {
		"Options",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		optionsButtonTextRect,
		white,
		NULL,
		false
	};

	// Options Button Button
	float optionsButtonWidth = 320;
	float optionsButtonHeight = 90;
	float optionsButtonX = 640 - optionsButtonWidth / 2;
	float optionsButtonY = 360;
	SDL_FRect optionsButtonRect = {
		optionsButtonX,
		optionsButtonY,
		optionsButtonWidth,
		optionsButtonHeight
	};

	uiButton optionsButton = {
		optionsButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&optionsButtonText
	};

	//////////////////////////////
	// Button: Quit
	//////////////////////////////
	// Quit Button Text
	float quitButtonTextWidth = 150;
	float quitButtonTextHeight = 90;
	float quitButtonTextX = 640 - quitButtonTextWidth / 2;
	float quitButtonTextY = 450;
	SDL_FRect quitButtonTextRect = {
		quitButtonTextX,
		quitButtonTextY,
		quitButtonTextWidth,
		quitButtonTextHeight
	};

	uiText quitButtonText = {
		"Quit",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		quitButtonTextRect,
		white,
		NULL,
		false
	};

	// Quit Button Button
	float quitButtonWidth = 320;
	float quitButtonHeight = 90;
	float quitButtonX = 640 - quitButtonWidth / 2;
	float quitButtonY = 450;
	SDL_FRect quitButtonRect = {
		quitButtonX,
		quitButtonY,
		quitButtonWidth,
		quitButtonHeight
	};

	uiButton quitButton = {
		quitButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&quitButtonText
	};


	uiButton* nav[3] = { 
		&playButton, 
		&optionsButton,
		&quitButton
	};
	uiNavigation uiNavigation = {
		0,
		0,
		NULL,
		NULL,
		nav,
		3
	};
};

void init(mainMenu* mainMenu);
void processInput(inputs* inputs, mainMenu* mainMenu);
void update(float deltaTime, inputs* inputs, mainMenu* mainMenu);
void render(SDL_Renderer* renderer, mainMenu* mainMenu);