#pragma once
#include "Enemy.h"
#include "Orc.h"
#include "Healer.h"
#include "Player.h"
#include "Ally.h"
#include "Priest.h"
#include <ctime>






//---------------------------------------------------------------------------------
// This function takes the Orc and the target of the orc attack as parameters
// then runs the Orc specific 'computeDamage' function which assigns damage and
// then displays the targets health after its been damaged.
//---------------------------------------------------------------------------------
void OrcAttack(Enemy *eptr, Ally *aptr)
{
	std::cout << "Its now Orc's turn!" << std::endl;
	// Attacks the target
	eptr->computeDamage(aptr);
}



//---------------------------------------------------------------------------------
// This function welcomes the player with starting information about the game.
//---------------------------------------------------------------------------------
void welcomePlayer()
{
	
	
	std::cout << "Welcome player!" << "\n\n";
	std::cout << "You will be facing an Orc and a healer!" << "\n\n";
	std::cout << "But its okay! you will have your own healer!" << "\n\n";
	std::cout << "Defeat both enemies to win the game!" << "\n\n";
	std::cout << "press any key to continue." << std::endl;
	std::cin.ignore();
	system("cls");

}

//---------------------------------------------------------------------------------
// There are two different healer functions 
// which either take the healer themselves (whether it be a Priest or a Healer)
// and their target and preforms the appropirate heal onto their target.
//---------------------------------------------------------------------------------
void heal(Ally *aptr, Ally *a_ptr_trgt)
{
	aptr->healingWave(a_ptr_trgt);
}
void heal(Enemy *eptr, Enemy *e_ptr_trgt)
{
	eptr->healingSurge(e_ptr_trgt);
}


//---------------------------------------------------------------------------------
// This function generate's a random number between 1 and 10. this is used for 
// NPC's to determine which target to attack or heal.
//---------------------------------------------------------------------------------
int RandomTargeting()
{
	int rndNum = 0;
	srand((unsigned)time(NULL)); // Seeds it. Only do this once.
	rndNum = (rand() % 10); //Gives you a number between 1 - 100
	return rndNum;
}


//---------------------------------------------------------------------------------
// This function takes the parameter's or the ally and enemy pointer array, as well
// the ints of the max amount of ally's and enemies and loops though each pointer array
// and compares two values and if one is greater then another then they are swapped.
//---------------------------------------------------------------------------------
void sortForces(Ally* allyArray[]  , Enemy* enemyArray[], int numOfAllys, int numOfEnemies)
{
	
	Ally *pTempAlly;
	Enemy *pTempEnemy;

	for (int i = 0; i < numOfAllys; i++)
	{
		if (allyArray[i]->m_health < 0)
		{
			allyArray[i]->m_health = 0;
		}
	}
	for (int i = 0; i < numOfEnemies; i++)
	{
		if (enemyArray[i]->m_health < 0)
		{
			enemyArray[i]->m_health = 0;
		}
	}
	
		if (allyArray[0]->m_health < allyArray[1]->m_health)
		{
			pTempAlly = allyArray[0];
			allyArray[0] = allyArray[1];
			allyArray[1] = pTempAlly;
		}
		
		int allyCount = 0;
		for (int i = 0; i < numOfAllys; i++)
		
		{
			
			if (allyArray[i]->isPlayer())
			{
				std::cout << "Ally force number " << ++allyCount << " is a player and has" << allyArray[i]->m_health << " health remaining." << "\n\n";

			}
			if (allyArray[i]->isPriest())
			{
				std::cout << "Ally force number " << ++allyCount << " is a priest and has" << allyArray[i]->m_health << " health remaining." << "\n\n";
			}
		}
			
		
		std::cout << "That should be Allys sorted, now for enemies...." << "\n\n";

			if (enemyArray[0]->m_health < enemyArray[1]->m_health)
			{
				pTempEnemy = enemyArray[0];
				enemyArray[0] = enemyArray[1];
				enemyArray[1] = pTempEnemy;
			}




			std::cout << "Enemy forces sorted?..." << "\n\n";
			int enemyCount = 0;
			for (int i = 0; i < numOfEnemies; i++)
			
			{
				
				if (enemyArray[i]->isOrc())
				{
					std::cout << "Enemy force number " << ++enemyCount  << " is an Orc and has" << enemyArray[i]->m_health << " health remaining." << "\n\n";
				}
				if (enemyArray[i]->isHealer())
				{
					std::cout << "Enemy force number " << ++enemyCount << " is a healer and has" << enemyArray[i]->m_health << " health remaining." << "\n\n";
				}
			}



		
}

