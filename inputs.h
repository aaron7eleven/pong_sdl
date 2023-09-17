#pragma once
#include <SDL.h>

struct inputs {
	SDL_Event e;
	const Uint8* keyStates;

	bool uiSelected = false;
	bool uiBack = false;

	SDL_Keycode uiPrimaryMoveUp = SDLK_w;
	SDL_Keycode uiPrimaryMoveDown = SDLK_s;
	SDL_Keycode uiPrimaryMoveRight = SDLK_d;
	SDL_Keycode uiPrimaryMoveLeft = SDLK_a;
	SDL_Keycode uiPrimarySelect = SDLK_RETURN;
	SDL_Keycode uiPrimaryBack = SDLK_ESCAPE;


};