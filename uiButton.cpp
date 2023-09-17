#pragma once
#include "uiButton.h"
#include "SDL_wrappers.h"

void highlight(uiButton* button) {
	button->text->color = button->highlightedTextColor;
	button->color = button->highlightedButtonColor;
	button->highlighted = true;
}

void unhighlight(uiButton* button) {
	button->text->color = button->idleTextColor;
	button->color = button->idleButtonColor;
	button->highlighted = false;
}

void init(uiButton* uiButton) {
	init(uiButton->text);
	unhighlight(uiButton);
}

void render(SDL_Renderer* renderer, uiButton* uiButton) {
	// Render button then text
	SDL_SetRenderDrawColor(renderer, uiButton->color);
	SDL_RenderFillRectF(renderer, &uiButton->rect);
	render(renderer, uiButton->text);

	// Debug
	SDL_SetRenderDrawColor(renderer, cyan);
	SDL_RenderDrawRectF(renderer, &uiButton->rect);

}

void centerAlignText(uiButton* button) {
	float buttonCenterX = button->rect.x + (button->rect.w / 2.0f);
	button->text->rect.x = buttonCenterX - (button->text->rect.w / 2.0f);
}

void setButtonText(uiButton* uiButton, std::string text) {
	setText(uiButton->text, text);
	centerAlignText(uiButton);
}

