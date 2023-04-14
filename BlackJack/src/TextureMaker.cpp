#pragma warning(disable : 4996)
#include "TextureMaker.h"
#include "Card.h"

SDL_Texture* TextureMaker::makeTexture(SDL_Renderer* renderer, const char* fileName) {
    SDL_Surface* surface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

std::string TextureMaker::getPath(class Card card){
    std::string dotPNG = ".png";
    std::string firstFolder = "assets/suit/";
    std::string foldetPath = card.suitToString(static_cast<Card::Suit>(card.getCardSuit()));
    std::string fileName = card.rankToString(static_cast<Card::Rank>(card.getCardRank())) + dotPNG;
    std::string concatenatePath = firstFolder + foldetPath + fileName;
    return concatenatePath;
}