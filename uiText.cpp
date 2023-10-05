#pragma once
#include <stdio.h>
#include "uiText.h"
#include "SDL_wrappers.h"


void init(uiText* uiText) {
	loadFont(uiText);
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

SDL_Texture* loadTexture(SDL_Renderer* renderer, uiText* uiText) {
	SDL_Texture* outputTexture = NULL;

	SDL_Surface* textSurface = TTF_RenderText_Solid(uiText->font, uiText->text.c_str(), uiText->color);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface (%s)! SDL_TTF Error: %s\n", uiText->text.c_str(), TTF_GetError());
	}
	else {
		outputTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (outputTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", uiText->text.c_str(), SDL_GetError());
		}
	}

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(uiText->texture);
	uiText->texture = outputTexture;
	return uiText->texture;
}

void loadFont(uiText* uiText) {
	uiText->font = TTF_OpenFont(uiText->fontFilePath.c_str(), uiText->fontPointSize);
	if (uiText->font == NULL) {
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
	}
}

void render(SDL_Renderer* renderer, uiText* uiText) {
	//if (uiText->texture == NULL) {
	//	loadTexture(renderer, uiText);
	//}
	//else if (uiText->changed) {
	//	loadTexture(renderer, uiText);
	//	uiText->changed = false;
	//}

	loadTexture(renderer, uiText);

	SDL_RenderCopyExF(renderer, uiText->texture, NULL, &uiText->rect, 0, NULL, SDL_FLIP_NONE);

	// Debug
	//SDL_SetRenderDrawColor(renderer, magenta);
	//SDL_RenderDrawRectF(renderer, &uiText->rect);
}

void free(uiText* uiText) {
	//if (uiText->texture != NULL) {
	//	SDL_DestroyTexture(uiText->texture);
	//	uiText->texture = NULL;
	//}

	if (uiText->font != NULL) {
		TTF_CloseFont(uiText->font);
		uiText->font = NULL;
	}
}

void setText(uiText* uiText, std::string text) {
	uiText->text = text;
}

void setTextAutoAdjustWidth(uiText* uiText, std::string text) {
	uiText->text = text;
	// single/few characters -> looks streched horzontially
	if ((uiText->rect.w / text.length()) > uiText->maxWidthPerChar) {
		// Fix scale text width down
		uiText->rect.w = text.length() * uiText->maxWidthPerChar;
	}
	// too many characters -> look crunched horzontially
	else if ((uiText->rect.w / text.length()) < uiText->minWidthPerChar) {
		// Fix scale text width up
		uiText->rect.w = text.length() * uiText->minWidthPerChar;
	}
}

