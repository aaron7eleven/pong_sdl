#pragma once
#include <SDL.h>


struct wall {
	SDL_FRect rectCollider;
	SDL_Color color;
};

void render(SDL_Renderer* renderer, wall* wall);