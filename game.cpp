#pragma once
#include "game.h"

void init(game* game) {
	init(&game->mainMenu);
	init(&game->optionsMenu);
	init(&game->controlsMenu);
}

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
				// what button was selected?
				// Play? Options? Quit?
				if (game->mainMenu.mainMenuNavigation.uiNavigation.currentButton->text->text == "Play") {
					// do nothing
				}
				else if (game->mainMenu.mainMenuNavigation.uiNavigation.currentButton->text->text == "Options") {
					game->gameState = gameState::optionsMenu;
				}
				else if (game->mainMenu.mainMenuNavigation.uiNavigation.currentButton->text->text == "Quit") {
					game->quit = true;
				}
			}
		} break;

		case gameState::optionsMenu: {
			if (inputs->uiSelected) {
				if (game->optionsMenu.uiNavigation.currentButton->text->text == "Controls") {
					game->gameState = gameState::controlsMenu;
				}
			}
			else if (inputs->uiBack) {
				game->gameState = gameState::mainMenu;
			}
		} break;

		case gameState::controlsMenu: {

			update(deltaTime, inputs, &game->controlsMenu);

			if (inputs->uiSelected) {
				// Do nothing
			}
			else if (inputs->uiBack) {
				game->gameState = gameState::optionsMenu;
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

	default:
		break;
	}
}