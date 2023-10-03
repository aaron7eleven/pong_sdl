#pragma once
#include <SDL.h>

#include "SDL_wrappers.h"
#include "uiNavigation.h"
#include "inputs.h"
#include "appSettings.h"
#include "audioManager.h"

struct controlsGameplayMenu {

	bool listening = false;
	bool heard = false;
	uiButton* listeningButton = NULL;
	SDL_Keycode listeningKeyCode = NULL;
	SDL_Scancode listeningScanCode; // Paddle Controller input takes in Scancode
	SDL_Keycode* listeningKeyCodeToChange = NULL;


	audioManager* audioManager = NULL;
	appSettings* appSettings = NULL;

	//////////////////////////////
	// Title: Controls
	//////////////////////////////
	float titleWidth = 540;
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
		"Gameplay Controls",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		titleRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Text: UI Move Up
	//////////////////////////////
	float leftPaddleUpWidth = 240;
	float leftPaddleUpHeight = 60;
	float leftPaddleUpX = 480 - leftPaddleUpWidth / 2;
	float leftPaddleUpY = 180;
	SDL_FRect leftPaddleUpRect = {
		leftPaddleUpX,
		leftPaddleUpY,
		leftPaddleUpWidth,
		leftPaddleUpHeight
	};

	uiText leftPaddleUp = {
		"Left Paddle Up",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		leftPaddleUpRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Button 1: UI Move Up
	//////////////////////////////
	float leftPaddleUpButtonTextWidth = 120;
	float leftPaddleUpButtonTextHeight = 60;
	float leftPaddleUpButtonTextX = 800 - leftPaddleUpButtonTextWidth / 2;
	float leftPaddleUpButtonTextY = 180;
	SDL_FRect leftPaddleUpButtonTextRect = {
		leftPaddleUpButtonTextX,
		leftPaddleUpButtonTextY,
		leftPaddleUpButtonTextWidth,
		leftPaddleUpButtonTextHeight
	};

	uiText leftPaddleUpButtonText = {
		"W",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		leftPaddleUpButtonTextRect,
		white,
		NULL,
		false
	};

	float leftPaddleUpButtonWidth = 240;
	float leftPaddleUpButtonHeight = 60;
	float leftPaddleUpButtonX = 800 - leftPaddleUpButtonWidth / 2;
	float leftPaddleUpButtonY = 180;
	SDL_FRect leftPaddleUpButtonRect = {
		leftPaddleUpButtonX,
		leftPaddleUpButtonY,
		leftPaddleUpButtonWidth,
		leftPaddleUpButtonHeight
	};

	uiButton leftPaddleUpButton = {
		leftPaddleUpButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&leftPaddleUpButtonText
	};

	//////////////////////////////
	// Text: UI Move Down
	//////////////////////////////
	float leftPaddleDownWidth = 240;
	float leftPaddleDownHeight = 60;
	float leftPaddleDownX = 480 - leftPaddleDownWidth / 2;
	float leftPaddleDownY = 270;
	SDL_FRect leftPaddleDownRect = {
		leftPaddleDownX,
		leftPaddleDownY,
		leftPaddleDownWidth,
		leftPaddleDownHeight
	};

	uiText leftPaddleDown = {
		"Left Paddle Down",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		leftPaddleDownRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Button 1: UI Move Down
	//////////////////////////////
	float leftPaddleDownButtonTextWidth = 120;
	float leftPaddleDownButtonTextHeight = 60;
	float leftPaddleDownButtonTextX = 800 - leftPaddleDownButtonTextWidth / 2;
	float leftPaddleDownButtonTextY = 270;
	SDL_FRect leftPaddleDownButtonTextRect = {
		leftPaddleDownButtonTextX,
		leftPaddleDownButtonTextY,
		leftPaddleDownButtonTextWidth,
		leftPaddleDownButtonTextHeight
	};

	uiText leftPaddleDownButtonText = {
		"S",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		leftPaddleDownButtonTextRect,
		white,
		NULL,
		false
	};

	float leftPaddleDownButtonWidth = 240;
	float leftPaddleDownButtonHeight = 60;
	float leftPaddleDownButtonX = 800 - leftPaddleDownButtonWidth / 2;
	float leftPaddleDownButtonY = 270;
	SDL_FRect leftPaddleDownButtonRect = {
		leftPaddleDownButtonX,
		leftPaddleDownButtonY,
		leftPaddleDownButtonWidth,
		leftPaddleDownButtonHeight
	};

	uiButton leftPaddleDownButton = {
		leftPaddleDownButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&leftPaddleDownButtonText
	};

	//////////////////////////////
	// Text: UI Move Left
	//////////////////////////////
	float rightPaddleUpWidth = 240;
	float rightPaddleUpHeight = 60;
	float rightPaddleUpX = 480 - rightPaddleUpWidth / 2;
	float rightPaddleUpY = 360;
	SDL_FRect rightPaddleUpRect = {
		rightPaddleUpX,
		rightPaddleUpY,
		rightPaddleUpWidth,
		rightPaddleUpHeight
	};

	uiText rightPaddleUp = {
		"Right Paddle Up",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		rightPaddleUpRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Button 1: UI Move Left
	//////////////////////////////
	float rightPaddleUpButtonTextWidth = 120;
	float rightPaddleUpButtonTextHeight = 60;
	float rightPaddleUpButtonTextX = 800 - rightPaddleUpButtonTextWidth / 2;
	float rightPaddleUpButtonTextY = 360;
	SDL_FRect rightPaddleUpButtonTextRect = {
		rightPaddleUpButtonTextX,
		rightPaddleUpButtonTextY,
		rightPaddleUpButtonTextWidth,
		rightPaddleUpButtonTextHeight
	};

	uiText rightPaddleUpButtonText = {
		"Up",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		rightPaddleUpButtonTextRect,
		white,
		NULL,
		false
	};

	float rightPaddleUpButtonWidth = 240;
	float rightPaddleUpButtonHeight = 60;
	float rightPaddleUpButtonX = 800 - rightPaddleUpButtonWidth / 2;
	float rightPaddleUpButtonY = 360;
	SDL_FRect rightPaddleUpButtonRect = {
		rightPaddleUpButtonX,
		rightPaddleUpButtonY,
		rightPaddleUpButtonWidth,
		rightPaddleUpButtonHeight
	};

	uiButton rightPaddleUpButton = {
		rightPaddleUpButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&rightPaddleUpButtonText
	};

	//////////////////////////////
	// Text: UI Move Right
	//////////////////////////////
	float rightPaddleDownWidth = 240;
	float rightPaddleDownHeight = 60;
	float rightPaddleDownX = 480 - rightPaddleDownWidth / 2;
	float rightPaddleDownY = 450;
	SDL_FRect rightPaddleDownRect = {
		rightPaddleDownX,
		rightPaddleDownY,
		rightPaddleDownWidth,
		rightPaddleDownHeight
	};

	uiText rightPaddleDown = {
		"Right Paddle Down",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		rightPaddleDownRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Button 1: UI Move Right
	//////////////////////////////
	float rightPaddleDownButtonTextWidth = 120;
	float rightPaddleDownButtonTextHeight = 60;
	float rightPaddleDownButtonTextX = 800 - rightPaddleDownButtonTextWidth / 2;
	float rightPaddleDownButtonTextY = 450;
	SDL_FRect rightPaddleDownButtonTextRect = {
		rightPaddleDownButtonTextX,
		rightPaddleDownButtonTextY,
		rightPaddleDownButtonTextWidth,
		rightPaddleDownButtonTextHeight
	};

	uiText rightPaddleDownButtonText = {
		"Down",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		rightPaddleDownButtonTextRect,
		white,
		NULL,
		false
	};

	float rightPaddleDownButtonWidth = 240;
	float rightPaddleDownButtonHeight = 60;
	float rightPaddleDownButtonX = 800 - rightPaddleDownButtonWidth / 2;
	float rightPaddleDownButtonY = 450;
	SDL_FRect rightPaddleDownButtonRect = {
		rightPaddleDownButtonX,
		rightPaddleDownButtonY,
		rightPaddleDownButtonWidth,
		rightPaddleDownButtonHeight
	};

	uiButton rightPaddleDownButton = {
		rightPaddleDownButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&rightPaddleDownButtonText
	};

	//////////////////////////////
	// Menu Navigation
	//////////////////////////////
	uiButton* nav[4] = {
		&leftPaddleUpButton,
		&leftPaddleDownButton,
		&rightPaddleUpButton,
		&rightPaddleDownButton
	};
	uiNavigation uiNavigation = {
		0,
		0,
		NULL,
		NULL,
		nav,
		4
	};
};

void init(controlsGameplayMenu* controlsGameplayMenu);
void processInput(inputs* inputs, controlsGameplayMenu* controlsGameplayMenu);
void update(float deltaTime, inputs* inputs, controlsGameplayMenu* controlsGameplayMenu);
void render(SDL_Renderer* renderer, controlsGameplayMenu* controlsGameplayMenu);
void free(controlsGameplayMenu* controlsGameplayMenu);