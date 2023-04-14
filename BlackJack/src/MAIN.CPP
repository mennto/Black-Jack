#include "Game.h"
#include "Button.h"
#include "Card.h"
#include "TextureMaker.h"
#include "Player.h"

#define  WIDTH = 1280;
#define  HEIGHT = 720;

 Game* Game::game_ = nullptr;

 int main(int argc, char* arg[]) {

     game = Game::getInstance();
     game->init("Black Jack", 1360, 720);
     auto buttons = game->getButtonQueue();
     SDL_Rect cardTargetForDealer, cardTargetForPlayer;
     Button* startButton = buttons->find("start")->second;
     Button* hitButton=nullptr;
     Button* betButton = nullptr;
     Button* plusButton = nullptr;
     Button* minusButton = nullptr;
     Button* standButton = nullptr;
     Button* restartButton = nullptr;
     Player* player = nullptr;
     Player* dealer = nullptr;
     bool menu=true;
     bool bet = false;
     bool playerMove = true;
     bool gameOver = false;
    
     cardTargetForDealer.x = 750;
     cardTargetForDealer.y = -200;

     cardTargetForPlayer.x = 450;
     cardTargetForPlayer.y = 500;
     


     while (game->getIsRunning()) {

         game->render();
         SDL_Event event;
         if (!menu&&!playerMove && (dealer->getScore()+5 < 21 || dealer->getScore()+5 < player->getScore())) {
             cardTargetForDealer.x -= 50;
             dealer->takeCard(game->getDeck()->getMyDeck()->back(), cardTargetForDealer, "assets/features/back.png");
             dealer->toCountScore();
             game->getDeck()->getMyDeck()->pop_back();
         }
         else if (!game->getEndGame() && !gameOver && !playerMove && !menu && (dealer->getScore() + 5 >= 21 || dealer->getScore() + 5 >= player->getScore())) {
             std::string str;
             for (int i = 0; i < dealer->getMyHand()->size(); i++) {
                 dealer->getMyHand()->at(i).setTexture(TextureMaker::makeTexture(game->getRender(), TextureMaker::getPath(dealer->getMyHand()->at(i)).c_str()));
             }
             game->showRestartButton();
             restartButton = buttons->find("restart")->second;
             if (player->getScore() > dealer->getScore() && player->getScore() <= 21&&dealer->getScore()<=21) {
                 player->setCash(player->getCash() + player->getCurrentBet() * 2);
             }
             else if (player->getScore() == dealer->getScore() && player->getScore() <= 21){

             }
             gameOver = true;
         }
         
         while (SDL_PollEvent(&event)) {
             if (event.type == SDL_QUIT) {
                 game->setIsRunning(false);
             }
             switch (event.type)
             {
                 //game quit
             case SDL_QUIT:
                 game->setIsRunning(false);
                 break;

             case SDL_MOUSEBUTTONDOWN:
                  //start button event
                 if (startButton->clickOnButton(event)) {
                     if (menu) {
                         buttons->erase("start");
                         game->startGame();
                         hitButton= buttons->find("hit")->second;
                         betButton= buttons->find("bet")->second;
                         plusButton = buttons->find("plusBet")->second;
                         minusButton = buttons->find("minusBet")->second;
                         standButton = buttons->find("stand")->second;
                         player = game->getPlayers()->find("player")->second;
                         dealer = game->getPlayers()->find("dealer")->second;
                         menu = false;
                     }
                 }
                 //bet button event
                 if (betButton!=nullptr&&betButton->clickOnButton(event)&&!bet) {
                     int cardGiven = 0;
                     for (int i = 0; i < 4; i++) {
                         Card& card = game->getDeck()->getMyDeck()->back();
                         if (playerMove) {
                             cardTargetForPlayer.x += 50;
                             game->getPlayers()->find("player")->second->takeCard(card, cardTargetForPlayer, TextureMaker::getPath(card));
                             cardGiven++;
                             if (cardGiven == 2)
                                 playerMove = false;
                         }
                         else {
                             cardTargetForDealer.x -= 50;
                            dealer->takeCard(card, cardTargetForDealer, "assets/features/back.png");
                         }
                         //player->;
                         game->getDeck()->getMyDeck()->pop_back();
                     }
                     player->toCountScore();
                     player->setCash(player->getCash() - player->getCurrentBet());
                     playerMove = true;
                     bet = true;
                 }
                 //hit button event
                 if (hitButton != nullptr && hitButton->clickOnButton(event) && bet && (player->getScore() <= 21 && playerMove)/*your score<21*/) {
                     Card& card = game->getDeck()->getMyDeck()->back();
                     cardTargetForPlayer.x += 50;
                     game->getPlayers()->find("player")->second->takeCard(card, cardTargetForPlayer, TextureMaker::getPath(card));
                     player->toCountScore();
                     if (player->getScore() >= 21)
                         playerMove = false;
                     game->getDeck()->getMyDeck()->pop_back();
                 }

                 //plus bet button event
                 if (plusButton != nullptr && plusButton->clickOnButton(event) && !bet) {
                     if (player->getCurrentBet() + 10 <= player->getCash())
                         player->setCurrentBet(player->getCurrentBet() + 10);
                 }

                 //minus bet button event
                 if (minusButton != nullptr && minusButton->clickOnButton(event) && !bet) {
                     if (player->getCurrentBet() > 10)
                         player->setCurrentBet(player->getCurrentBet() - 10);
                 }

                 //stand button event
                 if (standButton != nullptr && standButton->clickOnButton(event) && bet) {
                     playerMove = false;
                 }
                 //restart button event
                 if (restartButton != nullptr && restartButton->clickOnButton(event)) {
                     if (player->getCash() <= 0) {
                         game->setIsRunning(false);
                     }
                     else
                     {
                         game->restartGame();
                         buttons->erase("restart");
                         player->setCurrentBet(10);
                         dealer->setScore(0);
                         player->setScore(0);
                         bet = false;
                         playerMove = true; 
                         cardTargetForDealer.x = 750;
                         cardTargetForDealer.y = -200;
                         cardTargetForPlayer.x = 450;
                         cardTargetForPlayer.y = 500;
                     }
                     
                 }
                 break;
             default:
                 break;
             }
         }



     }
     game->clean();
     return 0;
 }