#pragma once
#include "uiButton.h"
#include "quitButtonText.h"

struct quitButton {
	float width = 320;
	float height = 90;
	float x = 640 - width / 2;
	float y = 450;
	SDL_FRect rect = {
		x,
		y,
		width,
		height
	};

	quitButtonText quitbuttonText;

	uiButton uiButton = {
		rect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&quitbuttonText.uiText
	};
};