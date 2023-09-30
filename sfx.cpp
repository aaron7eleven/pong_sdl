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
	Mix_Volume(-1, volumeCheck(volume));
	Mix_PlayChannel(-1, sfx, 0);
}

void play(Mix_Chunk* sfx, int volume, int randomness) {
	Mix_Volume(-1, (volumeCheck(volume) - randomness) + (rand() % randomness));
	Mix_PlayChannel(-1, sfx, 0);
}

int volumeCheck(int volume) {
	if (volume > MIX_MAX_VOLUME) {
		volume = MIX_MAX_VOLUME;
	}
	else if (volume < 0) {
		volume = 0;
	}
	return volume;
}

int free(sfx* sfx) {
	Mix_FreeChunk(sfx->clip);
	sfx->clip = NULL;
	return 0;
}

