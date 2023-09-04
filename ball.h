#pragma once
#include <SDL.h>
#include "app.h"
#include "circleCollider.h"
#include "color.h"

struct ball {
	SDL_FPoint transform = { 0.0f, 0.0f };
	SDL_Color color = white;
	circleCollider circleCollider = { transform, 20.0f };
	SDL_FPoint velocity = { 0.5f, 0.5f };
	float speed = 600.0f;
};

void update(app* app, ball* ball);