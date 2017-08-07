#include "PlayLoop.h"
#include "Application2D.h"
#include "GSM.h"
#include "Global.h"
#include <string>
#include "Player.h"
#include <GLFW/glfw3.h>
#include "Enemy.h"
#include "Seek.h"
#include "Flee.h"
#include "seekState.h"
#include "wanderState.h"
#include "Wander.h"
#include "fleeState.h"
#include <ctime>
//#include "Factory.h"

using namespace StateMangement;
using namespace BehaviourManagement;

class Player;
playLoop::playLoop()
{
	theBoard = new blackBoard();
	srand(time(NULL));
	myNodes.fillGameNodes();
	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 16));
	input = aie::Input::getInstance();
	player = new Player(500,500);
	enemies.push_back(new Enemy(1200, 300));
	enemies.push_back(new Enemy(1100, 500));
	for (auto &enemy : enemies)
	{
		enemy->target = player;
		enemy->m_behaviours.push_front(new Seek(enemy));
		enemy->m_behaviours.push_front(new Flee(enemy));
		enemy->m_behaviours.push_front(new Wander(enemy));
		enemy->health = 100;
		int enemyKey;
		enemyKey = myNodes.getIndex(enemy->position.x, enemy->position.y);
		for (int i = 0; i < 576; i++)
		{
			if (myNodes.gameNodes[i].key == enemyKey)
			{
				if (myNodes.gameNodes[i].getWalkable())
				{
					enemy->currentNode = &myNodes.gameNodes[i];
				}
			}
		}
		enemy->enemyFSM->registerState(WANDER, new wanderState(enemy, enemy->enemyFSM));
		enemy->enemyFSM->registerState(SEEK, new seekState(enemy, enemy->enemyFSM));
		enemy->enemyFSM->registerState(FLEE, new fleeState(enemy, enemy->enemyFSM));

		enemy->enemyFSM->pushState(WANDER);
	
		theBoard->activeEnemies.push_back(enemy);
	}
	
		

	

	int tempKey;
	tempKey = myNodes.getIndex(player->position.x, player->position.y);
	for (int i = 0; i < 576; i++)
	{
		if (myNodes.gameNodes[i].key == tempKey)
		{
			if (myNodes.gameNodes[i].getWalkable())
			{
				player->closestNode = &myNodes.gameNodes[i];
			}
		}
	}


	//enemy = new Enemy(1200,300);
	//enemy->target = player;
	//enemy->m_behaviours.push_front(new Seek(enemy));
	//enemy->m_behaviours.push_front(new Flee(enemy));
	//enemy->health = 100;
	//enemy2 = new Enemy(1100, 500);
	//enemy2->target = player;
	//enemy2->m_behaviours.push_front(new Seek(enemy2));
	//enemy2->m_behaviours.push_front(new Flee(enemy2));

	for (int i = 0; i <= GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
	{
		if (myNodes.gameNodes[i].getWalkable() == false)
		{
			myWalls.push_back(new Wall(myNodes.gameNodes[i].posX, myNodes.gameNodes[i].posY));
		}
	}
	timer = 0.0;

	//for (auto &behaviours : enemies)
	//{
	//	for (auto &enemys : behaviours->m_behaviours)
	//	{
	//		enemys->behaviourWeight = 0.0f;
	//	}
	//}
}
playLoop::~playLoop()
{
	//// These will ensure that the items get deleted properly.
	//delete paddleLeft;
	//delete paddleRight;
	//delete Ball;
	delete player;
	delete theBoard;
	//delete enemy;
	//delete enemy2;
	//delete myWalls;
}

playLoop * playLoop::getInstance()
{
	// This will make playloop a singleton, as we only want one play loop in our game.
	static playLoop playloop;
	return &playloop;
}

