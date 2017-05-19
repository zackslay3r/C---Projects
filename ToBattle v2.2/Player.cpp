#include "Player.h"
#include "Enemy.h"
#include <iostream>


Player::Player()
{
	m_health = 100;
	//playerWeapon m_playerWeapon;
}


Player::~Player()
{
}

void Player::computeDamage(Enemy *eptr)
{
	int damage = 0;

	damage = rand() % (24 - 15 + 1) + 15;
	if (m_playerWeapon == playerWeapon::Axe)
	{
		
		damage = damage + 10;
	}

	
	// Display the Orc's new health.
	if (eptr->isOrc())
	{	
		std::cout << "You are hitting the Orc for " << damage << " damage!" << "\n\n";
		eptr->m_health -= damage;
		std::cout << "The Orc's new health is now " << eptr->m_health << std::endl;
	}
	if (eptr->isHealer())
	{
		std::cout << "You are hitting the enemy Healer for " << damage << " damage!" << "\n\n";
		eptr->m_health -= damage;
		std::cout << "The healers new health is now " << eptr->m_health << std::endl;
	}
}

int Player::getId()
{
	return m_AllyId;
}

int Player::getHealth()
{
	return m_health;
}

void Player::setWeapon(playerWeapon pWeapon)
{
	m_playerWeapon = pWeapon;
}

//void Player::playerTurn(int g_numOfAllys, Ally* g_allys[], int g_numOfEnemies, Enemy* g_enemies[])
//{
//	char enemyChoice;
//	bool validTurn;
//	validTurn = false;
//
//	//this is the main ally loop that checks though and if there is a player of a certain type
//	// they have their turn. 
//	for (int i = 0; i < g_numOfAllys; i++)
//	{
//
//		// Check winner checks to see if all Allys or all enemies are killed.
//		if (g_allys[i]->m_health > 0 && g_allys[i]->isPlayer())
//		{
//
//			while (validTurn == false)
//			{
//				std::cout << "Would you like to damage the Orc or the healer?" << "\n\n";
//				std::cout << "type o for the orc and h for the healer." << "\n\n";
//				// This is the user input based on a char.
//				std::cin >> enemyChoice;
//				// If the char is a 'o', attack the orc.
//
//				if (enemyChoice == 'o')
//
//					//this is a sub loop for finding the target.
//					for (int j = 0; j < g_numOfEnemies; j++)
//					{
//
//						if (g_enemies[j]->m_health > 0 && g_enemies[j]->isOrc())
//						{
//
//							std::cout << "You are attacking the Orc!" << "\n\n";
//							std::cout << "press any key to continue." << std::endl;
//							std::cin.ignore();
//							system("cls");
//							g_allys[i]->computeDamage(g_enemies[j]);
//							validTurn = true;
//						}
//
//					}
//				//if the target is h, attack the healer
//				if (enemyChoice == 'h')
//				{
//					for (int j = 0; j < g_numOfEnemies; j++)
//					{
//						if (g_enemies[j]->m_health > 0 && g_enemies[j]->isHealer())
//						{
//
//							std::cout << "You are attacking the enemy Healer!" << "\n\n";
//							std::cin.ignore();
//							system("cls");
//							g_allys[i]->computeDamage(g_enemies[j]);
//							validTurn = true;
//
//						}
//					}
//					if (validTurn == false)
//					{
//						std::cout << "Please select the other enemy as the enemy you have selected doesnt have health." << "\n\n";
//
//					}
//
//				}
//			}
//		}
//
//
//	}
//}
