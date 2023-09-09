#pragma once
#include "uiNavigation.h"

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
	//UnhighlightUIButton(uiNavigation->previousButton);
	//HighlightUIButton(uiNavigation->currentButton);
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
	//UnhighlightUIButton(uiNavigation->previousButton);
	//HighlightUIButton(uiNavigation->currentButton);
}