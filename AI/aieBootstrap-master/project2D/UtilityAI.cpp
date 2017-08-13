#include "UtilityAI.h"



UtilityAI::UtilityAI()
{
}


void UtilityAI::runAway(Enemy* myself)
{
	double tempHealth = 0.0;

	tempHealth = myself->health;

	int damagedHealth = 50 - int(tempHealth);

	int wantToFlee;

	if (tempHealth < 50)
	{
		for (auto &behaviours : myself->m_behaviours)
		{
			if (behaviours->type == FLEE)
			{

				wantToFlee =int(double(damagedHealth) * 0.5);

				damagedHealth = damagedHealth / 10;
				behaviours->behaviourWeight = 1.1f * (damagedHealth * wantToFlee);
			}
		}

	}
}

void UtilityAI::runAway(enemyStateUser * stateEnemy)
{
	float tempHealth = 0.0f;

	tempHealth = float(stateEnemy->health) / 10.0f;
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
