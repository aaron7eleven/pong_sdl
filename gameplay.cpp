#pragma once
#include "gameplay.h"
#include "collisions.h"

void init(gameplay* gameplay) {
	init(&gameplay->leftScore);
	init(&gameplay->rightScore);

	setText(&gameplay->leftScore, std::to_string(0));
	setText(&gameplay->rightScore, std::to_string(0));
}

void processInput(inputs* inputs, gameplay* gameplay) {
	processInput(inputs, &gameplay->leftPaddle);
	processInput(inputs, &gameplay->rightPaddle);
	//render(renderer, &gameplay->leftWall);
	//render(renderer, &gameplay->rightWall);
	//render(renderer, &gameplay->topWall);
	//render(renderer, &gameplay->bottomWall);
}

void preUpdate(gameplay* gameplay) {
	preUpdate(&gameplay->leftPaddle);
	preUpdate(&gameplay->rightPaddle);
}

void update(float deltaTime, inputs* inputs, gameplay* gameplay) {

	update(deltaTime, inputs, &gameplay->leftPaddle);
	update(deltaTime, inputs, &gameplay->rightPaddle);
	
	if (checkCollision(gameplay->leftPaddle.rectCollider, gameplay->bottomWall.rectCollider)) {
		// Undo Move
		gameplay->leftPaddle.rectCollider.y -= gameplay->leftPaddle.velocity * gameplay->leftPaddle.speed * deltaTime;
	}

	if (checkCollision(gameplay->leftPaddle.rectCollider, gameplay->topWall.rectCollider)) {
		// Undo Move
		gameplay->leftPaddle.rectCollider.y -= gameplay->leftPaddle.velocity * gameplay->leftPaddle.speed * deltaTime;
	}

	if (checkCollision(gameplay->rightPaddle.rectCollider, gameplay->bottomWall.rectCollider)) {
		// Undo Move
		gameplay->rightPaddle.rectCollider.y -= gameplay->rightPaddle.velocity * gameplay->rightPaddle.speed * deltaTime;
	}

	if (checkCollision(gameplay->rightPaddle.rectCollider, gameplay->topWall.rectCollider)) {
		// Undo Move
		gameplay->rightPaddle.rectCollider.y = gameplay->rightPaddle.velocity * gameplay->rightPaddle.speed * deltaTime;
	}

	/////////////////////////
	// Ball Collision
	/////////////////////////

	// Vertical Walls
	if (checkCollision(gameplay->ball.circleCollider, gameplay->topWall.rectCollider)) {
		gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
		gameplay->ball.circleCollider.center.y += gameplay->ball.velocity.y * gameplay->ball.speed * deltaTime; // Moving down
	}
	else if (checkCollision(gameplay->ball.circleCollider, gameplay->bottomWall.rectCollider)) {
		gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
		gameplay->ball.circleCollider.center.y += gameplay->ball.velocity.y * gameplay->ball.speed * deltaTime; // Moving down
	}

	// Horizontal Walls
	if (checkCollision(gameplay->ball.circleCollider, gameplay->leftWall.rectCollider)) {
		gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
		gameplay->ball.circleCollider.center.x += gameplay->ball.velocity.x * gameplay->ball.speed * deltaTime; // Moving down

		// Resetting ball
		gameplay->ball.circleCollider.center = gameplay->ballInitTransform;

		if (rand() % 2) {
			gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
		}

		if (rand() % 2) {
			gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
		}

		gameplay->resettingBall = true;
		//rightScore++;
		//rightScoreChanged = true;
	}
	else if (checkCollision(gameplay->ball.circleCollider, gameplay->rightWall.rectCollider)) {
		gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
		gameplay->ball.circleCollider.center.x += gameplay->ball.velocity.x * gameplay->ball.speed * deltaTime; // Moving down

		// Resetting ball
		gameplay->ball.circleCollider.center = gameplay->ballInitTransform;

		if (rand() % 2) {
			gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
		}

		if (rand() % 2) {
			gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
		}

		gameplay->resettingBall = true;
		//leftScore++;
		//leftScoreChanged = true;
	}


	// Left Paddles
	if (checkCollision(gameplay->ball.circleCollider, gameplay->leftPaddle.rectCollider)) {
		bool ballAbovePaddle = gameplay->ball.circleCollider.center.y <= gameplay->leftPaddle.rectCollider.y;
		bool ballBelowPaddle = gameplay->ball.circleCollider.center.y >= gameplay->leftPaddle.rectCollider.y + gameplay->leftPaddle.height;

		// Check ball hit vertical ends of paddle
		if (ballAbovePaddle || ballBelowPaddle) {
			gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
		}
		else {
			gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
			gameplay->ball.circleCollider.center.x += gameplay->ball.velocity.x * gameplay->ball.speed * deltaTime;
		}
	}

	// Right Paddle
	if (checkCollision(gameplay->ball.circleCollider, gameplay->rightPaddle.rectCollider)) {
		bool ballAbovePaddle = gameplay->ball.circleCollider.center.y <= gameplay->rightPaddle.rectCollider.y;
		bool ballBelowPaddle = gameplay->ball.circleCollider.center.y >= gameplay->rightPaddle.rectCollider.y + gameplay->rightPaddle.height;

		// Check ball hit vertical ends of paddle
		if (ballAbovePaddle || ballBelowPaddle) {
			gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
		}
		else {
			gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
			gameplay->ball.circleCollider.center.x += gameplay->ball.velocity.x * gameplay->ball.speed * deltaTime;
		}
	}

	//if (leftScoreChanged) {
//	// Update texture
//	leftTextTexture = LoadTextTexture(renderer, font, std::to_string(leftScore), textColor);
//	leftScoreChanged = false;
//}

//if (rightScoreChanged) {
//	// Update texture
//	rightTextTexture = LoadTextTexture(renderer, font, std::to_string(rightScore), textColor);
//	rightScoreChanged = false;
//}
}

void render(SDL_Renderer* renderer, gameplay* gameplay) {
	render(renderer, &gameplay->leftPaddle);
	render(renderer, &gameplay->rightPaddle);
	render(renderer, &gameplay->leftWall);
	render(renderer, &gameplay->rightWall);
	render(renderer, &gameplay->topWall);
	render(renderer, &gameplay->bottomWall);
	render(renderer, &gameplay->leftScore);
	render(renderer, &gameplay->rightScore);
	render(renderer, &gameplay->ball);

}