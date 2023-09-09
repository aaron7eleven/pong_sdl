#pragma once
#include <SDL.h>
#include "uiText.h"

struct title {
	float width = 320;
	float height = 180;
	float x = 640 - width / 2;
	float y = 45;
	SDL_FRect rect = {
		x,
		y,
		width,
		height
	};

	uiText uiText = {
		"Pong",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		rect,
		white,
		NULL,
		false
	};
};