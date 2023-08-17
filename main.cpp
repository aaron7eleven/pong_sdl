#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "stdio.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "color.h"

struct Entity {
	SDL_FRect position;
	SDL_Color color;
};

struct CircleEntity {
	SDL_FRect position;
	SDL_Color color;
	float radius;
};

struct Vector2 {
	float x;
	float y;
};

struct Line {
	SDL_Point start;
	SDL_Point end;
};

struct UI_Text {
	SDL_FRect rect;
	SDL_Color color;
	SDL_Texture* texture;
	std::string text;
};

struct UI_Button {
	SDL_FRect rect;
	SDL_Color color;
	SDL_Texture* texture;
	UI_Text text;
};

//struct UI_Button_State {
//	bool selected;
//	bool highlighted;
//	SDL_Color color;
//	SDL_Texture* texture;
//	UI_Text text;
//};


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

bool CheckCollision(SDL_FRect a, SDL_FRect b)
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

float DistanceSquared(float x1, float y1, float x2, float y2) {
	float deltaX = x2 - x1;
	float deltaY = y2 - y1;
	return deltaX * deltaX + deltaY * deltaY;
};

float ClosestXToCircle(CircleEntity& circle, SDL_FRect b) {

	float circleX = 0.0f;
	
	// Find closest X position to Rect b from Circle's position
	// Circle is to the left of b
	if (circle.position.x < b.x) {
		circleX = b.x;
	}
	// Circle is to the right of b
	else if (circle.position.x > (b.x + b.w)) {
		circleX = b.x + b.w;
	}
	// Circle is inside of b
	else {
		circleX = circle.position.x;
	}

	return circleX;
}

bool CheckCollision(CircleEntity& circle, SDL_FRect b)
{

	float circleX;
	float circleY;

	// Find closest X position to Rect b from Circle's position
	// Circle is to the left of b
	if (circle.position.x < b.x) {
		circleX = b.x;
	}
	// Circle is to the right of b
	else if (circle.position.x > (b.x + b.w)) {
		circleX = b.x + b.w;
	}
	// Circle is inside of b
	else {
		circleX = circle.position.x;
	}

	// Same for Y (Same code as above)
	// Circle is to the above of b 
	if (circle.position.y < b.y) {
		circleY = b.y;
	}
	// Circle is to the below of b
	else if (circle.position.y > (b.y + b.h)) {
		circleY = b.y + b.h;
	}
	// Circle is inside of b
	else {
		circleY = circle.position.y;
	}

	if (DistanceSquared(circle.position.x, circle.position.y, circleX, circleY) < (circle.radius * circle.radius)) {
		// Colliding
		return true;
	}

	// Not colliding
	return false;

};

float Magnitude(Vector2* vec2) {
	return std::sqrt(vec2->x * vec2->x + vec2->y * vec2->y);
}

void Normalize(Vector2* vec2) {
	Vector2 normVec2;
	float magnitude = Magnitude(vec2);
	vec2->x = vec2->x / magnitude;
	vec2->y = vec2->y / magnitude;
}

//void ResetBall(CircleEntity* ball) {
//
//	ball->position = {
//		BALL_INIT_X,
//		BALL_INIT_Y,
//		BALL_RADIUS,
//		BALL_RADIUS
//	};
//	ball.color = { 0xFF, 0xFF, 0xFF, 0xFF };
//	ball.radius = BALL_RADIUS;
//	Vector2 ballVelocity = { 0.5f, 0.5f };
//}

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




