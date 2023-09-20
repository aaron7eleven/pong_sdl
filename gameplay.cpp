#pragma once
#include "gameplay.h"
#include "collisions.h"

void init(gameplay* gameplay) {

}

void processInput(inputs* inputs, gameplay* gameplay) {
	processInput(inputs, &gameplay->leftPaddle);
	processInput(inputs, &gameplay->rightPaddle);
	//render(renderer, &gameplay->leftWall);
	//render(renderer, &gameplay->rightWall);
	//render(renderer, &gameplay->topWall);
	//render(renderer, &gameplay->bottomWall);
}

void update(float deltaTime, inputs* inputs, gameplay* gameplay) {

	if (checkCollision(gameplay->leftPaddle.rectCollider, gameplay->bottomWall.rectCollider)) {
		// Undo Move
		gameplay->leftPaddle.rectCollider.y -= gameplay->leftPaddle.velocity * gameplay->leftPaddle.speed * deltaTime;
	}

	if (checkCollision(gameplay->leftPaddle.rectCollider, gameplay->topWall.rectCollider)) {
		// Undo Move
		gameplay->leftPaddle.rectCollider.y += gameplay->leftPaddle.velocity * gameplay->leftPaddle.speed * deltaTime;
	}

	if (checkCollision(gameplay->rightPaddle.rectCollider, gameplay->bottomWall.rectCollider)) {
		// Undo Move
		gameplay->rightPaddle.rectCollider.y -= gameplay->rightPaddle.velocity * gameplay->rightPaddle.speed * deltaTime;
	}

	if (checkCollision(gameplay->rightPaddle.rectCollider, gameplay->topWall.rectCollider)) {
		// Undo Move
		gameplay->rightPaddle.rectCollider.y += gameplay->rightPaddle.velocity * gameplay->rightPaddle.speed * deltaTime;
	}
}

void render(SDL_Renderer* renderer, gameplay* gameplay) {
	render(renderer, &gameplay->leftPaddle);
	render(renderer, &gameplay->rightPaddle);
	render(renderer, &gameplay->leftWall);
	render(renderer, &gameplay->rightWall);
	render(renderer, &gameplay->topWall);
	render(renderer, &gameplay->bottomWall);

}