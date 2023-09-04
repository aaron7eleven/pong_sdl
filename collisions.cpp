#pragma once
#include "collisions.h"
#include "math.h"
bool checkCollision(SDL_FRect a, SDL_FRect b)
{
	
	float leftA;
	float rightA;
	float leftB;
	float rightB;

	float topA;
	float bottomA;
	float topB;
	float bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;

};

bool checkCollision(circleCollider& circleCollider, SDL_FRect rect)
{
	SDL_FPoint circle = circleCollider.center;
	
	float circleX;
	float circleY;

	// Find closest X position to Rect b from Circle's position
	// Circle is to the left of b
	if (circle.x < rect.x) {
		circleX = rect.x;
	}
	// Circle is to the right of b
	else if (circle.x > (rect.x + rect.w)) {
		circleX = rect.x + rect.w;
	}
	// Circle is inside of b
	else {
		circleX = circle.x;
	}

	// Same for Y (Same code as above)
	// Circle is to the above of b 
	if (circle.y < rect.y) {
		circleY = rect.y;
	}
	// Circle is to the below of b
	else if (circle.y > (rect.y + rect.h)) {
		circleY = rect.y + rect.h;
	}
	// Circle is inside of b
	else {
		circleY = circle.y;
	}

	if (DistanceSquared(circle.x, circle.y, circleX, circleY) < (circleCollider.radius * circleCollider.radius)) {
		// Colliding
		return true;
	}

	// Not colliding
	return false;

};