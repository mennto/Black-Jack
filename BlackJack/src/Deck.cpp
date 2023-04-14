#include "Deck.h"
#include "Card.h"
#include <random>

Deck::Deck() {
	
}

void Deck::dropDeck(){
	my_Deck.clear();
}

void Deck::createDeck(){
	my_Deck.reserve(52);
	for (int rank = Card::ACE; rank <= Card::KING; ++rank) {
		for (int suit = Card::CLUBS; suit <= Card::SPADES; ++suit) {
			//create cards
			my_Deck.push_back(Card(1100 + rank * 2, 100, 98, 157, 0, 0, static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)));
			my_Deck.back().setTexture(TextureMaker::makeTexture(game->getRender(), "assets/features/back.png"));
			//my_Deck.back().setTexture(TextureMaker::makeTexture(game->getRender(), TextureMaker::getPath(my_Deck.back()).c_str()));
		}
	}
}

void Deck::mixDeck(){
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(my_Deck.begin(), my_Deck.end(), g);
}



void Deck::renderDeck() {
	for (int i = 0; i < my_Deck.size(); i++) {
		SDL_Rect src = my_Deck[i].getSrcRect();
		SDL_Rect dest = my_Deck[i].getDestRect();
		SDL_RenderCopy(game->getRender(), my_Deck[i].getTexture(), &src, &dest);
	}
}