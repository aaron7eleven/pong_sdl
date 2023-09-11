#pragma once
#include "uiNavigation.h"

struct mainMenuNavigation
{
	uiButton* nav[3] = {NULL, NULL, NULL};
	uiNavigation uiNavigation = {
		0,
		0,
		NULL,
		NULL,
		nav,
		3
	};
};

void insertIntoNav(uiNavigation* uiNavigation, uiButton* uiButton, int index);