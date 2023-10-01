#pragma once
#include <iostream>
#include "controlsGameplayMenu.h"

void init(controlsGameplayMenu* controlsGameplayMenu) {
	init(&controlsGameplayMenu->title);
	init(&controlsGameplayMenu->leftPaddleUp);
	init(&controlsGameplayMenu->leftPaddleUpButton);
	init(&controlsGameplayMenu->leftPaddleDown);
	init(&controlsGameplayMenu->leftPaddleDownButton);
	init(&controlsGameplayMenu->rightPaddleUp);
	init(&controlsGameplayMenu->rightPaddleUpButton);
	init(&controlsGameplayMenu->rightPaddleDown);
	init(&controlsGameplayMenu->rightPaddleDownButton);

	init(&controlsGameplayMenu->uiNavigation);
}


void processInput(inputs* inputs, controlsGameplayMenu* controlsGameplayMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		// Dynamic Input -> use if's
		if (controlsGameplayMenu->listening) {
			controlsGameplayMenu->listeningKeyCode = inputs->e.key.keysym.sym;
			controlsGameplayMenu->listeningScanCode = inputs->e.key.keysym.scancode;
			controlsGameplayMenu->heard = true;
			play(controlsGameplayMenu->audioManager, &controlsGameplayMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&controlsGameplayMenu->uiNavigation);
			play(controlsGameplayMenu->audioManager, &controlsGameplayMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&controlsGameplayMenu->uiNavigation);
			play(controlsGameplayMenu->audioManager, &controlsGameplayMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
			play(controlsGameplayMenu->audioManager, &controlsGameplayMenu->audioManager->uiSelect);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryBack) {
			inputs->uiBack = true;
			play(controlsGameplayMenu->audioManager, &controlsGameplayMenu->audioManager->uiSelect);
		}
	}
}

void update(float deltaTime, inputs* inputs, controlsGameplayMenu* controlsGameplayMenu)
{
	if (!controlsGameplayMenu->listening) {
		setButtonText(&controlsGameplayMenu->leftPaddleUpButton, SDL_GetKeyName(inputs->leftPaddlePrimaryUp));
		setButtonText(&controlsGameplayMenu->leftPaddleDownButton, SDL_GetKeyName(inputs->leftPaddlePrimaryDown));
		setButtonText(&controlsGameplayMenu->rightPaddleUpButton, SDL_GetKeyName(inputs->rightPaddlePrimaryUp));
		setButtonText(&controlsGameplayMenu->rightPaddleDownButton, SDL_GetKeyName(inputs->rightPaddlePrimaryDown));
	}
}

void render(SDL_Renderer* renderer, controlsGameplayMenu* controlsGameplayMenu) {
	render(renderer, &controlsGameplayMenu->title);

	render(renderer, &controlsGameplayMenu->leftPaddleUp);
	render(renderer, &controlsGameplayMenu->leftPaddleUpButton);
	render(renderer, &controlsGameplayMenu->leftPaddleDown);
	render(renderer, &controlsGameplayMenu->leftPaddleDownButton);
	render(renderer, &controlsGameplayMenu->rightPaddleUp);
	render(renderer, &controlsGameplayMenu->rightPaddleUpButton);
	render(renderer, &controlsGameplayMenu->rightPaddleDown);
	render(renderer, &controlsGameplayMenu->rightPaddleDownButton);
}