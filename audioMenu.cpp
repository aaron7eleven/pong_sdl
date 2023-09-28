#pragma once
#include <iostream>
#include "audioMenu.h"

void init(audioMenu* audioMenu) {
	init(&audioMenu->title);
	init(&audioMenu->sfxVolume);
	init(&audioMenu->sfxVolumeUpButton);
	init(&audioMenu->sfxVolumeDownButton);
	init(&audioMenu->sfxVolumeValue);

	init(&audioMenu->uiNavigation);
}


void processInput(inputs* inputs, audioMenu* audioMenu) {
	if (inputs->e.type == SDL_KEYDOWN) {
		// Dynamic Input -> use if's
		if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveUp) {
			previous(&audioMenu->uiNavigation);
			play(audioMenu->audioManager, &audioMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryMoveDown) {
			next(&audioMenu->uiNavigation);
			play(audioMenu->audioManager, &audioMenu->audioManager->uiMove);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimarySelect) {
			inputs->uiSelected = true;
			play(audioMenu->audioManager, &audioMenu->audioManager->uiSelect);
		}
		else if (inputs->e.key.keysym.sym == inputs->uiPrimaryBack) {
			inputs->uiBack = true;
			play(audioMenu->audioManager, &audioMenu->audioManager->uiSelect);
		}
	}
}

void update(float deltaTime, inputs* inputs, audioMenu* audioMenu)
{
	//if (!audioMenu->listening) {
	//	setButtonText(&audioMenu->uiMoveUpButton, SDL_GetKeyName(inputs->uiPrimaryMoveUp));
	//	setButtonText(&audioMenu->uiMoveDownButton, SDL_GetKeyName(inputs->uiPrimaryMoveDown));
	//	setButtonText(&audioMenu->uiMoveLeftButton, SDL_GetKeyName(inputs->uiPrimaryMoveLeft));
	//	setButtonText(&audioMenu->uiMoveRightButton, SDL_GetKeyName(inputs->uiPrimaryMoveRight));
	//	setButtonText(&audioMenu->uiSelectButton, SDL_GetKeyName(inputs->uiPrimarySelect));
	//	setButtonText(&audioMenu->uiBackButton, SDL_GetKeyName(inputs->uiPrimaryBack));
	//}
}

void render(SDL_Renderer* renderer, audioMenu* audioMenu) {
	render(renderer, &audioMenu->title);
	render(renderer, &audioMenu->sfxVolume);
	render(renderer, &audioMenu->sfxVolumeUpButton);
	render(renderer, &audioMenu->sfxVolumeDownButton);
	render(renderer, &audioMenu->sfxVolumeValue);
}