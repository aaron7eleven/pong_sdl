#pragma once
#include <SDL.h>
#include "app.h"
#include "ball.h"
#include "collisions.h"

void update(app* app, ball* ball) {
	if (app->resettingBall) {
		if (app->resetBallTimer >= app->timeToResetBall) {
			app->resettingBall = false; // move next frame
			app->resetBallTimer = 0.0f;
		}
		else {
			app->resetBallTimer += app->deltaTime;
		}
	}
	else {
		// Move ball
		ball->circleCollider.center.y += ball->velocity.y * ball->speed * app->deltaTime; // Moving Y
		ball->circleCollider.center.x += ball->velocity.x * ball->speed * app->deltaTime; // Moving X
	}

	/////////////////////////
	// Ball Collision
	/////////////////////////

	// Vertical Walls
	if (checkCollision(ball->circleCollider, app->topWall.rectCollider)) {
		ball->velocity.y = -ball->velocity.y;
		ball->circleCollider.center.y += ball->velocity.y * ball->speed * app->deltaTime; // Moving down
	}
	else if (checkCollision(ball->circleCollider, app->bottomWall.rectCollider)) {
		ball->velocity.y = -ball->velocity.y;
		ball->circleCollider.center.y += ball->velocity.y * ball->speed * app->deltaTime; // Moving down
	}

	// Horizontal Walls
	if (checkCollision(ball->circleCollider, app->leftWall.rectCollider)) {
		ball->velocity.x = -ball->velocity.x;
		ball->circleCollider.center.x += ball->velocity.x * ball->speed * app->deltaTime; // Moving down

		// Resetting ball
		ball->circleCollider.center = app->ballInitTransform;

		if (rand() % 2) {
			ball->velocity.x = -ball->velocity.x;
		}

		if (rand() % 2) {
			ball->velocity.y = -ball->velocity.y;
		}

		app->resettingBall = true;
		//rightScore++;
		//rightScoreChanged = true;
	}
	else if (checkCollision(ball->circleCollider, app->rightWall.rectCollider)) {
		ball->velocity.x = -ball->velocity.x;
		ball->circleCollider.center.x += ball->velocity.x * ball->speed * app->deltaTime; // Moving down

		// Resetting ball
		ball->circleCollider.center = app->ballInitTransform;

		if (rand() % 2) {
			ball->velocity.x = -ball->velocity.x;
		}

		if (rand() % 2) {
			ball->velocity.y = -ball->velocity.y;
		}

		app->resettingBall = true;
		//leftScore++;
		//leftScoreChanged = true;
	}


	// Left Paddles
	if (checkCollision(ball->circleCollider,app->leftPaddle.rectCollider)) {
		bool ballAbovePaddle = ball->circleCollider.center.y <= app->leftPaddle.rectCollider.y;
		bool ballBelowPaddle = ball->circleCollider.center.y >= app->leftPaddle.rectCollider.y + app->leftPaddle.height;

		// Check ball hit vertical ends of paddle
		if (ballAbovePaddle || ballBelowPaddle) {
			ball->velocity.y = -ball->velocity.y;
		}
		else {
			ball->velocity.x = -ball->velocity.x;
			ball->circleCollider.center.x += ball->velocity.x * ball->speed * app->deltaTime;
		}
	}

	// Right Paddle
	if (checkCollision(ball->circleCollider, app->rightPaddle.rectCollider)) {
		bool ballAbovePaddle = ball->circleCollider.center.y <= app->rightPaddle.rectCollider.y;
		bool ballBelowPaddle = ball->circleCollider.center.y >= app->rightPaddle.rectCollider.y + app->rightPaddle.height;

		// Check ball hit vertical ends of paddle
		if (ballAbovePaddle || ballBelowPaddle) {
			ball->velocity.y = -ball->velocity.y;
		}
		else {
			ball->velocity.x = -ball->velocity.x;
			ball->circleCollider.center.x += ball->velocity.x * ball->speed * app->deltaTime;
		}
	}
}