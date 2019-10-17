#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Game;
class Ball;

class Paddle: public sf::RectangleShape
{
public:
    Paddle(sf::Vector2f size, sf::Color color, float speed, sf::Vector2f pos, bool ki);
    
    float speed = 1;
    bool paddleKi = false;
    int points = 0;

    
    void update(Game& game, Ball& ball);
};

#endif // PADDLE_H
