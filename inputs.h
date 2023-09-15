#pragma once
#include <SDL.h>

struct inputs {
	SDL_Event e;
	const Uint8* keyStates;
};