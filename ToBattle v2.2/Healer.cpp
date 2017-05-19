#include "Healer.h"




// A healer constructor
// When a Healer is created, do this
Healer::Healer()
{
    // Override the Enemy variables to values that apply to Healers
    m_health = 50;

}


// Healer Destructor
// When a Healer is destroyed, do this
Healer::~Healer()
{
}


// This function will heal something as long as it is a enemy pointer.
// aka, if its either a Orc or a Healer.
//void Healer::heal(Enemy *pEnemy)
//{
//	pEnemy->m_health += 10;
//}


// TESTING
// Test to see if it can heal based on type.
int Healer::getId()
{
	return m_enemyId;
}



void Healer::healingSurge(Enemy *pEnemy)
{
	
	if (pEnemy->isOrc())
	{
		pEnemy->m_health += 35;
		std::cout << "The Orc's new health is now " << pEnemy->m_health << "\n\n";
	}
	else if (pEnemy->isHealer())
	{
		pEnemy->m_health += 20;
		std::cout << "The enemy healer's new health is now " << pEnemy->m_health << "\n\n";
	}
}

int Healer::getHealth()
{
	return m_health;
}
//
//void Healer::heal(Enemy *hptr)
//{
//	std::cout << "Its now the healers turn!" << std::endl;
//	// Create a variable called target
//	// and make it between 1 and 10
//	int target = 0;
//	target = rand() % 10 + 1;
//	// if the target is less then 5,
//	// target the Orc.
//	if (target < 5)
//	{
//		g_enemies[1]->healingSurge(g_enemies[0]);
//		//show the updated health.
//		std::cout << "The Orc's Health is now" << g_enemies[0]->m_health;
//	}
//	// If the target is greater then 5
//	// target the healer itself.
//	if (target >= 5)
//	{
//		g_enemies[1]->healingSurge(g_enemies[1]);
//		std::cout << "The Healer's Health is now" << g_enemies[1]->m_health;
//	}
//}

