#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

#include "uiText.h"

void initUIText(uiText* uiText, SDL_FRect rect, std::string text, SDL_Color color) {
	uiText->rect = rect;
	uiText->text = text;
	uiText->color = color;
}

//SDL_Texture* LoadTextTexture(SDL_Renderer* renderer, TTF_Font* font, std::string textureText, SDL_Color textColor) {
//	SDL_Texture* outputTexture = NULL;
//
//	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
//	if (textSurface == NULL)
//	{
//		printf("Unable to render text surface (%s)! SDL_TTF Error: %s\n", textureText, TTF_GetError());
//	}
//	else {
//		outputTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//		if (outputTexture == NULL)
//		{
//			printf("Unable to create texture from %s! SDL Error: %s\n", SDL_GetError());
//		}
//		else {
//			// get image dimen
//		}
//	}
//
//	SDL_FreeSurface(textSurface);
//
//	return outputTexture;
//}