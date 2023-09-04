#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "color.h"
#include "paddle.h"
#include "paddleController.h"
#include "wall.h"
#include "ball.h"
#include "appState.h"

struct app {
	SDL_Window* window = NULL;
	SDL_Surface* windowSurface = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* texture = NULL;
	TTF_Font* font = NULL;
	SDL_Color textColor = { 255, 255, 255, 255 }; // white
	int fontPointSize = 100;

	float deltaTime = 0.0f;
	Uint32 startTicks = SDL_GetTicks();
	Uint32 lastTicks = 0;

	SDL_Event e;
	const Uint8* keyStates;
	
	bool quit = false;
	appState gameState = appState::GAME;

	int screenWidth = 1280;
	int screenHeight = 720;
	int fps = 60;
	int ticksPerFrame = 1000 / fps; // 1000 ms / X frames

	float paddleWidth = screenWidth / 64;
	float paddleHeight = screenHeight / 8;
	float paddleSpeed = 300;

	float leftPaddleInitX = screenWidth / 8;
	float leftPaddleInitY = screenHeight / 2;

	paddleController leftPaddleController = {
		SDL_SCANCODE_W,
		false,
		SDL_SCANCODE_S,
		false
	};

	paddle leftPaddle = {
		paddleWidth,
		paddleHeight,
		paddleSpeed,
		0.0f,
		{leftPaddleInitX, leftPaddleInitY},
		{leftPaddleInitX, leftPaddleInitY, paddleWidth, paddleHeight},
		white,
		leftPaddleController
	};


	float rightPaddleInitX = screenWidth - (screenWidth / 8);
	float rightPaddleInitY = screenHeight / 2;

	paddleController rightPaddleController = {
		SDL_SCANCODE_UP,
		false,
		SDL_SCANCODE_DOWN,
		false
	};
	paddle rightPaddle = {
		paddleWidth,
		paddleHeight,
		paddleSpeed,
		0.0f,
		{rightPaddleInitX, rightPaddleInitY},
		{rightPaddleInitX, rightPaddleInitY, paddleWidth, paddleHeight},
		white,
		rightPaddleController
	};

	SDL_Color wallColor = white;
	float horzWallWidth = screenWidth / 128;
	float horzWallHeight = screenHeight;
	float leftWallX = screenWidth / 16;
	float leftWallY = 0; // Starts at top left corner not center (0 not screenHeight / 2)
	SDL_FRect	leftWallRectTranform = {
		leftWallX,
		leftWallY,
		horzWallWidth,
		horzWallHeight
	};
	
	wall leftWall = {
		leftWallRectTranform,
		white
	};


	float rightWallX = screenWidth * 15 / 16;
	float rightWallY = 0; // Starts at top left corner not center (0 not screenHeight / 2)
	SDL_FRect	rightWallRectTranform = {
		rightWallX,
		rightWallY,
		horzWallWidth,
		horzWallHeight
	};

	wall rightWall = {
		rightWallRectTranform,
		white
	};
	
	float vertWallWidth = screenWidth;
	float vertWallHeight = screenWidth / 128;
	float topWallX = 0; // Starts at top left corner not center (0 not screenWidth / 2)
	float topWallY = vertWallHeight;
	SDL_FRect topWallRectTransform = {
		topWallX,
		topWallY,
		vertWallWidth,
		vertWallHeight
	};

	wall topWall = {
		topWallRectTransform,
		white
	};

	float bottomWallX = 0; // Starts at top left corner not center (0 not screenWidth / 2)
	float bottomWallY = screenHeight - vertWallHeight * 2.0f; // Move above the bottom edge of window
	SDL_FRect bottomWallRectTransform = {
		bottomWallX,
		bottomWallY,
		vertWallWidth,
		vertWallHeight
	};

	wall bottomWall = {
		bottomWallRectTransform,
		white
	};


	float ballRadius = screenWidth / 64; // Same width as paddle
	float ballInitX = screenWidth / 2;
	float ballInitY = screenHeight / 2;
	float ballSpeed = 600;
	SDL_FPoint ballInitTransform = { ballInitX, ballInitY };
	SDL_FPoint ballInitVelocity = { 0.5f, 0.5f };
	circleCollider ballCollider = {
		ballInitTransform,
		ballRadius
	};

	ball ball = {
		ballInitTransform,
		white,
		ballCollider,
		ballInitVelocity
	};

	float resetBallTimer = 0.0f;
	float timeToResetBall = 1.0f;
	bool resettingBall = false;

	float scoreTextWidth = screenWidth / 32;
	float scoreTextHeight = screenHeight / 8; // Same Height as paddle
	float scoreTextXOffset = screenWidth / 16;
	float scoreTextYOffset = screenWidth / 16;

