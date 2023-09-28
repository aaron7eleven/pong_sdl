#pragma once
#include <SDL.h>
#include "color.h"
#include "uiNavigation.h"
#include "inputs.h"

struct audioMenu {
	//////////////////////////////
	// Title: Audio
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
		"Audio",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		titleRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Text: SFX Volume
	//////////////////////////////
	float sfxVolumeWidth = 320;
	float sfxVolumeHeight = 60;
	float sfxVolumeX = 360 - sfxVolumeWidth / 2;
	float sfxVolumeY = 240;
	SDL_FRect sfxVolumeRect = {
		sfxVolumeX,
		sfxVolumeY,
		sfxVolumeWidth,
		sfxVolumeHeight
	};

	uiText sfxVolume = {
		"SFX Volume",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		sfxVolumeRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Button 1: SFX Volume Up
	//////////////////////////////
	float sfxVolumeUpButtonTextWidth = 15;
	float sfxVolumeUpButtonTextHeight = 30;
	float sfxVolumeUpButtonTextX = 720 - sfxVolumeUpButtonTextWidth / 2;
	float sfxVolumeUpButtonTextY = 240;
	SDL_FRect sfxVolumeUpButtonTextRect = {
		sfxVolumeUpButtonTextX,
		sfxVolumeUpButtonTextY,
		sfxVolumeUpButtonTextWidth,
		sfxVolumeUpButtonTextHeight
	};

	uiText sfxVolumeUpButtonText = {
		"+",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		sfxVolumeUpButtonTextRect,
		white,
		NULL,
		false
	};

	float sfxVolumeUpButtonWidth = 180;
	float sfxVolumeUpButtonHeight = 30;
	float sfxVolumeUpButtonX = 720 - sfxVolumeUpButtonWidth / 2;
	float sfxVolumeUpButtonY = 240;
	SDL_FRect sfxVolumeUpButtonRect = {
		sfxVolumeUpButtonX,
		sfxVolumeUpButtonY,
		sfxVolumeUpButtonWidth,
		sfxVolumeUpButtonHeight
	};

	uiButton sfxVolumeUpButton = {
		sfxVolumeUpButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&sfxVolumeUpButtonText
	};


	//////////////////////////////
	// Button 2: SFX Volume Down
	//////////////////////////////
	float sfxVolumeDownButtonTextWidth = 15;
	float sfxVolumeDownButtonTextHeight = 30;
	float sfxVolumeDownButtonTextX = 720 - sfxVolumeDownButtonTextWidth / 2;
	float sfxVolumeDownButtonTextY = 270;
	SDL_FRect sfxVolumeDownButtonTextRect = {
		sfxVolumeDownButtonTextX,
		sfxVolumeDownButtonTextY,
		sfxVolumeDownButtonTextWidth,
		sfxVolumeDownButtonTextHeight
	};

	uiText sfxVolumeDownButtonText = {
		"-",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		sfxVolumeDownButtonTextRect,
		white,
		NULL,
		false
	};

	float sfxVolumeDownButtonWidth = 180;
	float sfxVolumeDownButtonHeight = 30;
	float sfxVolumeDownButtonX = 720 - sfxVolumeDownButtonWidth / 2;
	float sfxVolumeDownButtonY = 270;
	SDL_FRect sfxVolumeDownButtonRect = {
		sfxVolumeDownButtonX,
		sfxVolumeDownButtonY,
		sfxVolumeDownButtonWidth,
		sfxVolumeDownButtonHeight
	};

	uiButton sfxVolumeDownButton = {
		sfxVolumeDownButtonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&sfxVolumeDownButtonText
	};

	//////////////////////////////
	// Text: SFX Volume Value
	//////////////////////////////
	float sfxVolumeValueWidth = 180;
	float sfxVolumeValueHeight = 60;
	float sfxVolumeValueX = 1000 - sfxVolumeValueWidth / 2;
	float sfxVolumeValueY = 240;
	SDL_FRect sfxVolumeValueRect = {
		sfxVolumeValueX,
		sfxVolumeValueY,
		sfxVolumeValueWidth,
		sfxVolumeValueHeight
	};

	uiText sfxVolumeValue = {
		"-.++",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		sfxVolumeValueRect,
		white,
		NULL,
		false
	};

	//////////////////////////////
	// Menu Navigation
	//////////////////////////////
	uiButton* nav[2] = {
		&sfxVolumeUpButton,
		&sfxVolumeDownButton
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

void init(audioMenu* audioMenu);
void processInput(inputs* inputs, audioMenu* audioMenu);
void update(float deltaTime, inputs* inputs, audioMenu* audioMenu);
void render(SDL_Renderer* renderer, audioMenu* audioMenu);