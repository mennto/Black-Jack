#pragma once
#include "Game.h" 

class VisualObj {
public:

	VisualObj();
	VisualObj(int x, int y, int srcRectW, int srcRectH, int srcRectX, int srcRectY);

	void render();

	void setTexture(SDL_Texture* tex){ texture = tex; }
	void changePosition(SDL_Rect rect);
	void setXPos(int x) { position.pos_X = x; }
	void setYPos(int y) { position.pos_Y = y; }
	void setSrcRect(SDL_Rect rect) { position.srcRect=rect; }
	void setDestRect(SDL_Rect rect) { position.destRect = rect; }
	//void setVisable(bool x) { visable = x; }
	void setTargetRect(SDL_Rect x) { targetRect = x; }
	void setOnTarget(bool x) { onTarget = x; }
	
	//bool getVisable() { return visable; }
	int getXPos() { return position.pos_X; }
	int getYPos() { return position.pos_Y; }
	bool getOnTarget() { return onTarget; }
	SDL_Texture* getTexture() { return texture; }
	SDL_Rect getSrcRect() { return position.srcRect; }
	SDL_Rect getDestRect() { return position.destRect; }
	SDL_Rect getTargetRect() { return targetRect; }


protected:
	bool clicked;
	//bool visable;
	SDL_Texture* texture;
	SDL_Rect targetRect;
	bool onTarget;
	TTF_Font* font;


	struct Position {
		Position();
		int pos_X;
		int pos_Y;
		SDL_Rect srcRect;
		SDL_Rect destRect;
	} position;
};