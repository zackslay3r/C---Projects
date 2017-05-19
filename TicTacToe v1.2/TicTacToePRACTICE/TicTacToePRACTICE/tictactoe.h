#pragma once
// tictactoe.h
#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
private:
	int pos[9];             // board position
	int player;             // current player
	int totalTurns;         // how many turns so far?
	int numberPlayers;      // 1 to 20
	bool playerType[20];    // player #, 0 = comp, 1 = human
public:
	TicTacToe();
	void printTurn();
	bool playerHuman();
	void humanMove();
	void computerMove();
	void drawBoard();
	bool Winner();
	bool fullBoard();
	void nextTurn();

};

#endif // TICTACTOE_H 