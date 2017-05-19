// This is the header file
// It contains all variables in a class and prototypes for functions.

#pragma once
// This is the Game class
// This contains the constants ROWS and COLUMMS, which is the maximum size the board can ever be.
// Contains char's assigned to playerOne and playerTwo, which are defaulted to 'X' and 'O' (could possibly be user customizeable.
// contains currPlayer, which is used when filling in the squares of the game board.
// contains rowSelected and colummSelected, which are variable that the user fills when a turn is made.
// contains winner, which is used for in a conditional loop, ensuring the game plays while winner is false.
//

class Game
{
private:
	const int ROWS = 3;
	const int COLUMMS = 3;
	
	char playerTwo = 'O';
	char currPlayer;
	int rowSelected = 0;
	int colummSelected = 0;
	bool winner = false;
	char playerOnePiece = 'A';
	char playerTwoPiece = 'A';
	// counter is used to count player turns,
	//playerTurn sets who's turn it is 
	//board[3][3] is the game board.
	int counter = 0;
	int playerTurn = 0;
	char board[3][3];

	// This variable checks if a turn is valid. 
	bool validTurn = false;

	// stores the value of who the Winning player is.
	int winningPlayer = 0;
	
	int rerun;
	
	
// Prototypes
	public:
		// Get values of private variables.
		bool getValidTurn();
	
	
	void setRowSelected(int rs);
	int getRowSelected();

	void setColummSelected(int cs);
	int getColoummSelected();
	

	int getWinner();


	void setValidTurn(bool tf);
	


	int getCounter();


	int getPlayerTurn();
	
	char getPlayerOne();
	char getPlayerTwo();


	void setPlayerTurn(int pt);

	void setCurrPlayer(char cp);

	
	
	void playerInput(int playerTurn);
	void squareCheck();
	void winnerCheck();



	int getReRun();
	void setReRun(int rr);
	void setPlayers();

	//This is the destructor.
	Game();
	~Game();
;}




;

