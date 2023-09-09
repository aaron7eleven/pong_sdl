#pragma once
#include "mainMenu.h"

void init(mainMenu* mainMenu) {
	init(&mainMenu->title.uiText);
	init(&mainMenu->playButton.uiButton);
	init(&mainMenu->optionsButton.uiButton);
	init(&mainMenu->quitButton.uiButton);
}

void render(SDL_Renderer* renderer, mainMenu* mainMenu) {
	render(renderer, &mainMenu->title.uiText);
	render(renderer, &mainMenu->playButton.uiButton);
	render(renderer, &mainMenu->optionsButton.uiButton);
	render(renderer, &mainMenu->quitButton.uiButton);
}