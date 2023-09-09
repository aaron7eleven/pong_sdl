#pragma once
#include <SDL.h>
#include "uiText.h"

struct quitButtonText {
	float width = 150;
	float height = 90;
	float x = 640 - width / 2;
	float y = 450;
	SDL_FRect rect = {
		x,
		y,
		width,
		height
	};

	uiText uiText = {
		"Quit",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		rect,
		white,
		NULL,
		false
	};
};