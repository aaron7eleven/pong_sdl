#pragma once
#include <iostream>
#include <string>
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


	// Pause them all
	Mix_Pause(-1);

	//while (Mix_Playing(-1)) {
	//	// do nothing until audio finishes
	//	std::cout << "Waiting for finish playing sfx on channel " << Mix_Playing(-1) << std::endl;
	//}

	

	//std::cout << "Finished playing sfx and freeing sfx in audio manager" << std::endl;

	for (int i = 0; i < audioManager->sfxsLength; i++) {
		free(audioManager->sfxs[i]);
	}
}