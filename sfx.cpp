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

void play(sfx* sfx, float appVolume) {
	play(sfx->clip, sfx->volume, sfx->randomness, appVolume);
}

void play(sfx* sfx) {
	play(sfx->clip, sfx->volume, sfx->randomness);
}

void play(Mix_Chunk* sfx, int volume, int randomness) {
	Mix_Volume(-1, (volume - randomness) + (rand() % randomness));
	Mix_PlayChannel(-1, sfx, 0);
}

void play(Mix_Chunk* sfx, int volume, int randomness, float appVolume) {
	Mix_Volume(-1, ((volume - randomness) + (rand() % randomness)) * appVolume);
	Mix_PlayChannel(-1, sfx, 0);
}