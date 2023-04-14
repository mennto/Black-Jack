#pragma once
#include "VisualObject.h"
class VisualObj;

class Button : public VisualObj {
public:
	Button();
	Button(int x, int y, int srcRectW, int srcRectH, int srcRectX, int srcRectY);
	void deleteButton();
	bool clickOnButton(SDL_Event event);
};