//---------------------------------------------------------------------------------
// This function loops though both the of the pointer arrays from the first position in the array 
// till g_numOfAllys or g_numOfEnemies and check's if all the enemies or ally's on
// one side have 0 health and if one side has no health, then return false, which in main()
// will cancel the main game loop.
//---------------------------------------------------------------------------------
bool checkWinner(int g_numOfAllys, Ally* g_allys[], int g_numOfEnemies, Enemy* g_enemies[])
{
	// this variable is used to count the amount of enemies that are dead.
	int counter = 0;
	for (int i = 0; i < g_numOfEnemies; i++)
	{

		if (g_enemies[i]->m_health <= 0)
		{
			counter++;
			if (counter == g_numOfEnemies)
			{
				std::cout << "You win!" << "\n\n";
				return false;
				
			}
		}
	}

	// this get's reset to 0 for the allys.
	counter = 0;
	for (int i = 0; i < g_numOfAllys; i++)
	{

		if (g_allys[i]->m_health <= 0)
		{
			counter++;
			if (counter == g_numOfAllys)
			{
				std::cout << "You lose!" << "\n\n";
				return false;
				
			}
		}
	}
	return true;
}

//---------------------------------------------------------------------------------
// This function lets the player themself select a weapon. 
// This takes on the parameters of the number of ally's and the ally pointer array.
// this ensure's it can loop the ally pointer array to find every instance of a player
// within the array and gives them a weapon. 
//---------------------------------------------------------------------------------
void playerWeaponSelection(int g_numOfAllys, Ally* g_allys[])
{
	char weaponSelect;
	std::cout << "Which weapon would you like to use?" << "\n\n";
	std::cout << "1 for Sword and 2 for Axe." << "\n\n";
	std::cout << "If you pick the axe, you will recieve a +10 point damage buff over the sword." << "\n\n";
	std::cout << "However, you will recieve a +5 points more damage. Axes are heavy, you know!" << "\n\n";

	//---------------------------------------------------------------------------------
	//Input the weapon choice
	//---------------------------------------------------------------------------------
	std::cin >> weaponSelect;
	
	
	
	for (int i = 0; i < g_numOfAllys; i++)
	{
		// pAlly is a temporary pointer.
		Ally *pAlly = g_allys[i];
		if (pAlly->isPlayer())
		{
			// this casts the Ally pointer to be a Player pointer.

			Player *pPlayer = (Player *)pAlly; // Dangerous way to do it




			// this loop ensures that the user makes a valid selection in their weapon.
			weaponSelect = weaponSelect - 48;
			bool choice = false;
			// this do statement makes sure the the user will pick a enemy with health.
			do
			{
				switch (weaponSelect)
				{
					//If the input is 1, their weapon is a Sword
				case 1:
					system("cls");
					pPlayer->setWeapon(playerWeapon::Sword);
					std::cout << "You have selected the Sword!" << "\n\n";

					system("cls");

					choice = true;
					break;
					// If the input is 2, their weapon is an Axe.
				case 2:
					system("cls");
					pPlayer->setWeapon(playerWeapon::Axe);
					std::cout << "You have selected the Axe!" << "\n\n";
					std::cout << "press any key to continue." << std::endl;
					std::cin.ignore();
					system("cls");
					choice = true;
					break;

					// If the input is not a valid input.
				default:
					std::cout << "Please input a valid weapon type." << "\n\n";
					std::cin >> weaponSelect;
					weaponSelect = weaponSelect - 48;
					break;

				}

			} while (choice == false);

		}
	}

}

