#pragma once
#include <SDL.h>
#include "mainMenu.h"

struct game {
	//app* app;
	mainMenu mainMenu;

	//gameState gameState = gameState::GAME;

	//float paddleWidth = screenWidth / 64;
	//float paddleHeight = screenHeight / 8;
	//float paddleSpeed = 300;

	//float leftPaddleInitX = screenWidth / 8;
	//float leftPaddleInitY = screenHeight / 2;

	//paddleController leftPaddleController = {
	//	SDL_SCANCODE_W,
	//	false,
	//	SDL_SCANCODE_S,
	//	false
	//};

	//paddle leftPaddle = {
	//	paddleWidth,
	//	paddleHeight,
	//	paddleSpeed,
	//	0.0f,
	//	{leftPaddleInitX, leftPaddleInitY},
	//	{leftPaddleInitX, leftPaddleInitY, paddleWidth, paddleHeight},
	//	white,
	//	leftPaddleController
	//};


	//float rightPaddleInitX = screenWidth - (screenWidth / 8);
	//float rightPaddleInitY = screenHeight / 2;

	//paddleController rightPaddleController = {
	//	SDL_SCANCODE_UP,
	//	false,
	//	SDL_SCANCODE_DOWN,
	//	false
	//};
	//paddle rightPaddle = {
	//	paddleWidth,
	//	paddleHeight,
	//	paddleSpeed,
	//	0.0f,
	//	{rightPaddleInitX, rightPaddleInitY},
	//	{rightPaddleInitX, rightPaddleInitY, paddleWidth, paddleHeight},
	//	white,
	//	rightPaddleController
	//};

	//SDL_Color wallColor = white;
	//float horzWallWidth = screenWidth / 128;
	//float horzWallHeight = screenHeight;
	//float leftWallX = screenWidth / 16;
	//float leftWallY = 0; // Starts at top left corner not center (0 not screenHeight / 2)
	//SDL_FRect	leftWallRectTranform = {
	//	leftWallX,
	//	leftWallY,
	//	horzWallWidth,
	//	horzWallHeight
	//};

	//wall leftWall = {
	//	leftWallRectTranform,
	//	white
	//};


	//float rightWallX = screenWidth * 15 / 16;
	//float rightWallY = 0; // Starts at top left corner not center (0 not screenHeight / 2)
	//SDL_FRect	rightWallRectTranform = {
	//	rightWallX,
	//	rightWallY,
	//	horzWallWidth,
	//	horzWallHeight
	//};

	//wall rightWall = {
	//	rightWallRectTranform,
	//	white
	//};

	//float vertWallWidth = screenWidth;
	//float vertWallHeight = screenWidth / 128;
	//float topWallX = 0; // Starts at top left corner not center (0 not screenWidth / 2)
	//float topWallY = vertWallHeight;
	//SDL_FRect topWallRectTransform = {
	//	topWallX,
	//	topWallY,
	//	vertWallWidth,
	//	vertWallHeight
	//};

	//wall topWall = {
	//	topWallRectTransform,
	//	white
	//};

	//float bottomWallX = 0; // Starts at top left corner not center (0 not screenWidth / 2)
	//float bottomWallY = screenHeight - vertWallHeight * 2.0f; // Move above the bottom edge of window
	//SDL_FRect bottomWallRectTransform = {
	//	bottomWallX,
	//	bottomWallY,
	//	vertWallWidth,
	//	vertWallHeight
	//};

	//wall bottomWall = {
	//	bottomWallRectTransform,
	//	white
	//};


	//float ballRadius = screenWidth / 64; // Same width as paddle
	//float ballInitX = screenWidth / 2;
	//float ballInitY = screenHeight / 2;
	//float ballSpeed = 600;
	//SDL_FPoint ballInitTransform = { ballInitX, ballInitY };
	//SDL_FPoint ballInitVelocity = { 0.5f, 0.5f };
	//circleCollider ballCollider = {
	//	ballInitTransform,
	//	ballRadius
	//};

	//ball ball = {
	//	ballInitTransform,
	//	white,
	//	ballCollider,
	//	ballInitVelocity
	//};

	//float resetBallTimer = 0.0f;
	//float timeToResetBall = 1.0f;
	//bool resettingBall = false;

	//float scoreTextWidth = screenWidth / 32;
	//float scoreTextHeight = screenHeight / 8; // Same Height as paddle
	//float scoreTextXOffset = screenWidth / 16;
	//float scoreTextYOffset = screenWidth / 16;

	//float leftScoreTextX = (screenWidth / 2) - scoreTextWidth - scoreTextXOffset;
	//float leftScoreTextY = scoreTextYOffset;

	//float rightScoreTextX = (screenWidth / 2) + scoreTextXOffset;
	//float rightScoreTextY = scoreTextYOffset;

	//
};

void init(game* game);
void update(float deltaTime, const Uint8* keyStates, game* game);
void render(SDL_Renderer* renderer, game* game);