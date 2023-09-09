#pragma once
#include "uiButton.h"
#include "playButtonText.h"

struct playButton {
	float width = 320;
	float height = 90;
	float x = 640 - width / 2;
	float y = 270;
	SDL_FRect rect = {
		x,
		y,
		width,
		height
	};

	playButtonText playbuttonText;

	uiButton uiButton = {
		rect,
		white,
		NULL,
		black,
		white,
		false,
		white,
		black,
		&playbuttonText.uiText
	};
	
	

};