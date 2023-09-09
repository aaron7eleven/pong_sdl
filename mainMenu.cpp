#pragma once
#include "mainMenu.h"

void init(mainMenu* mainMenu) {
	init(&mainMenu->title.uiText);
	init(&mainMenu->playButton.uiButton);
	init(&mainMenu->optionsButtonText);
	init(&mainMenu->quitButtonText);
}

void render(SDL_Renderer* renderer, mainMenu* mainMenu) {
	render(renderer, &mainMenu->title.uiText);
	render(renderer, &mainMenu->playButton.uiButton);
	render(renderer, &mainMenu->optionsButtonText);
	render(renderer, &mainMenu->quitButtonText);
}