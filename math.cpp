#pragma once
#include "math.h"

float distanceSquared(float x1, float y1, float x2, float y2) {
	float deltaX = x2 - x1;
	float deltaY = y2 - y1;
	return deltaX * deltaX + deltaY * deltaY;
};

float magnitude(float x1, float y1, float x2, float y2) {
	float squaredDist = distanceSquared(x1, y1, x2, y2);
	return sqrtf(squaredDist);
}

SDL_FPoint normalize(SDL_FPoint point) {
	float pointMagnitude = magnitude(0.0f, 0.0f, point.x, point.y);
	SDL_FPoint pointNorm = { point.x / pointMagnitude, point.y / pointMagnitude };
	return pointNorm;
}