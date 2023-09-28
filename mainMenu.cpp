#pragma once
#include "mainMenu.h"

void init(mainMenu* mainMenu) {
	init(&mainMenu->title);
	init(&mainMenu->playButton);
	init(&mainMenu->optionsButton);
	init(&mainMenu->quitButton);

	init(&mainMenu->uiNavigation);	
}


void processInput(inputs* inputs, mainMenu* mainMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		// Dynamic Input -> use if's
		if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&mainMenu->uiNavigation);
			play(&mainMenu->audioManager->uiMove, mainMenu->appSettings->sfxVolume);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&mainMenu->uiNavigation);
			play(&mainMenu->audioManager->uiMove, mainMenu->appSettings->sfxVolume);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
			play(&mainMenu->audioManager->uiSelect, mainMenu->appSettings->sfxVolume);
		}
	}
}

void update(float deltaTime, inputs* inputs, mainMenu* mainMenu) {
}

void render(SDL_Renderer* renderer, mainMenu* mainMenu) {
	render(renderer, &mainMenu->title);
	render(renderer, &mainMenu->playButton);
	render(renderer, &mainMenu->optionsButton);
	render(renderer, &mainMenu->quitButton);
}