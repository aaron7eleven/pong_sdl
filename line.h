#pragma once
#include <SDL.h>

struct line {
	SDL_FPoint start = { 0.0f, 1.0f };
	SDL_FPoint end = { 0.0f, 0.0f };
};