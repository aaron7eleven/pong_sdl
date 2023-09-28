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
		if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&videoMenu->uiNavigation);
			play(&videoMenu->audioManager->uiMove, videoMenu->appSettings->sfxVolume);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&videoMenu->uiNavigation);
			play(&videoMenu->audioManager->uiMove, videoMenu->appSettings->sfxVolume);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
			play(&videoMenu->audioManager->uiSelect, videoMenu->appSettings->sfxVolume);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryBack) {
			inputs->uiBack = true;
			play(&videoMenu->audioManager->uiSelect, videoMenu->appSettings->sfxVolume);
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