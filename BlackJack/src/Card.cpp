#include "Card.h"
#include "VisualObject.h"

Card::Card() : VisualObj() {
}

Card::Card(int x, int y, int srcRectW, int srcRectH, int srcRectX, int srcRectY,Rank r, Suit s)
	  : VisualObj(x, y, srcRectW, srcRectH, srcRectX, srcRectY), card_Rank(r), card_Suit(s) {

}

Card::~Card() {}


void Card::click() {
}

int Card::getValue() {
	if (card_Rank == Rank::JACK || card_Rank == Rank::QUEEN || card_Rank == Rank::KING) {
		return 10;
	}
	else if (card_Rank == Rank::ACE) {
		return 11;
	}
	else {
		return static_cast<int>(card_Rank);
	}

}

std::string Card::rankToString(Rank r){
	switch (r){
	case Card::ACE:
		return "ace";
	case Card::TWO:
		return "two";
	case Card::THREE:
		return "three";
	case Card::FOUR:
		return "four";
	case Card::FIVE:
		return "five";
	case Card::SIX:
		return "six";
	case Card::SEVEN:
		return "seven";
	case Card::EIGHT:
		return "eight";
	case Card::NINE:
		return "nine";
	case Card::TEN:
		return "ten";
	case Card::JACK:
		return "jack";
	case Card::QUEEN:
		return "queen";
	case Card::KING:
		return "king";
	default:
		return "none";
	}
	
}

std::string Card::suitToString(Suit s){
	switch (s){
	case Card::CLUBS:
		return "clubs/";
	case Card::DIAMONDS:
		return "diamonds/";
	case Card::HEARTS:
		return "hearts/";
	case Card::SPADES:
		return "spades/";
	default:
		return "none";
	}
}