void playLoop::update(float dt, GSM* gsm)
{
	
	

	Vector2 prevPos = player->position;
	for (auto &enemys : enemies)
	{
		enemys->previousPos = enemys->position;
	}

	player->update(dt);
	

	for (auto &enemys : enemies)
	{
		enemys->update(dt);

	}
	for (auto &enemys : enemies)
	{
		enemys->enemyFSM->updateStates(dt);
		
		enemys->velocity.x = enemys->velocity.x / float(enemys->enemyFSM->amountOfActive);
		enemys->velocity.y = enemys->velocity.y / float(enemys->enemyFSM->amountOfActive);
	}


	bool reversedplayers = false;
	

	for (auto &walls : myWalls)
	{
		if (checkCollide(player, walls))
		{
			/*	if (player->velocity.x > 0)
			{
			player->velocity.x -= player->velocity.x + 1.5f;
			}
			if (player->velocity.x < 0)
			{
			player->velocity.x += player->velocity.x + 1.5f;
			}
			if (player->velocity.y > 0)
			{
			player->velocity.y -= player->velocity.y + 1.5f;
			}
			if (player->velocity.y < 0)
			{
			player->velocity.y += player->velocity.y + 1.5f;
			}*/
			if (!reversedplayers)
			{
				player->position = prevPos;
				reversedplayers = true;
				player->velocity = player->velocity * -1.0f;

				break;
			}
			//player->velocity = { 0.0f, 0.0f };
		}
	}
		for (auto &enemys : enemies)
		{
			bool reversedenemies = false;
			for (auto &walls : myWalls)
			{
				if (checkCollide(enemys, walls))
				{
					if (!reversedenemies)
					{
						enemys->position = enemys->previousPos;
						reversedenemies = true;
						enemys->velocity = enemys->velocity * -1.0f;

						break;
					}
				}
			}
		}
	

	//enemy2->update(dt);
		if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
		{
			int keyCheckerCount = 0;
			int mX = 0;
			int mY = 0;
			input->getMouseXY(&mX, &mY);
			Vector2 mousePos = { float(mX),float(mY) };

			int tempKey = 0;
			tempKey = myNodes.getIndex(mousePos.x, mousePos.y);

			for (int i = 0 ; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
			{
				if (tempKey == myNodes.gameNodes[i].key)
				{
					if (tempKey != player->closestNode->key)
					{
						
						for (auto &enemys : enemies)
							if (tempKey != enemys->currentNode->key)
							{
								keyCheckerCount++;
								if (keyCheckerCount == enemies.size())
								{
									myNodes.wallSetter(myNodes.gameNodes[i].key);
									myWalls.push_back(new Wall(myNodes.gameNodes[i].posX, myNodes.gameNodes[i].posY));
								}
							for (auto walls : myWalls)
							{
								if (checkCollide(walls, player))
								{
									myWalls.pop_back();
									myNodes.gameNodes[i].setWalkable(true);
									myNodes.CleanUpEdgePointers();
									break;
								}
								if (checkCollide(walls, enemys))
								{
									myWalls.pop_back();
									myNodes.gameNodes[i].setWalkable(true);
									myNodes.CleanUpEdgePointers();
									break;
								}
							}
						}
					}
				}
			}
		}

	if (input->wasKeyPressed(aie::INPUT_KEY_1) == true)
	{
		if (myNodes.showKeys)
		{
			myNodes.showKeys = false;
		}
		else
		{
			myNodes.showKeys = true;
		}
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_2) == true)
	{
		if (myNodes.showSquares)
		{
			myNodes.showSquares = false;
		}
		else
		{
			myNodes.showSquares = true;
		}
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_3) == true)
	{
		
		if (myNodes.showNodes)
		{
			myNodes.showNodes = false;
		}
		else
		{
			myNodes.showNodes = true;
		}
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_4) == true)
	{

		if (myNodes.showClosedSet)
		{
			myNodes.showClosedSet = false;
		}
		else
		{
			myNodes.showClosedSet = true;
		}
	}
	
	if (input->wasKeyPressed(aie::INPUT_KEY_5) == true)
	{
		if (myNodes.showOpenSet)
		{
			myNodes.showOpenSet = false;
		}
		else
		{
			myNodes.showOpenSet = true;
		}

	}
	
	
	
		/*if (player->position.x < 50)
		{
			player->position.x = 50;
		}
		if (player->position.y >= 50.0f && player->position.y <= 100.0f)
		{
			if (player->position.y < 75.0f)
			{
				player->position.y = 49.0f;
			}
			else
			{
				player->position.y = 101.0f;
			}
		}*/
		
	
	
	bool fiveSec = TimerTick(dt);

	if (fiveSec == true)
	{
		displayPath = true;
	}
	else
	{
		displayPath = false;
	}
			
			/*std::list<Node*> path;
			Node* tempPtr;*/

			if (glfwGetTime() > timer)
			{
				
				
				for (auto &enemys : enemies)
				{

					int enemyKey;
					enemyKey = myNodes.getIndex(enemys->position.x, enemys->position.y);
					for (int i = 0; i < 576; i++)
					{
						if (myNodes.gameNodes[i].key == enemyKey)
						{
							if (myNodes.gameNodes[i].getWalkable())
							{
								enemys->currentNode = &myNodes.gameNodes[i];
							}
						}
					}
				}
				int tempKey;
				tempKey = myNodes.getIndex(player->position.x, player->position.y);
				for (int i = 0; i < 576; i++)
				{
					if (myNodes.gameNodes[i].key == tempKey)
					{
						if (myNodes.gameNodes[i].getWalkable())
						{
							player->closestNode = &myNodes.gameNodes[i];
						}
					}
				}

				
				// for all the enemies, draw their path

				for (auto &enemys : enemies)
				{
					if (enemys->currentNode != nullptr && player->closestNode != nullptr)
					{
						enemys->path.clear();
						//path = myNodes.pathFinding(enemy->currentNode, player->closestNode);
						enemys->path = myNodes.pathFinding(enemys->currentNode, player->closestNode);
						enemys->closedSet = myNodes.completedClosedSet;
						enemys->openSet = myNodes.completedOpenSet;
						if (path.size() <= 0)
						{
							enemys->velocity = { 0.0f,0.0f };
							tempPtr = nullptr;
						}
						else
						{
							tempPtr = path.front();
						}
						timer = glfwGetTime() + 0.5;
					}
				}
			}
			
			for (auto &enemys : enemies)
			{
				enemys->healthString = std::to_string(enemys->health);
				if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
				{
					if (checkCollide(player, enemys))
					{
						enemys->health -= 10;
					}
				}
			}
			// for all the enemies update them.
			
			/*if (myNodes.distanceCheck(player->closestNode, 150, enemy->currentNode))
			{

				for (auto &behaviours : enemy->m_behaviours)
				{
					if (behaviours->type == 0)
					{
						behaviours->behaviourWeight = 1.0f;
					}
					else
					{
						behaviours->behaviourWeight = 0.0f;
					}
					behaviours->Update(dt);
					
				}
			}*/
			


			if (player->position.y < 25)
			{
				player->position.y = 25;
			}
			if (player->position.y > 875)
			{
				player->position.y = 875;
			}
			if (player->position.x < 25)
			{
				player->position.x = 25;
			}
			if (player->position.x > 1575)
			{
				player->position.x = 1575;
			}

			for (auto &enemys : enemies)
			{

				if (enemys->position.y < 25)
				{
					enemys->position.y = 25;
				}
				if (enemys->position.y > 875)
				{
					enemys->position.y = 875;
				}
				if (enemys->position.x < 25)
				{
					enemys->position.x = 25;
				}
				if (enemys->position.x > 1575)
				{
					enemys->position.x = 1575;
				}
				
			}
			
		
				
			
}



