#include "wanderState.h"
#include "PlayLoop.h"
#include "Global.h"
#include "Player.h"

class Player;
wanderState::wanderState(enemyStateUser * _enemy, gameFSM * _gamefsm) : IGameState(_enemy, _gamefsm)
{
	enemyStateMyself = _enemy;
}

int wanderState::random()
{

	int rannumber = rand() % 10 + 1;
	return rannumber;
}

void wanderState::setAngle(Vector2 * displacement, float wanderAngle)
{
	float tempFloat = 10.0f;

	displacement->x = cos(wanderAngle) * tempFloat;
	displacement->y = sin(wanderAngle) * tempFloat;
}

void wanderState::update(float dt)
{

		
	//
	// for each enemy...
	//for (auto &behaviours : enemyStateMyself->m_behaviours)
	//{
	//	if (behaviours->type == WANDER)
	//	{
	//		behaviours->behaviourWeight = 1;
	//		behaviours->Update(dt);
	//	}
	//	else
	//	{
	//		behaviours->behaviourWeight = 0;
	//	}
	//	//PLAY->theBoard->seekAsWell();
	//}
	//	// if the distance to the player is equal or less than 300...
	//	if (PLAY->myNodes.distanceCheck(enemyStateMyself, 300, PLAY->player))
	//	{
	//		enemyStateMyself->enemyFSM->popState();
	//		enemyStateMyself->enemyFSM->pushState(SEEK);
	//	}
	
	 //circleCentre is a clone of the enemy's position, then it is normalized
	 //then it is multiplied by the wander distance.


	Vector2 circleCentre;
	circleCentre = ((enemyStateUser*)enemyStateMyself)->velocity;
	circleCentre.normalise();
	circleCentre = circleCentre * wanderDistance;

	//calculate the displacement force
	Vector2 displacement;
	displacement = { 0,-1 };
	displacement = displacement * wanderRadius;

	// randomly change the vector direction
	setAngle(&displacement, wanderAngle);

	// change the wanderAngle a little bit, so its not the same every frame.
	wanderAngle += (random() * wanderJitter) - (wanderJitter * 0.5);

	float speed = 200.0f;

	//Vector2 v1 = mySelf->position;
	// This is downcasting that will tell it to act as though it is a enemy pointer rather then a Object.
	Vector2 v2 = circleCentre + displacement;

	//Vector2 v3 = v2 - v1;

	v2.normalise();

	enemyStateMyself->velocity = v2 * speed;

	if (PLAY->myNodes.distanceCheck(enemyStateMyself, 300, PLAY->player))
	{
		enemyStateMyself->enemyFSM->popState();
		enemyStateMyself->enemyFSM->pushState(SEEK);
	}
}
	

wanderState::~wanderState()
{
}
