#include <iostream>
#include "stdio.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>


SDL_Surface* LoadSurface(SDL_Surface* window, std::string path) {
	
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* imageSurface = IMG_Load(path.c_str());
	if (imageSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else {
		optimizedSurface = SDL_ConvertSurface(imageSurface, window->format, 0);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
	}

	SDL_FreeSurface(imageSurface);
	
	return optimizedSurface;
}

SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string path) {
	SDL_Texture* outputTexture = NULL;

	SDL_Surface* imageSurface = IMG_Load(path.c_str());
	if (imageSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else {
		outputTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
		if (outputTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
	}

	SDL_FreeSurface(imageSurface);

	return outputTexture;
}

struct Entity {
	SDL_FRect position;
	SDL_Color color;
};


int main(int argc, char* argv[]) 
{
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS; // 1000 ms / X frames

	const int PADDLE_INIT_X = SCREEN_WIDTH / 8;
	const int PADDLE_INIT_Y = SCREEN_HEIGHT / 2;
	const int PADDLE_WIDTH = SCREEN_WIDTH / 64;
	const int PADDLE_HEIGHT = SCREEN_HEIGHT / 8;
	const int PADDLE_SPEED = 200;

	const int LEFT_WALL_X = SCREEN_WIDTH / 16;
	const int LEFT_WALL_Y = 0; // Starts at top left corner not center (0 not SCREEN_HEIGHT / 2)
	const int RIGHT_WALL_X = SCREEN_WIDTH * 15 / 16;
	const int RIGHT_WALL_Y = 0; // Starts at top left corner not center (0 not SCREEN_HEIGHT / 2)
	const int HORZ_WALL_WIDTH = SCREEN_WIDTH / 128;
	const int HORZ_WALL_HEIGHT = SCREEN_HEIGHT;

	const int TOP_WALL_X = 0; // Starts at top left corner not center (0 not SCREEN_WIDTH / 2)
	const int TOP_WALL_Y = 0;
	const int BOTTOM_WALL_X = 0; // Starts at top left corner not center (0 not SCREEN_WIDTH / 2)
	const int BOTTOM_WALL_Y = SCREEN_HEIGHT;
	const int VERT_WALL_WIDTH = SCREEN_WIDTH;
	const int VERT_WALL_HEIGHT = SCREEN_WIDTH / 128;

	
	SDL_Window* window = NULL;
	SDL_Surface* windowSurface = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* texture = NULL;

	// Initialization
	if (SDL_Init(SDL_INIT_EVERYTHING)) 
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}
	else 
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			}
			else {

				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				}
				else
				{
					//Get window surface
					windowSurface = SDL_GetWindowSurface(window);
				}
			}
			
			
		}
	}

	texture = LoadTexture(renderer, "assets/loaded.png");


	if (texture == NULL) {
		printf("Failed to load texture image\n");
	}
	else {

		// Main Loop
		bool quit = false;
		SDL_Event e;

		Entity leftPaddle;
		leftPaddle.position = {
			PADDLE_INIT_X,
			PADDLE_INIT_Y,
			PADDLE_WIDTH,
			PADDLE_HEIGHT
		};

		leftPaddle.color = { 0xFF, 0xFF, 0xFF, 0xFF };
		bool leftPaddleUpHeld = false;
		bool leftPaddleDownHeld = false;

		Entity leftWall;
		leftWall.position = {
			LEFT_WALL_X,
			LEFT_WALL_Y,
			HORZ_WALL_WIDTH,
			HORZ_WALL_HEIGHT
		};
		leftWall.color = { 0xFF, 0xFF, 0xFF, 0xFF };

		Entity rightWall;
		rightWall.position = {
			RIGHT_WALL_X,
			RIGHT_WALL_Y,
			HORZ_WALL_WIDTH,
			HORZ_WALL_HEIGHT
		};
		rightWall.color = { 0xFF, 0xFF, 0xFF, 0xFF };

		Entity topWall;
		topWall.position = {
			TOP_WALL_X,
			TOP_WALL_Y,
			VERT_WALL_WIDTH,
			VERT_WALL_HEIGHT
		};
		topWall.color = { 0xFF, 0xFF, 0xFF, 0xFF };

		Entity bottomWall;
		bottomWall.position = {
			BOTTOM_WALL_X,
			BOTTOM_WALL_Y,
			VERT_WALL_WIDTH,
			VERT_WALL_HEIGHT
		};
		bottomWall.color = { 0xFF, 0xFF, 0xFF, 0xFF };



		float deltaTime = 0.0f;
		Uint32 startTicks = SDL_GetTicks();
		Uint32 lastTicks = 0;

		while (!quit) {
			/*startTime = SDL_GetTicks();
			deltaTime = (lastTime - startTime) / 1000.0f;
			lastTime = startTime;*/
			//startTime = SDL_GetTicks();
			deltaTime = (SDL_GetTicks() - startTicks) / 1000.0f;
			//lastTime = startTime;
			startTicks = SDL_GetTicks();

			//printf("deltaTime = %f\n", deltaTime);

			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (e.type == SDL_KEYDOWN) {
					//Select surfaces based on key press
					switch (e.key.keysym.sym)
					{

						// Left Paddle
						case SDLK_w:							
							leftPaddleUpHeld = true;
							break;

						case SDLK_s:
							leftPaddleDownHeld = true;
							break;

						// Right Paddle
						case SDLK_UP:
							printf("Up");
							break;

						case SDLK_DOWN:
							printf("Down");
							break;

						default:
							printf("Default");
							break;
					}
				}
				else if (e.type == SDL_KEYUP) {
					//Select surfaces based on key press
					switch (e.key.keysym.sym)
					{

						// Left Paddle
					case SDLK_w:
						leftPaddleUpHeld = false;
						break;

					case SDLK_s:
						leftPaddleDownHeld = false;
						break;

						// Right Paddle
					case SDLK_UP:
						printf("Up");
						break;

					case SDLK_DOWN:
						printf("Down");
						break;

					default:
						printf("Default");
						break;
					}
				}
			}

			if (leftPaddleUpHeld) {
				leftPaddle.position.y -= PADDLE_SPEED * deltaTime;
			}

			if (leftPaddleDownHeld) {
				leftPaddle.position.y += PADDLE_SPEED * deltaTime;
			}

			//Clear screen to Black
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(renderer);

			// Draw Entities
			SDL_SetRenderDrawColor(renderer, leftPaddle.color.r, leftPaddle.color.g, leftPaddle.color.b, leftPaddle.color.a);
			SDL_RenderFillRectF(renderer, &leftPaddle.position);

			SDL_SetRenderDrawColor(renderer, leftWall.color.r, leftWall.color.g, leftWall.color.b, leftWall.color.a);
			SDL_RenderFillRectF(renderer, &leftWall.position);

			SDL_SetRenderDrawColor(renderer, rightWall.color.r, rightWall.color.g, rightWall.color.b, rightWall.color.a);
			SDL_RenderFillRectF(renderer, &rightWall.position);

			SDL_SetRenderDrawColor(renderer, topWall.color.r, topWall.color.g, topWall.color.b, topWall.color.a);
			SDL_RenderFillRectF(renderer, &topWall.position);

			SDL_SetRenderDrawColor(renderer, bottomWall.color.r, bottomWall.color.g, bottomWall.color.b, bottomWall.color.a);
			SDL_RenderFillRectF(renderer, &bottomWall.position);


			SDL_RenderPresent(renderer);

			int frameTicks = SDL_GetTicks() - startTicks;
			if (frameTicks < SCREEN_TICKS_PER_FRAME)
			{
				//Wait remaining time
				SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
			}

		}
	}



	SDL_DestroyTexture(texture);
	texture = NULL;
	//Deallocate surface
	SDL_FreeSurface(windowSurface);
	windowSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}