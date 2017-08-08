#include "seekState.h"
#include "PlayLoop.h"
#include "Global.h"


using namespace BehaviourManagement;
seekState::seekState(enemyStateUser* _enemy, gameFSM * _gamefsm) : IGameState(_enemy, _gamefsm)
{
	enemyStateMyself = _enemy;
}

void seekState::update(float dt)
{
	
	
	
		// If the path is not empty...
		if (((enemyStateUser*)enemyStateMyself)->path.size() > 0)
		{
			// the default distance between nodes.
			float distance = 50.0f;
			// the enemy position - the position of the last node.
			float DistX = (((enemyStateUser*)enemyStateMyself)->position.x) - (((enemyStateUser*)enemyStateMyself)->path.back()->posX);
			float DistY = (((enemyStateUser*)enemyStateMyself)->position.y) - (((enemyStateUser*)enemyStateMyself)->path.back()->posY);


			float x = DistX * DistX;
			float y = DistY * DistY;
			float xy = x + y;

			if (xy < distance * distance)
			{
				(((enemyStateUser*)enemyStateMyself)->path.pop_back());
			}
		}


		// if the path has at least one node in it, we need to go there!
		if (((enemyStateUser*)enemyStateMyself)->path.size() > 0)
		{
			// default velocity.
			float speed = 100.0f;

			// vector1 is our own position.
			Vector2 v1 = enemyStateMyself->position;
			// This is downcasting that will tell it to act as though it is a enemy pointer rather then a Object.
			Vector2 v2 = { ((enemyStateUser*)enemyStateMyself)->path.back()->posX, ((enemyStateUser*)enemyStateMyself)->path.back()->posY };

			Vector2 v3 = v2 - v1;

			v3.normalise();

			//this will work out the final velocity.
			enemyStateMyself->velocity = v3 * speed;

		}
		// if the path is 0, we want to stop moving, please?
		if (((enemyStateUser*)enemyStateMyself)->path.size() <= 0)
		{
			enemyStateMyself->velocity = { 0,0 };
		}
			PLAY->theBoard->isOtherSeeking.push_back(enemyStateMyself);
			PLAY->theBoard->seekAsWell();
		
	
	

	
		if (enemyStateMyself->health <= 30)
		{
			enemyStateMyself->enemyFSM->popState();
			enemyStateMyself->enemyFSM->pushState(FLEE);
		}
	//myself->utility->runAway(myself);
	
}

seekState::~seekState()
{
}
