#pragma once
#include <cmath>
#include <SDL.h>

float distanceSquared(float x1, float y1, float x2, float y2);
float magnitude(float x1, float y1, float x2, float y2);
SDL_FPoint normalize(SDL_FPoint point);