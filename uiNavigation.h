#pragma once
#include "uiButton.h"

struct uiNavigation {
	int currentIndex = 0;
	int previousIndex = 0;
	uiButton* currentButton;
	uiButton* previousButton;
	uiButton** nav;
	int navLength = 0;
};

void init(uiNavigation* uiNavigation);
void next(uiNavigation* uiNavigation);
void previous(uiNavigation* uiNavigation);