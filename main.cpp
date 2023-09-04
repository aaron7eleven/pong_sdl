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
#include "appState.h"

struct uiNavigation {
	int currentIndex = 0;
	int previousIndex = 0;
	uiButton* currentButton;
	uiButton* previousButton;
	uiButton** nav;
	int navLength = 0;
};

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

SDL_Texture* LoadTextTexture(SDL_Renderer* renderer,TTF_Font* font, std::string textureText, SDL_Color textColor) {
	SDL_Texture* outputTexture = NULL;

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str() , textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface (%s)! SDL_TTF Error: %s\n", textureText, TTF_GetError());
	}
	else {
		outputTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (outputTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n",SDL_GetError());
		}
		else {
			// get image dimen
		}
	}

	SDL_FreeSurface(textSurface);

	return outputTexture;
}

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

void HighlightUIButton(uiButton* button) {
	// Turn button white
	// Turn text black
	// Set as highlighted
	button->text->color = button->highlightedTextColor;
	button->color = button->highlightedButtonColor;
	button->highlighted = true;
}

void UnhighlightUIButton(uiButton* button) {
	// Turn button black
	// Turn text white
	// unset as highlighted
	button->text->color = button->idleTextColor;
	button->color = button->idleButtonColor;
	button->highlighted = false;
}

void NextUIButton(uiNavigation* uiNavigation) {
	uiNavigation->previousIndex = uiNavigation->currentIndex;
	if (uiNavigation->currentIndex + 1 >= uiNavigation->navLength) {
		uiNavigation->currentIndex = 0;
	}
	else {
		uiNavigation->currentIndex++;
	}
	uiNavigation->previousButton = uiNavigation->nav[uiNavigation->previousIndex];
	uiNavigation->currentButton = uiNavigation->nav[uiNavigation->currentIndex];
	UnhighlightUIButton(uiNavigation->previousButton);
	HighlightUIButton(uiNavigation->currentButton);
}

void PreviousUIButton(uiNavigation* uiNavigation) {
	uiNavigation->previousIndex = uiNavigation->currentIndex;
	if (uiNavigation->currentIndex - 1 < 0) {
		uiNavigation->currentIndex = uiNavigation->navLength - 1;
	}
	else {
		uiNavigation->currentIndex--;
	}
	uiNavigation->previousButton = uiNavigation->nav[uiNavigation->previousIndex];
	uiNavigation->currentButton = uiNavigation->nav[uiNavigation->currentIndex];
	UnhighlightUIButton(uiNavigation->previousButton);
	HighlightUIButton(uiNavigation->currentButton);
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
	//int idCount = 0;
	
	//const int app.screenWidth = 1280;
	//const int app.screenHeight = 720;
	//const int SCREEN_FPS = 60;
	//const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS; // 1000 ms / X frames
	app app;

	//uiButton playButton;
	//initPlayButton(&playButton, &app);
	//


	//uiNavigation uiNavigation;
	//uiNavigation.navLength = 3;
	////uiButton* mainMenuButtons[3] = { &playButton, &optionsButton, &quitButton };
	//uiButton* mainMenuButtons[1] = { &playButton};
	//uiNavigation.nav = mainMenuButtons;
	//uiNavigation.currentIndex = 0;
	//uiNavigation.currentButton = uiNavigation.nav[uiNavigation.currentIndex];
	//uiNavigation.previousIndex = 0;
	//uiNavigation.previousButton = uiNavigation.nav[uiNavigation.previousIndex];
	//HighlightUIButton(uiNavigation.currentButton);


	//const int MIDLINE_LINE_LENGTH = 32;
	//const int MIDLINE_LINE_THICKNESS = 20;
	//const int MIDLINE_LINES_COUNT = 10;
	//const int MIDLINE_LINES_TOTAL_COUNT = MIDLINE_LINES_COUNT * MIDLINE_LINE_THICKNESS;
	//line midlines[MIDLINE_LINES_TOTAL_COUNT];

	//for (int line_count = 0; line_count < MIDLINE_LINES_COUNT; line_count++)
	//{
	//	for (int line_thickness = 0; line_thickness < MIDLINE_LINE_THICKNESS; line_thickness++)
	//	{
	//		line line = {
	//			{app.screenWidth / 2 + line_thickness - (MIDLINE_LINE_THICKNESS / 2) ,  app.screenHeight / MIDLINE_LINES_COUNT * line_count },
	//			{app.screenWidth / 2 + line_thickness - (MIDLINE_LINE_THICKNESS / 2) ,  app.screenHeight / MIDLINE_LINES_COUNT * line_count + MIDLINE_LINE_LENGTH}
	//		};

	//		midlines[line_count * MIDLINE_LINE_THICKNESS + line_thickness] = line;
	//	}
	//}

	//int leftScore = 0;
	//bool leftScoreChanged = false;
	//int rightScore = 0;
	//bool rightScoreChanged = false;

	if (init(&app)) {
		return 1;
	}

	run(&app);

	free(&app);
	return 0;
}