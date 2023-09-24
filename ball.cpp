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
	// https://en.wikipedia.org/w/index.php?title=Midpoint_circle_algorithm&oldid=889172082#C_example
	SDL_FPoint point = { radius - 1.0f, 0.0f };
	SDL_FPoint diff = { 1.0f, 1.0f };
	float error = diff.x - (radius * 2.0f);

	while (point.x >= point.y) {
		// Draws circle outline
				// Draws circle outline
		// Octant 1 - above +x axis
		SDL_RenderDrawPointF(renderer, center.x + point.x, center.y + point.y);
		// Octant 2 (Mirror of Octant 1) - right +y axis
		SDL_RenderDrawPointF(renderer, center.x + point.y, center.y + point.x);
		// Octant 3 - above -x axis
		SDL_RenderDrawPointF(renderer, center.x - point.x, center.y + point.y);
		// Octant 4 (Mirror of Octant 3) - left +y axis
		SDL_RenderDrawPointF(renderer, center.x - point.y, center.y + point.x);
		// Octant 5 - below -x axis
		SDL_RenderDrawPointF(renderer, center.x - point.x, center.y - point.y);
		// Octant 6 (Mirror of Octant 5) - left -y axis
		SDL_RenderDrawPointF(renderer, center.x - point.y, center.y - point.x);
		// Octant 7 - below +x axis
		SDL_RenderDrawPointF(renderer, center.x + point.x, center.y - point.y);
		// Octant 8 (Mirror of Octant 7) - right -y axis
		SDL_RenderDrawPointF(renderer, center.x + point.y, center.y - point.x);

		if (error <= 0.0f) {
			point.y++;
			error += diff.y;
			diff.y += 2.0f;
		}

		if (error > 0.0f) {
			point.x--;
			diff.x += 2.0f;
			error += diff.x - (radius * 2.0f);
		}
	}
}