int main(int argc, char* argv[])
{
	Color color;
	
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS; // 1000 ms / X frames

	const int PADDLE_WIDTH = SCREEN_WIDTH / 64;
	const int PADDLE_HEIGHT = SCREEN_HEIGHT / 8;
	const int PADDLE_SPEED = 300;

	const int LEFT_PADDLE_INIT_X = SCREEN_WIDTH / 8;
	const int LEFT_PADDLE_INIT_Y = SCREEN_HEIGHT / 2;

	const int RIGHT_PADDLE_INIT_X = SCREEN_WIDTH - (SCREEN_WIDTH / 8);
	const int RIGHT_PADDLE_INIT_Y = SCREEN_HEIGHT / 2;

	const int HORZ_WALL_WIDTH = SCREEN_WIDTH / 128;
	const int HORZ_WALL_HEIGHT = SCREEN_HEIGHT;
	const int LEFT_WALL_X = SCREEN_WIDTH / 16;
	const int LEFT_WALL_Y = 0; // Starts at top left corner not center (0 not SCREEN_HEIGHT / 2)
	const int RIGHT_WALL_X = SCREEN_WIDTH * 15 / 16;
	const int RIGHT_WALL_Y = 0; // Starts at top left corner not center (0 not SCREEN_HEIGHT / 2)

	const int VERT_WALL_WIDTH = SCREEN_WIDTH;
	const int VERT_WALL_HEIGHT = SCREEN_WIDTH / 128;
	const int TOP_WALL_X = 0; // Starts at top left corner not center (0 not SCREEN_WIDTH / 2)
	const int TOP_WALL_Y = VERT_WALL_HEIGHT;
	const int BOTTOM_WALL_X = 0; // Starts at top left corner not center (0 not SCREEN_WIDTH / 2)
	const int BOTTOM_WALL_Y = SCREEN_HEIGHT - VERT_WALL_HEIGHT * 2.0f; // Move above the bottom edge of window
	
	const int BALL_RADIUS = SCREEN_WIDTH / 64; // Same width as paddle
	const int BALL_INIT_X = SCREEN_WIDTH / 2;
	const int BALL_INIT_Y = SCREEN_HEIGHT / 2;
	const int BALL_SPEED = 600;

	const int SCORE_TEXT_WIDTH = SCREEN_WIDTH / 32;
	const int SCORE_TEXT_HEIGHT = SCREEN_HEIGHT / 8; // Same Height as paddle
	const int SCORE_TEXT_X_OFFSET = SCREEN_WIDTH / 16;
	const int SCORE_TEXT_Y_OFFSET = SCREEN_WIDTH / 16;

	const int LEFT_SCORE_TEXT_X = (SCREEN_WIDTH / 2) - SCORE_TEXT_WIDTH - SCORE_TEXT_X_OFFSET;
	const int LEFT_SCORE_TEXT_Y = SCORE_TEXT_Y_OFFSET;

	const int RIGHT_SCORE_TEXT_X = (SCREEN_WIDTH / 2) + SCORE_TEXT_X_OFFSET;
	const int RIGHT_SCORE_TEXT_Y = SCORE_TEXT_Y_OFFSET;
	
	const int TITLE_TEXT_X_OFFSET = 0;
	const int TITLE_TEXT_Y_OFFSET = SCREEN_WIDTH / 16;
	const int TITLE_TEXT_WIDTH = SCREEN_WIDTH / 8;
	const int TITLE_TEXT_HEIGHT = SCREEN_HEIGHT / 8; // Same Height as paddle
	const int TITLE_TEXT_X = (SCREEN_WIDTH / 2) - TITLE_TEXT_WIDTH / 2 ;
	const int TITLE_TEXT_Y = SCORE_TEXT_Y_OFFSET;

	UI_Text title;	
	title.rect.w = SCREEN_WIDTH / 4;
	title.rect.h = SCREEN_HEIGHT / 4;
	title.rect.x = (SCREEN_WIDTH / 2) - title.rect.w / 2;
	title.rect.y = SCREEN_HEIGHT / 16;
	title.text = "Pong";
	title.color = color.white;

	UI_Text playButtonText;
	playButtonText.rect.w = SCREEN_WIDTH / 8;
	playButtonText.rect.h = SCREEN_HEIGHT / 8;
	playButtonText.rect.x = (SCREEN_WIDTH / 2) - playButtonText.rect.w / 2;
	playButtonText.rect.y = SCREEN_HEIGHT * 3 / 8;
	playButtonText.text = "Play";
	playButtonText.color = color.black;

	UI_Button playButton;
	playButton.color = color.white;
	playButton.text = playButtonText;
	playButton.rect.w = SCREEN_WIDTH / 4;
	playButton.rect.h = SCREEN_HEIGHT / 8;
	playButton.rect.x = (SCREEN_WIDTH / 2) - playButton.rect.w / 2;
	playButton.rect.y = SCREEN_HEIGHT * 3 / 8;

	UI_Text optionsButtonText;
	optionsButtonText.rect.w = SCREEN_WIDTH / 6;
	optionsButtonText.rect.h = SCREEN_HEIGHT / 8;
	optionsButtonText.rect.x = (SCREEN_WIDTH / 2) - optionsButtonText.rect.w / 2;
	optionsButtonText.rect.y = SCREEN_HEIGHT * 4 / 8;
	optionsButtonText.text = "Options";
	optionsButtonText.color = color.white;

	UI_Button optionsButton;
	optionsButton.color = color.black;
	optionsButton.text = optionsButtonText;
	optionsButton.rect.w = SCREEN_WIDTH / 4;
	optionsButton.rect.h = SCREEN_HEIGHT / 8;
	optionsButton.rect.x = (SCREEN_WIDTH / 2) - optionsButton.rect.w / 2;
	optionsButton.rect.y = SCREEN_HEIGHT * 4 / 8;

	UI_Text quitButtonText;
	quitButtonText.rect.w = SCREEN_WIDTH / 8;
	quitButtonText.rect.h = SCREEN_HEIGHT / 8;
	quitButtonText.rect.x = (SCREEN_WIDTH / 2) - quitButtonText.rect.w / 2;
	quitButtonText.rect.y = SCREEN_HEIGHT * 5 / 8;
	quitButtonText.text = "Quit";
	quitButtonText.color = color.white;

	UI_Button quitButton;
	quitButton.color = color.black;
	quitButton.text = quitButtonText;
	quitButton.rect.w = SCREEN_WIDTH / 4;
	quitButton.rect.h = SCREEN_HEIGHT / 8;
	quitButton.rect.x = (SCREEN_WIDTH / 2) - quitButton.rect.w / 2;
	quitButton.rect.y = SCREEN_HEIGHT * 5 / 8;

	enum gameState
	{
		MAIN_MENU = 0,
		GAME,
		COUNT
	};
	

	const int MIDLINE_LINE_LENGTH = 32;
	const int MIDLINE_LINE_THICKNESS = 20;
	const int MIDLINE_LINES_COUNT = 10;
	const int MIDLINE_LINES_TOTAL_COUNT = MIDLINE_LINES_COUNT * MIDLINE_LINE_THICKNESS;
	Line midlines[MIDLINE_LINES_TOTAL_COUNT];

	for (int line_count = 0; line_count < MIDLINE_LINES_COUNT; line_count++)
	{
		for (int line_thickness = 0; line_thickness < MIDLINE_LINE_THICKNESS; line_thickness++)
		{
			Line line = {
				{SCREEN_WIDTH / 2 + line_thickness - (MIDLINE_LINE_THICKNESS / 2) ,  SCREEN_HEIGHT / MIDLINE_LINES_COUNT * line_count },
				{SCREEN_WIDTH / 2 + line_thickness - (MIDLINE_LINE_THICKNESS / 2) ,  SCREEN_HEIGHT / MIDLINE_LINES_COUNT * line_count + MIDLINE_LINE_LENGTH}
			};

			midlines[line_count * MIDLINE_LINE_THICKNESS + line_thickness] = line;
		}
	}

	int leftScore = 0;
	bool leftScoreChanged = false;
	int rightScore = 0;
	bool rightScoreChanged = false;

	SDL_Window* window = NULL;
	SDL_Surface* windowSurface = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* texture = NULL;
	TTF_Font* font = NULL;
	SDL_Color textColor = {255, 255, 255, 255 }; // white
	const int fontPointSize = 100;

	SDL_Texture* leftTextTexture = NULL;
	SDL_Texture* rightTextTexture = NULL;

	SDL_Texture* titleTextTexture = NULL;


	// Initialization
	if (SDL_Init(SDL_INIT_EVERYTHING)) 
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}
	else 
	{
		//Create window
		window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			}
			else {

				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				}
				else
				{
					//Get window surface
					windowSurface = SDL_GetWindowSurface(window);
				}

				if (TTF_Init() == -1) {
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				}
				else {
					font = TTF_OpenFont("assets/font/DotGothic16-Regular.ttf", fontPointSize);
					if (font == NULL) {
						printf("Faile to load font! SDL_ttf Error: %s\n", TTF_GetError());
					}
					else {
						// Render Text

					}
				}
			}			
		}
	}

	texture = LoadTexture(renderer, "assets/loaded.png");
	leftTextTexture = LoadTextTexture(renderer, font, std::to_string(leftScore), textColor);
	rightTextTexture = LoadTextTexture(renderer, font, std::to_string(rightScore), textColor);
	title.texture = LoadTextTexture(renderer, font, title.text, title.color);
	playButtonText.texture = LoadTextTexture(renderer, font, playButtonText.text, playButtonText.color);
	optionsButtonText.texture = LoadTextTexture(renderer, font, optionsButtonText.text, optionsButtonText.color);
	quitButtonText.texture = LoadTextTexture(renderer, font, quitButtonText.text, quitButtonText.color);
	
	//TTF_SizeText()

	if (texture == NULL) {
		printf("Failed to load texture image\n");
	}
	else if (leftTextTexture == NULL) {
		printf("Failed to load left text texture image\n");
	}
	else if (rightTextTexture == NULL) {
		printf("Failed to load right text texture image\n");
	}
	else {

		// Main Loop
		bool quit = false;
		SDL_Event e;

		Entity leftPaddle;
		leftPaddle.position = {
			LEFT_PADDLE_INIT_X,
			LEFT_PADDLE_INIT_Y,
			PADDLE_WIDTH,
			PADDLE_HEIGHT
		};

		leftPaddle.color = { 0xFF, 0xFF, 0xFF, 0xFF };
		bool leftPaddleUpHeld = false;
		bool leftPaddleDownHeld = false;
		float leftPaddleVelocity = 0.0f;

		Entity rightPaddle;
		rightPaddle.position = {
			RIGHT_PADDLE_INIT_X,
			RIGHT_PADDLE_INIT_Y,
			PADDLE_WIDTH,
			PADDLE_HEIGHT
		};

		rightPaddle.color = { 0xFF, 0xFF, 0xFF, 0xFF };
		bool rightPaddleUpHeld = false;
		bool rightPaddleDownHeld = false;
		float rightPaddleVelocity = 0.0f;


		Entity leftWall;
		leftWall.position = {
			LEFT_WALL_X,
			LEFT_WALL_Y,
			HORZ_WALL_WIDTH,
			HORZ_WALL_HEIGHT
		};
		leftWall.color = { 0xFF, 0xFF, 0xFF, 0xFF };

		Entity rightWall;
		rightWall.position = {
			RIGHT_WALL_X,
			RIGHT_WALL_Y,
			HORZ_WALL_WIDTH,
			HORZ_WALL_HEIGHT
		};
		rightWall.color = { 0xFF, 0xFF, 0xFF, 0xFF };

		Entity topWall;
		topWall.position = {
			TOP_WALL_X,
			TOP_WALL_Y,
			VERT_WALL_WIDTH,
			VERT_WALL_HEIGHT
		};
		topWall.color = { 0xFF, 0xFF, 0xFF, 0xFF };

		Entity bottomWall;
		bottomWall.position = {
			BOTTOM_WALL_X,
			BOTTOM_WALL_Y,
			VERT_WALL_WIDTH,
			VERT_WALL_HEIGHT
		};
		bottomWall.color = { 0xFF, 0xFF, 0xFF, 0xFF };

		CircleEntity ball;
		ball.position = {
			BALL_INIT_X,
			BALL_INIT_Y,
			BALL_RADIUS,
			BALL_RADIUS
		};
		ball.color = { 0xFF, 0xFF, 0xFF, 0xFF };
		ball.radius = BALL_RADIUS;
		Vector2 ballVelocity = { 0.5f, 0.5f };

		float deltaTime = 0.0f;
		Uint32 startTicks = SDL_GetTicks();
		Uint32 lastTicks = 0;

		srand((unsigned)time(NULL));

		float resetBallTimer = 0.0f;
		float timeToResetBall = 1.0f;
		bool resettingBall = false;

		while (!quit) {
			/*startTime = SDL_GetTicks();
			deltaTime = (lastTime - startTime) / 1000.0f;
			lastTime = startTime;*/
			//startTime = SDL_GetTicks();
			deltaTime = (SDL_GetTicks() - startTicks) / 1000.0f;
			//lastTime = startTime;
			startTicks = SDL_GetTicks();

			//printf("deltaTime = %f\n", deltaTime);

			leftPaddleVelocity = 0.0f;
			rightPaddleVelocity = 0.0f;

			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (e.type == SDL_KEYDOWN) {
					switch (e.key.keysym.sym) {
						case SDLK_ESCAPE: {
							quit = true;
						}
					}
				}
				//else if (e.type == SDL_KEYDOWN) {
				//	//Select surfaces based on key press
				//	switch (e.key.keysym.sym)
				//	{

				//		// Left Paddle
				//		case SDLK_w:							
				//			leftPaddleUpHeld = true;
				//			//leftPaddleVelocity -= 1.0f;
				//			break;

				//		case SDLK_s:
				//			leftPaddleDownHeld = true;
				//			//leftPaddleVelocity += 1.0f;
				//			break;

				//		// Right Paddle
				//		case SDLK_UP:
				//			rightPaddleUpHeld = true;
				//			break;

				//		case SDLK_DOWN:
				//			printf("Down");
				//			break;

				//		default:
				//			printf("Default");
				//			break;
				//	}
				//}
				//else if (e.type == SDL_KEYUP) {
				//	//Select surfaces based on key press
				//	switch (e.key.keysym.sym)
				//	{

				//		// Left Paddle
				//	case SDLK_w:
				//		leftPaddleUpHeld = false;
				//		//leftPaddleVelocity += 1.0f;
				//		break;

				//	case SDLK_s:
				//		leftPaddleDownHeld = false;
				//		//leftPaddleVelocity -= 1.0f;
				//		break;

				//		// Right Paddle
				//	case SDLK_UP:
				//		printf("Up");
				//		break;

				//	case SDLK_DOWN:
				//		printf("Down");
				//		break;

				//	default:
				//		printf("Default");
				//		break;
				//	}
				//}
			}

			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

			// Not sure which this isn't working
			//if (currentKeyStates[SDLK_w]) {
			//	leftPaddleVelocity -= 1.0f;
			//}

			//if (currentKeyStates[SDLK_s]) {
			//	leftPaddleVelocity += 1.0f;
			//}

			// This works
			if (currentKeyStates[SDL_SCANCODE_W]) {
				leftPaddleVelocity -= 1.0f;
			}

			if (currentKeyStates[SDL_SCANCODE_S]) {
				leftPaddleVelocity += 1.0f;
			}

			//if (currentKeyStates[SDLK_up]) {
			//	rightPaddleVelocity -= 1.0f;
			//}

			//if (currentKeyStates[SDLK_DOWN]) {
			//	rightPaddleVelocity += 1.0f;
			//}

			// This works
			if (currentKeyStates[SDL_SCANCODE_UP]) {
				rightPaddleVelocity -= 1.0f;
			}

			if (currentKeyStates[SDL_SCANCODE_DOWN]) {
				rightPaddleVelocity += 1.0f;
			}

			leftPaddle.position.y += leftPaddleVelocity * PADDLE_SPEED * deltaTime;
			rightPaddle.position.y += rightPaddleVelocity * PADDLE_SPEED * deltaTime;

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
				ball.position.y += ballVelocity.y * BALL_SPEED * deltaTime; // Moving X
				ball.position.x += ballVelocity.x * BALL_SPEED * deltaTime; // Moving Y
			}

			/////////////////////////
			// Paddles Collision
			/////////////////////////

			// Left
			if (CheckCollision(leftPaddle.position, bottomWall.position)) {
				// Undo Move
				leftPaddle.position.y -= leftPaddleVelocity * PADDLE_SPEED * deltaTime;
			}

			if (CheckCollision(leftPaddle.position, topWall.position)) {
				// Undo Move
				leftPaddle.position.y -= leftPaddleVelocity * PADDLE_SPEED * deltaTime;
			}

			// Right
			if (CheckCollision(rightPaddle.position, bottomWall.position)) {
				// Undo Move
				rightPaddle.position.y -= rightPaddleVelocity * PADDLE_SPEED * deltaTime;
			}

			if (CheckCollision(rightPaddle.position, topWall.position)) {
				// Undo Move
				rightPaddle.position.y -= rightPaddleVelocity * PADDLE_SPEED * deltaTime;
			}

			/////////////////////////
			// Ball Collision
			/////////////////////////
			
			// Vertical Walls
			if (CheckCollision(ball, topWall.position)) {
				ballVelocity.y = -ballVelocity.y;
				ball.position.y += ballVelocity.y * BALL_SPEED * deltaTime; // Moving down
			}
			else if (CheckCollision(ball, bottomWall.position)) {
				ballVelocity.y = -ballVelocity.y;
				ball.position.y += ballVelocity.y * BALL_SPEED * deltaTime; // Moving down
			}

			// Horizontal Walls
			if (CheckCollision(ball, leftWall.position)) {
				ballVelocity.x = -ballVelocity.x;
				ball.position.x += ballVelocity.x * BALL_SPEED * deltaTime; // Moving down

				// Resetting ball
				ball.position.x = BALL_INIT_X;
				ball.position.y = BALL_INIT_Y;
				
				if (rand() % 2) {
					ballVelocity.x = -ballVelocity.x;
				}

				if (rand() % 2) {
					ballVelocity.y = -ballVelocity.y;
				}

				resettingBall = true;
				rightScore++;
				rightScoreChanged = true;
			}
			else if (CheckCollision(ball, rightWall.position)) {
				ballVelocity.x = -ballVelocity.x;
				ball.position.x += ballVelocity.x * BALL_SPEED * deltaTime; // Moving down

				// Resetting ball
				ball.position.x = BALL_INIT_X;
				ball.position.y = BALL_INIT_Y;

				if (rand() % 2) {
					ballVelocity.x = -ballVelocity.x;
				}

				if (rand() % 2) {
					ballVelocity.y = -ballVelocity.y;
				}

				resettingBall = true;
				leftScore++;
				leftScoreChanged = true;
			}


			// Left Paddles
			if (CheckCollision(ball, leftPaddle.position)) {
				//ballVelocity.x = -ballVelocity.x;
				//ball.position.x += ballVelocity.x * BALL_SPEED * deltaTime; // Moving down
				
				bool ballAbovePaddle = ball.position.y >= leftPaddle.position.y;
				bool ballRightOfPaddle = ball.position.x >= leftPaddle.position.x + PADDLE_WIDTH;

				// Check ball if above paddle
				if (ballAbovePaddle) {
					// Check if ball is to the right of the left paddle
					if (ballRightOfPaddle) {
						// Hit sweet spot on corner
					}
					else {
						// Hit Top -> bounce off top
						ballVelocity.y = -ballVelocity.y;
						ball.position.y += ballVelocity.y * BALL_SPEED * deltaTime; // Moving down
					}
				}
				//
				else {
					// Diff
					printf("Paddle Hit Side");
					ballVelocity.x = -ballVelocity.x;
					ball.position.x += ballVelocity.x * BALL_SPEED * deltaTime; // Moving down

					float paddleHalfHeight = PADDLE_HEIGHT / 2.0f;
					float paddleCenterY = leftPaddle.position.y - paddleHalfHeight;
					float diffFromPaddleCenter = abs(paddleCenterY - ball.position.y);
					ballVelocity.y = 0.5f * (diffFromPaddleCenter / paddleHalfHeight);
					if (ball.position.y < paddleCenterY) {
						ballVelocity.y *= -1;
					}
					ball.position.y += ballVelocity.y * BALL_SPEED * deltaTime; // Moving down
				}


				//// Check if Ball is above or below paddle
				//if (ball.position.x >= leftPaddle.position.x && ball.position.x < leftPaddle.position.x + PADDLE_WIDTH) {
				//	ballVelocity.y = -ballVelocity.y;
				//	ball.position.y += ballVelocity.y * BALL_SPEED * deltaTime; // Moving down

				//	// Do you care if it is above or below
				//	//if (ball.position.y >= leftPaddle.position.y) {
				//	//	// Above
				//	//	
				//	//}
				//	//else {
				//	//	// Below
				//	//}

				//}
				//// Ball is in front of left paddle
				//// Check if ball is above paddle (hit paddle corner) or within paddle (hit paddle side)
				//else if (ball.position.y >= leftPaddle.position.y) {
				//	// Max Angle Hit
				//	if (ballVelocity.x > 0) {
				//		ballVelocity.x = 0.5f;
				//	}
				//	else if (ballVelocity.x < 0) {
				//		ballVelocity.x = 0.5f;
				//	}
				//	else {
				//		ballVelocity.x = 0.0f;
				//	}
				//	// Flip for hit
				//	//ballVelocity.x = -ballVelocity.x;

				//	ballVelocity.x = 0.5f;
				//	if (ballVelocity.y > 0) {
				//		ballVelocity.y = 0.5;
				//	}
				//	else {

				//	}
				//}
				//// Ball hit paddle side
				//else {
				//	// Diff
				//	printf("Paddle Hit Side");
				//	float paddleHalfHeight = PADDLE_HEIGHT / 2.0f;
				//	float paddleCenterY = leftPaddle.position.y - paddleHalfHeight;
				//	float diffFromPaddleCenter = abs(paddleCenterY - ball.position.y);
				//	ballVelocity.y = 0.5f * (diffFromPaddleCenter / paddleHalfHeight);
				//	if (ball.position.y < 0) {
				//		ballVelocity.y *= -1;
				//	}
				//}

				// Ball above paddle
				// Ball within paddle
				// Ball below
			}

			// Right Paddle
			if (CheckCollision(ball, rightPaddle.position)) {
				ballVelocity.x = -ballVelocity.x;
				//float collidedX = ClosestXToCircle(ball, leftPaddle.position);				
				ball.position.x += ballVelocity.x * BALL_SPEED * deltaTime; // Moving down
			}

			//if (CheckCollision(ball, rightPaddle.position)) {
			//	ballVelocity.y = -ballVelocity.y;
			//	ball.position.y += ballVelocity.y * BALL_SPEED * deltaTime; // Moving down
			//}

			if (leftScoreChanged) {
				// Update texture
				leftTextTexture = LoadTextTexture(renderer, font, std::to_string(leftScore), textColor);
				leftScoreChanged = false;
			}

			if (rightScoreChanged) {
				// Update texture
				rightTextTexture = LoadTextTexture(renderer, font, std::to_string(rightScore), textColor);
				rightScoreChanged = false;
			}

			/////////////////////////
			// Render Pass
			/////////////////////////

			//Clear screen to Black
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(renderer);
#if 0



			/////////////////////////
			// Render Entities
			/////////////////////////

			// Draw Paddles
			SDL_SetRenderDrawColor(renderer, leftPaddle.color.r, leftPaddle.color.g, leftPaddle.color.b, leftPaddle.color.a);
			SDL_RenderFillRectF(renderer, &leftPaddle.position);

			SDL_SetRenderDrawColor(renderer, rightPaddle.color.r, rightPaddle.color.g, rightPaddle.color.b, rightPaddle.color.a);
			SDL_RenderFillRectF(renderer, &rightPaddle.position);

			// Draw Walls
			SDL_SetRenderDrawColor(renderer, leftWall.color.r, leftWall.color.g, leftWall.color.b, leftWall.color.a);
			SDL_RenderFillRectF(renderer, &leftWall.position);

			SDL_SetRenderDrawColor(renderer, rightWall.color.r, rightWall.color.g, rightWall.color.b, rightWall.color.a);
			SDL_RenderFillRectF(renderer, &rightWall.position);

			SDL_SetRenderDrawColor(renderer, topWall.color.r, topWall.color.g, topWall.color.b, topWall.color.a);
			SDL_RenderFillRectF(renderer, &topWall.position);

			SDL_SetRenderDrawColor(renderer, bottomWall.color.r, bottomWall.color.g, bottomWall.color.b, bottomWall.color.a);
			SDL_RenderFillRectF(renderer, &bottomWall.position);

			// Draw Midline
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			//SDL_RenderDrawPoints(renderer, MIDLINE_POINTS, MIDLINE_POINTS_COUNT);
			//SDL_RenderDrawLines(renderer, MIDLINE_POINTS, MIDLINE_POINTS_COUNT);
			for (int i = 0; i < MIDLINE_LINES_TOTAL_COUNT; i++)
			{
				Line line = midlines[i];
				//if ((i % MIDLINE_LINES_COUNT) == (MIDLINE_LINE_THICKNESS / 2)) {
				//	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
				//}
				SDL_RenderDrawLine(renderer, line.start.x, line.start.y, line.end.x, line.end.y);
				
			}

			// Draw Ball
			SDL_SetRenderDrawColor(renderer, ball.color.r, ball.color.g, ball.color.b, ball.color.a);
			//SDL_RenderFillRectF(renderer, &ballCollider);
			SDL_RenderFillCircle(renderer, ball.position.x, ball.position.y, ball.radius);

			/////////////////////////
			// Render Entities Debug
			/////////////////////////

			// Paddle Position (Top Left)
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green
			SDL_RenderDrawPointF(renderer, leftPaddle.position.x, leftPaddle.position.y);
			SDL_RenderDrawPointF(renderer, rightPaddle.position.x, rightPaddle.position.y);

			// Ball Position (Center)
			SDL_RenderDrawPointF(renderer, ball.position.x, ball.position.y);

			// Ball Collider
			SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Yellow
			SDL_FRect ballCollider = { ball.position.x - ball.radius, ball.position.y - ball.radius, 2.0f * ball.radius, 2.0f * ball.radius };
			SDL_RenderDrawRectF(renderer, &ballCollider);

