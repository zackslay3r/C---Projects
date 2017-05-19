// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016


#include <iostream>
#include <vector>
#include "Main.h"



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

	// Declares interger variables that assign the number of marines and the number of zerlings.
	int squadSize;
	int swarmSize;

	// Recieves the input from the user of how big the squad of marines and swarm of zerglings 
	// they would like to simulate fighting each other.
	std::cout << "How many marines would you like?" << "\n\n";
	std::cin >> squadSize;
	std::cout << "How many zergling's would you like?" << "\n\n";
	std::cin >> swarmSize;


	// Declares a new instace of marine called m and then from 0 to squadSize, fill the vector of marines with a new marine.
	Marine m;
	for (int i = 0; i < squadSize; i++)
	{
		squad.push_back(m);
	}
	// Declares a new instace of zergling called z and then from 0 to swarmSize, fill the vector of zerlings with a new zerling.
	Zergling z;
	for (int i = 0; i < swarmSize; i++)
	{	
		swarm.push_back(z);
	}


	// Tell the user that the simulation is taking place and then initialize two variables that are used for keeping track of the zerlings and marines that are alive.
	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << std::endl;
	int zerglingsAlive = swarmSize;
	int marinesAlive = squadSize;
	

	// This then performs the attack function, the main part of the game that will do automated attacks and determine the winner of the game
	attack(squad, swarm, marinesAlive, zerglingsAlive);

}