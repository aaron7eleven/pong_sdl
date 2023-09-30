#pragma once
#include "audioManager.h"

void init(audioManager* audioManager)
{
	for (int i = 0; i < audioManager->sfxsLength; i++) {
		init(audioManager->sfxs[i]);
	}
}

void play(audioManager* audioManager, sfx* sfx) {
	if (sfx->randomness <= 0) {
		play(sfx->clip, sfx->volume * (*audioManager->appVolume));
	}
	else {
		play(sfx->clip, sfx->volume * (*audioManager->appVolume), sfx->randomness * (*audioManager->appVolume));
	}
}

void free(audioManager* audioManager) {

	//while (Mix_Playing(-1)) {
	//	// do nothing until audio finishes
	//}

	//std::cout << "Finished playing sfx and freeing audio manager" << std::endl;

	for (int i = 0; i < audioManager->sfxsLength; i++) {
		free(audioManager->sfxs[i]);
		//Mix_FreeChunk(audioManager->sfxs[i]->clip);
	}
}