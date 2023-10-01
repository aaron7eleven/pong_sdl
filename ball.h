#pragma once
#include <SDL.h>

#include "circleCollider.h"
#include "SDL_wrappers.h"
#include "inputs.h"

struct ball {
	SDL_FPoint transform = { 0.0f, 0.0f };
	SDL_Color color = white;
	circleCollider circleCollider = { transform, 20.0f };
	SDL_FPoint velocity = { 0.5f, 0.5f };
	float speed = 600.0f;

	bool reset = false;
	float resetTimer = 0.0f;
	float timeToReset = 1.0f;
};

void update(float deltaTime, inputs* inputs, ball* ball);
void renderCircle(SDL_Renderer* renderer, SDL_FPoint center, float radius);
void render(SDL_Renderer* renderer, ball* ball);