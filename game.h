#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "menue.h"
#include "play.h"
#include "gamestate.h"

class Game
{
public:
    Game();

    enum gameStates{
        PLAY,
        MAINMENUE
    };

    sf::RenderWindow window;
    std::unique_ptr<Gamestate> currState;


    void run();
    void changeState(gameStates newState);
};

#endif // GAME_H
