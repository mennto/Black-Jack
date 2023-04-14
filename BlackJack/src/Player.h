#pragma once
#include "VisualObject.h"

class Player {
public:

	Player(bool isPlayer);

	void render();
	void renderFont(std::string str, int x, int y);
	void update();
	void setCurrentBet(int x) { currentBet = x; }
	void takeCard(Card card,SDL_Rect destRect,std::string fileName);
	void toCountScore();
	void dealerMove(int playerScore);
	void printEndGame(std::string str);
	void setEndGameRes(std::string str) { endGameRes = str; }
	void dropHand();
	void setScore(int x) { score = x; }

	int getScore() { return score; }
	int getCurrentBet() { return currentBet; }
	int getCash() { return cash; }
	void setCash(int x) { cash = x; }
	std::string getEndGameRes() { return endGameRes; }

	std::vector<class Card>* getMyHand() { return &my_Hand; }

private:
	int cash;
	int currentBet;
	int score;
	bool isPlayer;
	std::string endGameRes;
	TTF_Font* font;
	std::vector<class Card> my_Hand;
};