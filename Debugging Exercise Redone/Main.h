#pragma once
#include <iostream>
#include <vector>
#include "Marine.h"
#include "Zergling.h"

using std::vector;
using std::cout;
using std::endl;




// This function automates all attacks between the marines and the zerglings until either one reaches 0. 
// This function then also displays to the user who won the simulation.
// squad is the Marine vector, swarm is the zerling vector, marinesAlive is the marine count for alive marines and zerlingingsAlive is the zerling count for alive zerglings.
void attack(vector<Marine> squad, vector<Zergling> swarm, int marinesAlive, int zerglingsAlive)
{

	// This while loop continues if at least one unit is alive on each side.
	while (squad.size() > 0 && swarm.size() > 0)
	{

		// This for loop lets every marine thats alive have a turn to attack unless
		// all the zerling's are dead, and if that happens, then the for loop is broken.
		for (vector<Marine>::iterator i = squad.begin(); i != squad.end(); ++i)
		{
			if (zerglingsAlive == 0)
			{
				break;
			}

			// if a zerling at the beginning of the vector is alive, then allow the marine to attack them.
			if (swarm.begin()->isAlive() == true)
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad.begin()->attack() << " damage. " << endl;
				// if the zergling dies, it is removed from the swarm

				swarm.begin()->takeDamage(squad.begin()->attack());

				// and then display to the user that a zerling has died and decrement the zerglingsAlive variable.
				if (swarm.begin()->health <= 0)
				{
					cout << "The zergling target dies" << endl;

					swarm.erase(swarm.begin());

					zerglingsAlive--;

				}
			}

		}

		// This for loop lets every zerling thats alive have a turn to attack unless
		// all the marine's are dead, and if that happens, then the for loop is broken.
		for (vector<Zergling>::iterator i = swarm.begin(); i != swarm.end(); ++i)
		{
			if (marinesAlive == 0)
			{
				break;
			}
			// each zergling will attack the first zergling in the squad
			cout << "A zergling attacks for " << i->attack() << " damage." << endl;
			// if a marine at the beginning of the vector is alive, then allow the zerling to attack them.
			if (squad.begin()->isAlive() == true)
			{
				squad.begin()->takeDamage(i->attack());
			}
			// if a marine dies, it is removed from the squad
			// and then display to the user that a marine has died and decrement the marinesAlive variable.
			if (squad.begin()->health <= 0)
			{
				squad.erase(squad.begin());
				cout << "The marine succumbs to his wounds." << endl;
				marinesAlive--;
			}
		}


		
		cout << "The fight is over. ";
		// Then at the end of the fight, if there is still a marine alive, then the marines have won.
		if (squad.size() >= 1)
		{
			cout << "The Marines win." << endl;
			system("pause");
		}
		// Otherwise, the swarm has won.
		else
		{
			cout << "The Zerg win." << endl;
			system("pause");
		}

	}
}
// This function will tell the user whether or not the squad or the swarm has won based on whether or not squad still has one member in it after the function of "attack".
void declareWinner(vector<Marine> squad)
{
	//cout << "The fight is over. ";
	//if (squad.size() >= 1)
	//{
	//	cout << "The Marines win." << endl;
	//	system("pause");
	//}
	//else 
	//{
	//	cout << "The Zerg win." << endl;
	//	system("pause");
	//}
}


// This function checks to see if the size of the marine squad and if it is greater then 0
// then it will return true.
bool marineAlive(vector<Marine> squad)
{
	if (squad.size() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// This function checks to see if the size of the zergling squad and if it is greater then 0
// then it will return true.
bool zerglingAlive(vector<Zergling> swarm)
{
	if (swarm.size() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
