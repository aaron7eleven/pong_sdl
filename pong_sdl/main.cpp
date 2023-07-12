#include <iostream>
#include "stdio.h"
#include <SDL.h>

int main(int argc, char* argv[]) 
{
	
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		printf("Failed to initialize SDL");
		return 1;
	}
	return 0;
}