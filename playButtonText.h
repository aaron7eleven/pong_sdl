#pragma once
#include <SDL.h>
#include "uiText.h"

struct playButtonText {
	float width = 150;
	float height = 90;
	float x = 640 - width / 2;
	float y = 270;
	SDL_FRect rect = {
		x,
		y,
		width,
		height
	};

	uiText uiText = {
		"Play",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		rect,
		white,
		NULL,
		false
	};
};