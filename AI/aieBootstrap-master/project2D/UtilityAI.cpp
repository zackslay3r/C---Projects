#include "UtilityAI.h"



UtilityAI::UtilityAI()
{
}


void UtilityAI::runAway(Enemy* myself)
{
		float tempHealth = 0;
	
 		tempHealth = myself->health / 10;
		if (tempHealth <= 3.0)
		{
			for (auto &behaviours : myself->m_behaviours)
			{
				if (behaviours->type == FLEE)
				{
					behaviours->behaviourWeight = 1.0f;
				}
			}
		}
		
		if (tempHealth <= 2.0)
		{
			for (auto &behaviours : myself->m_behaviours)
			{
				if (behaviours->type == FLEE)
				{
					behaviours->behaviourWeight = 2.0f;
				}
			}
		}
		if (tempHealth <= 1.0)
		{
			for (auto &behaviours : myself->m_behaviours)
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
