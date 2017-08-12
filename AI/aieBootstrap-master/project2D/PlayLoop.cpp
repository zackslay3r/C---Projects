#include "PlayLoop.h"
#include "Application2D.h"
#include "GSM.h"
#include "Global.h"
#include <string>
#include "Player.h"
#include <GLFW/glfw3.h>
#include "Enemy.h"
#include "MoveAlongPath.h"
#include "Flee.h"
#include "seekState.h"
#include "wanderState.h"
#include "Wander.h"
#include "fleeState.h"
#include "Avoidance.h"
#include "Alignment.h"
#include "Separation.h"
#include "Cohesion.h"

#include "Seeking.h"
#include <ctime>
//#include "Factory.h"

using namespace StateMangement;
using namespace BehaviourManagement;

class Player;
playLoop::playLoop()
{
	// Initalises the blackboard.
	theBoard = new blackBoard();
	// Initialised the srand for later use in Wander.
	srand(time(NULL));
	// Fills the game nodes.
	myNodes.fillGameNodes();
	// The font that will be used to display health.
	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 16));
	// Gets the instance of the singleton.
	input = aie::Input::getInstance();
	// Initalises the player.
	player = new Player(500,500);
	player->type = Object::AgentType::PLAYER;
	// Initalises the dumb AI.
	stateEnemy.push_back(new enemyStateUser(1150,600));
	// Initalises the smart AI enemies,
	enemies.push_back(new Enemy(1200, 300));
	enemies.push_back(new Enemy(800, 500));

	// Initalises the flock.
	flock.push_back(new FlockCube(600, 600));
	flock.push_back(new FlockCube(500, 600));
	flock.push_back(new FlockCube(600, 700));
	flock.push_back(new FlockCube(700, 700));

	// For all the enemys in the list, push their behaviours,
	// set health to 100, and get their current node index.
	// before setting their default behaviour to wander.
	// and adding to the blackboard that they are an active enemy.
	for (auto &enemy : enemies)
	{
		enemy->target = player;
		enemy->m_behaviours.push_front(new MoveAlongPath(enemy));
		enemy->m_behaviours.push_front(new Seeking(enemy));
		enemy->m_behaviours.push_front(new Flee(enemy));
		enemy->m_behaviours.push_front(new Wander(enemy));
		//enemy->m_behaviours.push_front(new Avoidance(enemy, 0.0f));
		enemy->m_behaviours.push_front(new Avoidance(enemy, 35.0f, 5.0f));
		enemy->m_behaviours.push_front(new Avoidance(enemy, -35.0f, 5.0f));
		enemy->m_behaviours.push_front(new Avoidance(enemy, 0.0f, 10.0f));
		//enemy->m_behaviours.push_front(new Alignment(enemy));
		//enemy->m_behaviours.push_front(new Separation(enemy));
		//enemy->m_behaviours.push_front(new Cohesion(enemy));
		//enemy->m_behaviours.push_front(new Avoidance(enemy, 90.0f));
		//enemy->m_behaviours.push_front(new Avoidance(enemy, -90.0f));
		enemy->type = Object::AgentType::BEHAVIOURUSINGENEMY;
		enemy->health = 100;
		int enemyKey;
		enemyKey = myNodes.getIndex(enemy->position.x, enemy->position.y);
		for (int i = 0; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
		{
			if (myNodes.gameNodes[i].key == enemyKey)
			{
				if (myNodes.gameNodes[i].getWalkable())
				{
					enemy->currentNode = &myNodes.gameNodes[i];
				}
			}
		}
		enemy->changeToWander();
		
	
		theBoard->activeEnemies.push_back(enemy);
	}

	
	// Add the states to the dumb ai and push the WANDER state.
	// While also setting the node key to be of the current node it is in.
	for (auto &dumbenemies : stateEnemy)
	{
		
		dumbenemies->enemyFSM->registerState(WANDER, new wanderState(dumbenemies, dumbenemies->enemyFSM));
		dumbenemies->enemyFSM->registerState(SEEK, new seekState(dumbenemies, dumbenemies->enemyFSM));
		dumbenemies->enemyFSM->registerState(FLEE, new fleeState(dumbenemies, dumbenemies->enemyFSM));
		dumbenemies->enemyFSM->pushState(WANDER);
		dumbenemies->type = Object::AgentType::STATEUSINGENEMY;

		int enemyKey;
		enemyKey = myNodes.getIndex(dumbenemies->position.x, dumbenemies->position.y);
		for (int i = 0; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
		{
			if (myNodes.gameNodes[i].key == enemyKey)
			{
				if (myNodes.gameNodes[i].getWalkable())
				{
					dumbenemies->currentNode = &myNodes.gameNodes[i];
				}
			}
		}
		

		for (auto &flockcubes : flock)
		{ 
			int flockKey = 1;
			
			flockcubes->id = flockKey;
			flockKey++;
			if(flockcubes->id == 1)
			{
			flockcubes->m_behaviours.push_front(new Seeking(flockcubes));
			flockcubes->target = player;
			flockcubes->changeToSeek();
			flockcubes->type = Object::AgentType::FLOCKCUBE;
			flockcubes->m_behaviours.push_front(new Alignment(flockcubes));
			flockcubes->m_behaviours.push_front(new Separation(flockcubes));
			flockcubes->m_behaviours.push_front(new Cohesion(flockcubes));
			}
			else
			{
				flockcubes->m_behaviours.push_front(new Alignment(flockcubes));
				flockcubes->m_behaviours.push_front(new Separation(flockcubes));
				flockcubes->m_behaviours.push_front(new Cohesion(flockcubes));
				flockcubes->type = Object::AgentType::FLOCKCUBE;
			}
		}
		

	}

	
	// Get the current node index for the player.
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

	// Create the inital walls in the game.
	for (int i = 0; i <= GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
	{
		if (myNodes.gameNodes[i].getWalkable() == false)
		{
			myWalls.push_back(new Wall(myNodes.gameNodes[i].posX, myNodes.gameNodes[i].posY));
		}
	}
	// set the timer to be 0.
	timer = 0.0;


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
	
	
	// Set the previous position of the player before the update.
	Vector2 prevPos = player->position;
	// Update the player.
	player->update(dt);
	
	// Set the enemy's previous position to be that of its current before it moves.
	for (auto &enemys : enemies)
	{
		enemys->previousPos = enemys->position;
	}
	// Set the dumbAi's previous position to be that of its current before it updates.
	for (auto &dumbenemies : stateEnemy)
	{
		dumbenemies->previousPos = dumbenemies->position;
	}
	
	
	// SmartEnemies update.
	for (auto &enemys : enemies)
	{
		enemys->update(dt);

	}
	// Dumbenemies Update.
	for (auto &dumbenemies : stateEnemy)
	{
		dumbenemies->update(dt);
	}
	
	for (auto &flockcubes : flock)
	{
		flockcubes->update(dt);
	}
	
	// Set the reversedplayers boolean to false.
	bool reversedplayers = false;
	
	// for all the walls, check to see if they are colliding with the player.
	for (auto &walls : myWalls)
	{
		if (checkCollide(player, walls))
		{

			// if the bool is false, set it to true, make the position of the player as it was
			// in the previous frame and set its velocity to bounce back the player.
			// This will only happen once every frame.

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
		// This does the exact same thing for smartAI enemies.
	/*	for (auto &enemys : enemies)
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
		}*/
		
		// This does the exact same thing for dumbAI enemies.
		for (auto &dumbenemies : stateEnemy)
		{
			bool reverseddumbenemies = false;
			for (auto &walls : myWalls)
			{
				if (checkCollide(dumbenemies, walls))
				{
					if (!reverseddumbenemies)
					{
						dumbenemies->position = dumbenemies->previousPos;
						reverseddumbenemies = true;
						dumbenemies->velocity = dumbenemies->velocity * -1.0f;

						break;
					}
				}
			}
		}

		// This function is responsible for creating walls mid game.
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
			

			// if the timer ticks over, reget all enemies and player's currentNodes.
			if (glfwGetTime() > timer)
			{
				
				// Smart enemies
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
				// dumb enemies
				for (auto &dumbenemies : stateEnemy)
				{

					int enemyKey;
					enemyKey = myNodes.getIndex(dumbenemies->position.x, dumbenemies->position.y);
					for (int i = 0; i < 576; i++)
					{
						if (myNodes.gameNodes[i].key == enemyKey)
						{
							if (myNodes.gameNodes[i].getWalkable())
							{
								dumbenemies->currentNode = &myNodes.gameNodes[i];
							}
						}
					}
				}
				// Player
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
				// smart enemies
				for (auto &enemys : enemies)
				{
					if (enemys->currentNode != nullptr && player->closestNode != nullptr)
					{
						enemys->path.clear();
						//path = myNodes.pathFinding(enemy->currentNode, player->closestNode);
						enemys->path = myNodes.pathFinding(enemys->currentNode, player->closestNode);
						
						
							
									std::list<Node*>::iterator startIter;
									std::list<Node*>::iterator middleIter;
									std::list<Node*>::iterator endIter;

									startIter = enemys->path.begin();

								//for (auto &path : enemys->path)
								while (startIter != enemys->path.end())
								{
									middleIter = startIter;
									middleIter++;
									if (middleIter == enemys->path.end())
									{
										break;
									}
									endIter = middleIter;
									endIter++;
									if (endIter == enemys->path.end())
									{
										break;
									}
									
									if (nodeCollision({ (*startIter)->posX,(*startIter)->posY },
										{ (*endIter)->posX,(*endIter)->posY }))//hit wall
									{
										startIter = middleIter;									
									}
									else // no wall
									{
										enemys->path.remove((*middleIter));
									}
								}

							
						
						
						
						
						enemys->closedSet = myNodes.completedClosedSet;
						enemys->openSet = myNodes.completedOpenSet;
						if (path.size() <= 0)
						{
							//enemys->velocity = { 0.0f,0.0f };
							tempPtr = nullptr;
						}
						else
						{
							tempPtr = path.front();
						}
						
						//increment the timer.
						timer = glfwGetTime() + 0.5;
					}
				}


				// for all the enemies, draw their path
				// dumb enemies
				for (auto &dumbenemies : stateEnemy)
				{
					if (dumbenemies->currentNode != nullptr && player->closestNode != nullptr)
					{
						dumbenemies->path.clear();
						//path = myNodes.pathFinding(enemy->currentNode, player->closestNode);
						dumbenemies->path = myNodes.pathFinding(dumbenemies->currentNode, player->closestNode);
						dumbenemies->closedSet = myNodes.completedClosedSet;
						dumbenemies->openSet = myNodes.completedOpenSet;
						if (path.size() <= 0)
						{
							dumbenemies->velocity = { 0.0f,0.0f };
							tempPtr = nullptr;
						}
						else
						{
							tempPtr = path.front();
						}
						
					}
				}
			}
			
			
			
			// for all the smart enemies, check if they are getting damaged.
			/*for (auto &enemys : enemies)
			{
				enemys->healthString = std::to_string(enemys->health);
				if (input->isKeyDown(aie::INPUT_KEY_SPACE))
				{
					if (checkCollide(player, enemys))
					{
						enemys->health -= 1;
					}
				}
			}*/
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
			

			// make sure they dont go out of the screen!
			//Player
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
			//smart enemies
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
			//dumb enemies
			for (auto &dumbenemies : stateEnemy)
			{

				if (dumbenemies->position.y < 25)
				{
					dumbenemies->position.y = 25;
				}
				if (dumbenemies->position.y > 875)
				{
					dumbenemies->position.y = 875;
				}
				if (dumbenemies->position.x < 25)
				{
					dumbenemies->position.x = 25;
				}
				if (dumbenemies->position.x > 1575)
				{
					dumbenemies->position.x = 1575;
				}

			}
		
				
			
}



void playLoop::render()
{
	
	// draw both smart and dumbAI's path
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


	for (auto &dumbenemies : stateEnemy)
	{
		if (dumbenemies->path.size() > 0)
		{

			tempPtr = dumbenemies->path.front();
			for (auto &var : dumbenemies->path)
			{
				// if the end of the path is hit, stop the loop.
				if (var == dumbenemies->path.front())
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
	
	
	for (auto &enemys : enemies)
	{
		for (auto &enemyfeelers : enemys->m_behaviours)
		{
			if (enemyfeelers->type == IBehavior::AVOIDANCE)
			{

			PLAY->app->m_2dRenderer->drawLine(enemys->position.x, enemys->position.y, 
				((Avoidance*)enemyfeelers)->lineEnd.x, ((Avoidance*)enemyfeelers)->lineEnd.y, 5);
			}

		}
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
	for (auto &dumbenemies : stateEnemy)
	{
		dumbenemies->render();
	}
	
	for (auto &enemies : enemies)
	{
		enemies->render();
	}
	
	for (auto &flockcubes : flock)
	{
		flockcubes->render();
	}
}

bool playLoop::lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	// calculate the direction of the lines
	float uA = ((x4 - x3)*(y1 - y3) - (y4 - y3)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));
	float uB = ((x2 - x1)*(y1 - y3) - (y2 - y1)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));

	// if uA and uB are between 0-1, lines are colliding
	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {

		return true;
	}
	return false;

}

bool playLoop::lineRec(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh)
{
	// check if the line has hit any of the rectangle's sides
	// uses the Line/Line function below
	bool left = lineLine(x1, y1, x2, y2, rx, ry, rx, ry + rh);
	bool right = lineLine(x1, y1, x2, y2, rx + rw, ry, rx + rw, ry + rh);
	bool top = lineLine(x1, y1, x2, y2, rx, ry, rx + rw, ry);
	bool bottom = lineLine(x1, y1, x2, y2, rx, ry + rh, rx + rw, ry + rh);

	// if ANY of the above are true, the line
	// has hit the rectangle
	if (left || right || top || bottom) {
		return true;
	}
	return false;
}

bool playLoop::nodeCollision(Vector2 pos1, Vector2 pos2)
{
	
	for (auto &walls : PLAY->myWalls)
	{
		if (lineRec(pos1.x, pos1.y, pos2.x, pos2.y, walls->position.x, walls->position.y, walls->scale.x, walls->scale.y))
		{
			return true;
		}
	
	}
	return false;
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