//---------------------------------------------------------------------------------
// This function loops the ally array and gives every player a chance to attack a enemy. 
// after a player selects a target, the function then loops though the enemy array 
// and for every instance of the selected enemy, they will get attacked.
//---------------------------------------------------------------------------------
void playerTurn(int g_numOfAllys, Ally* g_allys[], int g_numOfEnemies, Enemy* g_enemies[])
{
	char enemyChoice;
	bool validTurn;
	validTurn = false;

	//this is the main ally loop that checks though and if there is a player of a certain type
	// they have their turn. 
	for (int i = 0; i < g_numOfAllys; i++)
	{

		// Check winner checks to see if all Allys or all enemies are killed.
		if (g_allys[i]->m_health > 0 && g_allys[i]->isPlayer())
		{

			while (validTurn == false)
			{
				std::cout << "Would you like to damage the Orc or the healer?" << "\n\n";
				std::cout << "type o for the orc and h for the healer." << "\n\n";
				// This is the user input based on a char.
				std::cin >> enemyChoice;
				// If the char is a 'o', attack the orc.

				if (enemyChoice == 'o')
				{

					//this is a sub loop for finding the target.
					for (int j = 0; j < g_numOfEnemies; j++)
					{

						if (g_enemies[j]->m_health > 0 && g_enemies[j]->isOrc())
						{

							std::cout << "You are attacking the Orc!" << "\n\n";
							std::cout << "press any key to continue." << std::endl;
							std::cin.ignore();
							system("cls");
							g_allys[i]->computeDamage(g_enemies[j]);
							validTurn = true;
						}


					}
				}
				//if the target is h, attack the healer
				if (enemyChoice == 'h')
				{
					for (int j = 0; j < g_numOfEnemies; j++)
					{
						if (g_enemies[j]->m_health > 0 && g_enemies[j]->isHealer())
						{

							std::cout << "You are attacking the enemy Healer!" << "\n\n";
							std::cin.ignore();
							system("cls");
							g_allys[i]->computeDamage(g_enemies[j]);
							validTurn = true;

						}
					}
				}
				


				if (validTurn == false)
				{
					std::cout << "Please select the other enemy as the enemy you have selected doesnt have health or is not a valid enemy." << "\n\n";

				}

			}
		}
	}

}

//---------------------------------------------------------------------------------
// This function loops the ally array and gives every priest a chance to heal an ally target. 
// after a priest selects a target, the function then loops though the ally array 
// and for every instance of the selected ally, they will get healed.
//---------------------------------------------------------------------------------
void priestTurn(int g_numOfAllys, Ally* g_allys[])
{
	bool validTurn;
	validTurn = false;
	for (int i = 0; i < g_numOfAllys; i++)
	{
		if (g_allys[i]->m_health > 0 && g_allys[i]->isPriest())
		{

			int randomSelection = RandomTargeting();
			int counter = 0;
			//--------------------------------------------------------------------------------------
			// Friendly priests turn
			//--------------------------------------------------------------------------------------


			// if the target is less then 5,
			// target the Player.
			if (randomSelection < 5)

			{
				for (int j = 0; j < g_numOfAllys; j++)
				{
					if (g_allys[j]->m_health > 0 &&
						g_allys[j]->isPlayer())
					{

						heal(g_allys[i], g_allys[j]);
						//g_allys[1]->healingWave(g_allys[0]);
						//show the updated health.
						std::cout << "Your Health is now" << g_allys[j]->m_health << "\n\n";
						counter++;
					}
				}

				for (int j = 0; j < g_numOfAllys; j++)
				{
					if (g_allys[j]->m_health > 0 &&
						g_allys[j]->isPriest() &&
						counter == 0)
					{
						heal(g_allys[i], g_allys[j]);
						//g_allys[1]->healingWave(g_allys[0]);
						//show the updated health.
						std::cout << "Your Priests health is now " << g_allys[j]->m_health << "\n\n";
						counter++;
					}
				}
			}
			if (randomSelection >= 5)
			{
				for (int j = 0; j < g_numOfAllys; j++)
				{
					if (g_allys[j]->m_health > 0 &&
						g_allys[j]->isPriest())
					{

						heal(g_allys[i], g_allys[j]);
						//g_allys[1]->healingWave(g_allys[0]);
						//show the updated health.
						std::cout << "Your Priests health is now" << g_allys[j]->m_health << "\n\n";
						counter++;
					}
				}

				for (int j = 0; j < g_numOfAllys; j++)
				{
					if (g_allys[j]->m_health > 0 &&
						g_allys[j]->isPlayer() &&
						counter == 0)
					{
						heal(g_allys[i], g_allys[j]);
						//g_allys[1]->healingWave(g_allys[0]);
						//show the updated health.
						std::cout << "Your Health is now" << g_allys[j]->m_health << "\n\n";
						counter++;
					}
				}
			}
			validTurn = false;
		}
	}
}

