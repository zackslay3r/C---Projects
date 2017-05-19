#include "Game.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

// This is the constructor for the board itself.
Game::Game()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMMS; j++)
		{
			board[i][j] = 'A';
		}
	}
	

}



//This is the destructor
Game::~Game()
{
}





// This function returns the row that was selected.
int Game::getRowSelected()
{
	return rowSelected;
}

// This function sets the row that was selected by the user.
void Game::setRowSelected(int rs)
{
	rowSelected = rs;
}


// This function returns the coloumm that was selected.
int Game::getColoummSelected()

{
	return colummSelected;
}

// This function sets the colummSelected that was selected by the user.
void Game::setColummSelected(int cs)
{
	colummSelected = cs;
}

// This function returns the winner of the game.
int Game::getWinner()
{
return winner;
}

// This function returns player ones piece.
char Game::getPlayerOne()
{
	return playerOnePiece;
}
// This function returns player twos piece.
char Game::getPlayerTwo()
{
	return playerTwoPiece;
}


// This function returns player one's piece
bool Game::getValidTurn()
{
	return validTurn;
}

// this function sets whos turn is valid.
void Game::setValidTurn(bool tf)
{
	validTurn = tf;
}

// THis function returns a turn counter, used for deciding between player turns.
int Game::getCounter()
{
	return counter;
}

// This function returns a variable called playerTurn that is used for determining a player's turn.
int Game::getPlayerTurn()
{
	return playerTurn;
}
// This function sets a players turn.
void Game::setPlayerTurn(int pt)
{
	playerTurn = pt;
}

// This function sets the current player.
void Game::setCurrPlayer(char cp)
{
	currPlayer = cp;
}

int Game::getReRun()
{
	return rerun;
}

void Game::setReRun(int rr)
{
	rerun = rr;
}


// Main functions 
void Game::squareCheck()
{
	{
		// while ValidTurn is false, give the user error messages unless they make a 
		//valid choice.
		while (getValidTurn() == false)
		{
			// if they have selected a square that has already been selected
			if (board[rowSelected][colummSelected] != 'A')
			{
				std::cout << "Your choice of sqaure is invalid as a player has already selected a sqaure";
				std::cout << std::endl;
				std::cout << "please select another.";
				std::cout << std::endl;
				break;
			}





			// if the user pick is outside the game board
			// display this error
			if (rowSelected > ROWS || colummSelected > COLUMMS || rowSelected < 0 || colummSelected < 0)
			{
				std::cout << "Your choice is invalid as you have selected outside the board.";
				std::cout << std::endl;
				std::cout << "Please select a valid square.";
				break;


			}
			// if the square is empty, then fill it and confirm that a valid turn has been made.
			if (board[rowSelected][colummSelected] == 'A')
			{

				board[rowSelected][colummSelected] = currPlayer;

				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLUMMS; j++)
					{
						std::cout << board[i][j];
					}
					std::cout << std::endl;
					validTurn = true;
					counter++;
				}

			}
		}
	}
}



void Game::playerInput(int playerTurn)
{
	// initializes temporary variables to later be used for row and columm selection.
	int tempRow = 0;
	int tempColumm = 0;

	// Used for formatting
	// will later be added for the game board.
	std::cout << "-----------------------------------------------" << std::endl;
	

	// Outputs to the player, using the 'playerTurn' variable to tell the user whos turn it is.
	std::cout << "Please player " << playerTurn << " make your turn!";
	std::cout << std::endl;
	// Askes the user which row and columm they would like to select.
	// The user is allowed to enter 1-3 instead of 0-2 to make it easier to understand.
	// the convers
	std::cout << "Please select which row you would like to pick. 1-3";
	std::cout << std::endl;
	std::cin >> tempRow;
	tempRow--;
	setRowSelected(tempRow);
	std::cout << "Please select which columm you would like to pick. 1-3";
	std::cout << std::endl;
	std::cin >> tempColumm;
	tempColumm--;
	setColummSelected(tempColumm);
	// clears old data from the console
	system("cls");


}


