#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
class Game;

class Ball: public sf::CircleShape
{
public:
    Ball(sf::Color col, sf::Vector2f pos, float speed);

    bool moveUp = false;
    bool moveRight = false;
    float speed = 1;
    float dx = 0, dy = 0;

    void update(Game& game, sf::RectangleShape& a, sf::RectangleShape& b);
};

#endif // BALL_H
