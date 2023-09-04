#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "stdio.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "app.h"

#include "collisions.h"
#include "color.h"
#include "primitives.h"
#include "ui.h"
#include "vectors.h"
#include "paddle.h"
#include "gameUI.h"
#include "appState.h"

struct uiNavigation {
	int currentIndex = 0;
	int previousIndex = 0;
	uiButton* currentButton;
	uiButton* previousButton;
	uiButton** nav;
	int navLength = 0;
};

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

SDL_Texture* LoadTextTexture(SDL_Renderer* renderer,TTF_Font* font, std::string textureText, SDL_Color textColor) {
	SDL_Texture* outputTexture = NULL;

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str() , textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface (%s)! SDL_TTF Error: %s\n", textureText, TTF_GetError());
	}
	else {
		outputTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (outputTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n",SDL_GetError());
		}
		else {
			// get image dimen
		}
	}

	SDL_FreeSurface(textSurface);

	return outputTexture;
}

// SDL_RenderFillCircle.c
// https://gist.github.com/henkman/1b6f4492b82dc76adad1dc110c923baa
void SDL_RenderFillCircle(SDL_Renderer* rend, float x0, float y0, float radius)
{
	// Uses the midpoint circle algorithm to draw a filled circle
	// https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
	int x = radius;
	int y = 0;
	int radiusError = 1 - x;
	while (x >= y) {
		SDL_RenderDrawLine(rend, x + x0, y + y0, -x + x0, y + y0);
		SDL_RenderDrawLine(rend, y + x0, x + y0, -y + x0, x + y0);
		SDL_RenderDrawLine(rend, -x + x0, -y + y0, x + x0, -y + y0);
		SDL_RenderDrawLine(rend, -y + x0, -x + y0, y + x0, -x + y0);
		y++;
		if (radiusError < 0)
			radiusError += 2 * y + 1;
		else {
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
}

void HighlightUIButton(uiButton* button) {
	// Turn button white
	// Turn text black
	// Set as highlighted
	button->text->color = button->highlightedTextColor;
	button->color = button->highlightedButtonColor;
	button->highlighted = true;
}

void UnhighlightUIButton(uiButton* button) {
	// Turn button black
	// Turn text white
	// unset as highlighted
	button->text->color = button->idleTextColor;
	button->color = button->idleButtonColor;
	button->highlighted = false;
}

void NextUIButton(uiNavigation* uiNavigation) {
	uiNavigation->previousIndex = uiNavigation->currentIndex;
	if (uiNavigation->currentIndex + 1 >= uiNavigation->navLength) {
		uiNavigation->currentIndex = 0;
	}
	else {
		uiNavigation->currentIndex++;
	}
	uiNavigation->previousButton = uiNavigation->nav[uiNavigation->previousIndex];
	uiNavigation->currentButton = uiNavigation->nav[uiNavigation->currentIndex];
	UnhighlightUIButton(uiNavigation->previousButton);
	HighlightUIButton(uiNavigation->currentButton);
}

void PreviousUIButton(uiNavigation* uiNavigation) {
	uiNavigation->previousIndex = uiNavigation->currentIndex;
	if (uiNavigation->currentIndex - 1 < 0) {
		uiNavigation->currentIndex = uiNavigation->navLength - 1;
	}
	else {
		uiNavigation->currentIndex--;
	}
	uiNavigation->previousButton = uiNavigation->nav[uiNavigation->previousIndex];
	uiNavigation->currentButton = uiNavigation->nav[uiNavigation->currentIndex];
	UnhighlightUIButton(uiNavigation->previousButton);
	HighlightUIButton(uiNavigation->currentButton);
}

//void //AssignId(uiButton* button, int* idCount) {
//	printf("Button %s has id %d\n", button->name.c_str(), button->id);
//	button->id = *idCount;
//	(*idCount)++;
//	//*idCount
//}
//
//void //AssignId(uiText* text, int* idCount) {
//	printf("Text %s has id %i\n", text->name.c_str() , text->id);
//	text->id = *idCount;
//	(*idCount)++;
//}

//void StartGame()

int main(int argc, char* argv[])
{
	//int idCount = 0;
	
	//const int app.screenWidth = 1280;
	//const int app.screenHeight = 720;
	//const int SCREEN_FPS = 60;
	//const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS; // 1000 ms / X frames
	app app;

	//uiButton playButton;
	//initPlayButton(&playButton, &app);
	//


	//uiNavigation uiNavigation;
	//uiNavigation.navLength = 3;
	////uiButton* mainMenuButtons[3] = { &playButton, &optionsButton, &quitButton };
	//uiButton* mainMenuButtons[1] = { &playButton};
	//uiNavigation.nav = mainMenuButtons;
	//uiNavigation.currentIndex = 0;
	//uiNavigation.currentButton = uiNavigation.nav[uiNavigation.currentIndex];
	//uiNavigation.previousIndex = 0;
	//uiNavigation.previousButton = uiNavigation.nav[uiNavigation.previousIndex];
	//HighlightUIButton(uiNavigation.currentButton);


	//const int MIDLINE_LINE_LENGTH = 32;
	//const int MIDLINE_LINE_THICKNESS = 20;
	//const int MIDLINE_LINES_COUNT = 10;
	//const int MIDLINE_LINES_TOTAL_COUNT = MIDLINE_LINES_COUNT * MIDLINE_LINE_THICKNESS;
	//line midlines[MIDLINE_LINES_TOTAL_COUNT];

	//for (int line_count = 0; line_count < MIDLINE_LINES_COUNT; line_count++)
	//{
	//	for (int line_thickness = 0; line_thickness < MIDLINE_LINE_THICKNESS; line_thickness++)
	//	{
	//		line line = {
	//			{app.screenWidth / 2 + line_thickness - (MIDLINE_LINE_THICKNESS / 2) ,  app.screenHeight / MIDLINE_LINES_COUNT * line_count },
	//			{app.screenWidth / 2 + line_thickness - (MIDLINE_LINE_THICKNESS / 2) ,  app.screenHeight / MIDLINE_LINES_COUNT * line_count + MIDLINE_LINE_LENGTH}
	//		};

	//		midlines[line_count * MIDLINE_LINE_THICKNESS + line_thickness] = line;
	//	}
	//}

	//int leftScore = 0;
	//bool leftScoreChanged = false;
	//int rightScore = 0;
	//bool rightScoreChanged = false;

	if (initApp(&app)) {
		return 1;
	}

	//texture = LoadTexture(renderer, "assets/loaded.png");
	//leftTextTexture = LoadTextTexture(renderer, font, std::to_string(leftScore), textColor);
	//rightTextTexture = LoadTextTexture(renderer, font, std::to_string(rightScore), textColor);
	//title.texture = LoadTextTexture(renderer, font, title.text, title.color);
	//playButton.text->texture = LoadTextTexture(renderer, font, playButton.text->text, playButton.text->color);
	//optionsButton.text->texture = LoadTextTexture(renderer, font, optionsButton.text->text, optionsButton.text->color);
	//quitButton.text->texture = LoadTextTexture(renderer, font, quitButton.text->text, quitButton.text->color);
	
	//TTF_SizeText()

	//if (texture == NULL) {
	//	printf("Failed to load texture image\n");
	//}
	////else if (leftTextTexture == NULL) {
	////	printf("Failed to load left text texture image\n");
	////}
	////else if (rightTextTexture == NULL) {
	////	printf("Failed to load right text texture image\n");
	////}
	//else {
	//}


	// Main Loop
	bool quit = false;
	SDL_Event e;

	paddle leftPaddle = app.leftPaddle;
	paddle rightPaddle = app.rightPaddle;
	wall leftWall = app.leftWall;
	wall rightWall = app.rightWall;
	wall topWall = app.topWall;
	wall bottomWall = app.bottomWall;
	ball ball = app.ball;

	float deltaTime = 0.0f;
	Uint32 startTicks = SDL_GetTicks();
	Uint32 lastTicks = 0;

	srand((unsigned)time(NULL));

	float resetBallTimer = 0.0f;
	float timeToResetBall = 1.0f;
	bool resettingBall = false;

	while (!quit) {
		deltaTime = (SDL_GetTicks() - startTicks) / 1000.0f;
		startTicks = SDL_GetTicks();

		// Pre-Update
		switch (app.gameState)
		{
		case appState::MAIN_MENU:
			break;
		case appState::GAME: {
			leftPaddle.velocity = 0.0f;
			rightPaddle.velocity = 0.0f;
		} break;

		case appState::COUNT:
			break;
		default:
			break;
		}


		/////////////////////////
		// Game Input
		/////////////////////////
		// Event Based Inputs (Handle events on queue)
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN) {

				switch (app.gameState)
				{
				case appState::MAIN_MENU: {
					switch (e.key.keysym.sym) {
					case SDLK_ESCAPE: {
						quit = true;
					} break;

					case SDLK_s: {
						//NextUIButton(&uiNavigation);
					} break;

					case SDLK_w: {
						//PreviousUIButton(&uiNavigation);
					} break;

					case SDLK_RETURN: {
						//if (uiNavigation.currentButton->id == playButton.id) {
						//	app.gameState = appState::GAME;
						//}
						//else if (uiNavigation.currentButton->id == quitButton.id) {
						//	quit = true;
						//}
					} break;

					}
				} break;

				case appState::GAME: {

				} break;
				case appState::COUNT: {

				} break;
				default:
					break;
				}



			}
		}

		// Non Event Base game Input
		switch (app.gameState)
		{
		case appState::MAIN_MENU:
			break;
		case appState::GAME: {
			/////////////////////////
			// Paddle Input
			/////////////////////////
			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

			// This works
			if (currentKeyStates[SDL_SCANCODE_W]) {
				leftPaddle.velocity -= 1.0f;
			}

			if (currentKeyStates[SDL_SCANCODE_S]) {
				leftPaddle.velocity += 1.0f;
			}

			// This works
			if (currentKeyStates[SDL_SCANCODE_UP]) {
				rightPaddle.velocity -= 1.0f;
			}

			if (currentKeyStates[SDL_SCANCODE_DOWN]) {
				rightPaddle.velocity += 1.0f;
			}
		} break;

		case appState::COUNT:
			break;
		default:
			break;
		}

		// Update
		switch (app.gameState)
		{
		case appState::MAIN_MENU: {
			//if (uiNavigation.previousButton->id != uiNavigation.currentButton->id) {
			//	uiNavigation.previousButton->text->texture = LoadTextTexture(renderer, font, uiNavigation.previousButton->text->text, uiNavigation.previousButton->text->color);
			//	uiNavigation.currentButton->text->texture = LoadTextTexture(renderer, font, uiNavigation.currentButton->text->text, uiNavigation.currentButton->text->color);
			//}
		} break;

		case appState::GAME: {
			leftPaddle.rectCollider.y += leftPaddle.velocity * leftPaddle.speed * deltaTime;
			rightPaddle.rectCollider.y += rightPaddle.velocity * rightPaddle.speed * deltaTime;

			if (resettingBall) {
				if (resetBallTimer >= timeToResetBall) {
					resettingBall = false; // move next frame
					resetBallTimer = 0.0f;
				}
				else {
					resetBallTimer += deltaTime;
				}
			}
			else {
				// Move ball
				ball.circleCollider.center.y += ball.velocity.y * ball.speed * deltaTime; // Moving X
				ball.circleCollider.center.x += ball.velocity.x * ball.speed * deltaTime; // Moving Y
			}

			/////////////////////////
			// Paddles Collision
			/////////////////////////

			// Left
			if (checkCollision(leftPaddle.rectCollider, bottomWall.rectCollider)) {
				// Undo Move
				leftPaddle.rectCollider.y -= leftPaddle.velocity * leftPaddle.speed * deltaTime;
			}

			if (checkCollision(leftPaddle.rectCollider, topWall.rectCollider)) {
				// Undo Move
				leftPaddle.rectCollider.y -= leftPaddle.velocity * leftPaddle.speed * deltaTime;
			}

			// Right
			if (checkCollision(rightPaddle.rectCollider, bottomWall.rectCollider)) {
				// Undo Move
				rightPaddle.rectCollider.y -= rightPaddle.velocity * rightPaddle.speed * deltaTime;
			}

			if (checkCollision(rightPaddle.rectCollider, topWall.rectCollider)) {
				// Undo Move
				rightPaddle.rectCollider.y -= rightPaddle.velocity * rightPaddle.speed * deltaTime;
			}

			/////////////////////////
			// Ball Collision
			/////////////////////////

			// Vertical Walls
			if (checkCollision(ball.circleCollider, topWall.rectCollider)) {
				ball.velocity.y = -ball.velocity.y;
				ball.circleCollider.center.y += ball.velocity.y * ball.speed * deltaTime; // Moving down
			}
			else if (checkCollision(ball.circleCollider, bottomWall.rectCollider)) {
				ball.velocity.y = -ball.velocity.y;
				ball.circleCollider.center.y += ball.velocity.y * ball.speed * deltaTime; // Moving down
			}

			// Horizontal Walls
			if (checkCollision(ball.circleCollider, leftWall.rectCollider)) {
				ball.velocity.x = -ball.velocity.x;
				ball.circleCollider.center.x += ball.velocity.x * ball.speed * deltaTime; // Moving down

				// Resetting ball
				ball.circleCollider.center = app.ballInitTransform;

				if (rand() % 2) {
					ball.velocity.x = -ball.velocity.x;
				}

				if (rand() % 2) {
					ball.velocity.y = -ball.velocity.y;
				}

				resettingBall = true;
				//rightScore++;
				//rightScoreChanged = true;
			}
			else if (checkCollision(ball.circleCollider, rightWall.rectCollider)) {
				ball.velocity.x = -ball.velocity.x;
				ball.circleCollider.center.x += ball.velocity.x * ball.speed * deltaTime; // Moving down

				// Resetting ball
				ball.circleCollider.center = app.ballInitTransform;

				if (rand() % 2) {
					ball.velocity.x = -ball.velocity.x;
				}

				if (rand() % 2) {
					ball.velocity.y = -ball.velocity.y;
				}

				resettingBall = true;
				//leftScore++;
				//leftScoreChanged = true;
			}


			// Left Paddles
			if (checkCollision(ball.circleCollider, leftPaddle.rectCollider)) {
				bool ballAbovePaddle = ball.circleCollider.center.y <= leftPaddle.rectCollider.y;
				bool ballBelowPaddle = ball.circleCollider.center.y >= leftPaddle.rectCollider.y + leftPaddle.height;

				// Check ball hit vertical ends of paddle
				if (ballAbovePaddle || ballBelowPaddle) {
					ball.velocity.y = -ball.velocity.y;
				}
				else {
					ball.velocity.x = -ball.velocity.x;
					ball.circleCollider.center.x += ball.velocity.x * ball.speed * deltaTime;
				}
			}

			// Right Paddle
			if (checkCollision(ball.circleCollider, rightPaddle.rectCollider)) {
				bool ballAbovePaddle = ball.circleCollider.center.y <= rightPaddle.rectCollider.y;
				bool ballBelowPaddle = ball.circleCollider.center.y >= rightPaddle.rectCollider.y + rightPaddle.height;

				// Check ball hit vertical ends of paddle
				if (ballAbovePaddle || ballBelowPaddle) {
					ball.velocity.y = -ball.velocity.y;
				}
				else {
					ball.velocity.x = -ball.velocity.x;
					ball.circleCollider.center.x += ball.velocity.x * ball.speed * deltaTime;
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
		} break;

		default:
			break;
		}

		/////////////////////////
		// Render Pass
		/////////////////////////

		//Clear screen to Black
		SDL_SetRenderDrawColor(app.renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(app.renderer);

		switch (app.gameState)
		{
		case appState::MAIN_MENU: {
			//
			//const SDL_FRect titleDestRect = title.rect;
			//SDL_RenderCopyExF(renderer, title.texture, NULL, &titleDestRect, 0, NULL, SDL_FLIP_NONE);

			// Render button
			/*SDL_SetRenderDrawColor(renderer, playButton.color.r, playButton.color.g, playButton.color.b, playButton.color.a);
			const SDL_FRect playButtonDestRect = playButton.rect;
			SDL_RenderFillRectF(renderer, &playButtonDestRect);
			const SDL_FRect playButtonTextDestRect = playButton.text->rect;
			SDL_RenderCopyExF(renderer, playButton.text->texture, NULL, &playButtonTextDestRect, 0, NULL, SDL_FLIP_NONE);*/

			//// Render button
			//SDL_SetRenderDrawColor(renderer, optionsButton.color.r, optionsButton.color.g, optionsButton.color.b, optionsButton.color.a);
			//const SDL_FRect optionsButtonDestRect = optionsButton.rect;
			//SDL_RenderFillRectF(renderer, &optionsButtonDestRect);
			//const SDL_FRect optionsButtonTextDestRect = optionsButton.text->rect;
			//SDL_RenderCopyExF(app.renderer, optionsButton.text->texture, NULL, &optionsButtonTextDestRect, 0, NULL, SDL_FLIP_NONE);

			//// Render button
			//SDL_SetRenderDrawColor(app.renderer, quitButton.color.r, quitButton.color.g, quitButton.color.b, quitButton.color.a);
			//const SDL_FRect quitButtonDestRect = quitButton.rect;
			//SDL_RenderFillRectF(app.renderer, &quitButtonDestRect);
			//const SDL_FRect quitButtonTextDestRect = quitButton.text->rect;
			//SDL_RenderCopyExF(app.renderer, quitButton.text->texture, NULL, &quitButtonTextDestRect, 0, NULL, SDL_FLIP_NONE);
		} break;

		case appState::GAME: {
			/////////////////////////
			// Render Entities
			/////////////////////////

			// Draw Paddles
			SDL_SetRenderDrawColor(app.renderer, leftPaddle.color.r, leftPaddle.color.g, leftPaddle.color.b, leftPaddle.color.a);
			SDL_RenderFillRectF(app.renderer, &leftPaddle.rectCollider);

			SDL_SetRenderDrawColor(app.renderer, rightPaddle.color.r, rightPaddle.color.g, rightPaddle.color.b, rightPaddle.color.a);
			SDL_RenderFillRectF(app.renderer, &rightPaddle.rectCollider);

			// Draw Walls
			SDL_SetRenderDrawColor(app.renderer, leftWall.color.r, leftWall.color.g, leftWall.color.b, leftWall.color.a);
			SDL_RenderFillRectF(app.renderer, &leftWall.rectCollider);

			SDL_SetRenderDrawColor(app.renderer, rightWall.color.r, rightWall.color.g, rightWall.color.b, rightWall.color.a);
			SDL_RenderFillRectF(app.renderer, &rightWall.rectCollider);

			SDL_SetRenderDrawColor(app.renderer, topWall.color.r, topWall.color.g, topWall.color.b, topWall.color.a);
			SDL_RenderFillRectF(app.renderer, &topWall.rectCollider);

			SDL_SetRenderDrawColor(app.renderer, bottomWall.color.r, bottomWall.color.g, bottomWall.color.b, bottomWall.color.a);
			SDL_RenderFillRectF(app.renderer, &bottomWall.rectCollider);

			// Draw Midline
			//SDL_SetRenderDrawColor(app.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			//SDL_RenderDrawPoints(app.renderer, MIDLINE_POINTS, MIDLINE_POINTS_COUNT);
			//SDL_RenderDrawLines(app.renderer, MIDLINE_POINTS, MIDLINE_POINTS_COUNT);
			//for (int i = 0; i < MIDLINE_LINES_TOTAL_COUNT; i++)
			//{
			//	line line = midlines[i];
			//	//if ((i % MIDLINE_LINES_COUNT) == (MIDLINE_LINE_THICKNESS / 2)) {
			//	//	SDL_SetRenderDrawColor(app.renderer, 0xFF, 0x00, 0x00, 0xFF);
			//	//}
			//	SDL_RenderDrawLine(app.renderer, line.start.x, line.start.y, line.end.x, line.end.y);

			//}

			// Draw Ball
			SDL_SetRenderDrawColor(app.renderer, ball.color.r, ball.color.g, ball.color.b, ball.color.a);
			//SDL_RenderFillRectF(app.renderer, &ballCollider);
			SDL_RenderFillCircle(app.renderer, ball.circleCollider.center.x, ball.circleCollider.center.y, ball.circleCollider.radius);

			/////////////////////////
			// Render Entities Debug
			/////////////////////////

			// Paddle Position (Top Left)
			SDL_SetRenderDrawColor(app.renderer, 0, 255, 0, 255); // Green
			SDL_RenderDrawPointF(app.renderer, leftPaddle.rectCollider.x, leftPaddle.rectCollider.y);
			SDL_RenderDrawPointF(app.renderer, rightPaddle.rectCollider.x, rightPaddle.rectCollider.y);

			// Ball Position (Center)
			SDL_RenderDrawPointF(app.renderer, ball.circleCollider.center.x, ball.circleCollider.center.y);

			// Ball Collider
			SDL_SetRenderDrawColor(app.renderer, 255, 255, 0, 255); // Yellow
			SDL_FRect ballCollider = { ball.circleCollider.center.x - ball.circleCollider.radius, ball.circleCollider.center.y - ball.circleCollider.radius, 2.0f * ball.circleCollider.radius, 2.0f * ball.circleCollider.radius };
			SDL_RenderDrawRectF(app.renderer, &ballCollider);

			/////////////////////////
			// Render Text
			/////////////////////////

			//Render text texture to screen
			//SDL_RenderCopy(app.renderer, textTexture, NULL, NULL);
			//const SDL_Rect leftTextDestRect = {
			//	LEFT_SCORE_TEXT_X,
			//	LEFT_SCORE_TEXT_Y,
			//	SCORE_TEXT_WIDTH,
			//	SCORE_TEXT_HEIGHT
			//};
			//SDL_RenderCopyEx(app.renderer, leftTextTexture, NULL, &leftTextDestRect, 0, NULL, SDL_FLIP_NONE);

			//const SDL_Rect rightTextDestRect = {
			//	RIGHT_SCORE_TEXT_X,
			//	RIGHT_SCORE_TEXT_Y,
			//	SCORE_TEXT_WIDTH,
			//	SCORE_TEXT_HEIGHT
			//};
			//SDL_RenderCopyEx(app.renderer, rightTextTexture, NULL, &rightTextDestRect, 0, NULL, SDL_FLIP_NONE);


		} break;

		default:
			break;
		}

		SDL_RenderPresent(app.renderer);

		int frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < app.ticksPerFrame)
		{
			//Wait remaining time
			SDL_Delay(app.ticksPerFrame - frameTicks);
		}
	}

	freeApp(&app);
	return 0;
}