#ifndef MENUE_H
#define MENUE_H

#include "gamestate.h"
#include <SFML/Graphics.hpp>


class Menue: public Gamestate
{
public:
    Menue();

    bool bStartGameSelected = false;
    bool bQuitGameSelected = false;
    sf::Font font;
    sf::Text txtStart;
    sf::Text txtQuit;


    void handleEvent(Game& game);
    void update(Game& game);
    void draw(Game& game);
};

#endif // MENUE_H
