#include "VisualObject.h"

VisualObj::VisualObj(){
}

VisualObj::VisualObj(int x, int y, int srcRectW, int srcRectH, int srcRectX, int srcRectY){
	position.pos_X = x;
	position.pos_Y = y;
	position.srcRect.w = srcRectW;
	position.srcRect.h = srcRectH;
	position.srcRect.x = srcRectX;
	position.srcRect.y = srcRectY;
	position.destRect.w = srcRectW*2;
	position.destRect.h = srcRectH * 2;
	position.destRect.x = x;
	position.destRect.y = y;
	clicked = false;

}

VisualObj::Position::Position() {

}


void VisualObj::render(){
	SDL_RenderCopy(game->getRender(), texture, &position.srcRect, &position.destRect);
}

void VisualObj::changePosition(SDL_Rect rect){
	position.destRect.x = rect.x;
	position.destRect.y = rect.y;
}
