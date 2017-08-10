#include "UtilityAI.h"



UtilityAI::UtilityAI()
{
}


void UtilityAI::runAway(Enemy* myself)
{
	double tempHealth = 0.0;

	tempHealth = myself->health;

	double damagedHealth = 50.0 - tempHealth;

	int wantToFlee;

	if (tempHealth < 50)
	{
		for (auto &behaviours : myself->m_behaviours)
		{
			if (behaviours->type == FLEE)
			{

				wantToFlee = damagedHealth * 0.5;

				damagedHealth = damagedHealth / 10.0;
				behaviours->behaviourWeight = 1 * (damagedHealth * wantToFlee);
			}
		}

	}
}

void UtilityAI::runAway(enemyStateUser * stateEnemy)
{
	float tempHealth = 0;

	tempHealth = stateEnemy->health / 10;
	if (tempHealth <= 3.0)
	{
		for (auto &behaviours : stateEnemy->m_behaviours)
		{
			if (behaviours->type == FLEE)
			{
				behaviours->behaviourWeight = 1.0f;
			}
		}
	}

	if (tempHealth <= 2.0)
	{
		for (auto &behaviours : stateEnemy->m_behaviours)
		{
			if (behaviours->type == FLEE)
			{
				behaviours->behaviourWeight = 2.0f;
			}
		}
	}
	if (tempHealth <= 1.0)
	{
		for (auto &behaviours : stateEnemy->m_behaviours)
		{
			if (behaviours->type == FLEE)
			{
				behaviours->behaviourWeight = 3.0f;
			}
		}
	}

}

UtilityAI::~UtilityAI()
{
}
