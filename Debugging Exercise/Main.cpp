// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <iostream>
#include <vector>
#include "Marine.h"
#include "Zergling.h"
#include "Entity.h"




//using 
using std::vector;
using std::cout;
using std::endl;

int main()
{
	// declares a vector of Marines called squad.
	vector<Marine> squad;
	// declares a vector of Zerglings called swarm.
	vector<Zergling> swarm;

	int squadSize = 10;
	int swarmSize = 20;

	// Set up the Squad and the Swarm at their initial sizes listed above

	Marine m;
	for (int i = 0; i < squadSize; i++)
	{
		squad.push_back(m);
	}
	
	Zergling z;
	for (int i = 0; i < swarmSize; i++)
	{
		
		swarm.push_back(z);
	}

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << std::endl;
	int zerlingsAlive = swarmSize;
	// Attack each other until only one team is left alive
	while (squad.size() > 0 && swarm.size() > 0) // If anyone is left alive to fight . . .
	{
		
		for (vector<Marine>::iterator i = squad.begin(); i != squad.end(); ++i) // go through the squad
		{
			if (zerlingsAlive == 0)
			{
				break;
			}

			if (swarm.begin()->isAlive() == true)
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad.begin()->attack() << " damage. " << endl;
				// if the zergling dies, it is removed from the swarm
				
				swarm.begin()->takeDamage(squad.begin()->attack());
				
				if (swarm.begin()->health <= 0)
				{
					cout << "The zergling target dies" << endl;
				
					swarm.erase(swarm.begin());
					
					zerlingsAlive = zerlingsAlive - 1;
					
				}
			}
			
		}
		
	
			for (vector<Zergling>::iterator i = swarm.begin(); i != swarm.end(); ++i) // loop through zerglings
			{
				cout << "A zergling attacks for " << i->attack() << " damage." << endl;
				
				if (squad.begin()->isAlive() == true)
				{
				squad.begin()->takeDamage(i->attack());
				}
				
				if(squad.begin()->health <= 0)
				{ 
					squad.erase(squad.begin());
					cout << "The marine succumbs to his wounds." << endl;
				}
			}
		
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (squad.size() >= 1)
	{
		cout << "The Marines win." << endl;
		system("pause");
	} 
	else 
	{
		cout << "The Zerg win." << endl;
		system("pause");
	}
}

// Is there a Marine Alive?
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

// Is there a zergling Alive
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
