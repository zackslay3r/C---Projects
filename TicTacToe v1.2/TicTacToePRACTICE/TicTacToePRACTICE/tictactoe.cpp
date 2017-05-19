// tictactoe.cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tictactoe.h"

TicTacToe::TicTacToe()
{
    srand (time(0));

    player = 1;           // who starts first?
    totalTurns = 0;

    // new player setup
    numberPlayers = 2;
    playerType[1] = 1;  // playerType[player] is human (1)
    playerType[2] = 0;  // playerType[player] is computer (0)
#include "tictactoe.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

	using namespace std;

	class TicTacToe {
	private:
		char theBoard[3][3];


	public:
		TicTacToe(void);
		void playOneGame(void);
		void switchPlayer(char &);
		void showBoard(void);
		void postMove(int, int, char);
		char determineWinner(void);


	};

	int main(void) {

		TicTacToe Game1;
		Game1.playOneGame();
	}






	void TicTacToe::playOneGame(void) {

		const int MaxMoves = 9;
		char currentPlayer = 'O';
		int row = 0;
		int clmn = 0;
		char theWinner = ' ';
		int nmbrOfMoves = 0;

		do {
			switchPlayer(currentPlayer);
			showBoard();
			cout << "\n\nPlayer " << currentPlayer << endl;
			cout << "\nEnter your row (1, 2, 3): ";
			cin >> row;
			cout << "\nEnter your column (1, 2, 3): ";
			cin >> clmn;

			postMove(row, clmn, currentPlayer);

			theWinner = determineWinner();

			nmbrOfMoves++;
		} while ((theWinner == 'D') && (nmbrOfMoves < MaxMoves));

		showBoard();

		if (theWinner != 'D')
			cout << "\n\nTheWinner is player " << theWinner;
		else
			cout << "\n\nThe Game was a Draw" << endl;
	}

	TicTacToe::TicTacToe(void) {


		for (int row = 0; row< 3; row++) {
			for (int clmn = 0; clmn<3; clmn++) {
				theBoard[row][clmn] = ' ';
			}
		}
	}


	void TicTacToe::switchPlayer(char &currentPlayer) {


		

		if (currentPlayer == 'X')
		{
			(currentPlayer = 'O');
			cout << "\nIt's player 1 turn" << endl;

		}
		else
			(currentPlayer = 'X');

	}


	void TicTacToe::showBoard() {

		cout << "     Tic Tac Toe!" << endl << endl;
		cout << "     1     2     3" << endl << endl;
		cout << "1    " << theBoard[0][0] << "  |  " << theBoard[0][1] << "  |  " << theBoard[0][2] << endl;
		cout << "   -----------------" << endl;
		cout << "2    " << theBoard[1][0] << "  |  " << theBoard[1][1] << "  |  " << theBoard[1][2] << endl;
		cout << "   -----------------" << endl;
		cout << "3    " << theBoard[2][0] << "  |  " << theBoard[2][1] << "  |  " << theBoard[2][2] << endl << endl;
	}



	void TicTacToe::postMove(int row, int col, char value) {

		char currentPlayer = ' ';
		theBoard[row - 1][col - 1] = value;
		if (row != 0 && row != 1 && row != 2)
		{
			cout << "\nInvalid move, try Again" << endl;
		}
		else if (col != 0 && col != 1 && col != 2)
		{
			cout << "\nInvalid move, try Again" << endl;;
		}
		else if (theBoard[row][col] == currentPlayer)
		{
			cout << "\nAlready Taken, Try Again" << endl;;
		}


	}



	char TicTacToe::determineWinner(void) {

		for (int i = 0; i < 3; i++) {
			if (theBoard[i][0] == theBoard[i][1]
				&& theBoard[i][1] == theBoard[i][2]
				&& theBoard[i][0] != ' ') {
				return theBoard[i][0];
			}
		}


		for (int i = 0; i < 3; i++) {
			if (theBoard[0][i] == theBoard[1][i]
				&& theBoard[1][i] == theBoard[2][i]
				&& theBoard[0][i] != ' ') {
				return theBoard[0][i];
			}
		}


		if (theBoard[0][0] == theBoard[1][1]
			&& theBoard[1][1] == theBoard[2][2]
			&& theBoard[0][0] != ' ') {
			return theBoard[0][0];
		}

		if (theBoard[2][0] == theBoard[1][1]
			&& theBoard[1][1] == theBoard[0][2]
			&& theBoard[2][0] != ' ') {
			return theBoard[2][0];
		}

		return 'D';

	}