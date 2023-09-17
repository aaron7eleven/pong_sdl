#pragma once
#include "controlsMenu.h"

void init(controlsMenu* controlsMenu) {
	init(&controlsMenu->title);
	init(&controlsMenu->uiMoveUp);
	init(&controlsMenu->uiMoveDown);
	init(&controlsMenu->uiMoveLeft);
	init(&controlsMenu->uiMoveRight);
	init(&controlsMenu->uiSelect);
	init(&controlsMenu->uiBack);
	//init(&controlsMenu->audioButton);
	//init(&controlsMenu->controlsButton);
	//init(&controlsMenu->uiNavigation);
}


void processInput(inputs* inputs, controlsMenu* controlsMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		// Dynamic Input -> use if's
		if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&controlsMenu->uiNavigation);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&controlsMenu->uiNavigation);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryBack) {
			inputs->uiBack = true;
		}
	}
}

void render(SDL_Renderer* renderer, controlsMenu* controlsMenu) {
	render(renderer, &controlsMenu->title);
	render(renderer, &controlsMenu->uiMoveUp);
	render(renderer, &controlsMenu->uiMoveDown);
	render(renderer, &controlsMenu->uiMoveLeft);
	render(renderer, &controlsMenu->uiMoveRight);
	render(renderer, &controlsMenu->uiSelect);
	render(renderer, &controlsMenu->uiBack);
	
	//render(renderer, &controlsMenu->videoButton);
	//render(renderer, &controlsMenu->audioButton);
	//render(renderer, &controlsMenu->controlsButton);
	//render(renderer, &mainMenu->optionsButton.uiButton);
	//render(renderer, &mainMenu->quitButton.uiButton);
}