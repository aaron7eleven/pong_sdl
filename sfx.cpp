#pragma once
#include <iostream>
#include <string>

#include "sfx.h"


void init(sfx* sfx) {
	sfx->clip = Mix_LoadWAV(sfx->path);
	if (sfx->clip == NULL)
	{
		printf("Failed to load %s sound effect! SDL_mixer Error: %s\n", sfx->path, Mix_GetError());
	}
}

void play(Mix_Chunk* sfx, int volume) {
	if (volume > 128) {
		volume = 128;
	}
	else if (volume < 0) {
		volume = 0;
	}

	Mix_Volume(-1, volume);
	Mix_PlayChannel(-1, sfx, 0);
}

void play(Mix_Chunk* sfx, int volume, int randomness) {
	if (volume > 128) {
		volume = 128;
	}
	else if (volume < 0) {
		volume = 0;
	}

	Mix_Volume(-1, (volume - randomness) + (rand() % randomness));
	Mix_PlayChannel(-1, sfx, 0);
}


