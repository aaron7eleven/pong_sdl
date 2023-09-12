#pragma once
#include "uiNavigation.h"

void init(uiNavigation* uiNavigation) {
	uiNavigation->currentIndex = 0;
	uiNavigation->previousIndex = uiNavigation->navLength - 1;
	uiNavigation->previousButton = uiNavigation->nav[uiNavigation->previousIndex];
	uiNavigation->currentButton = uiNavigation->nav[uiNavigation->currentIndex];
	highlight(uiNavigation->currentButton);
}

void next(uiNavigation* uiNavigation) {
	uiNavigation->previousIndex = uiNavigation->currentIndex;
	if (uiNavigation->currentIndex + 1 >= uiNavigation->navLength) {
		uiNavigation->currentIndex = 0;
	}
	else {
		uiNavigation->currentIndex++;
	}
	uiNavigation->previousButton = uiNavigation->nav[uiNavigation->previousIndex];
	uiNavigation->currentButton = uiNavigation->nav[uiNavigation->currentIndex];
	unhighlight(uiNavigation->previousButton);
	highlight(uiNavigation->currentButton);
}

void previous(uiNavigation* uiNavigation) {
	uiNavigation->previousIndex = uiNavigation->currentIndex;
	if (uiNavigation->currentIndex - 1 < 0) {
		uiNavigation->currentIndex = uiNavigation->navLength - 1;
	}
	else {
		uiNavigation->currentIndex--;
	}
	uiNavigation->previousButton = uiNavigation->nav[uiNavigation->previousIndex];
	uiNavigation->currentButton = uiNavigation->nav[uiNavigation->currentIndex];
	unhighlight(uiNavigation->previousButton);
	highlight(uiNavigation->currentButton);
}