#pragma once
#include <cstdlib>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <time.h>

#include "app.h"
#include "game.h"
int appMain(int argc, char* argv[]) {
	app app;

	if (init(&app)) {
		return 1;
	}

	run(&app);

	free(&app);
	return 0;
}

int init(app* app) {
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	//Create window
	app->window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, app->screenWidth, app->screenHeight, SDL_WINDOW_SHOWN);
	if (app->window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	// Create Renderer
	app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
	if (app->renderer == NULL) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return 1;
	}

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return 1;
	}

	//Get window surface
	app->windowSurface = SDL_GetWindowSurface(app->window);

	// Load text library
	if (TTF_Init() == -1) {
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return 1;
	}

	//// Load Font
	//app->font = TTF_OpenFont("assets/font/DotGothic16-Regular.ttf", app->fontPointSize);
	//if (app->font == NULL) {
	//	printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
	//	return 1;
	//}

	srand((unsigned)time(NULL));

	return 0;
}

int free(app* app) {
	//TTF_CloseFont(app->font);
	//app->font = NULL;

	//Deallocate surface
	SDL_FreeSurface(app->windowSurface);
	app->windowSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(app->window);
	app->window = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}

void updateDeltaTime(app* app) {
	app->deltaTime = (SDL_GetTicks() - app->startTicks) / 1000.0f;
	app->startTicks = SDL_GetTicks();
}

void applyFrameDelay(app* app) {
	int frameTicks = SDL_GetTicks() - app->startTicks;
	if (frameTicks < app->ticksPerFrame)
	{
		//Wait remaining time
		SDL_Delay(app->ticksPerFrame - frameTicks);
	}
}
void getUserInput(app* app) {
	/////////////////////////
	// Game Input
	/////////////////////////
	// Event Based Inputs (Handle events on queue)
	while (SDL_PollEvent(&app->e) != 0)
	{
		//User requests quit
		if (app->e.type == SDL_QUIT)
		{
			app->quit = true;
		}
		//else if (app->e.type == SDL_KEYDOWN) {

		//	switch (app->gameState)
		//	{
		//	case appState::MAIN_MENU: {
		//		switch (app->e.key.keysym.sym) {
		//		case SDLK_ESCAPE: {
		//			app->quit = true;
		//		} break;
		//	} break;

		//	case appState::GAME: {

		//	} break;
		//	case appState::COUNT: {

		//	} break;
		//	default:
		//		break;
		//	}
		//}
	}

	app->keyStates = SDL_GetKeyboardState(NULL);

	//// Non Event Base game Input
	//switch (app.gameState)
	//{
	//case appState::MAIN_MENU:
	//	break;
	//case appState::GAME: {
	//	/////////////////////////
	//	// Paddle Input
	//	/////////////////////////
	//	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	//	// This works
	//	if (currentKeyStates[SDL_SCANCODE_W]) {
	//		leftPaddle.velocity -= 1.0f;
	//	}

	//	if (currentKeyStates[SDL_SCANCODE_S]) {
	//		leftPaddle.velocity += 1.0f;
	//	}

	//	// This works
	//	if (currentKeyStates[SDL_SCANCODE_UP]) {
	//		rightPaddle.velocity -= 1.0f;
	//	}

	//	if (currentKeyStates[SDL_SCANCODE_DOWN]) {
	//		rightPaddle.velocity += 1.0f;
	//	}
	//} break;

	//case appState::COUNT:
	//	break;
	//default:
	//	break;
	//}
}

void preUpdate(app* app) {
	//switch (app->gameState)
	//{
	//	case appState::MAIN_MENU:
	//		break;
	//	case appState::GAME: {
	//		app->leftPaddle.velocity = 0.0f;
	//		app->rightPaddle.velocity = 0.0f;
	//	} break;
	//	default:
	//		break;
	//}
}

