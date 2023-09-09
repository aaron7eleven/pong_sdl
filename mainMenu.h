#pragma once
#include <SDL.h>
//#include "app.h"
#include "uiText.h"
#include "color.h"
#include "title.h"
#include "playButton.h"
#include "optionsButton.h"
#include "quitButton.h"

struct mainMenu {
	title title;
	//playButtonText playButtonText;
	playButton playButton;
	optionsButton optionsButton;
	quitButton quitButton;
	//uiText title = {
	//	"titleText",
	//	"Pong",
	//	NULL,
	//	"assets/font/DotGothic16-Regular.ttf",
	//	100,
	//	{480, 45, 320, 180}, // {x,y,w,h}
	//	white,
	//	NULL,
	//	false
	//};

	//uiText playButtonText = {
	//	"Play",
	//	NULL,
	//	"assets/font/DotGothic16-Regular.ttf",
	//	100,
	//	{565, 270, 150, 90}, // {x,y,w,h}
	//	white,
	//	NULL,
	//	false
	//};

	//uiText optionsButtonText = {
	//	"Options",
	//	NULL,
	//	"assets/font/DotGothic16-Regular.ttf",
	//	100,
	//	//{640, 270, 180, 90}, // {x,y,w,h}
	//	{505, 360, 270, 90}, // {x,y,w,h}
	//	white,
	//	NULL,
	//	false
	//};

	//uiText quitButtonText = {
	//	"Quit",
	//	NULL,
	//	"assets/font/DotGothic16-Regular.ttf",
	//	100,
	//	//{640, 270, 180, 90}, // {x,y,w,h}
	//	{550, 450, 180, 90}, // {x,y,w,h}
	//	white,
	//	NULL,
	//	false
	//};

	//float		playButtonWidth = screenWidth / 4;
	//float		playButtonHeight = screenHeight / 8;
	//float		playButtonX = (screenWidth / 2) - playButtonTextWidth / 2;;
	//float		playButtonY = screenHeight * 3 / 8;
	//SDL_FRect	playButtonRectTranform = {
	//	playButtonWidth,
	//	playButtonHeight,
	//	playButtonX,
	//	playButtonY
	//};
	//SDL_Color	playButtonHighlightedButtonColor = white;
	//SDL_Color	playButtonIdleButtonColor = black;
	//SDL_Color	playButtonHighlightedTextColor = black;
	//SDL_Color	playButtonIdleTextColor = white;

	//float		playButtonTextWidth = screenWidth / 8;
	//float		playButtonTextHeight = screenHeight / 8;
	//float		playButtonTextX = playButtonX;
	//float		playButtonTextY = playButtonY;
	//SDL_FRect	playButtonTextRectTranform = {
	//	playButtonTextWidth,
	//	playButtonTextHeight,
	//	playButtonTextX,
	//	playButtonTextY
	//};
	//std::string playButtonText = "Play";
	//SDL_Color	playButtonTextColor = playButtonIdleTextColor;

	//float		optionsButtonWidth = screenWidth / 4;
	//float		optionsButtonHeight = screenHeight / 8;
	//float		optionsButtonX = (screenWidth / 2) - optionsButtonWidth / 2;;
	//float		optionsButtonY = screenHeight * 4 / 8;
	//SDL_FRect	optionsButtonRectTranform = {
	//	optionsButtonWidth,
	//	optionsButtonHeight,
	//	optionsButtonX,
	//	optionsButtonY
	//};
	//SDL_Color	optionsButtonHighlightedButtonColor = white;
	//SDL_Color	optionsButtonIdleButtonColor = black;
	//SDL_Color	optionsButtonHighlightedTextColor = black;
	//SDL_Color	optionsButtonIdleTextColor = white;

	//float		optionsButtonTextWidth = screenWidth / 6;
	//float		optionsButtonTextHeight = screenHeight / 8;
	//float		optionsButtonTextX = optionsButtonX;
	//float		optionsButtonTextY = optionsButtonY;
	//SDL_FRect	optionsButtonTextRectTranform = {
	//	optionsButtonTextWidth,
	//	optionsButtonTextHeight,
	//	optionsButtonTextX,
	//	optionsButtonTextY
	//};
	//std::string optionsButtonText = "Play";
	//SDL_Color	optionsButtonTextColor = optionsButtonIdleTextColor;

	//float		quitButtonWidth = screenWidth / 4;
	//float		quitButtonHeight = screenHeight / 8;
	//float		quitButtonX = (screenWidth / 2) - quitButtonWidth / 2;
	//float		quitButtonY = screenHeight * 5 / 8;
	//SDL_FRect	quitButtonRectTranform = {
	//			quitButtonWidth,
	//			quitButtonHeight,
	//			quitButtonX,
	//			quitButtonY
	//};
	//SDL_Color	quitButtonHighlightedButtonColor = white;
	//SDL_Color	quitButtonIdleButtonColor = black;
	//SDL_Color	quitButtonHighlightedTextColor = black;
	//SDL_Color	quitButtonIdleTextColor = white;

	//float		quitButtonTextWidth = screenWidth / 8;
	//float		quitButtonTextHeight = screenHeight / 8;
	//float		quitButtonTextX = optionsButtonX;
	//float		quitButtonTextY = optionsButtonY;
	//SDL_FRect	quitButtonTextRectTranform = {
	//			quitButtonTextWidth,
	//			quitButtonTextHeight,
	//			quitButtonTextX,
	//			quitButtonTextY
	//};
	//std::string quitButtonText = "Quit";
	//SDL_Color	quitButtonTextColor = optionsButtonIdleTextColor;

};

void init(mainMenu* mainMenu);
void render(SDL_Renderer* renderer, mainMenu* mainMenu);