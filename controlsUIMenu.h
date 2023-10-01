#pragma once
#include <SDL.h>

#include "SDL_wrappers.h"
#include "uiNavigation.h"
#include "inputs.h"
#include "appSettings.h"
#include "audioManager.h"

struct controlsUIMenu {

	bool listening = false;
	bool heard = false;
	uiButton* listeningButton = NULL;
	SDL_Keycode listeningKeyCode = NULL;
	SDL_Keycode* listeningKeyCodeToChange = NULL;

	audioManager* audioManager = NULL;
	appSettings* appSettings = NULL;

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
		"UI Controls",
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
	// Button 1: UI Move Up
	//////////////////////////////
	float uiMoveUpButtonTextWidth = 120;
	float uiMoveUpButtonTextHeight = 60;
	float uiMoveUpButtonTextX = 800 - uiMoveUpButtonTextWidth / 2;
	float uiMoveUpButtonTextY = 180;
	SDL_FRect uiMoveUpButtonTextRect = {
		uiMoveUpButtonTextX,
		uiMoveUpButtonTextY,
		uiMoveUpButtonTextWidth,
		uiMoveUpButtonTextHeight
	};

	uiText uiMoveUpButtonText = {
		"W",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		uiMoveUpButtonTextRect,
		white,
		NULL,
		false
	};

	float uiMoveUpButtonWidth = 240;
	float uiMoveUpButtonHeight = 60;
	float uiMoveUpButtonX = 800 - uiMoveUpButtonWidth / 2;
	float uiMoveUpButtonY = 180;
	SDL_FRect uiMoveUpButtonRect = {
		uiMoveUpButtonX,
		uiMoveUpButtonY,
		uiMoveUpButtonWidth,
		uiMoveUpButtonHeight
	};

