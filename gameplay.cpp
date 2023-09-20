#pragma once
#include "gameplay.h"
#include "collisions.h"

void init(gameplay* gameplay) {

}

void processInput(inputs* inputs, gameplay* gameplay) {

}

void update(float deltaTime, inputs* inputs, gameplay* gameplay) {

	// Move
	gameplay->paddle->rectCollider.y += paddle->velocity * paddle->speed * app->deltaTime;

	if (checkCollision(paddle->rectCollider, app->bottomWall.rectCollider)) {
		// Undo Move
		paddle->rectCollider.y -= paddle->velocity * paddle->speed * app->deltaTime;
	}

	if (checkCollision(paddle->rectCollider, app->topWall.rectCollider)) {
		// Undo Move
		paddle->rectCollider.y -= paddle->velocity * paddle->speed * app->deltaTime;
	}
}

void render(SDL_Renderer* renderer, gameplay* gameplay) {

}