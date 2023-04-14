#pragma once

#include "VisualObject.h"
class TextureMaker {
public:
	static SDL_Texture* makeTexture(SDL_Renderer* renderer, const char* fileName);
	static std::string getPath(class Card card);
};