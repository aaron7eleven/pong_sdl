#pragma once
#include <SDL.h>

struct paddleController {
	SDL_Scancode up;
	bool upHeld;

	SDL_Scancode down;
	bool downHeld;
};