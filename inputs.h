#pragma once
#include <SDL.h>

struct inputs {
	SDL_Event e;
	const Uint8* keyStates;

	bool uiSelected = false;
	bool uiBack = false;

	SDL_KeyCode uiPrimaryMoveUp = SDLK_w;
	SDL_KeyCode uiPrimaryMoveDown = SDLK_s;
	SDL_KeyCode uiPrimaryMoveRight = SDLK_d;
	SDL_KeyCode uiPrimaryMoveLeft = SDLK_a;
	SDL_KeyCode uiPrimarySelect = SDLK_RETURN;
	SDL_KeyCode uiPrimaryBack = SDLK_ESCAPE;


};