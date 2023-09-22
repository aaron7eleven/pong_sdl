#pragma once
#include <SDL.h>
#include "SDL_wrappers.h"
#include "ball.h"
#include "collisions.h"
#include "app.h"

void update(float deltaTime, inputs* inputs, ball* ball) {
	if (ball->reset) {
		if (ball->resetTimer >= ball->timeToReset) {
			ball->reset = false; // move next frame
			ball->resetTimer = 0.0f;
		}
		else {
			ball->resetTimer += deltaTime;
		}
	}
	else {
		// Move ball
		ball->circleCollider.center.y += ball->velocity.y * ball->speed * deltaTime; // Moving Y
		ball->circleCollider.center.x += ball->velocity.x * ball->speed * deltaTime; // Moving X
	}
}

void renderCircle(SDL_Renderer* renderer, SDL_FPoint center, float radius) {
	// https://saturncloud.io/blog/midpoint-circle-algorithm-for-filled-circles/#:~:text=The%20midpoint%20circle%20algorithm%20is,midpoint%20between%20two%20adjacent%20points.
	// Decision Parameter (p)
	float p = 1.0f - radius;
	SDL_Point point = { center.x, center.y - radius };

	while (point.x >= point.y) {
		if (p < 0) {
			point.x++;
			p += (2.0f * point.x) + 1.0f;
		}

		if (p >= 0) {
			point.x++;
			point.y++;
			p += (2.0f * point.x) - (2.0f * point.y) + 1.0f;
		}

		SDL_RenderDrawPointF(renderer, point.x, point.y);
	}
}

void render(SDL_Renderer* renderer, ball* ball) {
	// Draw Ball
	SDL_SetRenderDrawColor(renderer, ball->color);

	renderCircle(renderer, ball->circleCollider.center, ball->circleCollider.radius);

	//SDL_RenderFillRectF(renderer, ball->circleCollider);
	//SDL_RenderFillCircle(renderer, ball.circleCollider.center.x, ball.circleCollider.center.y, ball.circleCollider.radius);

}