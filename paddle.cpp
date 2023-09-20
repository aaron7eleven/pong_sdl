#pragma once
 #include <SDL.h>
#include "paddle.h"


void processInput(inputs* inputs, paddle* paddle) {
	// Update based on user input
	if (inputs->keyStates[paddle->paddleController.up]) {
		paddle->velocity -= 1.0f;
	}

	if (inputs->keyStates[paddle->paddleController.down]) {
		paddle->velocity += 1.0f;
	}
}

void update(float deltaTime, inputs* inputs, paddle* paddle) {
	// Move
	paddle->rectCollider.y += paddle->velocity * paddle->speed * deltaTime;
}

void render(SDL_Renderer* renderer, paddle* paddle) {
	SDL_SetRenderDrawColor(renderer, paddle->color);
	SDL_RenderFillRectF(renderer, &paddle->rectCollider);
}