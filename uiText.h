#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include "color.h"

struct uiText {
	//int id = 0;
	std::string text = "Text";
	TTF_Font* font = NULL;
	std::string fontFilePath = "";
	int fontPointSize = 24;
	SDL_FRect rect = {0.0f, 0.0f, 0.0f, 0.0f };
	SDL_Color color = white;
	
	SDL_Texture* texture = NULL;
	bool changed = false;
	float widthPerChar = 37.5f; // Looks decent for text of all sizes
};


void init(uiText* uiText);
void loadFont(uiText* uiText);

void render(SDL_Renderer* renderer, uiText* uiText);
SDL_Texture* loadTexture(SDL_Renderer* renderer, uiText* uiText);

void setText(uiText* uiText, std::string text);
