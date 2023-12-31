#pragma once
#include "optionsMenu.h"

void init(optionsMenu* optionsMenu) {
	init(&optionsMenu->title);
	init(&optionsMenu->videoButton);
	init(&optionsMenu->audioButton);
	init(&optionsMenu->controlsButton);
	init(&optionsMenu->uiNavigation);
}


void processInput(inputs* inputs, optionsMenu* optionsMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		// Dynamic Input -> use if's
		if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&optionsMenu->uiNavigation);
			play(optionsMenu->audioManager, &optionsMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&optionsMenu->uiNavigation);
			play(optionsMenu->audioManager, &optionsMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
			play(optionsMenu->audioManager, &optionsMenu->audioManager->uiSelect);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryBack) {
			inputs->uiBack = true;
			play(optionsMenu->audioManager, &optionsMenu->audioManager->uiSelect);
		}
	}
}

void render(SDL_Renderer* renderer, optionsMenu* optionsMenu) {
	render(renderer, &optionsMenu->title);
	render(renderer, &optionsMenu->videoButton);
	render(renderer, &optionsMenu->audioButton);
	render(renderer, &optionsMenu->controlsButton);
	//render(renderer, &mainMenu->optionsButton.uiButton);
	//render(renderer, &mainMenu->quitButton.uiButton);
}

void free(optionsMenu* optionsMenu) {
	optionsMenu->audioManager = NULL;
	optionsMenu->appSettings = NULL;
	free(&optionsMenu->title);
	free(&optionsMenu->videoButton);
	free(&optionsMenu->audioButton);
	free(&optionsMenu->controlsButton);
	free(&optionsMenu->uiNavigation);
}