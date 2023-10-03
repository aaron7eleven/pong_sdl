#pragma once
#include "SDL_mixer.h"
#include "gameplay.h"
#include "collisions.h"
#include "sfx.h"
#include "math.h"

void init(gameplay* gameplay) {
	init(&gameplay->ball);
	init(&gameplay->leftPaddle);
	init(&gameplay->rightPaddle);
	init(&gameplay->leftScoreText);
	init(&gameplay->rightScoreText);

	gameplay->win = false;
	gameplay->quit = false;
	gameplay->leftScore = 0;
	gameplay->leftScoreChanged = false;
	gameplay->rightScore = 0;
	gameplay->rightScoreChanged = false;
	setText(&gameplay->leftScoreText, std::to_string(gameplay->leftScore));
	setText(&gameplay->rightScoreText, std::to_string(gameplay->rightScore));

	gameplay->leftPaddle.rectCollider.x = gameplay->leftPaddleInitX;
	gameplay->leftPaddle.rectCollider.y = gameplay->leftPaddleInitY;

	gameplay->rightPaddle.rectCollider.x = gameplay->rightPaddleInitX;
	gameplay->rightPaddle.rectCollider.y = gameplay->rightPaddleInitY;

	gameplay->ball.circleCollider.center.x = gameplay->ballInitX;
	gameplay->ball.circleCollider.center.y = gameplay->ballInitY;
	
	gameplay->ball.velocity = gameplay->ballInitVelocity;

	if (rand() % 2) {
		gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
	}

	if (rand() % 2) {
		gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
	}

	gameplay->ball.velocity = normalize(gameplay->ball.velocity);
	gameplay->ball.velocity.x *= 0.5f;
	gameplay->ball.velocity.y *= 0.5f;
}

void processInput(inputs* inputs, gameplay* gameplay) {
	processInput(inputs, &gameplay->leftPaddle);
	processInput(inputs, &gameplay->rightPaddle);

	if (inputs->e.key.keysym.sym == SDLK_ESCAPE) {
		gameplay->quit = true;
		play(gameplay->audioManager, &gameplay->audioManager->uiSelect);
	}
}

void preUpdate(gameplay* gameplay) {
	preUpdate(&gameplay->leftPaddle);
	preUpdate(&gameplay->rightPaddle);
}

