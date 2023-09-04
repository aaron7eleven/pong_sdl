#pragma once
#include <SDL.h>
#include <string>

struct uiText {
	std::string name = "uiText";
	int id = 0;
	SDL_FRect rect = {0.0f, 0.0f, 0.0f, 0.0f };
	SDL_Color color = { 0xFF, 0xFF, 0xFF, 0xFF };
	SDL_Texture* texture = NULL;
	std::string text = "Text";
};

void initUIText(uiText* uiText, SDL_FRect rect, std::string text, SDL_Color color);