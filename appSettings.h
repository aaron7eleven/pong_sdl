#pragma once
#include <SDL.h>

struct appSettings {
	int screenWidth = 1280;
	int screenHeight = 720;
	int screenFPS = 60;
	int screenTicksPerFrame = 1000 / screenFPS; // 1000 ms / X frames
};