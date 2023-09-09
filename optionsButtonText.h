#pragma once
#include <SDL.h>
#include "uiText.h"

struct optionsButtonText {
	float width = 262.5;
	float height = 90;
	float x = 640 - width / 2;
	float y = 360;
	SDL_FRect rect = {
		x,
		y,
		width,
		height
	};

	uiText uiText = {
		"Options",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		rect,
		white,
		NULL,
		false
	};
};