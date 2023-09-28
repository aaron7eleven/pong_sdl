#pragma once
#include "winMenu.h"

void init(winMenu* winMenu) {
	init(&winMenu->title);
	init(&winMenu->subtitle);
	init(&winMenu->mainMenuButton);
	init(&winMenu->playAgainButton);
	init(&winMenu->quitButton);
	init(&winMenu->uiNavigation);
}


void processInput(inputs* inputs, winMenu* winMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		// Dynamic Input -> use if's
		if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&winMenu->uiNavigation);
			play(winMenu->audioManager, &winMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&winMenu->uiNavigation);
			play(winMenu->audioManager, &winMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
			play(winMenu->audioManager, &winMenu->audioManager->uiSelect);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryBack) {
			inputs->uiBack = true;
			play(winMenu->audioManager, &winMenu->audioManager->uiSelect);
		}
	}
}

void render(SDL_Renderer* renderer, winMenu* winMenu) {
	render(renderer, &winMenu->title);
	render(renderer, &winMenu->subtitle);
	render(renderer, &winMenu->mainMenuButton);
	render(renderer, &winMenu->playAgainButton);
	render(renderer, &winMenu->quitButton);
	//render(renderer, &mainMenu->optionsButton.uiButton);
	//render(renderer, &mainMenu->quitButton.uiButton);
}