void Game::winnerCheck()
{
	// Testing rows

	for (int i = 0; i < ROWS; i++)
	{
		int total = 0;
		for (int j = 0; j < COLUMMS; j++)
		{
			// adds up 3 in a row to check the asci
			total += board[i][j];
		}

		// Total is calculated with the addition with ascii characters. 

		// 


		// Player 1 win condition
		if (total == playerOnePiece * 3)
		{
			winner = true;
			winningPlayer = 1;
			break;
		}

		// Player 2 Win Condition.
		if (total == playerTwoPiece * 3)
		{
			winner = true;
			winningPlayer = 2;
			break;

		}

	}




	//Testing Columms

	for (int i = 0; i < COLUMMS; i++)
	{
		int total = 0;
		for (int j = 0; j < ROWS; j++)
		{
			total += board[j][i];
		}


		// Player 1 win condition
		if (total == playerOnePiece * 3)
		{
			winner = true;
			winningPlayer = 1;
			break;
		}

		// Player 2 Win Condition.
		if (total == playerTwoPiece * 3)
		{
			winner = true;
			winningPlayer = 2;
			break;

		}
	}

	// Testing for [0][0], [1][1], [2][2]
	int total = 0;
	for (int i = 0; i < COLUMMS; i++)
	{

		total += board[i][i];


		// Player 1 win condition
		if (total == playerOnePiece * 3)
		{
			winner = true;
			winningPlayer = 1;
			break;
		}

		// Player 2 Win Condition.
		if (total == playerTwoPiece * 3)
		{
			winner = true;
			winningPlayer = 2;
			break;

		}

	}

	// Testing for [2][0], [1][1],[0][2]

	for (int i = 2; i >= 0; i--)
	{
		total = 0;
		for (int j = 0; j <= 2; j++)
		{
			total += board[i][j];
			i--;
		}


		// Player 1 win condition
		if (total == playerOnePiece * 3)
		{
			winner = true;
			winningPlayer = 1;
			break;
		}

		// Player 2 Win Condition.
		if (total == playerTwoPiece * 3)
		{
			winner = true;
			winningPlayer = 2;
			break;

		}
	}

	// this counts all the pieces to see if there is a draw on the board.
	int DrawCounter = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMMS; j++)
		{
			if (board[i][j] != 'A')
			{
				DrawCounter++;
			if (DrawCounter == 9)
				{
				winner = true;
				winningPlayer = 3;
				}
			}
		}
		
	}


	

	// if player one or player two wins, prompt the users, else, prompt them that the game is draw.
	if (winningPlayer == 1)
	{
		std::cout << "Player One Wins!";
		system("pause");
	}
	if (winningPlayer == 2)
	{
		std::cout << "Player Two Wins!";
		system("pause");
	}
	if (winningPlayer == 3)
	{
		std::cout << "The game is a draw.";
		system("pause");
	}


}

// This fuction sets the players pieces according to the input of a char. 
void Game::setPlayers()
{
	// THese are variables that are used to compare against for while loops.
	int playerSelectedCounter = 0;
	bool bothPlayersSelected = false;


	// While both players havent picked a piece, run though this loop.
	while (bothPlayersSelected == false)
	{
		std::cout << "Player 1! Please input a character to use as you game pieces" << std::endl;
		playerOnePiece = _getch();
		// as long as the user doesnt pick A, then their piece is set.
		if (playerOnePiece != 'A')
		{
			std::cout << "You have selected " << playerOnePiece << " as your game piece." << std::endl;
			playerSelectedCounter++;
		}
		// propmt the user if they pick A.
		else
		{
			std::cout << "Please dont pick 'A' as it is being used to siginify empty pieces." << std::endl;
		}



		// This will only get to the second player selection when the first player has had a piece set for them.
		while (playerSelectedCounter == 1)
		{
			std::cout << "Player 2! Please input a character to use as you game pieces" << std::endl;
			//std::cin >> tempTwo;
			//playerTwoPiece = tempTwo;

			playerTwoPiece = _getch();

			//If player two's piece is not player ones piece AND is not A, then set both players sleected to true, which will now exit the set players loops.
			if (playerTwoPiece != playerOnePiece)
			{
				if (playerTwoPiece != 'A')
				{
					std::cout << "You have selected " << playerTwoPiece << " as your game piece." << std::endl;
					playerSelectedCounter++;
					bothPlayersSelected = true;
				}
				// propmt the user if they pick A.
				else
				{
					std::cout << "Please dont pick 'A' as it is being used to siginify empty pieces." << std::endl;
				}
			}
			// prompt the user if he picked what piece player one is.
			else
			{
				std::cout << "Please select a different character to use as a piece as Player One has already taken it /  " << std::endl;
			}
		}
	}
}