void updateGame(app* app) {
	// update left paddle
	//update(app, &app->leftPaddle);
	// update right paddle
	//update(app, &app->rightPaddle);
	// update ball
	//update(app, &app->ball);

//	/////////////////////////
//// Paddles Collision
///////////////////////////
//
//// Left
//	if (checkCollision(leftPaddle.rectCollider, bottomWall.rectCollider)) {
//		// Undo Move
//		leftPaddle.rectCollider.y -= leftPaddle.velocity * leftPaddle.speed * deltaTime;
//	}
//
//	if (checkCollision(leftPaddle.rectCollider, topWall.rectCollider)) {
//		// Undo Move
//		leftPaddle.rectCollider.y -= leftPaddle.velocity * leftPaddle.speed * deltaTime;
//	}
//
//	// Right
//	if (checkCollision(rightPaddle.rectCollider, bottomWall.rectCollider)) {
//		// Undo Move
//		rightPaddle.rectCollider.y -= rightPaddle.velocity * rightPaddle.speed * deltaTime;
//	}
//
//	if (checkCollision(rightPaddle.rectCollider, topWall.rectCollider)) {
//		// Undo Move
//		rightPaddle.rectCollider.y -= rightPaddle.velocity * rightPaddle.speed * deltaTime;
//	}

	///////////////////////////
	//// Ball Collision
	///////////////////////////

	//// Vertical Walls
	//if (checkCollision(ball.circleCollider, topWall.rectCollider)) {
	//	ball.velocity.y = -ball.velocity.y;
	//	ball.circleCollider.center.y += ball.velocity.y * ball.speed * deltaTime; // Moving down
	//}
	//else if (checkCollision(ball.circleCollider, bottomWall.rectCollider)) {
	//	ball.velocity.y = -ball.velocity.y;
	//	ball.circleCollider.center.y += ball.velocity.y * ball.speed * deltaTime; // Moving down
	//}

	//// Horizontal Walls
	//if (checkCollision(ball.circleCollider, leftWall.rectCollider)) {
	//	ball.velocity.x = -ball.velocity.x;
	//	ball.circleCollider.center.x += ball.velocity.x * ball.speed * deltaTime; // Moving down

	//	// Resetting ball
	//	ball.circleCollider.center = app.ballInitTransform;

	//	if (rand() % 2) {
	//		ball.velocity.x = -ball.velocity.x;
	//	}

	//	if (rand() % 2) {
	//		ball.velocity.y = -ball.velocity.y;
	//	}

	//	resettingBall = true;
	//	//rightScore++;
	//	//rightScoreChanged = true;
	//}
	//else if (checkCollision(ball.circleCollider, rightWall.rectCollider)) {
	//	ball.velocity.x = -ball.velocity.x;
	//	ball.circleCollider.center.x += ball.velocity.x * ball.speed * deltaTime; // Moving down

	//	// Resetting ball
	//	ball.circleCollider.center = app.ballInitTransform;

	//	if (rand() % 2) {
	//		ball.velocity.x = -ball.velocity.x;
	//	}

	//	if (rand() % 2) {
	//		ball.velocity.y = -ball.velocity.y;
	//	}

	//	resettingBall = true;
	//	//leftScore++;
	//	//leftScoreChanged = true;
	//}


	//// Left Paddles
	//if (checkCollision(ball.circleCollider, leftPaddle.rectCollider)) {
	//	bool ballAbovePaddle = ball.circleCollider.center.y <= leftPaddle.rectCollider.y;
	//	bool ballBelowPaddle = ball.circleCollider.center.y >= leftPaddle.rectCollider.y + leftPaddle.height;

	//	// Check ball hit vertical ends of paddle
	//	if (ballAbovePaddle || ballBelowPaddle) {
	//		ball.velocity.y = -ball.velocity.y;
	//	}
	//	else {
	//		ball.velocity.x = -ball.velocity.x;
	//		ball.circleCollider.center.x += ball.velocity.x * ball.speed * deltaTime;
	//	}
	//}

	//// Right Paddle
	//if (checkCollision(ball.circleCollider, rightPaddle.rectCollider)) {
	//	bool ballAbovePaddle = ball.circleCollider.center.y <= rightPaddle.rectCollider.y;
	//	bool ballBelowPaddle = ball.circleCollider.center.y >= rightPaddle.rectCollider.y + rightPaddle.height;

	//	// Check ball hit vertical ends of paddle
	//	if (ballAbovePaddle || ballBelowPaddle) {
	//		ball.velocity.y = -ball.velocity.y;
	//	}
	//	else {
	//		ball.velocity.x = -ball.velocity.x;
	//		ball.circleCollider.center.x += ball.velocity.x * ball.speed * deltaTime;
	//	}
	//}

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


void update(app* app) {

	//// Update
	//switch (app->gameState)
	//{
	//case appState::MAIN_MENU: {
	//	//if (uiNavigation.previousButton->id != uiNavigation.currentButton->id) {
	//	//	uiNavigation.previousButton->text->texture = LoadTextTexture(renderer, font, uiNavigation.previousButton->text->text, uiNavigation.previousButton->text->color);
	//	//	uiNavigation.currentButton->text->texture = LoadTextTexture(renderer, font, uiNavigation.currentButton->text->text, uiNavigation.currentButton->text->color);
	//	//}
	//} break;

	//case appState::GAME: {
	//	updateGame(app);
	//} break;

	//default:
	//	break;
	//}
}

void renderGame(app* app) {
	/////////////////////////
	// Render Entities
	/////////////////////////

	// Draw Paddles
	//render(app, &app->leftPaddle);
	
	//SDL_SetRenderDrawColor(app.renderer, leftPaddle.color.r, leftPaddle.color.g, leftPaddle.color.b, leftPaddle.color.a);
	//SDL_RenderFillRectF(app.renderer, &leftPaddle.rectCollider);

	//render(app, &app->rightPaddle);
	//SDL_SetRenderDrawColor(app.renderer, rightPaddle.color.r, rightPaddle.color.g, rightPaddle.color.b, rightPaddle.color.a);
	//SDL_RenderFillRectF(app.renderer, &rightPaddle.rectCollider);

	// Draw Walls
	//render(app, &app->leftWall);
	//SDL_SetRenderDrawColor(app.renderer, leftWall.color.r, leftWall.color.g, leftWall.color.b, leftWall.color.a);
	//SDL_RenderFillRectF(app.renderer, &leftWall.rectCollider);

	//render(app, &app->rightWall);
	//SDL_SetRenderDrawColor(app.renderer, rightWall.color.r, rightWall.color.g, rightWall.color.b, rightWall.color.a);
	//SDL_RenderFillRectF(app.renderer, &rightWall.rectCollider);

	//render(app, &app->topWall);
	//SDL_SetRenderDrawColor(app.renderer, topWall.color.r, topWall.color.g, topWall.color.b, topWall.color.a);
	//SDL_RenderFillRectF(app.renderer, &topWall.rectCollider);

	//render(app, &app->bottomWall);
	//SDL_SetRenderDrawColor(app.renderer, bottomWall.color.r, bottomWall.color.g, bottomWall.color.b, bottomWall.color.a);
	//SDL_RenderFillRectF(app.renderer, &bottomWall.rectCollider);

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
	//SDL_SetRenderDrawColor(app.renderer, ball.color.r, ball.color.g, ball.color.b, ball.color.a);
	//SDL_RenderFillRectF(app.renderer, &ballCollider);
	//SDL_RenderFillCircle(app.renderer, ball.circleCollider.center.x, ball.circleCollider.center.y, ball.circleCollider.radius);

	/////////////////////////
	// Render Entities Debug
	/////////////////////////

	// Paddle Position (Top Left)
	//SDL_SetRenderDrawColor(app.renderer, 0, 255, 0, 255); // Green
	//SDL_RenderDrawPointF(app.renderer, leftPaddle.rectCollider.x, leftPaddle.rectCollider.y);
	//SDL_RenderDrawPointF(app.renderer, rightPaddle.rectCollider.x, rightPaddle.rectCollider.y);

	// Ball Position (Center)
	//SDL_RenderDrawPointF(app.renderer, ball.circleCollider.center.x, ball.circleCollider.center.y);

	//// Ball Collider
	//SDL_SetRenderDrawColor(app.renderer, 255, 255, 0, 255); // Yellow
	//SDL_FRect ballCollider = { ball.circleCollider.center.x - ball.circleCollider.radius, ball.circleCollider.center.y - ball.circleCollider.radius, 2.0f * ball.circleCollider.radius, 2.0f * ball.circleCollider.radius };
	//SDL_RenderDrawRectF(app.renderer, &ballCollider);

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

}

void render(app* app) {
	//Clear screen to Black
	SDL_SetRenderDrawColor(app->renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(app->renderer);

	render(app->renderer, app->game);

	//switch (app->gameState)
	//{
	//case appState::MAIN_MENU: {
	//	//
	//	//const SDL_FRect titleDestRect = title.rect;
	//	//SDL_RenderCopyExF(renderer, title.texture, NULL, &titleDestRect, 0, NULL, SDL_FLIP_NONE);

	//	// Render button
	//	/*SDL_SetRenderDrawColor(renderer, playButton.color.r, playButton.color.g, playButton.color.b, playButton.color.a);
	//	const SDL_FRect playButtonDestRect = playButton.rect;
	//	SDL_RenderFillRectF(renderer, &playButtonDestRect);
	//	const SDL_FRect playButtonTextDestRect = playButton.text->rect;
	//	SDL_RenderCopyExF(renderer, playButton.text->texture, NULL, &playButtonTextDestRect, 0, NULL, SDL_FLIP_NONE);*/

	//	//// Render button
	//	//SDL_SetRenderDrawColor(renderer, optionsButton.color.r, optionsButton.color.g, optionsButton.color.b, optionsButton.color.a);
	//	//const SDL_FRect optionsButtonDestRect = optionsButton.rect;
	//	//SDL_RenderFillRectF(renderer, &optionsButtonDestRect);
	//	//const SDL_FRect optionsButtonTextDestRect = optionsButton.text->rect;
	//	//SDL_RenderCopyExF(app.renderer, optionsButton.text->texture, NULL, &optionsButtonTextDestRect, 0, NULL, SDL_FLIP_NONE);

	//	//// Render button
	//	//SDL_SetRenderDrawColor(app.renderer, quitButton.color.r, quitButton.color.g, quitButton.color.b, quitButton.color.a);
	//	//const SDL_FRect quitButtonDestRect = quitButton.rect;
	//	//SDL_RenderFillRectF(app.renderer, &quitButtonDestRect);
	//	//const SDL_FRect quitButtonTextDestRect = quitButton.text->rect;
	//	//SDL_RenderCopyExF(app.renderer, quitButton.text->texture, NULL, &quitButtonTextDestRect, 0, NULL, SDL_FLIP_NONE);
	//} break;

	//case appState::GAME: {
	//	renderGame(app);
	//	
	//	

	//} break;

	//default:
	//	break;
	//}

	SDL_RenderPresent(app->renderer);

}

int run(app* app) {
	// Load all textures
	// Check all the textures (if not NULL)

	game game;
	app->game = &game;
	init(&game);



	while (!app->quit) {
		updateDeltaTime(app);

		getUserInput(app);

		preUpdate(app);
		update(app);
		
		render(app);
		
		applyFrameDelay(app);
	}

	return 0;
}
