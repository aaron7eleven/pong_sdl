//#pragma once
 #include <SDL.h>
#include "app.h"
#include "paddle.h"
#include "collisions.h"
#include "SDL_wrappers.h"

void update(app* app, paddle* paddle) {
	// Update based on user input
	if (app->keyStates[paddle->paddleController.up]) {
		paddle->velocity -= 1.0f;
	}

	if (app->keyStates[paddle->paddleController.down]) {
		paddle->velocity += 1.0f;
	}

	// Move
	paddle->rectCollider.y += paddle->velocity * paddle->speed * app->deltaTime;

	if (checkCollision(paddle->rectCollider, app->bottomWall.rectCollider)) {
		// Undo Move
		paddle->rectCollider.y -= paddle->velocity * paddle->speed * app->deltaTime;
	}

	if (checkCollision(paddle->rectCollider, app->topWall.rectCollider)) {
		// Undo Move
		paddle->rectCollider.y -= paddle->velocity * paddle->speed * app->deltaTime;
	}
}

void render(app* app, paddle* paddle) {
	SDL_SetRenderDrawColor(app->renderer, paddle->color);
	SDL_RenderFillRectF(app->renderer, &paddle->rectCollider);
}