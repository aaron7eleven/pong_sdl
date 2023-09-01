#pragma once
#include <SDL.h>
#include "rectCollider.h"

struct Paddle {
	float width;
	float height;
	float speed;
	float velocity;
	float initX;
	float initY;


	int id;
	rectCollider rectCollider;
	SDL_Color color;
};