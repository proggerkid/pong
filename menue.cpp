#include "menue.h"
#include "game.h"

Menue::Menue()
{

    font.loadFromFile("/home/tom/pong/assets/sagan");
    txtStart.setFont(font);
    txtStart.setString("START PONG");
    txtStart.setCharacterSize(30);
    txtStart.setFillColor(sf::Color::Red);
    txtStart.setPosition(300, 300);

    txtQuit.setFont(font);
    txtQuit.setString("QUIT GAME");
    txtQuit.setCharacterSize(30);
    txtQuit.setFillColor(sf::Color::Red);
    txtQuit.setPosition(300, 350);
}

void Menue::handleEvent(Game& game){
    sf::Event event;
    while(game.window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            game.window.close();
        }
        if(
            event.type == sf::Event::MouseButtonReleased &&
            event.mouseButton.button == 0 &&
            bStartGameSelected
          )
        {
            game.changeState(game.gameStates::PLAY);
        }
    }
}

void Menue::update(Game &game){
    ////////////////start game button///////////////////////
    if(
        txtStart.getGlobalBounds().contains(
                sf::Mouse::getPosition(game.window).x,
                sf::Mouse::getPosition(game.window).y
                )
        && txtStart.getColor() != sf::Color::Green
      )
    {
        txtStart.setFillColor(sf::Color::Green);
        bStartGameSelected = true;
    }
    else if(!
                txtStart.getGlobalBounds().contains(
                    sf::Mouse::getPosition(game.window).x,
                    sf::Mouse::getPosition(game.window).y
                )
            && txtStart.getColor() != sf::Color::Red
            )
    {
        txtStart.setFillColor(sf::Color::Red);
        bStartGameSelected = false;
    }

    /////////////////////quit game button////////////////////////
    if(
            txtQuit.getGlobalBounds().contains(
                sf::Mouse::getPosition(game.window).x,
                sf::Mouse::getPosition(game.window).y
                )
        && txtQuit.getColor() != sf::Color::Green
      )
    {
        txtQuit.setFillColor(sf::Color::Green);
        bQuitGameSelected = true;
    }
    else if(!
                txtQuit.getGlobalBounds().contains(
                    sf::Mouse::getPosition(game.window).x,
                    sf::Mouse::getPosition(game.window).y
                )
            && txtQuit.getColor() != sf::Color::Red
            )
    {
        txtQuit.setFillColor(sf::Color::Red);
        bQuitGameSelected = false;
    }


}

void Menue::draw(Game &game){
    game.window.draw(txtStart);
    game.window.draw(txtQuit);
}
