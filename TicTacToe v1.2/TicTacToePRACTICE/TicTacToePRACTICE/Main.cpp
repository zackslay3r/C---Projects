// main.cpp
#include <iostream>
#include "tictactoe.h"

int main()
{

    TicTacToe Game;
    Game.drawBoard();

    do
    {

        Game.printTurn();

        if (Game.playerHuman())     // human turn?
            Game.humanMove();
        else
            Game.computerMove();

        Game.drawBoard();
        Game.nextTurn();

    }
    while (!Game.Winner() && !Game.fullBoard());

    return 0;
}