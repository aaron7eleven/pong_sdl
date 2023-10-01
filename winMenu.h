#pragma once
#pragma once
#include <SDL.h>

#include "uiText.h"
#include "SDL_wrappers.h"
#include "uiNavigation.h"
#include "inputs.h"
#include "appSettings.h"
#include "audioManager.h"

struct winMenu {
	audioManager* audioManager = NULL;
	appSettings* appSettings = NULL;

	// Outline
	// - Title
	// - Sub Title
	// - Play Again
	// - Main Menu
	
	//////////////////////////////
	// Title: Winning Player
	//////////////////////////////
	float titleWidth = 480;
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
		"Side Player Won!!!",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		titleRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Title: Score
	//////////////////////////////
	float subtitleWidth = 240;
	float subtitleHeight = 90;
	float subtitleX = 640 - subtitleWidth / 2;
	float subtitleY = 165;
	SDL_FRect subtitleRect = {
		subtitleX,
		subtitleY,
		subtitleWidth,
		subtitleHeight
	};

	uiText subtitle = {
		"9 - 9",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		subtitleRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Button 1: Video
	//////////////////////////////
	//videoButton videoButton;
	float playAgainTextWidth = 240;
	float playAgainTextHeight = 90;
	float playAgainTextX = 640 - playAgainTextWidth / 2;
	float playAgainTextY = 270;
	SDL_FRect playAgainTextRect = {
		playAgainTextX,
		playAgainTextY,
		playAgainTextWidth,
		playAgainTextHeight
	};

	uiText playAgainButtonText = {
		"Play Again",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		playAgainTextRect,
		white,
		NULL,
		false
	};

	float playAgainButtonWidth = 320;
	float playAgainButtonHeight = 90;
	float playAgainButtonX = 640 - playAgainButtonWidth / 2;
	float playAgainButtonY = 270;
	SDL_FRect playAgainButtonRect = {
		playAgainButtonX,
		playAgainButtonY,
		playAgainButtonWidth,
		playAgainButtonHeight
	};

	uiButton playAgainButton = {
		playAgainButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&playAgainButtonText
	};

	//////////////////////////////
	// Button 2: Main Menu
	//////////////////////////////
	float mainMenuTextWidth = 240;
	float mainMenuTextHeight = 90;
	float mainMenuTextX = 640 - mainMenuTextWidth / 2;
	float mainMenuTextY = 360;
	SDL_FRect mainMenuTextRect = {
		mainMenuTextX,
		mainMenuTextY,
		mainMenuTextWidth,
		mainMenuTextHeight
	};

	uiText mainMenuButtonText = {
		"Main Menu",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		mainMenuTextRect,
		white,
		NULL,
		false
	};

	float mainMenuButtonWidth = 320;
	float mainMenuButtonHeight = 90;
	float mainMenuButtonX = 640 - mainMenuButtonWidth / 2;
	float mainMenuButtonY = 360;
	SDL_FRect mainMenuButtonRect = {
		mainMenuButtonX,
		mainMenuButtonY,
		mainMenuButtonWidth,
		mainMenuButtonHeight
	};

	uiButton mainMenuButton = {
		mainMenuButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&mainMenuButtonText
	};

	//////////////////////////////
	// Button 3: Quit
	//////////////////////////////
	float quitTextWidth = 180;
	float quitTextHeight = 90;
	float quitTextX = 640 - quitTextWidth / 2;
	float quitTextY = 450;
	SDL_FRect quitTextRect = {
		quitTextX,
		quitTextY,
		quitTextWidth,
		quitTextHeight
	};

	uiText quitButtonText = {
		"Quit",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		quitTextRect,
		white,
		NULL,
		false
	};

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

	//////////////////////////////
	// Menu Navigation
	//////////////////////////////
	uiButton* nav[3] = { &playAgainButton, &mainMenuButton, &quitButton };
	uiNavigation uiNavigation = {
		0,
		0,
		NULL,
		NULL,
		nav,
		3
	};
};

void init(winMenu* winMenu);
void processInput(inputs* inputs, winMenu* winMenu);
void update(float deltaTime, inputs* inputs, winMenu* winMenu);
void render(SDL_Renderer* renderer, winMenu* winMenu);