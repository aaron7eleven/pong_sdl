#pragma once
#include <iostream>
#include "controlsMenu.h"

void init(controlsMenu* controlsMenu) {
	init(&controlsMenu->title);
	init(&controlsMenu->uiMoveUp);
	init(&controlsMenu->uiMoveUpButton);
	init(&controlsMenu->uiMoveDown);
	init(&controlsMenu->uiMoveDownButton);
	init(&controlsMenu->uiMoveLeft);
	init(&controlsMenu->uiMoveLeftButton);
	init(&controlsMenu->uiMoveRight);
	init(&controlsMenu->uiMoveRightButton);
	init(&controlsMenu->uiSelect);
	init(&controlsMenu->uiSelectButton);
	init(&controlsMenu->uiBack);
	init(&controlsMenu->uiBackButton);

	init(&controlsMenu->uiNavigation);
}


void processInput(inputs* inputs, controlsMenu* controlsMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		// Dynamic Input -> use if's
		if (controlsMenu->listening) {
			
			controlsMenu->listeningKeyCode = inputs->e.key.keysym.sym;
			controlsMenu->heard = true;
			play(&controlsMenu->audioManager->uiMove, controlsMenu->appSettings->sfxVolume);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&controlsMenu->uiNavigation);
			play(&controlsMenu->audioManager->uiMove, controlsMenu->appSettings->sfxVolume);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&controlsMenu->uiNavigation);
			play(&controlsMenu->audioManager->uiMove, controlsMenu->appSettings->sfxVolume);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
			play(&controlsMenu->audioManager->uiSelect, controlsMenu->appSettings->sfxVolume);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryBack) {
			inputs->uiBack = true;
			play(&controlsMenu->audioManager->uiSelect, controlsMenu->appSettings->sfxVolume);
		}
	}
}

void update(float deltaTime, inputs* inputs, controlsMenu* controlsMenu)
{
	if (!controlsMenu->listening) {
		setButtonText(&controlsMenu->uiMoveUpButton, SDL_GetKeyName(inputs->uiPrimaryMoveUp));
		setButtonText(&controlsMenu->uiMoveDownButton, SDL_GetKeyName(inputs->uiPrimaryMoveDown));
		setButtonText(&controlsMenu->uiMoveLeftButton, SDL_GetKeyName(inputs->uiPrimaryMoveLeft));
		setButtonText(&controlsMenu->uiMoveRightButton, SDL_GetKeyName(inputs->uiPrimaryMoveRight));
		setButtonText(&controlsMenu->uiSelectButton, SDL_GetKeyName(inputs->uiPrimarySelect));
		setButtonText(&controlsMenu->uiBackButton, SDL_GetKeyName(inputs->uiPrimaryBack));
	}
}

void render(SDL_Renderer* renderer, controlsMenu* controlsMenu) {
	render(renderer, &controlsMenu->title);
	render(renderer, &controlsMenu->uiMoveUp);
	render(renderer, &controlsMenu->uiMoveUpButton);
	render(renderer, &controlsMenu->uiMoveDown);
	render(renderer, &controlsMenu->uiMoveDownButton);
	render(renderer, &controlsMenu->uiMoveLeft);
	render(renderer, &controlsMenu->uiMoveLeftButton);
	render(renderer, &controlsMenu->uiMoveRight);
	render(renderer, &controlsMenu->uiMoveRightButton);
	render(renderer, &controlsMenu->uiSelect);
	render(renderer, &controlsMenu->uiSelectButton);
	render(renderer, &controlsMenu->uiBack);
	render(renderer, &controlsMenu->uiBackButton);
}