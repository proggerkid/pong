#include "game.h"


int main()
{
    Game game;
    game.changeState(game.gameStates::MAINMENUE);
    game.run();

    return 0;
}
