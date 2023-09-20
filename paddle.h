#pragma once
#include <SDL.h>
//#include "app.h"
//#include "transform.h"
#include "rectCollider.h"
#include "color.h"
#include "paddleController.h"

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

	paddleController paddleController = {
		SDL_SCANCODE_UP,
		false,
		SDL_SCANCODE_DOWN,
		false
	};
};

void render(SDL_Renderer renderer, paddle* paddle)