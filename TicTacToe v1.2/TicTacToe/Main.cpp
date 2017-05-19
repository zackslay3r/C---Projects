#include <iostream>
#include "Game.h"






int main()
{
	
	
	// While there is no winner, set ValidTurn to false 
	// then determine which players turn it is
	// then ask the player for input.
	// followed by running the SquareCheck() function and
	// the WinnerCheck() function to determine who the winning player.
	Game currentGame;
	
	currentGame.setPlayers();

		while (currentGame.getWinner() == false)
		{
			currentGame.setValidTurn(false);
			if (currentGame.getCounter() % 2 == 0)
			{
				currentGame.setPlayerTurn(1);
				currentGame.setCurrPlayer(currentGame.getPlayerOne());
			}
			else
			{
				currentGame.setPlayerTurn(2);
				currentGame.setCurrPlayer(currentGame.getPlayerTwo());
			}

			currentGame.playerInput(currentGame.getPlayerTurn());
			currentGame.squareCheck();
			currentGame.winnerCheck();
		}
			
} 




