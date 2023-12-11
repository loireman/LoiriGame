#include <iostream>
#include "Game.h"
#define _WIN32_WINNT 0x0500
#include <windows.h> 

int main()
{
    std::srand(static_cast<unsigned> (time(NULL)));
    // init gameEngine

    Game game;
    // Game loop
    game.run();
    // End of app
    return 0;
}