//---------------------------------------------------------------------------------
// This function loops the enemy array and gives every orc a chance to attack an ally. 
// after a orc selects a target, the function then loops though the ally array 
// and for every instance of the selected ally, they will get attacked.
//---------------------------------------------------------------------------------
void orcTurn(int g_numOfAllys, Ally* g_allys[], int g_numOfEnemies, Enemy* g_enemies[])
{
	bool validTurn = false;
	for (int i = 0; i < g_numOfEnemies; i++)
	{
		// If the Orc has health, allow it to attack an Ally.
		if (g_enemies[i]->m_health > 0 && g_enemies[i]->isOrc())
		{
			int randomSelection = RandomTargeting();
			Orc* tempOrcPtr = (Orc*)(g_enemies[i]);
			WeaponType w = tempOrcPtr->m_weaponType;
			std::cout << "The Orc is attacking with a " << w << "\n\n";

			int counter = 0;
			while (validTurn == false)
			{
				// if the Random target generator is less then 5 and the target has health greater then 0, attack it.
				// if the selected target has no health, it will target the other possible target.
				if (randomSelection < 5)
				{
					for (int j = 0; j < g_numOfEnemies; j++)
					{
						if (g_allys[j]->m_health > 0 && g_allys[j]->isPlayer())
						{
							OrcAttack(g_enemies[i], g_allys[j]);
							counter++;
							validTurn = true;
						}
					}
					for (int j = 0; j < g_numOfEnemies; j++)
					{
						if (g_allys[j]->m_health > 0 && g_allys[j]->isPriest() && counter == 0)
						{
							OrcAttack(g_enemies[i], g_allys[j]);
							validTurn = true;
						}
					}
				}
				else if (randomSelection >= 5)
				{
					for (int j = 0; j < g_numOfEnemies; j++)
					{
						if (g_allys[j]->m_health > 0 && g_allys[j]->isPriest())
						{
							OrcAttack(g_enemies[i], g_allys[j]);
							counter++;
							validTurn = true;
						}
					}
					for (int j = 0; j < g_numOfEnemies; j++)
					{
						if (g_allys[j]->m_health > 0 && g_allys[j]->isPlayer() && counter == 0)
						{
							OrcAttack(g_enemies[i], g_allys[j]);
							validTurn = true;
						}
					}
				}
			}

		}
		validTurn = false;
	}
}

//---------------------------------------------------------------------------------
// This function loops the enemy array and gives every healer a chance to heal an enemy target. 
// after a healer selects a target, the function then loops though the enemy array 
// and for every instance of the selected enemy, they will get healed.
//---------------------------------------------------------------------------------
void healerTurn(int g_numOfEnemies, Enemy* g_enemies[])
	{
		bool validTurn = false;
		for (int i = 0; i < g_numOfEnemies; i++)
		{
			if (g_enemies[i]->m_health > 0 && g_enemies[i]->isHealer())
			{
				int randomSelection = RandomTargeting();
				std::cout << "It is the enemy healer's turn " << "\n\n";

				int counter = 0;
				while (validTurn == false)
				{
					// if the Random target generator is less then 5 and the target has health greater then 0, attack it.
					// if the selected target has no health, it will target the other possible target.
					if (randomSelection < 5)
					{
						for (int j = 0; j < g_numOfEnemies; j++)
						{
							if (g_enemies[j]->m_health > 0 && g_enemies[j]->isOrc())
							{
								heal(g_enemies[i], g_enemies[j]);
								counter++;
								validTurn = true;
							}
							for (int j = 0; j < g_numOfEnemies; j++)
							{
								if (g_enemies[j]->m_health > 0 && g_enemies[j]->isHealer() && counter == 0)
								{
									heal(g_enemies[i], g_enemies[j]);
									validTurn = true;
								}
							}
						}
					}
					else if (randomSelection >= 5)
					{
						for (int j = 0; j < g_numOfEnemies; j++)
						{
							if (g_enemies[i]->m_health > 0 && g_enemies[j]->isHealer())
							{
								heal(g_enemies[i], g_enemies[j]);
								counter++;
								validTurn = true;
							}
						}
						for (int j = 0; j < g_numOfEnemies; j++)
						{
							if (g_enemies[j]->m_health > 0 && g_enemies[j]->isOrc() && counter == 0)
							{
								heal(g_enemies[i], g_enemies[j]);
								validTurn = true;
							}
						}
					}
				}

			}
		}
	}