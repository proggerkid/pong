#include "play.h"
#include "game.h"

Play::Play()
{
    uptBall = std::unique_ptr<Ball>(new Ball(sf::Color::Red, sf::Vector2f(400, 300), 0.5));
    sptPad1 = std::shared_ptr<Paddle>(new Paddle(sf::Vector2f(20, 100), sf::Color::Green, 1, sf::Vector2f(25, 300), false));
    sptPaddleKi = std::shared_ptr<Paddle>(new Paddle(sf::Vector2f(20, 100), sf::Color::Green, 1, sf::Vector2f(778, 300), true));

    font.loadFromFile("/home/tom/pong/assets/sagan");
    playerAPoints.setFont(font);
    playerBPoints.setFont(font);

    playerAPoints.setString("0");
    playerAPoints.setFillColor(sf::Color::Green);
    playerAPoints.setCharacterSize(30);
    playerAPoints.setPosition(400, 30);


    playerBPoints.setString("0");
    playerBPoints.setFillColor(sf::Color::Green);
    playerBPoints.setCharacterSize(30);
    playerBPoints.setPosition(350, 30);

}

void Play::handleEvent(Game& game){
    sf::Event event;
    while(game.window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            game.window.close();
        }
        if(event.key.code == sf::Keyboard::Escape){
            game.window.close();
        }
    }
}

void Play::update(Game& game){
    uptBall->update(game, *sptPad1, *sptPaddleKi);
    sptPad1->update(game, *uptBall);
    sptPaddleKi->update(game, *uptBall);

    //set ball to center, count points;
    if(uptBall->getPosition().x > game.window.getSize().x){
        sptPad1->points++;
        uptBall->moveRight = false;
        uptBall->setPosition(game.window.getSize().x / 2, game.window.getSize().y / 2);
        uptBall->speed = 0.5;
        playerBPoints.setString(std::to_string(sptPad1->points));
    }
    if(uptBall->getPosition().x < 0){
        sptPaddleKi->points++;
        uptBall->moveRight = true;
        uptBall->setPosition(game.window.getSize().x / 2, game.window.getSize().y / 2);
        uptBall->speed = 0.5;
        playerAPoints.setString(std::to_string(sptPaddleKi->points));
    }
}

void Play::draw(Game &game){
    game.window.draw(*uptBall);
    game.window.draw(*sptPad1);
    game.window.draw(*sptPaddleKi);
    game.window.draw(playerAPoints);
    game.window.draw(playerBPoints);

}
