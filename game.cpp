#pragma once
#include "game.h"

void init(game* game) {
	init(&game->mainMenu);
	init(&game->optionsMenu);
	init(&game->controlsMenu);
	init(&game->videoMenu);
	init(&game->audioMenu	);
	init(&game->winMenu);
	init(&game->gameplay);

	game->gameplay.appSettings = game->appSettings;
	setText(&game->audioMenu.sfxVolumeValue, std::to_string(game->appSettings->sfxVolume));

	// Might put this in another function later after init and before main loop
	//std::string windowModeButtonState = game->appSettings->fullscreen ? "Fullscreen" : "Windowed";
	//setButtonText(&game->videoMenu.windowModeButton, windowModeButtonState);

	setButtonText(&game->videoMenu.windowModeButton, game->appSettings->fullscreenState[game->appSettings->fullscreen]);

	//std::string vSyncButtonState = game->appSettings->vSync ? "Enabled" : "Disabled";
	//setButtonText(&game->videoMenu.vSyncButton, vSyncButtonState);
	setButtonText(&game->videoMenu.vSyncButton, game->appSettings->vSyncState[game->appSettings->vSync]);
};

void processInput(inputs* inputs, game* game) {
	switch (game->gameState)
	{
		case gameState::mainMenu: {
			processInput(inputs, &game->mainMenu);
		} break;

		case gameState::optionsMenu: {
			processInput(inputs, &game->optionsMenu);

		} break;

		case gameState::controlsMenu: {
			processInput(inputs, &game->controlsMenu);

		} break;

		case gameState::videoMenu: {
			processInput(inputs, &game->videoMenu);
		} break;

		case gameState::audioMenu: {
			processInput(inputs, &game->audioMenu);
		} break;

		case gameState::gameplay: {
			processInput(inputs, &game->gameplay);
		} break;

		case gameState::winMenu: {
			processInput(inputs, &game->winMenu);
		} break;

		default:
			break;
	}
}

void preUpdate(game* game)
{
	switch (game->gameState)
	{
	//case gameState::mainMenu: {
	//	processInput(inputs, &game->mainMenu);
	//} break;

	//case gameState::optionsMenu: {
	//	processInput(inputs, &game->optionsMenu);

	//} break;

	//case gameState::controlsMenu: {
	//	processInput(inputs, &game->controlsMenu);

	//} break;

	//case gameState::videoMenu: {
	//	processInput(inputs, &game->videoMenu);
	//} break;

	case gameState::gameplay: {
		preUpdate(&game->gameplay);
	} break;

	default:
		break;
	}
}