void update(float deltaTime, inputs* inputs, gameplay* gameplay) {

	update(deltaTime, inputs, &gameplay->leftPaddle);
	update(deltaTime, inputs, &gameplay->rightPaddle);
	update(deltaTime, inputs, &gameplay->ball);
	
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
		gameplay->ball.circleCollider.center.y += gameplay->ball.velocity.y * gameplay->ball.speed * deltaTime; // Moving down1
		play(gameplay->audioManager, &gameplay->audioManager->ballHit);
	}
	else if (checkCollision(gameplay->ball.circleCollider, gameplay->bottomWall.rectCollider)) {
		gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
		gameplay->ball.circleCollider.center.y += gameplay->ball.velocity.y * gameplay->ball.speed * deltaTime; // Moving down
		play(gameplay->audioManager, &gameplay->audioManager->ballHit);
	}

	// Horizontal Walls
	if (checkCollision(gameplay->ball.circleCollider, gameplay->leftWall.rectCollider)) {
		gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
		//gameplay->ball.circleCollider.center.x += gameplay->ball.velocity.x * gameplay->ball.speed * deltaTime; // Moving down

		// Resetting ball
		gameplay->ball.circleCollider.center = gameplay->ballInitTransform;
		//gameplay->ball.velocity.x = 0.5f;
		//gameplay->ball.velocity.y = 0.5f;
		gameplay->ball.velocity = gameplay->ballInitVelocity;

		if (rand() % 2) {
			gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
		}

		if (rand() % 2) {
			gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
		}

		gameplay->ball.velocity = normalize(gameplay->ball.velocity);
		gameplay->ball.velocity.x *= 0.5f;
		gameplay->ball.velocity.y *= 0.5f;
		gameplay->ball.reset = true;
		gameplay->rightScore++;
		setText(&gameplay->rightScoreText, std::to_string(gameplay->rightScore));
	}
	else if (checkCollision(gameplay->ball.circleCollider, gameplay->rightWall.rectCollider)) {
		gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
		//gameplay->ball.circleCollider.center.x += gameplay->ball.velocity.x * gameplay->ball.speed * deltaTime; // Moving down

		// Resetting ball
		gameplay->ball.circleCollider.center = gameplay->ballInitTransform;
		//gameplay->ball.velocity.x = 0.5f;
		//gameplay->ball.velocity.y = 0.5f;
		gameplay->ball.velocity = gameplay->ballInitVelocity;

		if (rand() % 2) {
			gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
		}

		if (rand() % 2) {
			gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
		}

		gameplay->ball.velocity = normalize(gameplay->ball.velocity);
		gameplay->ball.velocity.x *= 0.5f;
		gameplay->ball.velocity.y *= 0.5f;
		gameplay->ball.reset = true;
		gameplay->leftScore++;
		setText(&gameplay->leftScoreText, std::to_string(gameplay->leftScore));
	}


	// Left Paddles
	if (checkCollision(gameplay->ball.circleCollider, gameplay->leftPaddle.rectCollider)) {
		// ball is moving left and approaching paddle from right
		bool ballAbovePaddle = gameplay->ball.circleCollider.center.y < gameplay->leftPaddle.rectCollider.y;
		bool ballBelowPaddle = gameplay->ball.circleCollider.center.y > gameplay->leftPaddle.rectCollider.y + gameplay->leftPaddle.height;

		bool ballLeftOfPaddle = gameplay->ball.circleCollider.center.x < gameplay->leftPaddle.rectCollider.x;
		bool ballRightOfPaddle = gameplay->ball.circleCollider.center.x > gameplay->leftPaddle.rectCollider.x + gameplay->leftPaddle.width;

		float halfPaddleHeight = (gameplay->leftPaddle.height / 2.0f);
		// + -> Ball above paddle center, - -> Ball below paddle center
		float yBallToPaddleCenterDiff = (gameplay->leftPaddle.rectCollider.y + halfPaddleHeight) - gameplay->ball.circleCollider.center.y;

		// Check ball hit vertical ends of paddle
		if (ballAbovePaddle || ballBelowPaddle) {
			if (ballRightOfPaddle) {
				//hit corner
				gameplay->ball.velocity.y = yBallToPaddleCenterDiff >= 0.0f ? -0.5f : 0.5f;
				gameplay->ball.velocity.x = 0.5f;
				gameplay->ball.velocity = normalize(gameplay->ball.velocity);
				gameplay->ball.circleCollider.center.y += gameplay->ball.velocity.y * gameplay->ball.speed * deltaTime;
				gameplay->ball.circleCollider.center.x += gameplay->ball.velocity.x * gameplay->ball.speed * deltaTime;
			}
			else {
				// hit top -> flip y
				gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
				gameplay->ball.velocity = normalize(gameplay->ball.velocity);
				gameplay->ball.circleCollider.center.y += gameplay->ball.velocity.y * gameplay->ball.speed * deltaTime;
			}
		}
		else {
			// Hit side -> Angle dependent on where ball hit paddle on y
			// greater diff -> higher the angle			
			gameplay->ball.velocity.y = -0.5f * (yBallToPaddleCenterDiff / halfPaddleHeight);
			gameplay->ball.velocity.x = 0.5f + 0.5f * (1.0f - abs((yBallToPaddleCenterDiff / halfPaddleHeight)));
			//gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
			gameplay->ball.velocity = normalize(gameplay->ball.velocity);

			gameplay->ball.circleCollider.center.y += gameplay->ball.velocity.y * gameplay->ball.speed * deltaTime;
			gameplay->ball.circleCollider.center.x += gameplay->ball.velocity.x * gameplay->ball.speed * deltaTime;
		}

		play(gameplay->audioManager, &gameplay->audioManager->ballHit);
	}

	// Right Paddle
	if (checkCollision(gameplay->ball.circleCollider, gameplay->rightPaddle.rectCollider)) {
		// ball is moving right and approaching paddle from left
		bool ballAbovePaddle = gameplay->ball.circleCollider.center.y < gameplay->rightPaddle.rectCollider.y;
		bool ballBelowPaddle = gameplay->ball.circleCollider.center.y > gameplay->rightPaddle.rectCollider.y + gameplay->rightPaddle.height;

		bool ballLeftOfPaddle = gameplay->ball.circleCollider.center.x < gameplay->rightPaddle.rectCollider.x;
		bool ballRightOfPaddle = gameplay->ball.circleCollider.center.x > gameplay->rightPaddle.rectCollider.x + gameplay->rightPaddle.width;

		float halfPaddleHeight = (gameplay->rightPaddle.height / 2.0f);
		// + -> Ball above paddle center, - -> Ball below paddle center
		float yBallToPaddleCenterDiff = (gameplay->rightPaddle.rectCollider.y + halfPaddleHeight) - gameplay->ball.circleCollider.center.y;

		// Check ball hit vertical ends of paddle
		if (ballAbovePaddle || ballBelowPaddle) {
			if (ballLeftOfPaddle) {
				//hit corner
				gameplay->ball.velocity.y = yBallToPaddleCenterDiff >= 0.0f ? -0.5f : 0.5f;
				gameplay->ball.velocity.x = -0.5f;
				gameplay->ball.velocity = normalize(gameplay->ball.velocity);
				gameplay->ball.circleCollider.center.y += gameplay->ball.velocity.y * gameplay->ball.speed * deltaTime;
				gameplay->ball.circleCollider.center.x += gameplay->ball.velocity.x * gameplay->ball.speed * deltaTime;
			}
			else {
				// hit top -> flip y
				gameplay->ball.velocity.y = -gameplay->ball.velocity.y;
				gameplay->ball.velocity = normalize(gameplay->ball.velocity);
				gameplay->ball.circleCollider.center.y += gameplay->ball.velocity.y * gameplay->ball.speed * deltaTime;
			}
		}
		else {
			// Hit side -> Angle dependent on where ball hit paddle on y
			// greater diff -> higher the angle			
			gameplay->ball.velocity.y = -0.5f * (yBallToPaddleCenterDiff / halfPaddleHeight);
			gameplay->ball.velocity.x = 0.5f + 0.5f * (1.0f - abs((yBallToPaddleCenterDiff / halfPaddleHeight)));
			gameplay->ball.velocity.x = -gameplay->ball.velocity.x;
			gameplay->ball.velocity = normalize(gameplay->ball.velocity);

			gameplay->ball.circleCollider.center.y += gameplay->ball.velocity.y * gameplay->ball.speed * deltaTime;
			gameplay->ball.circleCollider.center.x += gameplay->ball.velocity.x * gameplay->ball.speed * deltaTime;
		}
		play(gameplay->audioManager, &gameplay->audioManager->ballHit);
	}

	if (gameplay->leftScore >= gameplay->scoreToWin) {
		gameplay->win = true;
	}
	else if (gameplay->rightScore >= gameplay->scoreToWin) {
		gameplay->win = true;
	}

}

void render(SDL_Renderer* renderer, gameplay* gameplay) {
	render(renderer, &gameplay->leftPaddle);
	render(renderer, &gameplay->rightPaddle);
	render(renderer, &gameplay->leftWall);
	render(renderer, &gameplay->rightWall);
	render(renderer, &gameplay->topWall);
	render(renderer, &gameplay->bottomWall);
	render(renderer, &gameplay->leftScoreText);
	render(renderer, &gameplay->rightScoreText);
	render(renderer, &gameplay->ball);
}

void free(gameplay* gameplay) {
	//free(&gameplay->leftPaddle);
	//free(&gameplay->rightPaddle);
	//free(&gameplay->leftWall);
	//free(&gameplay->rightWall);
	//free(&gameplay->topWall);
	//free(&gameplay->bottomWall);
	free(&gameplay->leftScoreText);
	free(&gameplay->rightScoreText);
	//free(&gameplay->ball);
}