	float leftScoreTextX = (screenWidth / 2) - scoreTextWidth - scoreTextXOffset;
	float leftScoreTextY = scoreTextYOffset;

	float rightScoreTextX = (screenWidth / 2) + scoreTextXOffset;
	float rightScoreTextY = scoreTextYOffset;

	float		titleWidth = screenWidth / 4;
	float		titleHeight = screenHeight / 4;
	float		titleX = (screenWidth / 2) - titleWidth / 2;
	float		titleY = screenHeight / 16;
	std::string title = "Pong";
	SDL_Color	titleColor = white;
	SDL_FRect	titleRectTranform = {
		titleWidth,
		titleHeight,
		titleX,
		titleY
	};

	float		playButtonWidth = screenWidth / 4;
	float		playButtonHeight = screenHeight / 8;
	float		playButtonX = (screenWidth / 2) - playButtonTextWidth / 2;;
	float		playButtonY = screenHeight * 3 / 8;
	SDL_FRect	playButtonRectTranform = {
		playButtonWidth,
		playButtonHeight,
		playButtonX,
		playButtonY
	};
	SDL_Color	playButtonHighlightedButtonColor = white;
	SDL_Color	playButtonIdleButtonColor = black;
	SDL_Color	playButtonHighlightedTextColor = black;
	SDL_Color	playButtonIdleTextColor = white;
	
	float		playButtonTextWidth = screenWidth / 8;
	float		playButtonTextHeight = screenHeight / 8;
	float		playButtonTextX = playButtonX;
	float		playButtonTextY = playButtonY;
	SDL_FRect	playButtonTextRectTranform = {
		playButtonTextWidth,
		playButtonTextHeight,
		playButtonTextX,
		playButtonTextY
	};
	std::string playButtonText = "Play";
	SDL_Color	playButtonTextColor = playButtonIdleTextColor;

	float		optionsButtonWidth = screenWidth / 4;
	float		optionsButtonHeight = screenHeight / 8;
	float		optionsButtonX = (screenWidth / 2) - optionsButtonWidth / 2;;
	float		optionsButtonY = screenHeight * 4 / 8;
	SDL_FRect	optionsButtonRectTranform = {
		optionsButtonWidth,
		optionsButtonHeight,
		optionsButtonX,
		optionsButtonY
	};
	SDL_Color	optionsButtonHighlightedButtonColor = white;
	SDL_Color	optionsButtonIdleButtonColor = black;
	SDL_Color	optionsButtonHighlightedTextColor = black;
	SDL_Color	optionsButtonIdleTextColor = white;
				
	float		optionsButtonTextWidth = screenWidth / 6;
	float		optionsButtonTextHeight = screenHeight / 8;
	float		optionsButtonTextX = optionsButtonX;
	float		optionsButtonTextY = optionsButtonY;
	SDL_FRect	optionsButtonTextRectTranform = {
		optionsButtonTextWidth,
		optionsButtonTextHeight,
		optionsButtonTextX,
		optionsButtonTextY
	};
	std::string optionsButtonText = "Play";
	SDL_Color	optionsButtonTextColor = optionsButtonIdleTextColor;
	
	float		quitButtonWidth = screenWidth / 4;
	float		quitButtonHeight = screenHeight / 8;
	float		quitButtonX = (screenWidth / 2) - quitButtonWidth / 2;
	float		quitButtonY = screenHeight * 5 / 8;
	SDL_FRect	quitButtonRectTranform = {
				quitButtonWidth,
				quitButtonHeight,
				quitButtonX,
				quitButtonY
	};
	SDL_Color	quitButtonHighlightedButtonColor = white;
	SDL_Color	quitButtonIdleButtonColor = black;
	SDL_Color	quitButtonHighlightedTextColor = black;
	SDL_Color	quitButtonIdleTextColor = white;
				
	float		quitButtonTextWidth = screenWidth / 8;
	float		quitButtonTextHeight = screenHeight / 8;
	float		quitButtonTextX = optionsButtonX;
	float		quitButtonTextY = optionsButtonY;
	SDL_FRect	quitButtonTextRectTranform = {
				quitButtonTextWidth,
				quitButtonTextHeight,
				quitButtonTextX,
				quitButtonTextY
	};
	std::string quitButtonText = "Quit";
	SDL_Color	quitButtonTextColor = optionsButtonIdleTextColor;
};

int init(app* app);
int run(app* app);
int free(app* app);

void preUpdate(app* app);
void update(app* app);
void render(app* app);

void updateGame(app* app );

void updateDeltaTime(app* app);
void getUserInput(app* app);