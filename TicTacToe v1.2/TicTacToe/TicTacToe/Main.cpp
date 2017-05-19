#include <iostream>
const int ROWS = 3;
const int COLUMMS = 3;
int rowSelected = 0;
int colummSelected = 0;
bool Winner = false;
void WinnerCheck();
void SquareCheck();
void OneTurn();
void TwoTurn();

int playerTurn;


// Creates the board
int Board[ROWS][COLUMMS] = { {5,5,5}, {5,5,5},{5,5,5} };



// A Function to check to see if a player has won.
void OneTurn()
{

	if (playerTurn == 1)
	{
		Board[rowSelected][colummSelected] = 1;
		
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLUMMS; j++)
				{
					std::cout << Board[i][j];
				}
				std::cout << std::endl;
			}
		
		
		
	}
	playerTurn = 0;
}


void TwoTurn()
{
	if (playerTurn == 2)
	{





		

		Board[rowSelected][colummSelected] = 2;
		
			for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLUMMS; j++)
			{
				std::cout << Board[i][j];
			}
			std::cout << std::endl;
		
		
		}

		
	}
	playerTurn = 0;
	playerTurn = 1;
}




void WinnerCheck()
{
	if (Board[0][0] + Board[1][0] + Board[2][0] == 3 || Board[1][0] + Board [1][1] + Board[2][0] == 3
		|| Board[0][0] + Board[0][1] + Board[0][2] == 3 || 
		Board[0][0] + Board[1][1] + Board[2][2] == 3)
			{
				Winner = true;
				std::cout << "Player 1 Wins!";
				playerTurn = 0;
				std::cout << std::endl;
				std::cout << "Game over!";
			}

	if (Board[0][0] + Board[1][0] + Board[2][0] == 6
		|| Board[0][0] + Board[0][1] + Board[0][2] == 6 ||
		Board[0][0] + Board[1][1] + Board[2][2] == 6)
	{
		Winner = true;
		std::cout << "Player 2 Wins!";
		playerTurn = 0;
		std::cout << std::endl;
		std::cout << "Game over!";

	}

	
}




void SquareCheck()
{
	if (Board[rowSelected][colummSelected] != 5)
	{
		std::cout << "Your choice of sqaure is invalid as a player has already selected a sqaure";
		std::cout << std::endl;
		std::cout << "please select another.";
		std::cout << std::endl;
		

	}
	
	if (rowSelected > ROWS || colummSelected > COLUMMS)
	{
		std::cout << "Your choice is invalid as you have selected outside the board.";
		std::cout << std::endl;
		std::cout << "Please select a valid square.";


	}

	/*if ((Board[rowSelected][colummSelected] = 1) || (Board[rowSelected][colummSelected] = 2))
	{
		std::cout << "Your choice of sqaure is invalid as a player has already selected a sqaure";
		std::cout << std::endl;
		std::cout << "please select another.";
	}
	*/
	if (Board[rowSelected][colummSelected] == 5)
		{
			if (playerTurn == 1)
			{
				OneTurn();
			}
			if (playerTurn == 2)
			{
				TwoTurn();
			}
		
	}
	}
	

	
	

		
	
	/*
	if (playerTwoTurn = true)
	{
		Board[rowSelected][colummSelected] = 2;
		playerTwoTurn = false;


		if (playerTwoTurn == false)
		{
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLUMMS; j++)
				{
					std::cout << Board[i][j];
				}
				std::cout << std::endl;
			}
		}


	}
	*/
	

void TieChecker()
{
	if (Board[0][0] && Board[1][0] && Board[2][0] &&
		Board[1][0] && Board[2][0] && Board[3][0] &&
		Board[0][1] && Board[0][2] && Board[0][3] &&
		Board[1][1] && Board[2][2] && Board[3][3] != 5)
	{
		std::cout << "This game is a draw.";
		playerTurn = 0;
	
	}

}
	
	
	



int main()

{
	// Defaults Player ones turn to true.
	playerTurn = 1;
	
	// While a winner is not determinded, allow a player to make a move.
	while (Winner != true)
	{
		
	
		// Ask the user to input their turn, first with a row, then a columm
		// The row and columm selection is -1 so that the user can pick between 1 and 3
		while (playerTurn == 1)
		{
			std::cout << "Player 1! Select the row you'd like to select";
			std::cin >> rowSelected;
			rowSelected--;
			std::cout << "Select the columm you'd like to select";
			std::cin >> colummSelected;
			colummSelected--;

			// Code here for checking if the square has already been taken by player 1 or 2.
			// and if the square has not been taken then the player can take it.

			SquareCheck();
			}
			WinnerCheck();
			TieChecker();
			playerTurn = 2;
		
		
		
		while (playerTurn == 2)
		{
			std::cout << "Player 2! Select the row you'd like to select";
			std::cin >> rowSelected;
			rowSelected--;
			std::cout << "Select the columm you'd like to select";
			std::cin >> colummSelected;
			colummSelected--;

			SquareCheck();
		WinnerCheck();
		TieChecker();
		}
		
		
		playerTurn = 1;

	}



}

	
	
