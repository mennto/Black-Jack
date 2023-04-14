#include "Player.h"
#include "Card.h"
#include <string>

Player::Player(bool isPlayer){
	this->isPlayer = isPlayer;
	cash = 1000;
	currentBet = 10;
	font = TTF_OpenFont("assets/font/font1.ttf", 24);
}

void Player::render(){
	for (int i = 0; i < my_Hand.size(); i++) {
		SDL_Rect src = my_Hand[i].getSrcRect();
		SDL_Rect dest = my_Hand[i].getDestRect();
		//if (isPlayer)
			SDL_RenderCopy(game->getRender(), my_Hand[i].getTexture(), &src, &dest);
		/*else {
			my_Hand[i].setTexture(TextureMaker::makeTexture(game->getRender(), "assets/features/back.png"));
			SDL_RenderCopy(game->getRender(), my_Hand[i].getTexture(), &src, &dest);
		}*/
	}
	if (isPlayer) {
		//draw your score
		renderFont("Your score:"+ std::to_string(score), 600, 450);
		renderFont("Your bet:"+ std::to_string(currentBet) + " coins", 325, 550);
		renderFont("Your cash:"+ std::to_string(cash), 325, 650);
	}
}

void Player::renderFont(std::string str,int x,int y){
	SDL_Surface* surface = TTF_RenderText_Solid(font, str.c_str(), {255, 255, 255});
	SDL_Texture* texture = SDL_CreateTextureFromSurface(game->getRender(), surface);
	SDL_Rect numRect = { x, y, surface->w, surface->h };
	SDL_RenderCopy(game->getRender(), texture, NULL, &numRect);
}

void Player::update() {
	for (int i = 0; i < my_Hand.size(); i++) {
		if (my_Hand[i].getOnTarget()) {
			SDL_Rect a = my_Hand[i].getDestRect();
			a.x -= 7;
			if (isPlayer) {
				a.y += 7;
				if (a.x >= my_Hand[i].getTargetRect().x || a.y <= my_Hand[i].getTargetRect().y) {
					my_Hand[i].changePosition(a);
				}
				else {
					my_Hand[i].changePosition(my_Hand[i].getTargetRect());
					my_Hand[i].setOnTarget(false);
				}
			}
			else {
				a.y -= 7;
				if (a.x >= my_Hand[i].getTargetRect().x || a.y >= my_Hand[i].getTargetRect().y) {
					my_Hand[i].changePosition(a);
				}
				else {
					my_Hand[i].changePosition(my_Hand[i].getTargetRect());
					my_Hand[i].setOnTarget(false);
				}
			}
		}
	}
}

void Player::takeCard(Card card, SDL_Rect destRect,std::string fileName){
	card.setTargetRect(destRect);
	card.setOnTarget(true);
	card.setTexture(TextureMaker::makeTexture(game->getRender(), fileName.c_str()));
	getMyHand()->push_back(card);
}

void Player::toCountScore(){
	score = 0;
	for (int i = 0; i < my_Hand.size(); i++) {
		score += my_Hand[i].getValue();
	}
}

void Player::dealerMove(int playerScore){
	while (score < 21 || score < playerScore) {

	}
}

void Player::printEndGame(std::string str){
	renderFont(str, 300, 300);
}

void Player::dropHand(){
	my_Hand.clear();
}
