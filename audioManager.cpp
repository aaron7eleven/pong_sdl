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