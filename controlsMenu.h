#pragma once
#include <SDL.h>
#include "color.h"
#include "uiNavigation.h"
#include "inputs.h"

struct controlsMenu {
	//////////////////////////////
	// Title: Controls
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
	// Text: UI Move Up
	//////////////////////////////
	float uiMoveUpWidth = 180;
	float uiMoveUpHeight = 60;
	float uiMoveUpX = 480 - uiMoveUpWidth / 2;
	float uiMoveUpY = 180;
	SDL_FRect uiMoveUpRect = {
		uiMoveUpX,
		uiMoveUpY,
		uiMoveUpWidth,
		uiMoveUpHeight
	};

	uiText uiMoveUp = {
		"UI Move Up",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		uiMoveUpRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Text: UI Move Down
	//////////////////////////////
	float uiMoveDownWidth = 180;
	float uiMoveDownHeight = 60;
	float uiMoveDownX = 480 - uiMoveDownWidth / 2;
	float uiMoveDownY = 270;
	SDL_FRect uiMoveDownRect = {
		uiMoveDownX,
		uiMoveDownY,
		uiMoveDownWidth,
		uiMoveDownHeight
	};

	uiText uiMoveDown = {
		"UI Move Down",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		uiMoveDownRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Text: UI Move Left
	//////////////////////////////
	float uiMoveLeftWidth = 180;
	float uiMoveLeftHeight = 60;
	float uiMoveLeftX = 480 - uiMoveLeftWidth / 2;
	float uiMoveLeftY = 360;
	SDL_FRect uiMoveLeftRect = {
		uiMoveLeftX,
		uiMoveLeftY,
		uiMoveLeftWidth,
		uiMoveLeftHeight
	};

	uiText uiMoveLeft = {
		"UI Move Left",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		uiMoveLeftRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Text: UI Move Right
	//////////////////////////////
	float uiMoveRightWidth = 180;
	float uiMoveRightHeight = 60;
	float uiMoveRightX = 480 - uiMoveRightWidth / 2;
	float uiMoveRightY = 450;
	SDL_FRect uiMoveRightRect = {
		uiMoveRightX,
		uiMoveRightY,
		uiMoveRightWidth,
		uiMoveRightHeight
	};

	uiText uiMoveRight = {
		"UI Move Right",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		uiMoveRightRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Text: UI Select
	//////////////////////////////
	float uiSelectWidth = 180;
	float uiSelectHeight = 60;
	float uiSelectX = 480 - uiSelectWidth / 2;
	float uiSelectY = 540;
	SDL_FRect uiSelectRect = {
		uiSelectX,
		uiSelectY,
		uiSelectWidth,
		uiSelectHeight
	};

	uiText uiSelect = {
		"UI Select",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		uiSelectRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Text: UI Back
	//////////////////////////////
	float uiBackWidth = 180;
	float uiBackHeight = 60;
	float uiBackX = 480 - uiBackWidth / 2;
	float uiBackY = 630;
	SDL_FRect uiBackRect = {
		uiBackX,
		uiBackY,
		uiBackWidth,
		uiBackHeight
	};

	uiText uiBack = {
		"UI Back",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		uiBackRect,
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

void init(controlsMenu* controlsMenu);
void processInput(inputs* inputs, controlsMenu* controlsMenu);
void update(float deltaTime, inputs* inputs, controlsMenu* controlsMenu);
void render(SDL_Renderer* renderer, controlsMenu* controlsMenu);