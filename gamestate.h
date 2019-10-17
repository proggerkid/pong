#ifndef GAMESTATE_H
#define GAMESTATE_H

class Game;

class Gamestate{
public:

    virtual void handleEvent(Game& game)=0;
    virtual void update(Game& game)=0;
    virtual void draw(Game& game)=0;

};


#endif // GAMESTATE_H
