#pragma once
#include <iostream>
#include "videoMenu.h"

void init(videoMenu* videoMenu) {
	init(&videoMenu->title);
	init(&videoMenu->vSync);
	init(&videoMenu->vSyncButton);
	init(&videoMenu->windowMode);
	init(&videoMenu->windowModeButton);
	//init(&videoMenu->uiMoveUpButton);
	//init(&videoMenu->uiMoveDown);
	//init(&videoMenu->uiMoveDownButton);
	//init(&videoMenu->uiMoveLeft);
	//init(&videoMenu->uiMoveLeftButton);
	//init(&videoMenu->uiMoveRight);
	//init(&videoMenu->uiMoveRightButton);
	//init(&videoMenu->uiSelect);
	//init(&videoMenu->uiSelectButton);
	//init(&videoMenu->uiBack);
	//init(&videoMenu->uiBackButton);

	//setButtonText(&videoMenu->windowModeButton, "Fullscreen");

	init(&videoMenu->uiNavigation);
}


void processInput(inputs* inputs, videoMenu* videoMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&videoMenu->uiNavigation);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&videoMenu->uiNavigation);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryBack) {
			inputs->uiBack = true;
		}
	}
}

void update(float deltaTime, inputs* inputs, videoMenu* videoMenu)
{
	//if (!videoMenu->listening) {
	//	setButtonText(&videoMenu->uiMoveUpButton, SDL_GetKeyName(inputs->uiPrimaryMoveUp));
	//	setButtonText(&videoMenu->uiMoveDownButton, SDL_GetKeyName(inputs->uiPrimaryMoveDown));
	//	setButtonText(&videoMenu->uiMoveLeftButton, SDL_GetKeyName(inputs->uiPrimaryMoveLeft));
	//	setButtonText(&videoMenu->uiMoveRightButton, SDL_GetKeyName(inputs->uiPrimaryMoveRight));
	//	setButtonText(&videoMenu->uiSelectButton, SDL_GetKeyName(inputs->uiPrimarySelect));
	//	setButtonText(&videoMenu->uiBackButton, SDL_GetKeyName(inputs->uiPrimaryBack));
	//}
}

void render(SDL_Renderer* renderer, videoMenu* videoMenu) {
	render(renderer, &videoMenu->title);
	render(renderer, &videoMenu->vSync);
	render(renderer, &videoMenu->vSyncButton);
	render(renderer, &videoMenu->windowMode);
	render(renderer, &videoMenu->windowModeButton);
	//render(renderer, &videoMenu->uiMoveUpButton);
	//render(renderer, &videoMenu->uiMoveDown);
	//render(renderer, &videoMenu->uiMoveDownButton);
	//render(renderer, &videoMenu->uiMoveLeft);
	//render(renderer, &videoMenu->uiMoveLeftButton);
	//render(renderer, &videoMenu->uiMoveRight);
	//render(renderer, &videoMenu->uiMoveRightButton);
	//render(renderer, &videoMenu->uiSelect);
	//render(renderer, &videoMenu->uiSelectButton);
	//render(renderer, &videoMenu->uiBack);
	//render(renderer, &videoMenu->uiBackButton);
}