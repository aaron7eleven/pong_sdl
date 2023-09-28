#pragma once
#include "audioManager.h"

void init(audioManager* audioManager)
{
	for (int i = 0; i < audioManager->sfxsLength; i++) {
		init(audioManager->sfxs[i]);
	}
}
