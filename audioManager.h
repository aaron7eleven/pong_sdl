#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "sfx.h"

struct audioManager {

	float* appVolume = NULL;
	
	sfx ballHit = {
		//.path = "assets/sfx/269718__michorvath__ping-pong-ball-hit.wav",
		.path = "assets/sfx/66877__mikemunkie__bleep1.wav",
		.volume = 16,
		.randomness = 8,	
	};
	
	sfx uiMove = {
		//.path = "assets/sfx/66877__mikemunkie__bleep1.wav",
		.path = "assets/sfx/396406__goncalo95__ping-pong-low.wav",		
		.volume = 128,
		.randomness = 16,
	};

	sfx uiSelect = {
		.path = "assets/sfx/350871__cabled_mess__coin_c_04.wav",
		.volume = 96,
		.randomness = 8,
	};

	const int sfxsLength = 3;
	sfx* sfxs[3] = {
		&ballHit,
		&uiMove,
		&uiSelect
	};
};

void init(audioManager* audioManager);
void play(audioManager* audioManager, sfx* sfx);
void free(audioManager* audioManager);