void renderFillCircle(SDL_Renderer* renderer, SDL_FPoint center, float radius) {
	// https://en.wikipedia.org/w/index.php?title=Midpoint_circle_algorithm&oldid=889172082#C_example
	SDL_FPoint point = { radius - 1.0f, 0.0f };
	SDL_FPoint diff = { 1.0f, 1.0f };
	float error = diff.x - (radius * 2.0f);
	SDL_FPoint oct1 = { 0.0f };
	SDL_FPoint oct2 = { 0.0f };
	SDL_FPoint oct3 = { 0.0f };
	SDL_FPoint oct4 = { 0.0f };
	SDL_FPoint oct5 = { 0.0f };
	SDL_FPoint oct6 = { 0.0f };
	SDL_FPoint oct7 = { 0.0f };
	SDL_FPoint oct8 = { 0.0f };

	while (point.x >= point.y) {
		// Draws circle outline
		//// Octant 1 - above +x axis
		//SDL_RenderDrawPointF(renderer, center.x + point.x, center.y + point.y);
		//// Octant 2 (Mirror of Octant 1) - right +y axis
		//SDL_RenderDrawPointF(renderer, center.x + point.y, center.y + point.x);
		//// Octant 3 - above -x axis
		//SDL_RenderDrawPointF(renderer, center.x - point.x, center.y + point.y);
		//// Octant 4 (Mirror of Octant 3) - left +y axis
		//SDL_RenderDrawPointF(renderer, center.x - point.y, center.y + point.x);
		//// Octant 5 - below -x axis
		//SDL_RenderDrawPointF(renderer, center.x - point.x, center.y - point.y);
		//// Octant 6 (Mirror of Octant 5) - left -y axis
		//SDL_RenderDrawPointF(renderer, center.x - point.y, center.y - point.x);
		//// Octant 7 - below +x axis
		//SDL_RenderDrawPointF(renderer, center.x + point.x, center.y - point.y);
		//// Octant 8 (Mirror of Octant 7) - right -y axis
		//SDL_RenderDrawPointF(renderer, center.x + point.y, center.y - point.x);

		oct1.x = center.x + point.x;
		oct1.y = center.y + point.y;

		oct2.x = center.x + point.y;
		oct2.y = center.y + point.x;

		oct3.x = center.x - point.x;
		oct3.y = center.y + point.y;

		oct4.x = center.x - point.y;
		oct4.y = center.y + point.x;

		oct5.x = center.x - point.x;
		oct5.y = center.y - point.y;

		oct6.x = center.x - point.y;
		oct6.y = center.y - point.x;

		oct7.x = center.x + point.x;
		oct7.y = center.y - point.y;

		oct8.x = center.x + point.y;
		oct8.y = center.y - point.x;

		// xy axis are using traditional axis orientations. NOT SDL's!!! (y is flipped)
		// Octant 1 - above +x axis
		SDL_RenderDrawPointF(renderer, oct1.x, oct1.y);
		// Octant 2 (Mirror of Octant 1) - right +y axis
		SDL_RenderDrawPointF(renderer, oct2.x, oct2.y);
		// Octant 3 - above -x axis
		SDL_RenderDrawPointF(renderer, oct3.x, oct3.y);
		// Octant 4 (Mirror of Octant 3) - left +y axis
		SDL_RenderDrawPointF(renderer, oct4.x, oct4.y);
		// Octant 5 - below -x axis
		SDL_RenderDrawPointF(renderer, oct5.x, oct5.y);
		// Octant 6 (Mirror of Octant 5) - left -y axis
		SDL_RenderDrawPointF(renderer, oct6.x, oct6.y);
		// Octant 7 - below +x axis
		SDL_RenderDrawPointF(renderer, oct7.x, oct7.y);
		// Octant 8 (Mirror of Octant 7) - right -y axis
		SDL_RenderDrawPointF(renderer, oct8.x, oct8.y);
		
		// To fill circles, draw line between across circle horizonally or vertically
		// Choosing horizontally -> easier to think about and how pixels are actually drawn
		// Need to connect mirror across y-axis from left to right
		// Ex:
		// - Octant 3 to Octant 1 (Non-Mirrored Octants)
		// - Octant 4 to Octant 2 (Mirrored Octants)
		// Could also so a semi circle, portion of circle based on angle or adjustable outline circle
		
		// Draws bottom half of circle (y axis is flip in SDL [0 (or -y) is at top of window, and +y is at the bottom of window])
		//SDL_SetRenderDrawColor(renderer, magenta);
		SDL_RenderDrawLine(renderer, oct3.x, oct3.y, oct1.x, oct1.y);
		SDL_RenderDrawLine(renderer, oct4.x, oct4.y, oct2.x, oct2.y);
		
		// Draws top half
		//SDL_SetRenderDrawColor(renderer, cyan);
		SDL_RenderDrawLine(renderer, oct5.x, oct5.y, oct7.x, oct7.y);
		SDL_RenderDrawLine(renderer, oct6.x, oct6.y, oct8.x, oct8.y);
		//SDL_SetRenderDrawColor(renderer, white);

		if (error <= 0.0f) {
			point.y++;
			error += diff.y;
			diff.y += 2.0f;
		}

		if (error > 0.0f) {
			point.x--;
			diff.x += 2.0f;
			error += diff.x - (radius * 2.0f);
		}
	}
}

void render(SDL_Renderer* renderer, ball* ball) {
	// Draw Ball
	SDL_SetRenderDrawColor(renderer, ball->color);

	//renderCircle(renderer, ball->circleCollider.center, ball->circleCollider.radius);
	renderFillCircle(renderer, ball->circleCollider.center, ball->circleCollider.radius);
	// Debug
	//SDL_FRect debug = {
	//	ball->circleCollider.center.x,
	//	ball->circleCollider.center.y,
	//	ball->circleCollider.radius,
	//	ball->circleCollider.radius
	//};

	//circleColor() // available in SDL_gfx
	//SDL_SetRenderDrawColor(renderer, yellow);
	//SDL_RenderFillRectF(renderer, &debug);
	//SDL_RenderFillRectF(renderer, ball->circleCollider);
	//SDL_RenderFillCircle(renderer, ball.circleCollider.center.x, ball.circleCollider.center.y, ball.circleCollider.radius);

}