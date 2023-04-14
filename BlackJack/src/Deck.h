#pragma once

#include <vector>
//#include "Card.h"

class Deck {

public:
	Deck();
	~Deck();

	void dropDeck();
	void createDeck();
	void mixDeck();
	void renderDeck();
	
	std::vector<class Card>* getMyDeck() { return &my_Deck; }

private:
	std::vector<class Card> my_Deck;
};
