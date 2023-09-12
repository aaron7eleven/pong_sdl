#pragma once
#include <SDL.h>
//#include "app.h"
#include "uiText.h"
#include "color.h"
#include "title.h"
#include "playButton.h"
#include "optionsButton.h"
#include "quitButton.h"
#include "mainMenuNavigation.h"

struct mainMenu {
	title title;
	//playButtonText playButtonText;
	playButton playButton;
	optionsButton optionsButton;
	quitButton quitButton;
	mainMenuNavigation mainMenuNavigation;

};

void init(mainMenu* mainMenu);
void update(float deltaTime, const Uint8* keyStates, mainMenu* mainMenu);
void render(SDL_Renderer* renderer, mainMenu* mainMenu);