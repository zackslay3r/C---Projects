#include "enemyStateUser.h"



enemyStateUser::enemyStateUser()
{
}

enemyStateUser::enemyStateUser(float positionX, float positionY)
{
	position.x = positionX;
	position.y = positionY;
	scale.x = 25.0f;
	scale.y = 25.0f;
	health = 100;
	enemyFSM = new gameFSM();
	utility = new UtilityAI();
	velocity = { 5,5 };
	type = AgentType::STATEUSINGENEMY;

}

void enemyStateUser::render()
{
	PLAY->app->m_2dRenderer->setRenderColour(0, 255, 0);
	PLAY->app->m_2dRenderer->drawBox(position.x, position.y, scale.x, scale.y);
}

void enemyStateUser::update(float dt)
{
	/*for (auto &states : m_behaviours)
	{
		enemyFSM->updateStates(dt);
	}*/
	enemyFSM->updateStates(dt);
	position += velocity * dt;
}

void enemyStateUser::changeToSeek(Object * target)
{
	for (auto &behaviours : m_behaviours)
	{
		if (behaviours->type == 0)
		{
			behaviours->behaviourWeight = 1.0f;
		}
		else
		{
			behaviours->behaviourWeight = 0.0f;
		}
	}
}

void enemyStateUser::changeToFlee(Object * awayFromTarget)
{
	for (auto &behaviours : m_behaviours)
	{
		if (behaviours->type == 2)
		{
			behaviours->behaviourWeight = 1.0f;
		}
		else
		{
			behaviours->behaviourWeight = 0.0f;
		}
	}
}

void enemyStateUser::changeToWander(Object * target)
{
	for (auto &behaviours : m_behaviours)
		if (behaviours->type != BehaviourID::WANDER)
		{
			behaviours->behaviourWeight = 0.0f;
		}
		else
		{
			behaviours->behaviourWeight = 1.0f;
		}
}


enemyStateUser::~enemyStateUser()
{
}
