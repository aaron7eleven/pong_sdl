#pragma once
#include "game.h"

void init(game* game) {
	init(&game->audioManager);
	init(&game->mainMenu);
	init(&game->optionsMenu);
	init(&game->controlsMenu);
	init(&game->controlsUIMenu);
	init(&game->controlsGameplayMenu);
	init(&game->videoMenu);
	init(&game->audioMenu);
	init(&game->winMenu);
	init(&game->gameplay);
	
	game->audioManager.appVolume = &game->appSettings->sfxVolume;

	game->gameplay.audioManager = &game->audioManager;
	game->mainMenu.audioManager = &game->audioManager;
	game->optionsMenu.audioManager = &game->audioManager;
	game->controlsMenu.audioManager = &game->audioManager;
	game->controlsUIMenu.audioManager = &game->audioManager;
	game->controlsGameplayMenu.audioManager = &game->audioManager;
	game->videoMenu.audioManager = &game->audioManager;
	game->audioMenu.audioManager = &game->audioManager;
	game->winMenu.audioManager = &game->audioManager;

	setText(&game->audioMenu.sfxVolumeValue, std::to_string(game->appSettings->sfxVolume));

	// Might put this in another function later after init and before main loop
	setButtonText(&game->videoMenu.windowModeButton, game->appSettings->fullscreenState[game->appSettings->fullscreen]);
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

		case gameState::controlsUIMenu: {
			processInput(inputs, &game->controlsUIMenu);
		} break;

		case gameState::controlsGameplayMenu: {
			processInput(inputs, &game->controlsGameplayMenu);
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
				if (game->mainMenu.uiNavigation.currentButton == &game->mainMenu.playButton) {
					init(&game->gameplay);
					game->gameState = gameState::gameplay;
				}
				else if (game->mainMenu.uiNavigation.currentButton == &game->mainMenu.optionsButton) {
					game->gameState = gameState::optionsMenu;
				}
				else if (game->mainMenu.uiNavigation.currentButton == &game->mainMenu.quitButton) {
					game->quit = true;
				}
			}
		} break;

		case gameState::optionsMenu: {
			if (inputs->uiSelected) {
				if (game->optionsMenu.uiNavigation.currentButton == &game->optionsMenu.controlsButton) {
					game->gameState = gameState::controlsMenu;
				}
				else if (game->optionsMenu.uiNavigation.currentButton == &game->optionsMenu.videoButton) {
					game->gameState = gameState::videoMenu;
				}
				else if (game->optionsMenu.uiNavigation.currentButton == &game->optionsMenu.audioButton) {
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
			if (inputs->uiSelected) {
				if (game->controlsMenu.uiNavigation.currentButton == &game->controlsMenu.gameplayControlsButton) {
					game->gameState = gameState::controlsGameplayMenu;
				}
				else if (game->controlsMenu.uiNavigation.currentButton == &game->controlsMenu.uiControlsButton) {
					game->gameState = gameState::controlsUIMenu;
				}
			}
			else if (inputs->uiBack) {
				game->gameState = gameState::optionsMenu;
			}
		} break;

		case gameState::controlsGameplayMenu: {

			update(deltaTime, inputs, &game->controlsGameplayMenu);
			if (game->controlsGameplayMenu.listening) {
				if (game->controlsGameplayMenu.heard) {
					*game->controlsGameplayMenu.listeningKeyCodeToChange = game->controlsGameplayMenu.listeningKeyCode;

					// Assign change to paddle controller
					if (game->controlsGameplayMenu.listeningButton == &game->controlsGameplayMenu.leftPaddleUpButton) {
						game->gameplay.leftPaddle.paddleController.up = game->controlsGameplayMenu.listeningScanCode;
					}
					else if (game->controlsGameplayMenu.listeningButton == &game->controlsGameplayMenu.leftPaddleDownButton) {
						game->gameplay.leftPaddle.paddleController.down = game->controlsGameplayMenu.listeningScanCode;
					}
					else if (game->controlsGameplayMenu.listeningButton == &game->controlsGameplayMenu.rightPaddleUpButton) {
						game->gameplay.rightPaddle.paddleController.up = game->controlsGameplayMenu.listeningScanCode;
					}
					else if (game->controlsGameplayMenu.listeningButton == &game->controlsGameplayMenu.rightPaddleDownButton) {
						game->gameplay.rightPaddle.paddleController.down = game->controlsGameplayMenu.listeningScanCode;
					}

					game->controlsGameplayMenu.listening = false;
					game->controlsGameplayMenu.heard = false;
					game->controlsGameplayMenu.listeningButton = NULL;
					game->controlsGameplayMenu.listeningKeyCode = NULL;
				}
			}
			else if (inputs->uiSelected) {
				if (!game->controlsGameplayMenu.listening) {
					game->controlsGameplayMenu.listening = true;
					game->controlsGameplayMenu.listeningButton = game->controlsGameplayMenu.uiNavigation.currentButton;
					setButtonText(game->controlsGameplayMenu.listeningButton, "Listen...");

					// Link button to action to change
					if (game->controlsGameplayMenu.listeningButton == &game->controlsGameplayMenu.leftPaddleUpButton) {
						game->controlsGameplayMenu.listeningKeyCodeToChange = &inputs->leftPaddlePrimaryUp;
					}
					else if (game->controlsGameplayMenu.listeningButton == &game->controlsGameplayMenu.leftPaddleDownButton) {
						game->controlsGameplayMenu.listeningKeyCodeToChange = &inputs->leftPaddlePrimaryDown;
					}
					else if (game->controlsGameplayMenu.listeningButton == &game->controlsGameplayMenu.rightPaddleUpButton) {
						game->controlsGameplayMenu.listeningKeyCodeToChange = &inputs->rightPaddlePrimaryUp;
					}
					else if (game->controlsGameplayMenu.listeningButton == &game->controlsGameplayMenu.rightPaddleDownButton) {
						game->controlsGameplayMenu.listeningKeyCodeToChange = &inputs->rightPaddlePrimaryDown;
					}
				}				
			}
			else if (inputs->uiBack) {
				game->gameState = gameState::controlsMenu;
			}
		} break;

		case gameState::controlsUIMenu: {

			update(deltaTime, inputs, &game->controlsUIMenu);
			if (game->controlsUIMenu.listening) {
				if (game->controlsUIMenu.heard) {
					*game->controlsUIMenu.listeningKeyCodeToChange = game->controlsUIMenu.listeningKeyCode;
					game->controlsUIMenu.listening = false;
					game->controlsUIMenu.heard = false;
					game->controlsUIMenu.listeningButton = NULL;
					game->controlsUIMenu.listeningKeyCode = NULL;
				}
			}
			else if (inputs->uiSelected) {
				if (!game->controlsUIMenu.listening) {
					game->controlsUIMenu.listening = true;
					game->controlsUIMenu.listeningButton = game->controlsUIMenu.uiNavigation.currentButton;
					setButtonText(game->controlsUIMenu.listeningButton, "Listen...");

					// Link button to action to change
					if (game->controlsUIMenu.listeningButton == &game->controlsUIMenu.uiBackButton) {
						game->controlsUIMenu.listeningKeyCodeToChange = &inputs->uiPrimaryBack;
					}
					else if (game->controlsUIMenu.listeningButton == &game->controlsUIMenu.uiSelectButton) {
						game->controlsUIMenu.listeningKeyCodeToChange = &inputs->uiPrimarySelect;
					}
					else if (game->controlsUIMenu.listeningButton == &game->controlsUIMenu.uiMoveUpButton) {
						game->controlsUIMenu.listeningKeyCodeToChange = &inputs->uiPrimaryMoveUp;
					}
					else if (game->controlsUIMenu.listeningButton == &game->controlsUIMenu.uiMoveDownButton) {
						game->controlsUIMenu.listeningKeyCodeToChange = &inputs->uiPrimaryMoveDown;
					}
					//else if (game->controlsUIMenu.listeningButton == &game->controlsUIMenu.uiMoveLeftButton) {
					//	game->controlsUIMenu.listeningKeyCodeToChange = &inputs->uiPrimaryMoveLeft;
					//}
					//else if (game->controlsUIMenu.listeningButton == &game->controlsUIMenu.uiMoveRightButton) {
					//	game->controlsUIMenu.listeningKeyCodeToChange = &inputs->uiPrimaryMoveRight;
					//}
				}
			}
			else if (inputs->uiBack) {
				game->gameState = gameState::controlsMenu;
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

		case gameState::controlsUIMenu: {
			render(renderer, &game->controlsUIMenu);
		} break;

		case gameState::controlsGameplayMenu: {
			render(renderer, &game->controlsGameplayMenu);
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

int free(game* game) {
	free(&game->audioManager);
	return 0;
}