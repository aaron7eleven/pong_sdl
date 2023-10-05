#pragma once
#include <SDL.h>
#include <string>
#include "uiText.h"

struct uiButton {
	SDL_FRect rect = {0.0f};
	SDL_Color color = white;
	SDL_Texture* texture = NULL;	

	SDL_Color idleButtonColor = black;
	SDL_Color idleTextColor = white;

	bool highlighted;
	SDL_Color highlightedButtonColor = white;
	SDL_Color highlightedTextColor = black;

	uiText* text = NULL;
};

void init(uiButton* uiButton);
void render(SDL_Renderer* renderer, uiButton* uiButton);
void free(uiButton* uiButton);
void highlight(uiButton* button);
void unhighlight(uiButton* button);

void centerAlignText(uiButton* button);
void setButtonText(uiButton* button, std::string text);