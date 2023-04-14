#include "Button.h"
#include "VisualObject.h"

Button::Button():VisualObj(){
}

Button::Button(int x, int y, int srcRectW, int srcRectH, int srcRectX, int srcRectY) 
   : VisualObj( x, y,srcRectW, srcRectH, srcRectX, srcRectY) {
}

bool Button::clickOnButton(SDL_Event event) {
    if (event.button.button == SDL_BUTTON_LEFT && event.button.x >= this->getXPos() && event.button.x < this->getXPos() + this->getDestRect().w &&
        event.button.y >= this->getYPos() && event.button.y < this->getYPos() + this->getDestRect().h)
        return true;
    return false;

}

void Button::deleteButton(){
	delete this;
}
