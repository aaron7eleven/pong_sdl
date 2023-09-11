#pragma once
#include "uiNavigation.h"

void insertIntoNav(uiNavigation* uiNavigation, uiButton* uiButton, int index)
{
	uiNavigation->nav[index] = uiButton;
}