#endif // 0

			/////////////////////////
			// Render Text
			/////////////////////////

			//Render text texture to screen
			//SDL_RenderCopy(renderer, textTexture, NULL, NULL);
			//const SDL_Rect leftTextDestRect = {
			//	LEFT_SCORE_TEXT_X,
			//	LEFT_SCORE_TEXT_Y,
			//	SCORE_TEXT_WIDTH,
			//	SCORE_TEXT_HEIGHT
			//};
			//SDL_RenderCopyEx(renderer, leftTextTexture, NULL, &leftTextDestRect, 0, NULL, SDL_FLIP_NONE);

			//const SDL_Rect rightTextDestRect = {
			//	RIGHT_SCORE_TEXT_X,
			//	RIGHT_SCORE_TEXT_Y,
			//	SCORE_TEXT_WIDTH,
			//	SCORE_TEXT_HEIGHT
			//};
			//SDL_RenderCopyEx(renderer, rightTextTexture,NULL, &rightTextDestRect, 0, NULL, SDL_FLIP_NONE);

			const SDL_FRect titleDestRect = title.rect;
			SDL_RenderCopyExF(renderer, title.texture, NULL, &titleDestRect, 0, NULL, SDL_FLIP_NONE);

			// Render button
			SDL_SetRenderDrawColor(renderer, playButton.color.r, playButton.color.g, playButton.color.b, playButton.color.a);
			const SDL_FRect playButtonDestRect = playButton.rect;
			SDL_RenderFillRectF(renderer, &playButtonDestRect);
			const SDL_FRect playButtonTextDestRect = playButton.text.rect;
			SDL_RenderCopyExF(renderer, playButtonText.texture, NULL, &playButtonTextDestRect, 0, NULL, SDL_FLIP_NONE);

			// Render button
			SDL_SetRenderDrawColor(renderer, optionsButton.color.r, optionsButton.color.g, optionsButton.color.b, optionsButton.color.a);
			const SDL_FRect optionsButtonDestRect = optionsButton.rect;
			SDL_RenderFillRectF(renderer, &optionsButtonDestRect);
			const SDL_FRect optionsButtonTextDestRect = optionsButton.text.rect;
			SDL_RenderCopyExF(renderer, optionsButtonText.texture, NULL, &optionsButtonTextDestRect, 0, NULL, SDL_FLIP_NONE);

			// Render button
			SDL_SetRenderDrawColor(renderer, quitButton.color.r, quitButton.color.g, quitButton.color.b, quitButton.color.a);
			const SDL_FRect quitButtonDestRect = quitButton.rect;
			SDL_RenderFillRectF(renderer, &quitButtonDestRect);
			const SDL_FRect quitButtonTextDestRect = quitButton.text.rect;
			SDL_RenderCopyExF(renderer, quitButtonText.texture, NULL, &quitButtonTextDestRect, 0, NULL, SDL_FLIP_NONE);


			SDL_RenderPresent(renderer);

			int frameTicks = SDL_GetTicks() - startTicks;
			if (frameTicks < SCREEN_TICKS_PER_FRAME)
			{
				//Wait remaining time
				SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
			}

		}
	}



	SDL_DestroyTexture(texture);
	texture = NULL;

	SDL_DestroyTexture(rightTextTexture);
	rightTextTexture = NULL;
	SDL_DestroyTexture(leftTextTexture);
	leftTextTexture = NULL;

	TTF_CloseFont(font);

	//Deallocate surface
	SDL_FreeSurface(windowSurface);
	windowSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;



	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}