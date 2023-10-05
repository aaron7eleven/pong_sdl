#pragma once
#include <iostream>
#include "videoMenu.h"

void init(videoMenu* videoMenu) {
	init(&videoMenu->title);
	init(&videoMenu->vSync);
	init(&videoMenu->vSyncButton);
	init(&videoMenu->windowMode);
	init(&videoMenu->windowModeButton);

	init(&videoMenu->uiNavigation);
}


void processInput(inputs* inputs, videoMenu* videoMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		// Dynamic Input -> use if's
		if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&videoMenu->uiNavigation);
			play(videoMenu->audioManager, &videoMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&videoMenu->uiNavigation);
			play(videoMenu->audioManager, &videoMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
			play(videoMenu->audioManager, &videoMenu->audioManager->uiSelect);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryBack) {
			inputs->uiBack = true;
			play(videoMenu->audioManager, &videoMenu->audioManager->uiSelect);
		}
	}
}

void update(float deltaTime, inputs* inputs, videoMenu* videoMenu)
{
}

void render(SDL_Renderer* renderer, videoMenu* videoMenu) {
	render(renderer, &videoMenu->title);
	render(renderer, &videoMenu->vSync);
	render(renderer, &videoMenu->vSyncButton);
	render(renderer, &videoMenu->windowMode);
	render(renderer, &videoMenu->windowModeButton);
}

void free(videoMenu* videoMenu) {
	videoMenu->audioManager = NULL;
	videoMenu->appSettings = NULL;
	free(&videoMenu->title);
	free(&videoMenu->vSync);
	free(&videoMenu->vSyncButton);
	free(&videoMenu->windowMode);
	free(&videoMenu->windowModeButton);
	free(&videoMenu->uiNavigation);
}