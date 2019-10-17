#include "paddle.h"
#include "game.h"

Paddle::Paddle(sf::Vector2f size, sf::Color color, float speed, sf::Vector2f pos, bool ki)
{
    this->speed = speed;
    setSize(size);
    setOrigin(getSize().x / 2, getSize().y / 2);
    setFillColor(color);
    setPosition(pos);
    paddleKi = ki;
}

void Paddle::update(Game& game, Ball& ball){
    if(paddleKi){
        if(ball.moveRight && ball.getPosition().x > game.window.getSize().x / 2){
            if(ball.getPosition().y > this->getPosition().y){
                move(0, speed);
            }
            if(ball.getPosition().y < this->getPosition().y){
                move(0, -speed);
            }
        }
    }
    else{
        if(
            sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
            getPosition().y - getSize().y / 2 > 0
          ){
            setPosition(getPosition().x, getPosition().y - speed);
        }
        if(
            sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
            getPosition().y + getSize().y / 2 < game.window.getSize().y
          ){
            setPosition(getPosition().x, getPosition().y + speed);
        }
    }
}

