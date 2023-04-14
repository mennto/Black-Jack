#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <map>
#include "TextureMaker.h"
#include "Deck.h"
#include "Player.h"

class Card;
class Button;


class Game {
protected:
	Game();
	~Game();
	static Game* game_;

public:
	
	static Game* getInstance();

	int init(const char* name, int wigth, int height);
	void startGame();
	void render();
	void clean();
	void addButtonToQueue(int x, int y, int srcRectW, int srcRectH, int srcRectX, int srcRectY,
		std::string path, std::string buttonName);
	void addPlayer(std::string key,bool isPlayer);
	void showRestartButton();
	void restartGame();
	void setEndGame(bool x) { endGame = x; }
	void setStrEnd(std::string str) { strEnd = str; }

	void setIsRunning(bool x) { is_Running = x; }

	bool getEndGame() { return endGame; }
	bool getIsRunning() { return is_Running; }
	Deck* getDeck() { return deck; }
	SDL_Renderer* getRender() { return window.renderer; }
	SDL_Window* getWindow() { return window.window; }
	SDL_Texture* getBackGround() { return window.back_Ground; }
	std::map<std::string, class Button*>* getButtonQueue() { return &buttonQueue; }
	std::map<std::string, class Player*>* getPlayers() { return &players; }
private:
	struct Window {
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Texture* back_Ground;
	} window;

	class Deck* deck;
	bool is_Running;
	bool endGame;
	std::string strEnd;
	std::map<std::string, class Button*> buttonQueue;
	std::map<std::string, class Player*> players;
	
};

extern Game* game;




