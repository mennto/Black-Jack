#pragma once
#include "VisualObject.h"
class VisualObj;

class Card: public VisualObj {

public:
	enum Rank { ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	//Rank r = ACE, Suit s = SPADES

	Card();
	Card(int x, int y, int srcRectW, int srcRectH, int srcRectX, int srcRectY, Rank r = ACE, Suit s = CLUBS);
	~Card();

	/*void setCardRank(int x) { card_Rank = x; }
	void setCardSuit(int x) { card_Suit = x; }*/


	Rank getCardRank() { return card_Rank; }
	Suit getCardSuit() { return card_Suit; }


	void click();
	int getValue();

	std::string rankToString(Rank r);
	std::string suitToString(Suit s);

	//void setPosition(int x, int y) { position.destRect.x = x; position.destRect.y = y; }

private:
	Rank card_Rank;
	Suit card_Suit;

	bool taken;
};