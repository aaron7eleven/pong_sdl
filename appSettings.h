#pragma once
#include <string>
#include <SDL.h>

struct appSettings {
	bool fullscreen = false;
	std::string fullscreenState[2] = {"Windowed","Fullscreen" };
	bool vSync = true;
	std::string vSyncState[2] = { "Disabled", "Enabled" };	

	int screenWidth = 1280;
	int screenHeight = 720;
	Uint32 fps = 60;
	Uint32 ticksPerFrame = 1000 / fps; // 1000 ms / X frames

	float sfxVolume = 0.75f;
};