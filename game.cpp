#include "game.h"

Game::Game()
{
    window.create(sf::VideoMode(800, 600), "Pong");
}

void Game::run(){
    while(window.isOpen()){
        currState->handleEvent(*this);
        currState->update(*this);

        window.clear();
        currState->draw(*this);
        window.display();
    }
}

void Game::changeState(gameStates newState){
    switch(newState){
        case gameStates::PLAY:
            currState = std::move(std::unique_ptr<Play>(new Play()));
        break;
        case gameStates::MAINMENUE:
            currState = std::move(std::unique_ptr<Menue>(new Menue()));
        break;
    }
}
