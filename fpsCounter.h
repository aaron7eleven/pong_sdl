#pragma once
#include <SDL.h>
#include "uiText.h"

struct fpsCounter {
	float width = 600.0f;
	float height = 50.0f;
	float x = 0.0f;
	float y = 0.0f;
	SDL_FRect rect = {
		x,
		y,
		width,
		height
	};

	uiText uiText = {
		"FPS = XXX",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		rect, // {x,y,w,h}
		white,
		NULL,
		false
	};
};