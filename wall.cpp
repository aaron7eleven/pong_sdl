#pragma once
#include "app.h"
#include "wall.h"
#include "SDL_wrappers.h"

void render(app* app, wall* wall) {
	SDL_SetRenderDrawColor(app->renderer, wall->color);
	SDL_RenderFillRectF(app->renderer, &wall->rectCollider);
}