void playLoop::render()
{
	
	
	PLAY->app->m_2dRenderer->setRenderColour(255, 255, 255);
	for (auto &enemys : enemies)
	{
		if (enemys->path.size() > 0)
		{

			tempPtr = enemys->path.front();
			for (auto &var : enemys->path)
			{
				// if the end of the path is hit, stop the loop.
				if (var == enemys->path.front())
				{
					continue;
				}


				PLAY->app->m_2dRenderer->drawLine(tempPtr->posX, tempPtr->posY, var->posX, var->posY, 1.0f, 0);
				tempPtr = var;
			}
		}
	}
	//for (auto &var : enemy2->path)
	//{
	//	// if the end of the path is hit, stop the loop.
	//	if (var == enemy2->path.front())
	//	{
	//		continue;
	//	}


	//	PLAY->app->m_2dRenderer->drawLine(tempPtr->posX, tempPtr->posY, var->posX, var->posY, 1.0f, 0);
	//	tempPtr = var;
	//}
	// Draws the nodes.
	for (int i = 0; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
	{
		std::string keyString = std::to_string(myNodes.gameNodes[i].key);
		PLAY->app->m_2dRenderer->setRenderColour(0, 0, 255);
		if (myNodes.showKeys == true)
		{
			PLAY->app->m_2dRenderer->drawText(m_font.get(), keyString.c_str(), myNodes.gameNodes[i].posX, myNodes.gameNodes[i].posY + 20);
		}
		if (myNodes.showNodes == true)
		{
			PLAY->app->m_2dRenderer->setRenderColour(255, 255, 255);
			PLAY->app->m_2dRenderer->drawBox(myNodes.gameNodes[i].posX, myNodes.gameNodes[i].posY, 5, 5);
		}
		if (myNodes.showSquares == true)
		{
		std::list<Edge* >::iterator iter;
		for (iter = myNodes.gameNodes[i].links.begin(); iter != myNodes.gameNodes[i].links.end(); ++iter)
		{
			if ((*iter)->edgeColour == 'r')
			{
				PLAY->app->m_2dRenderer->setRenderColour(255, 255, 255);
			}
			if ((*iter)->edgeColour == 'b')
			{
				PLAY->app->m_2dRenderer->setRenderColour(0, 255, 0);
			}
			
			PLAY->app->m_2dRenderer->drawLine(myNodes.gameNodes[(*iter)->keyOne].posX, myNodes.gameNodes[(*iter)->keyOne].posY,
				myNodes.gameNodes[(*iter)->keyTwo].posX, myNodes.gameNodes[(*iter)->keyTwo].posY);

		}


			/*    (*iter)->dScore = 6;
			Edge gvd = *(*iter);
			Edge *fdgvd = (*iter);*/

		}	
		
	
		//std::list<Node*> tmpList;
		//tmpList = myNodes.completedClosedSet;
		/*if (myNodes.showClosedSet)
		{
			PLAY->app->m_2dRenderer->setRenderColour(0,255,0,2);
			for (auto &var : tmpList)
			{

				
				PLAY->app->m_2dRenderer->drawBox(float(var->posX), float(var->posY), 10.0f, 10.0f);
			}
		}*/
		
		if (myNodes.showClosedSet)
		{
			PLAY->app->m_2dRenderer->setRenderColour(0, 255, 0, 2);
			for (auto &enemys : enemies)
			{
				for (auto &nodes : enemys->closedSet)
				{
					PLAY->app->m_2dRenderer->drawBox(float(nodes->posX), float(nodes->posY), 10.0f, 10.0f);
				}
			}
		}
			
			
		
		
		/*if (displayPath == true)
		{*/
			
		/*}*/
	}

	/*std::list<Node*> openTmpList;
	openTmpList = myNodes.completedOpenSet;
	if (myNodes.showOpenSet)
	{
		PLAY->app->m_2dRenderer->setRenderColour(0, 0, 255, 2);
		for (auto &var : openTmpList)
		{


			PLAY->app->m_2dRenderer->drawBox(float(var->posX), float(var->posY), 10.0f, 10.0f);
		}
	}*/
	if (myNodes.showOpenSet)
	{
		PLAY->app->m_2dRenderer->setRenderColour(0, 0, 255, 2);
		for (auto &enemys : enemies)
		{
			for (auto &nodes : enemys->openSet)
			{
				PLAY->app->m_2dRenderer->drawBox(float(nodes->posX), float(nodes->posY), 10.0f, 10.0f);
			}
		}
	}

	for (auto &enemys : enemies)
	{
		PLAY->app->m_2dRenderer->drawText(m_font.get(), enemys->healthString.c_str(), enemys->position.x, enemys->position.y + 30.0f);
	}
	/*if (displayPath == true)
	{*/

	/*}*/

	/*for(int i = 0; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
	{*/
		/*if(myNodes.gameNodes[i].getWalkable() == false)
		{
		myWall->render(myNodes.gameNodes[i].posX, myNodes.gameNodes[i].posY);
		}*/
		


	/*}*/
	//RECODE LATER
	
	
	for (auto &walls : myWalls)
	{
		walls->render();
	}
	

	player->render();
	//enemy->render();
	//enemy2->render();

	for (auto &enemies : enemies)
	{
		enemies->render();
	}
}


bool playLoop::checkCollide(Object* obj1, Object* obj2)
{
	
	Vector2 shape1Pos = obj1->position;
	Vector2 shape1Scale = obj1->scale;

	Vector2 shape2Pos = obj2->position;
	Vector2 shape2Scale = obj2->scale;

	float x1Min = shape1Pos.x - shape1Scale.x / 2.0f;
	float x1Max = shape1Pos.x + shape1Scale.x / 2.0f;
	float y1Min = shape1Pos.y - shape1Scale.y / 2.0f;
	float y1Max = shape1Pos.y + shape1Scale.y / 2.0f;


	float x2Min = shape2Pos.x - shape2Scale.x / 2.0f;
	float x2Max = shape2Pos.x + shape2Scale.x / 2.0f;
	float y2Min = shape2Pos.y - shape2Scale.y / 2.0f;
	float y2Max = shape2Pos.y + shape2Scale.y / 2.0f;

	if (x1Max < x2Min || x1Min > x2Max) return false;
	if (y1Max < y2Min || y1Min > y2Max) return false;

	return true;
}

bool playLoop::TimerTick(float dt)
{
	static float updateClock;
	updateClock += dt;

	if (int(updateClock) % 5 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}


}

