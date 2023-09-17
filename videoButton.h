#pragma once
#include "uiButton.h"
//#include "quitButtonText.h"

struct videoButton {
	float textWidth = 150;
	float textHeight = 90;
	float textX = 640 - textWidth / 2;
	float textY = 270;
	SDL_FRect textRect = {
		textX,
		textY,
		textWidth,
		textHeight
	};

	uiText uiText = {
		"Video",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		textRect,
		white,
		NULL,
		false
	};

	float buttonWidth = 320;
	float buttonHeight = 90;
	float buttonX = 640 - buttonWidth / 2;
	float buttonY = 270;
	SDL_FRect buttonRect = {
		buttonX,
		buttonY,
		buttonWidth,
		buttonHeight
	};

	uiButton uiButton = {
		buttonRect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&uiText
	};
};