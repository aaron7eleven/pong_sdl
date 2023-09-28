#pragma once
#include <SDL.h>
#include <SDL_mixer.h>

struct sfx {
	const char* path = NULL;
	Mix_Chunk* clip = NULL;
	int volume = 63;
	int randomness = 0;
};

void init(sfx* sfx);
void play(sfx* sfx);
void play(sfx* sfx, float appVolume);
void play(Mix_Chunk* sfx, int volume, int randomness);
void play(Mix_Chunk* sfx, int volume, int randomness, float appVolume);