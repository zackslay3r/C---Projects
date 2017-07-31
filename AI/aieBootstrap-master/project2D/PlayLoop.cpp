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

//#include "Factory.h"

using namespace StateMangement;


class Player;
playLoop::playLoop()
{
	myNodes.fillGameNodes();
	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 16));
	input = aie::Input::getInstance();
	player = new Player(500,500);
	enemy = new Enemy(1200,300);
	enemy->target = player;
	enemy->m_behaviours.push_front(new Seek(enemy));
	enemy->m_behaviours.push_front(new Flee(enemy));
	enemy->health = 100;
	enemy2 = new Enemy(1100, 500);
	enemy2->target = player;
	enemy2->m_behaviours.push_front(new Seek(enemy2));
//	enemy2->m_behaviours.push_front(new Flee());

	for (int i = 0; i <= GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
	{
		if (myNodes.gameNodes[i].getWalkable() == false)
		{
			myWalls.push_back(new Wall(myNodes.gameNodes[i].posX, myNodes.gameNodes[i].posY));
		}
	}
	timer = 0.0;

	for (auto &behaviours : enemy->m_behaviours)
	{
		behaviours->behaviourWeight = 0.0f;
	}
}
playLoop::~playLoop()
{
	//// These will ensure that the items get deleted properly.
	//delete paddleLeft;
	//delete paddleRight;
	//delete Ball;
	delete player;
	delete enemy;
	delete enemy2;
}

playLoop * playLoop::getInstance()
{
	// This will make playloop a singleton, as we only want one play loop in our game.
	static playLoop playloop;
	return &playloop;
}

void playLoop::update(float dt, GSM* gsm)
{
	for (auto &walls : myWalls)
	{
		if (checkCollide(player, walls))
		{
			player->velocity -= player->velocity;
			player->velocity = { 0.0f, 0.0f };
		}
	}
	player->update(dt);
	
	for (auto &behaviours : enemy->m_behaviours)
	{
		
	}
	enemy2->update(dt);
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
				
				
				int enemyKey;
				enemyKey = myNodes.getIndex(enemy->position.x, enemy->position.y);
				for (int i = 0; i < 576; i++)
				{
					if (myNodes.gameNodes[i].key == enemyKey)
					{
						enemy->currentNode = &myNodes.gameNodes[i];
					}
				}
				int tempKey;
				tempKey = myNodes.getIndex(player->position.x, player->position.y);
				for (int i = 0; i < 576; i++)
				{
					if (myNodes.gameNodes[i].key == tempKey)
					{
						player->closestNode = &myNodes.gameNodes[i];
					}
				}

				if(enemy->currentNode != nullptr && player->closestNode != nullptr)
				{
					path.clear();
					//path = myNodes.pathFinding(enemy->currentNode, player->closestNode);
					enemy->path = myNodes.pathFinding(enemy->currentNode, player->closestNode);
					//path = myNodes.pathFinding(player->closestNode, enemy->currentNode);
					if (path.size() <= 0)
					{
						enemy->velocity = { 0.0f,0.0f };
						enemy2->velocity = { 0.0f,0.0f };
						tempPtr = nullptr;
					}
					else
					{
					tempPtr = path.front();
					}
					timer = glfwGetTime() + 1.0;
				}
			
			}
			

			if (myNodes.distanceCheck(player->closestNode, 300, enemy->currentNode))
			{
				enemy->changeToSeek(player);
			}
			if (enemy->health <= 30)
			{
				enemy->changeToFlee(player);
			}
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

			if (enemy->position.y < 25)
			{
				enemy->position.y = 25;
			}
			if (enemy->position.y > 875)
			{
				enemy->position.y = 875;
			}
			if (enemy->position.x < 25)
			{
				enemy->position.x = 25;
			}
			if (enemy->position.x > 1575)
			{
				enemy->position.x = 1575;
			}
			
			
			if (input->wasKeyPressed(aie::INPUT_KEY_SPACE) && checkCollide(player, enemy))
			{
				enemy->health -= 10;
			}
			
			
			enemy->update(dt);
}



void playLoop::render()
{
	std::string healthString = std::to_string(enemy->health);

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
		
	
		std::list<Node*> tmpList;
		tmpList = myNodes.completedClosedSet;
		if (myNodes.showClosedSet)
		{
			PLAY->app->m_2dRenderer->setRenderColour(0,255,0,2);
			for (auto &var : tmpList)
			{

				
				PLAY->app->m_2dRenderer->drawBox(float(var->posX), float(var->posY), 10.0f, 10.0f);
			}
		}
		
			
			//tempPtr = path.front();
			for (auto &var : enemy->path)
			{
				if (var  == enemy->path.front())
				{
					continue;
				}
				tempPtr = var;
				PLAY->app->m_2dRenderer->setRenderColour(255, 0, 0);
				PLAY->app->m_2dRenderer->drawLine(tempPtr->posX, tempPtr->posY, var->posX, var->posY, 1.0f, 0);
				
			}
		
		
		/*if (displayPath == true)
		{*/
			
		/*}*/
	}

	std::list<Node*> openTmpList;
	openTmpList = myNodes.completedOpenSet;
	if (myNodes.showOpenSet)
	{
		PLAY->app->m_2dRenderer->setRenderColour(0, 0, 255, 2);
		for (auto &var : openTmpList)
		{


			PLAY->app->m_2dRenderer->drawBox(float(var->posX), float(var->posY), 10.0f, 10.0f);
		}
	}

	
	PLAY->app->m_2dRenderer->drawText(m_font.get(), healthString.c_str(), enemy->position.x, enemy->position.y + 30.0f);

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
	enemy->render();
	enemy2->render();
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

