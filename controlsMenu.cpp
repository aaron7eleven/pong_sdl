#pragma once
#include <iostream>
#include "controlsMenu.h"

void init(controlsMenu* controlsMenu) {
	init(&controlsMenu->title);
	init(&controlsMenu->uiControlsButton);
	init(&controlsMenu->gameplayControlsButton);

	init(&controlsMenu->uiNavigation);
}


void processInput(inputs* inputs, controlsMenu* controlsMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		// Dynamic Input -> use if's
		if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&controlsMenu->uiNavigation);
			play(controlsMenu->audioManager, &controlsMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&controlsMenu->uiNavigation);
			play(controlsMenu->audioManager, &controlsMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
			play(controlsMenu->audioManager, &controlsMenu->audioManager->uiSelect);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryBack) {
			inputs->uiBack = true;
			play(controlsMenu->audioManager, &controlsMenu->audioManager->uiSelect);
		}
	}
}

void update(float deltaTime, inputs* inputs, controlsMenu* controlsMenu)
{
}

void render(SDL_Renderer* renderer, controlsMenu* controlsMenu) {
	render(renderer, &controlsMenu->title);
	render(renderer, &controlsMenu->uiControlsButton);
	render(renderer, &controlsMenu->gameplayControlsButton);
}