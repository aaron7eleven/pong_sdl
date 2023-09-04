#pragma once
#include <SDL.h>
#include "SDL_wrappers.h"
void SDL_SetRenderDrawColor(SDL_Renderer* renderer, SDL_Color color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}
