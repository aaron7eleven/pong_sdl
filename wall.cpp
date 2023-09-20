#pragma once
#include "SDL_wrappers.h"
#include "wall.h"

void render(SDL_Renderer* renderer, wall* wall) {
	SDL_SetRenderDrawColor(renderer, wall->color);
	SDL_RenderFillRectF(renderer, &wall->rectCollider);
}