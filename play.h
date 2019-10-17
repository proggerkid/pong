#ifndef PLAY_H
#define PLAY_H

#include "gamestate.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "ball.h"

class Play: public Gamestate
{
public:
    Play();

    sf::Font font;
    sf::Text playerAPoints;
    sf::Text playerBPoints;


    void handleEvent(Game& game);
    void update(Game& game);
    void draw(Game& game);

private:
    std::unique_ptr<Ball> uptBall;
    std::shared_ptr<Paddle> sptPad1;
    std::shared_ptr<Paddle> sptPaddleKi;
};

#endif // PLAY_H
