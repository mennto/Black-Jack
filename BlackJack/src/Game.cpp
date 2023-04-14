#include "Game.h"
#include "Button.h"

Game::Game() {}
Game::~Game() {}

 Game* Game::getInstance() {
    if (game_ == nullptr) {
        game_ = new Game();
    }
    return game_;
}


 int Game::init(const char* name, int wigth, int height) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window.window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, wigth, height, SDL_WINDOW_SHOWN);
    if (window.window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    window.renderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (window.renderer == nullptr) {
        SDL_DestroyWindow(window.window);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    TTF_Init();

    window.back_Ground = TextureMaker::makeTexture(window.renderer, "assets/image.png");
    is_Running = true;
    addButtonToQueue(400, 500, 225, 90, 0, 0, "assets/features/start.png", "start");
    return 0;
}

 void Game::startGame() {
     
     deck = new Deck();
     deck->createDeck();
     deck->mixDeck();
     addPlayer("player",true);
     addPlayer("dealer",false);
     addButtonToQueue(1100, 500, 100, 50, 0, 0, "assets/features/hit.png", "hit");
     addButtonToQueue(1100, 600, 100, 50, 0, 0, "assets/features/stand.png", "stand");
     addButtonToQueue(100, 500, 50, 50, 0, 0, "assets/features/plusbet.png", "plusBet");
     addButtonToQueue(200, 500,50, 50, 0, 0, "assets/features/minusBet.png", "minusBet");
     addButtonToQueue(100, 600, 100, 50, 0, 0, "assets/features/bet.png", "bet");
 }


void Game::render(){

    SDL_RenderClear(window.renderer);
    SDL_RenderCopy(window.renderer, window.back_Ground, NULL, NULL);
    if (deck != nullptr) {
        deck->renderDeck();
    }
    if (players.size() > 0) {
        players.find("player")->second->render();
        players.find("player")->second->update();
        players.find("dealer")->second->render();
        players.find("dealer")->second->update();
    }
    for (auto it = buttonQueue.begin(); it != buttonQueue.end();it++) {
        it->second->render();
    }
    SDL_RenderPresent(window.renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window.window);
    SDL_DestroyRenderer(window.renderer);
    SDL_Quit();
}

void Game::addButtonToQueue(int x,int y,int srcRectW, int srcRectH, int srcRectX, int srcRectY,
                                                    std::string path, std::string buttonName ){
    if (buttonQueue.count(buttonName) == 0) {
        Button* button = new Button(x, y, srcRectW, srcRectH, srcRectX, srcRectY);
        button->setTexture(TextureMaker::makeTexture(getRender(), path.c_str()));
        buttonQueue.insert(std::make_pair(buttonName, button));
    }
}

void Game::addPlayer(std::string key,bool isPlayer){
    Player* player = new Player(isPlayer);
    players.insert(std::make_pair(key, player));
}

void Game::showRestartButton(){
    addButtonToQueue(300, 300, 100, 50, 0, 0, "assets/features/restart.png", "restart");
    
}

void Game::restartGame(){
    deck->dropDeck();
    deck->createDeck();
    deck->mixDeck();
    players.find("player")->second->dropHand();
    players.find("dealer")->second->dropHand();

}

Game* game;



