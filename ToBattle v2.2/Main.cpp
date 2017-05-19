#include <iostream>
#include "Main.h"







// These two are both an array of pointers
// One for enemies
// One for Allys
Enemy *g_enemies[2];
Ally *g_allys[2];

// counters for the number of enemies and allys
int g_numOfEnemies = 0;
int g_numOfAllys = 0;

// a boolean to keep repeating game functions until all enemys or allys
// are dead.
bool GameRunning = true;


void main()
{



	//---------------------------------------------------------------------------------
	// This fills the ally pointer array with values.
	//---------------------------------------------------------------------------------
	g_allys[0] = new Player;
	g_allys[1] = new Priest;
	//---------------------------------------------------------------------------------
	// This fills the enemies pointer array with values.
	//---------------------------------------------------------------------------------
	g_enemies[0] = new Orc;
	g_enemies[1] = new Healer;
	
	//---------------------------------------------------------------------------------
	// This fills the ally pointer array with values.
	//---------------------------------------------------------------------------------
	g_numOfEnemies = 2;
	g_numOfAllys = 2;
	bool validTurn = false;
	int turnCounter;
	turnCounter = 0;
	


	//---------------------------------------------------------------------------------
	// This function welcomes the player and gives them information about the game.
	//---------------------------------------------------------------------------------
	welcomePlayer();
	
	
	
	//---------------------------------------------------------------------------------
	// This function lets the player themself select a weapon. 
	// This takes on the parameters of the number of ally's and the ally pointer array.
	// this ensure's it can loop the ally pointer array to find every instance of a player
	// within the array and gives them a weapon. 
	//---------------------------------------------------------------------------------
	playerWeaponSelection(g_numOfAllys, g_allys);



	// While the game is running, continue to loop through the game. 
	// GameRunning only gets turned to false when someone wins.
	while (GameRunning == true)
	{


	
		//---------------------------------------------------------------------------------
		// These are the ally's turn's and they will be preformed if a player or priest have 
		// more then 0 health.
		//---------------------------------------------------------------------------------
		playerTurn(g_numOfAllys, g_allys, g_numOfEnemies, g_enemies);
		priestTurn(g_numOfAllys, g_allys);



		//---------------------------------------------------------------------------------
		// These are the enemies turn's and they will be preformed if an orc or enemy healer have
		// more then 0 health.
		//---------------------------------------------------------------------------------
		orcTurn(g_numOfAllys, g_allys, g_numOfEnemies, g_enemies);
		healerTurn(g_numOfEnemies, g_enemies);
		
		
		//---------------------------------------------------------------------------------
		// After all characters have had turns, increment the turn counter and let the player
		// know that everyones turn is over.
		//---------------------------------------------------------------------------------
		turnCounter++;
		std::cout << "Turn " << turnCounter << " over!";
		system("pause");
		


		//---------------------------------------------------------------------------------
		// After the turn has been incremented, sort the pointer array's based on 
		// character's health and display to the player.
		//---------------------------------------------------------------------------------
		sortForces(g_allys, g_enemies, g_numOfAllys, g_numOfEnemies);
		

		//---------------------------------------------------------------------------------
		// Then check to see if either team has won the game and if a team has,
		// stop the game from running.
		//---------------------------------------------------------------------------------
		if (checkWinner(g_numOfAllys, g_allys, g_numOfEnemies, g_enemies) == false)
		{
			GameRunning = false;
		}
		else
		{
			GameRunning = true;
		}
	
	}
}
			