	uiButton uiMoveUpButton = {
		uiMoveUpButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&uiMoveUpButtonText
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
	// Button 1: UI Move Down
	//////////////////////////////
	float uiMoveDownButtonTextWidth = 120;
	float uiMoveDownButtonTextHeight = 60;
	float uiMoveDownButtonTextX = 800 - uiMoveDownButtonTextWidth / 2;
	float uiMoveDownButtonTextY = 270;
	SDL_FRect uiMoveDownButtonTextRect = {
		uiMoveDownButtonTextX,
		uiMoveDownButtonTextY,
		uiMoveDownButtonTextWidth,
		uiMoveDownButtonTextHeight
	};

	uiText uiMoveDownButtonText = {
		"S",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		uiMoveDownButtonTextRect,
		white,
		NULL,
		false
	};

	float uiMoveDownButtonWidth = 240;
	float uiMoveDownButtonHeight = 60;
	float uiMoveDownButtonX = 800 - uiMoveDownButtonWidth / 2;
	float uiMoveDownButtonY = 270;
	SDL_FRect uiMoveDownButtonRect = {
		uiMoveDownButtonX,
		uiMoveDownButtonY,
		uiMoveDownButtonWidth,
		uiMoveDownButtonHeight
	};

	uiButton uiMoveDownButton = {
		uiMoveDownButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&uiMoveDownButtonText
	};

	////////////////////////////////
	//// Text: UI Move Left
	////////////////////////////////
	//float uiMoveLeftWidth = 180;
	//float uiMoveLeftHeight = 60;
	//float uiMoveLeftX = 480 - uiMoveLeftWidth / 2;
	//float uiMoveLeftY = 360;
	//SDL_FRect uiMoveLeftRect = {
	//	uiMoveLeftX,
	//	uiMoveLeftY,
	//	uiMoveLeftWidth,
	//	uiMoveLeftHeight
	//};

	//uiText uiMoveLeft = {
	//	"UI Move Left",
	//	NULL,
	//	"assets/font/DotGothic16-Regular.ttf",
	//	100,
	//	uiMoveLeftRect,
	//	white,
	//	NULL,
	//	false
	//};

	////////////////////////////////
	//// Button 1: UI Move Left
	////////////////////////////////
	//float uiMoveLeftButtonTextWidth = 120;
	//float uiMoveLeftButtonTextHeight = 60;
	//float uiMoveLeftButtonTextX = 800 - uiMoveLeftButtonTextWidth / 2;
	//float uiMoveLeftButtonTextY = 360;
	//SDL_FRect uiMoveLeftButtonTextRect = {
	//	uiMoveLeftButtonTextX,
	//	uiMoveLeftButtonTextY,
	//	uiMoveLeftButtonTextWidth,
	//	uiMoveLeftButtonTextHeight
	//};

	//uiText uiMoveLeftButtonText = {
	//	"uiMoveLeftKey",
	//	NULL,
	//	"assets/font/DotGothic16-Regular.ttf",
	//	100,
	//	uiMoveLeftButtonTextRect,
	//	white,
	//	NULL,
	//	false
	//};

	//float uiMoveLeftButtonWidth = 240;
	//float uiMoveLeftButtonHeight = 60;
	//float uiMoveLeftButtonX = 800 - uiMoveLeftButtonWidth / 2;
	//float uiMoveLeftButtonY = 360;
	//SDL_FRect uiMoveLeftButtonRect = {
	//	uiMoveLeftButtonX,
	//	uiMoveLeftButtonY,
	//	uiMoveLeftButtonWidth,
	//	uiMoveLeftButtonHeight
	//};

	//uiButton uiMoveLeftButton = {
	//	uiMoveLeftButtonRect,
	//	white,
	//	NULL,
	//	black,
	//	white,
	//	false,
	//	white,
	//	black,
	//	&uiMoveLeftButtonText
	//};

	////////////////////////////////
	//// Text: UI Move Right
	////////////////////////////////
	//float uiMoveRightWidth = 180;
	//float uiMoveRightHeight = 60;
	//float uiMoveRightX = 480 - uiMoveRightWidth / 2;
	//float uiMoveRightY = 450;
	//SDL_FRect uiMoveRightRect = {
	//	uiMoveRightX,
	//	uiMoveRightY,
	//	uiMoveRightWidth,
	//	uiMoveRightHeight
	//};

	//uiText uiMoveRight = {
	//	"UI Move Right",
	//	NULL,
	//	"assets/font/DotGothic16-Regular.ttf",
	//	100,
	//	uiMoveRightRect,
	//	white,
	//	NULL,
	//	false
	//};

	////////////////////////////////
	//// Button 1: UI Move Right
	////////////////////////////////
	//float uiMoveRightButtonTextWidth = 120;
	//float uiMoveRightButtonTextHeight = 60;
	//float uiMoveRightButtonTextX = 800 - uiMoveRightButtonTextWidth / 2;
	//float uiMoveRightButtonTextY = 450;
	//SDL_FRect uiMoveRightButtonTextRect = {
	//	uiMoveRightButtonTextX,
	//	uiMoveRightButtonTextY,
	//	uiMoveRightButtonTextWidth,
	//	uiMoveRightButtonTextHeight
	//};

	//uiText uiMoveRightButtonText = {
	//	"uiMoveRightKey",
	//	NULL,
	//	"assets/font/DotGothic16-Regular.ttf",
	//	100,
	//	uiMoveRightButtonTextRect,
	//	white,
	//	NULL,
	//	false
	//};

	//float uiMoveRightButtonWidth = 240;
	//float uiMoveRightButtonHeight = 60;
	//float uiMoveRightButtonX = 800 - uiMoveRightButtonWidth / 2;
	//float uiMoveRightButtonY = 450;
	//SDL_FRect uiMoveRightButtonRect = {
	//	uiMoveRightButtonX,
	//	uiMoveRightButtonY,
	//	uiMoveRightButtonWidth,
	//	uiMoveRightButtonHeight
	//};

	//uiButton uiMoveRightButton = {
	//	uiMoveRightButtonRect,
	//	white,
	//	NULL,
	//	black,
	//	white,
	//	false,
	//	white,
	//	black,
	//	&uiMoveRightButtonText
	//};

	//////////////////////////////
	// Text: UI Select
	//////////////////////////////
	float uiSelectWidth = 180;
	float uiSelectHeight = 60;
	float uiSelectX = 480 - uiSelectWidth / 2;
	float uiSelectY = 360;
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
	// Button 1: UI Select
	//////////////////////////////
	float uiSelectButtonTextWidth = 120;
	float uiSelectButtonTextHeight = 60;
	float uiSelectButtonTextX = 800 - uiSelectButtonTextWidth / 2;
	float uiSelectButtonTextY = 360;
	SDL_FRect uiSelectButtonTextRect = {
		uiSelectButtonTextX,
		uiSelectButtonTextY,
		uiSelectButtonTextWidth,
		uiSelectButtonTextHeight
	};

	uiText uiSelectButtonText = {
		"Return",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		uiSelectButtonTextRect,
		white,
		NULL,
		false
	};

	float uiSelectButtonWidth = 240;
	float uiSelectButtonHeight = 60;
	float uiSelectButtonX = 800 - uiSelectButtonWidth / 2;
	float uiSelectButtonY = 360;
	SDL_FRect uiSelectButtonRect = {
		uiSelectButtonX,
		uiSelectButtonY,
		uiSelectButtonWidth,
		uiSelectButtonHeight
	};

	uiButton uiSelectButton = {
		uiSelectButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&uiSelectButtonText
	};

	//////////////////////////////
	// Text: UI Back
	//////////////////////////////
	float uiBackWidth = 180;
	float uiBackHeight = 60;
	float uiBackX = 480 - uiBackWidth / 2;
	float uiBackY = 450;
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
	// Button 1: UI Back
	//////////////////////////////
	float uiBackButtonTextWidth = 120;
	float uiBackButtonTextHeight = 60;
	float uiBackButtonTextX = 800 - uiBackButtonTextWidth / 2;
	float uiBackButtonTextY = 450;
	SDL_FRect uiBackButtonTextRect = {
		uiBackButtonTextX,
		uiBackButtonTextY,
		uiBackButtonTextWidth,
		uiBackButtonTextHeight
	};

	uiText uiBackButtonText = {
		"Escape",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		uiBackButtonTextRect,
		white,
		NULL,
		false
	};

	float uiBackButtonWidth = 240;
	float uiBackButtonHeight = 60;
	float uiBackButtonX = 800 - uiBackButtonWidth / 2;
	float uiBackButtonY = 450;
	SDL_FRect uiBackButtonRect = {
		uiBackButtonX,
		uiBackButtonY,
		uiBackButtonWidth,
		uiBackButtonHeight
	};

	uiButton uiBackButton = {
		uiBackButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&uiBackButtonText
	};

	//////////////////////////////
	// Menu Navigation
	//////////////////////////////
	uiButton* nav[4] = {
		&uiMoveUpButton,
		&uiMoveDownButton,
		//&uiMoveLeftButton,
		//&uiMoveRightButton,
		&uiSelectButton,
		&uiBackButton,
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

void init(controlsUIMenu* controlsUIMenu);
void processInput(inputs* inputs, controlsUIMenu* controlsUIMenu);
void update(float deltaTime, inputs* inputs, controlsUIMenu* controlsUIMenu);
void render(SDL_Renderer* renderer, controlsUIMenu* controlsUIMenu);