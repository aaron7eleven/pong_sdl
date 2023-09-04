#pragma once
#include <SDL.h>
#include "transform.h"
#include "rectCollider.h"
#include "color.h"

struct paddle {
	float width = 20;
	float height = 160;

	float speed = 300;
	float velocity = 0.0f;
	SDL_FPoint transform { 0.0f, 0.0f };

	SDL_FRect rectCollider = {
		transform.x,
		transform.y,
		width,
		height		
	};
	SDL_Color color = white;

	bool upHeld = false;
	bool downHeld = false;
};