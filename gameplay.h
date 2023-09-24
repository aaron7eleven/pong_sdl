#pragma once
#include <iostream>
#include <SDL.h>
#include "paddle.h"
#include "paddleController.h"
#include "wall.h"
#include "ball.h"
#include "ui.h"

struct gameplay {
	bool win = false;
	int scoreToWin = 9;
	int leftScore = 0;
	bool leftScoreChanged = false;
	int rightScore = 0;
	bool rightScoreChanged = false;

	float paddleWidth = 20; // screenWidth / 64
	float paddleHeight = 90; // screenHeight / 8
	float paddleSpeed = 300;

	float leftPaddleInitX = 160; // screenWidth / 8
	float leftPaddleInitY = 360; // screenHeight / 2

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


	//float rightPaddleInitX = screenWidth - (screenWidth / 8);
	//float rightPaddleInitY = screenHeight / 2;
	float rightPaddleInitX = 1280 - (1280/ 8); // screenWidth - (screenWidth / 8);
	float rightPaddleInitY = 720 / 2; // screenHeight / 2

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
	float horzWallWidth = 10; // screenWidth / 128
	float horzWallHeight = 720; // screenHeight
	float leftWallX = 1280 / 16; // screenWidth / 16
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


	float rightWallX = 1280 * 15 / 16; // screenWidth * 15 / 16
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

	float vertWallWidth = 1280; // screenWidth
	float vertWallHeight = 1280 / 128; // screenWidth / 128
	float topWallX = 0; // Starts at top left corner not center (0 not screenWidth / 2)
	float topWallY = -vertWallHeight;
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
	//float bottomWallY = 720 - vertWallHeight * 2.0f; // Move above the bottom edge of window // screenHeight - vertWallHeight * 2.0f
	float bottomWallY = 720; // Move above the bottom edge of window // screenHeight - vertWallHeight * 2.0f
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


	float ballRadius = 1280 / 64; // Same width as paddle // screenWidth / 64
	float ballInitX = 1280 / 2; // screenWidth / 2
	float ballInitY = 720 / 2; // screenHeight / 2
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

	float scoreTextWidth = 1280 / 32; // screenWidth / 32
	float scoreTextHeight = 720 / 8; // Same Height as paddle // screenHeight / 8
	float scoreTextXOffset = 1280 / 16; // screenWidth / 16
	float scoreTextYOffset = 1280 / 64; // screenWidth / 64

	float leftScoreTextX = (1280 / 2) - scoreTextWidth - scoreTextXOffset; // (screenWidth / 2) - scoreTextWidth - scoreTextXOffset
	float leftScoreTextY = scoreTextYOffset;

	uiText leftScoreText = {
		"leftScore",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		{leftScoreTextX, leftScoreTextY, scoreTextWidth, scoreTextHeight},
		white,
		NULL,
		false
	};

	float rightScoreTextX = (1280 / 2) + scoreTextXOffset; // (screenWidth / 2) + scoreTextXOffset
	float rightScoreTextY = scoreTextYOffset;

	uiText rightScoreText = {
		"rightScore",
		NULL,
		"assets/font/DotGothic16-Regular.ttf",
		100,
		{rightScoreTextX, rightScoreTextY, scoreTextWidth, scoreTextHeight},
		white,
		NULL,
		false
	};
};

void init(gameplay* gameplay);
void processInput(inputs* inputs, gameplay* gameplay);
void preUpdate(gameplay* gameplay);
void update(float deltaTime, inputs* inputs, gameplay* gameplay);
void render(SDL_Renderer* renderer, gameplay* gameplay);