#pragma once
#include <SDL.h>
#include "SDL_wrappers.h"
#include "uiNavigation.h"
#include "inputs.h"
#include "appSettings.h"
#include "audioManager.h"

struct videoMenu {
	audioManager* audioManager = NULL;
	appSettings* appSettings = NULL;

	//////////////////////////////
	// Title: Video
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
		"Video",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		titleRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Text: V-Sync
	//////////////////////////////
	float vSyncWidth = 180;
	float vSyncHeight = 60;
	float vSyncX = 480 - vSyncWidth / 2;
	float vSyncY = 180;
	SDL_FRect vSyncRect = {
		vSyncX,
		vSyncY,
		vSyncWidth,
		vSyncHeight
	};

	uiText vSync = {
		"V-Sync",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		vSyncRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Button 1: V-Sync
	//////////////////////////////
	float vSyncButtonTextWidth = 180;
	float vSyncButtonTextHeight = 60;
	float vSyncButtonTextX = 800 - vSyncButtonTextWidth / 2;
	float vSyncButtonTextY = 180;
	SDL_FRect vSyncButtonTextRect = {
		vSyncButtonTextX,
		vSyncButtonTextY,
		vSyncButtonTextWidth,
		vSyncButtonTextHeight
	};

	uiText vSyncButtonText = {
		"Disabled",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		vSyncButtonTextRect,
		white,
		NULL,
		false
	};

	float vSyncButtonWidth = 240;
	float vSyncButtonHeight = 60;
	float vSyncButtonX = 800 - vSyncButtonWidth / 2;
	float vSyncButtonY = 180;
	SDL_FRect vSyncButtonRect = {
		vSyncButtonX,
		vSyncButtonY,
		vSyncButtonWidth,
		vSyncButtonHeight
	};

	uiButton vSyncButton = {
		vSyncButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&vSyncButtonText
	};

	//////////////////////////////
	// Text: Window Mode
	//////////////////////////////
	float windowModeWidth = 240;
	float windowModeHeight = 60;
	float windowModeX = 480 - windowModeWidth / 2;
	float windowModeY = 270;
	SDL_FRect windowModeRect = {
		windowModeX,
		windowModeY,
		windowModeWidth,
		windowModeHeight
	};

	uiText windowMode = {
		"Window Mode",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		windowModeRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Button 1: Window Mode
	//////////////////////////////
	float windowModeButtonTextWidth = 180;
	float windowModeButtonTextHeight = 60;
	float windowModeButtonTextX = 800 - windowModeButtonTextWidth / 2;
	float windowModeButtonTextY = 270;
	SDL_FRect windowModeButtonTextRect = {
		windowModeButtonTextX,
		windowModeButtonTextY,
		windowModeButtonTextWidth,
		windowModeButtonTextHeight
	};

	uiText windowModeButtonText = {
		"Fullscreen",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		windowModeButtonTextRect,
		white,
		NULL,
		false
	};

	float windowModeButtonWidth = 240;
	float windowModeButtonHeight = 60;
	float windowModeButtonX = 800 - windowModeButtonWidth / 2;
	float windowModeButtonY = 270;
	SDL_FRect windowModeButtonRect = {
		windowModeButtonX,
		windowModeButtonY,
		windowModeButtonWidth,
		windowModeButtonHeight
	};

	uiButton windowModeButton = {
		windowModeButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		& windowModeButtonText
	};

	//////////////////////////////
	// Menu Navigation
	//////////////////////////////
	uiButton* nav[2] = {
		&vSyncButton,
		&windowModeButton
	};
	uiNavigation uiNavigation = {
		0,
		0,
		NULL,
		NULL,
		nav,
		2
	};
};

void init(videoMenu* videoMenu);
void processInput(inputs* inputs, videoMenu* videoMenu);
void update(float deltaTime, inputs* inputs, videoMenu* videoMenu);
void render(SDL_Renderer* renderer, videoMenu* videoMenu);
void free(videoMenu* videoMenu);
