#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "stdio.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "app.h"

#include "collisions.h"
#include "color.h"
#include "primitives.h"
#include "ui.h"
#include "vectors.h"
#include "paddle.h"
#include "gameUI.h"
#include "gameState.h"



SDL_Surface* LoadSurface(SDL_Surface* window, std::string path) {
	
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* imageSurface = IMG_Load(path.c_str());
	if (imageSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else {
		optimizedSurface = SDL_ConvertSurface(imageSurface, window->format, 0);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
	}

	SDL_FreeSurface(imageSurface);
	
	return optimizedSurface;
}

SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string path) {
	SDL_Texture* outputTexture = NULL;

	SDL_Surface* imageSurface = IMG_Load(path.c_str());
	if (imageSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else {
		outputTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
		if (outputTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
	}

	SDL_FreeSurface(imageSurface);

	return outputTexture;
}

//SDL_Texture* LoadTextTexture(SDL_Renderer* renderer,TTF_Font* font, std::string textureText, SDL_Color textColor) {
//	SDL_Texture* outputTexture = NULL;
//
//	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str() , textColor);
//	if (textSurface == NULL)
//	{
//		printf("Unable to render text surface (%s)! SDL_TTF Error: %s\n", textureText, TTF_GetError());
//	}
//	else {
//		outputTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//		if (outputTexture == NULL)
//		{
//			printf("Unable to create texture from %s! SDL Error: %s\n",SDL_GetError());
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

// SDL_RenderFillCircle.c
// https://gist.github.com/henkman/1b6f4492b82dc76adad1dc110c923baa
void SDL_RenderFillCircle(SDL_Renderer* rend, float x0, float y0, float radius)
{
	// Uses the midpoint circle algorithm to draw a filled circle
	// https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
	int x = radius;
	int y = 0;
	int radiusError = 1 - x;
	while (x >= y) {
		SDL_RenderDrawLine(rend, x + x0, y + y0, -x + x0, y + y0);
		SDL_RenderDrawLine(rend, y + x0, x + y0, -y + x0, x + y0);
		SDL_RenderDrawLine(rend, -x + x0, -y + y0, x + x0, -y + y0);
		SDL_RenderDrawLine(rend, -y + x0, -x + y0, y + x0, -x + y0);
		y++;
		if (radiusError < 0)
			radiusError += 2 * y + 1;
		else {
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
}



//void //AssignId(uiButton* button, int* idCount) {
//	printf("Button %s has id %d\n", button->name.c_str(), button->id);
//	button->id = *idCount;
//	(*idCount)++;
//	//*idCount
//}
//
//void //AssignId(uiText* text, int* idCount) {
//	printf("Text %s has id %i\n", text->name.c_str() , text->id);
//	text->id = *idCount;
//	(*idCount)++;
//}

//void StartGame()

int main(int argc, char* argv[])
{
	return appMain(argc, argv);
}