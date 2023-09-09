#pragma once
#include "game.h"

//void init(app* app, game* game) {
//	game->app = app;
//	init(game->app, &game->mainMenu);
//}
void init(game* game) {
	init(&game->mainMenu);
}


void render(SDL_Renderer* renderer, game* game) {
	render(renderer, &game->mainMenu);
}