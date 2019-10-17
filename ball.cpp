#include "ball.h"
#include "game.h"

Ball::Ball(sf::Color col, sf::Vector2f pos, float speed)
{
    this->setRadius(30);
    this->setFillColor(col);
    this->setPosition(pos);
    this->setOrigin(this->getRadius() / 2, this->getRadius() / 2);
    this->speed = speed;
}

void Ball::update(Game& game, sf::RectangleShape& a, sf::RectangleShape& b){
    ///////////////////collision//////////////////////////
    if(getGlobalBounds().intersects(a.getGlobalBounds())){
        moveRight = true;
    }
    if(getGlobalBounds().intersects((b.getGlobalBounds()))){
        moveRight = false;
    }
    ////////////////////ball moovement/////////////////////
    //move up and down
    if(moveUp){
        if(getPosition().y - getRadius() / 2 > 0){
            dy = -speed;
        }
        else{
            moveUp = false;
        }
    }
    if(!moveUp){
        if(getPosition().y + getRadius() / 2 < game.window.getSize().y){
            dy = speed;
        }
        else{
            moveUp = true;
        }
    }
    //move right and left
    if(moveRight){
        this->speed = this->speed + 0.00005;
        dx = speed;
    }
    if(!moveRight){
        this->speed = this->speed + 0.00005;
        dx = -speed;
    }

    move(dx, dy);
}
