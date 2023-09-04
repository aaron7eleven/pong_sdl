#pragma once
#include <SDL.h>
#include <string>
#include "uiText.h"

struct uiButton {
	std::string name;
	int id;
	SDL_FRect rect;
	SDL_Color color = { 0xFF, 0xFF, 0xFF, 0xFF };
	SDL_Texture* tex;	

	SDL_Color idleButtonColor;
	SDL_Color idleTextColor;

	bool highlighted;
	SDL_Color highlightedButtonColor;
	SDL_Color highlightedTextColor;

	uiText* text = NULL;
};