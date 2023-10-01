#pragma once
#include <iostream>
#include "controlsUIMenu.h"

void init(controlsUIMenu* controlsUIMenu) {
	init(&controlsUIMenu->title);
	init(&controlsUIMenu->uiMoveUp);
	init(&controlsUIMenu->uiMoveUpButton);
	init(&controlsUIMenu->uiMoveDown);
	init(&controlsUIMenu->uiMoveDownButton);
	//init(&controlsUIMenu->uiMoveLeft);
	//init(&controlsUIMenu->uiMoveLeftButton);
	//init(&controlsUIMenu->uiMoveRight);
	//init(&controlsUIMenu->uiMoveRightButton);
	init(&controlsUIMenu->uiSelect);
	init(&controlsUIMenu->uiSelectButton);
	init(&controlsUIMenu->uiBack);
	init(&controlsUIMenu->uiBackButton);

	init(&controlsUIMenu->uiNavigation);
}


void processInput(inputs* inputs, controlsUIMenu* controlsUIMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		// Dynamic Input -> use if's
		if (controlsUIMenu->listening) {
			controlsUIMenu->listeningKeyCode = inputs->e.key.keysym.sym;
			controlsUIMenu->heard = true;
			play(controlsUIMenu->audioManager, &controlsUIMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&controlsUIMenu->uiNavigation);
			play(controlsUIMenu->audioManager, &controlsUIMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&controlsUIMenu->uiNavigation);
			play(controlsUIMenu->audioManager, &controlsUIMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
			play(controlsUIMenu->audioManager, &controlsUIMenu->audioManager->uiSelect);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryBack) {
			inputs->uiBack = true;
			play(controlsUIMenu->audioManager, &controlsUIMenu->audioManager->uiSelect);
		}
	}
}

void update(float deltaTime, inputs* inputs, controlsUIMenu* controlsUIMenu)
{
	if (!controlsUIMenu->listening) {
		setButtonText(&controlsUIMenu->uiMoveUpButton, SDL_GetKeyName(inputs->uiPrimaryMoveUp));
		setButtonText(&controlsUIMenu->uiMoveDownButton, SDL_GetKeyName(inputs->uiPrimaryMoveDown));
		//setButtonText(&controlsUIMenu->uiMoveLeftButton, SDL_GetKeyName(inputs->uiPrimaryMoveLeft));
		//setButtonText(&controlsUIMenu->uiMoveRightButton, SDL_GetKeyName(inputs->uiPrimaryMoveRight));
		setButtonText(&controlsUIMenu->uiSelectButton, SDL_GetKeyName(inputs->uiPrimarySelect));
		setButtonText(&controlsUIMenu->uiBackButton, SDL_GetKeyName(inputs->uiPrimaryBack));
	}
}

void render(SDL_Renderer* renderer, controlsUIMenu* controlsUIMenu) {
	render(renderer, &controlsUIMenu->title);
	render(renderer, &controlsUIMenu->uiMoveUp);
	render(renderer, &controlsUIMenu->uiMoveUpButton);
	render(renderer, &controlsUIMenu->uiMoveDown);
	render(renderer, &controlsUIMenu->uiMoveDownButton);
	//render(renderer, &controlsUIMenu->uiMoveLeft);
	//render(renderer, &controlsUIMenu->uiMoveLeftButton);
	//render(renderer, &controlsUIMenu->uiMoveRight);
	//render(renderer, &controlsUIMenu->uiMoveRightButton);
	render(renderer, &controlsUIMenu->uiSelect);
	render(renderer, &controlsUIMenu->uiSelectButton);
	render(renderer, &controlsUIMenu->uiBack);
	render(renderer, &controlsUIMenu->uiBackButton);
}