#pragma once
#include "uiButton.h"
#include "optionsButtonText.h"

struct optionsButton {
	float width = 320;
	float height = 90;
	float x = 640 - width / 2;
	float y = 360;
	SDL_FRect rect = {
		x,
		y,
		width,
		height
	};

	optionsButtonText optionsbuttonText;

	uiButton uiButton = {
		rect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		& optionsbuttonText.uiText
	};
};