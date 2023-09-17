#pragma once
#include "mainMenu.h"

void init(mainMenu* mainMenu) {
	init(&mainMenu->title.uiText);
	init(&mainMenu->playButton.uiButton);
	init(&mainMenu->optionsButton.uiButton);
	init(&mainMenu->quitButton.uiButton);

	insertIntoNav(&mainMenu->mainMenuNavigation.uiNavigation, &mainMenu->playButton.uiButton, 0);
	insertIntoNav(&mainMenu->mainMenuNavigation.uiNavigation, &mainMenu->optionsButton.uiButton, 1);
	insertIntoNav(&mainMenu->mainMenuNavigation.uiNavigation, &mainMenu->quitButton.uiButton, 2);
	init(&mainMenu->mainMenuNavigation.uiNavigation);
}


void processInput(inputs* inputs, mainMenu* mainMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		// Dynamic Input -> use if's
		if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&mainMenu->mainMenuNavigation.uiNavigation);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&mainMenu->mainMenuNavigation.uiNavigation);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
		}
	}
}

void update(float deltaTime, inputs* inputs, mainMenu* mainMenu) {
}

void render(SDL_Renderer* renderer, mainMenu* mainMenu) {
	render(renderer, &mainMenu->title.uiText);
	render(renderer, &mainMenu->playButton.uiButton);
	render(renderer, &mainMenu->optionsButton.uiButton);
	render(renderer, &mainMenu->quitButton.uiButton);
}