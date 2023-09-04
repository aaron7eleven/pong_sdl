#pragma once

#include <SDL.h>
#include "app.h"

struct wall {
	SDL_FRect rectCollider;
	SDL_Color color;
};

void render(app* app, wall* wall);