void update(float deltaTime, inputs* inputs, game* game) {
	//update(deltaTime, inputs, &game->mainMenu);
	switch (game->gameState)
	{
		case gameState::mainMenu: {
			if (inputs->uiSelected) {
				if (game->mainMenu.uiNavigation.currentButton->text->text == "Play") {
					init(&game->gameplay);
					game->gameState = gameState::gameplay;
				}
				else if (game->mainMenu.uiNavigation.currentButton->text->text == "Options") {
					game->gameState = gameState::optionsMenu;
				}
				else if (game->mainMenu.uiNavigation.currentButton->text->text == "Quit") {
					game->quit = true;
				}
			}
		} break;

		case gameState::optionsMenu: {
			if (inputs->uiSelected) {
				if (game->optionsMenu.uiNavigation.currentButton->text->text == "Controls") {
					game->gameState = gameState::controlsMenu;
				}
				else if (game->optionsMenu.uiNavigation.currentButton->text->text == "Video") {
					game->gameState = gameState::videoMenu;
				}
				else if (game->optionsMenu.uiNavigation.currentButton->text->text == "Audio") {
					game->gameState = gameState::audioMenu;
				}
			}
			else if (inputs->uiBack) {
				game->gameState = gameState::mainMenu;
			}
		} break;

		case gameState::videoMenu: {
			if (inputs->uiSelected) {
				if (game->videoMenu.uiNavigation.currentButton == &game->videoMenu.vSyncButton) {
					bool vSync = game->videoMenu.uiNavigation.currentButton->text->text == "Enabled";
					bool toggledVSync = !vSync;
					setButtonText(game->videoMenu.uiNavigation.currentButton, game->appSettings->vSyncState[toggledVSync]);
					game->appSettings->vSync = toggledVSync;
					game->changeAppSettings = true;
				}
				else if (game->videoMenu.uiNavigation.currentButton == &game->videoMenu.windowModeButton) {
					bool fullscreen = game->videoMenu.uiNavigation.currentButton->text->text == "Fullscreen";
					bool toggledFullscreen = !fullscreen;
					setButtonText(game->videoMenu.uiNavigation.currentButton, game->appSettings->fullscreenState[toggledFullscreen]);
					game->appSettings->fullscreen = toggledFullscreen;
					game->changeAppSettings = true;
				}
			}
			else if (inputs->uiBack) {
				game->gameState = gameState::optionsMenu;
			}
		} break;

		case gameState::audioMenu: {
			if (inputs->uiSelected) {
				if (game->audioMenu.uiNavigation.currentButton == &game->audioMenu.sfxVolumeUpButton) {
					game->appSettings->sfxVolume += 0.05f;
					if (game->appSettings->sfxVolume > 1.0f) {
						game->appSettings->sfxVolume = 1.0f;
					}
					setText(&game->audioMenu.sfxVolumeValue, std::to_string(game->appSettings->sfxVolume));
				}
				else if (game->audioMenu.uiNavigation.currentButton == &game->audioMenu.sfxVolumeDownButton) {
					game->appSettings->sfxVolume -= 0.05f;
					if (game->appSettings->sfxVolume < 0.0f) {
						game->appSettings->sfxVolume = 0.0f;
					}
					setText(&game->audioMenu.sfxVolumeValue, std::to_string(game->appSettings->sfxVolume));
				}
			}
			else if (inputs->uiBack) {
				game->gameState = gameState::optionsMenu;
			}
		} break;

		case gameState::controlsMenu: {

			update(deltaTime, inputs, &game->controlsMenu);
			if (game->controlsMenu.listening) {
				if (game->controlsMenu.heard) {
					*game->controlsMenu.listeningKeyCodeToChange = game->controlsMenu.listeningKeyCode;
					game->controlsMenu.listening = false;
					game->controlsMenu.heard = false;
					game->controlsMenu.listeningButton = NULL;
					game->controlsMenu.listeningKeyCode = NULL;
				}
			}
			else if (inputs->uiSelected) {

				if (!game->controlsMenu.listening) {
					game->controlsMenu.listening = true;
					game->controlsMenu.listeningButton = game->controlsMenu.uiNavigation.currentButton;
					setButtonText(game->controlsMenu.listeningButton, "Listen");

					// Link button to action to change
					if (game->controlsMenu.listeningButton == &game->controlsMenu.uiBackButton) {
						game->controlsMenu.listeningKeyCodeToChange = &inputs->uiPrimaryBack;
					}
					else if (game->controlsMenu.listeningButton == &game->controlsMenu.uiSelectButton) {
						game->controlsMenu.listeningKeyCodeToChange = &inputs->uiPrimarySelect;
					}
					else if (game->controlsMenu.listeningButton == &game->controlsMenu.uiMoveUpButton) {
						game->controlsMenu.listeningKeyCodeToChange = &inputs->uiPrimaryMoveUp;
					}
					else if (game->controlsMenu.listeningButton == &game->controlsMenu.uiMoveDownButton) {
						game->controlsMenu.listeningKeyCodeToChange = &inputs->uiPrimaryMoveDown;
					}
					else if (game->controlsMenu.listeningButton == &game->controlsMenu.uiMoveLeftButton) {
						game->controlsMenu.listeningKeyCodeToChange = &inputs->uiPrimaryMoveLeft;
					}
					else if (game->controlsMenu.listeningButton == &game->controlsMenu.uiMoveRightButton) {
						game->controlsMenu.listeningKeyCodeToChange = &inputs->uiPrimaryMoveRight;
					}
				}				
			}
			else if (inputs->uiBack) {
				game->gameState = gameState::optionsMenu;
			}
		} break;

		case gameState::gameplay: {
			update(deltaTime, inputs, &game->gameplay);
			
			if (game->gameplay.win) {
				if (game->gameplay.leftScore >= game->gameplay.scoreToWin) {
					setText(&game->winMenu.title, "Left Player Won!!!");
				}
				else {
					setText(&game->winMenu.title, "Right Player Won!!!");
				}
				setText(&game->winMenu.subtitle, std::to_string(game->gameplay.leftScore) + " - " + std::to_string(game->gameplay.rightScore));
				game->gameState = gameState::winMenu;
			}
		} break;

		case gameState::winMenu: {
			if (inputs->uiSelected) {
				if (game->winMenu.uiNavigation.currentButton->text->text == "Play Again") {
					init(&game->gameplay);
					game->gameState = gameState::gameplay;
				}
				else if (game->winMenu.uiNavigation.currentButton->text->text == "Main Menu") {
					game->gameState = gameState::mainMenu;
				}
				else if (game->winMenu.uiNavigation.currentButton->text->text == "Quit") {
					game->quit = true;
				}
			}
			else if (inputs->uiBack) {
				game->gameState = gameState::mainMenu;
			}
		} break;

		default:
			break;
	}
}

void render(SDL_Renderer* renderer, game* game) {
	
	switch (game->gameState)
	{
		case gameState::mainMenu: {
			render(renderer, &game->mainMenu);
		} break;

		case gameState::optionsMenu: {
			render(renderer, &game->optionsMenu);
		} break;

		case gameState::controlsMenu: {
			render(renderer, &game->controlsMenu);
		} break;

		case gameState::videoMenu: {
			render(renderer, &game->videoMenu);
		} break;

		case gameState::audioMenu: {
			render(renderer, &game->audioMenu);
		} break;

		case gameState::gameplay: {
			render(renderer, &game->gameplay);
		} break;

		case gameState::winMenu: {
			render(renderer, &game->winMenu);
		} break;

	default:
		break;
	}
}