#include "blackBoard.h"
#include "Enemy.h"


blackBoard::blackBoard()
{
}


void blackBoard::seekAsWell()
{
	// For each enemy that is seeking...
	for (auto &seekingEnemies : isSeeking)
	{
		// and for each enemy that is active...
		for (auto &currentEnemies : activeEnemies)
		{
			// If the enemy is not of that that is currently seeking...
			if (seekingEnemies != currentEnemies)
			{
				if (isSeeking.size() < activeEnemies.size())
				{
				// and the distance between a seeking and non seeking enemy is less then 200....
				if (distanceCheck(seekingEnemies,800.0f, currentEnemies))
				{
					
					// push the active enemy to also seek and to add to the list of actively seeking enemys.
					currentEnemies->changeToSeek();
					isSeeking.push_back(currentEnemies);
					}
				}
			}
		}
	}

	// For each enemy that is seeking...
	for (auto &seekingEnemies : isOtherSeeking)
	{
		// and for each enemy that is active...
		for (auto &currentEnemies : isOtheractiveEnemies)
		{
			// If the enemy is not of that that is currently seeking...
			if (seekingEnemies != currentEnemies)
			{
				if (isSeeking.size() < activeEnemies.size())
				{
					// and the distance between a seeking and non seeking enemy is less then 200....
					if (distanceCheck(seekingEnemies, 500.0f, currentEnemies))
					{

						// push the active enemy to also seek and to add to the list of actively seeking enemys.
						currentEnemies->enemyFSM->popState();
						currentEnemies->enemyFSM->pushState(SEEK);
						isOtherSeeking.push_back(currentEnemies);
					}
				}
			}
		}
	}
}

bool blackBoard::usePathFollow(Enemy * myself)
{
	// If the path (after smoothing) only has the start and end node, just use the seek behaviour.
	if (myself->path.size() <= 2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool blackBoard::usePathFollow(enemyStateUser * myself)
{
	return false;
}



bool blackBoard::distanceCheck(Enemy * myself, float distance, Enemy * otherEnemy)
{
	Vector2 tempVector;
	tempVector = { myself->position - otherEnemy->position };

	return ((tempVector.x * tempVector.x) + (tempVector.y * tempVector.y)) < (distance * distance);
}

bool blackBoard::distanceCheck(enemyStateUser * myself, float distance, enemyStateUser * otherEnemy)
{
	Vector2 tempVector;
	tempVector = { myself->position - otherEnemy->position };

	return ((tempVector.x * tempVector.x) + (tempVector.y * tempVector.y)) < (distance * distance);
}



blackBoard::~blackBoard()
{
}
