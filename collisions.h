#pragma once
#include "rectCollider.h"
#include "circleCollider.h"

bool checkCollision(SDL_FRect aRect, SDL_FRect bRect);
bool checkCollision(circleCollider& circle, SDL_FRect rect);

