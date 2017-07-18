#include "PlayLoop.h"
#include "Application2D.h"
#include "GSM.h"
#include "Global.h"
#include <string>
#include "NodeManager.h"

//#include "Factory.h"
NodeManager myNodes;
using namespace StateMangement;
Wall* myWall;


playLoop::playLoop()
{
	myNodes.fillGameNodes();
	m_font = std::unique_ptr<aie::Font>(new aie::Font("./font/consolas.ttf", 16));
}
playLoop::~playLoop()
{
	//// These will ensure that the items get deleted properly.
	//delete paddleLeft;
	//delete paddleRight;
	//delete Ball;
}

playLoop * playLoop::getInstance()
{
	// This will make playloop a singleton, as we only want one play loop in our game.
	static playLoop playloop;
	return &playloop;
}

void playLoop::update(float dt, GSM* gsm)
{
	
}



void playLoop::render()
{
	
	

	// Draws the nodes.
	for (int i = 0; i < GAMESETTINGS->NODE_ARRAY_LENGTH; i++)
	{
		std::string keyString = std::to_string(myNodes.gameNodes[i].key);
		PLAY->app->m_2dRenderer->setRenderColour(0, 0, 255);
		PLAY->app->m_2dRenderer->drawText(m_font.get(), keyString.c_str(), myNodes.gameNodes[i].posX, myNodes.gameNodes[i].posY + 20);
		PLAY->app->m_2dRenderer->drawBox(myNodes.gameNodes[i].posX, myNodes.gameNodes[i].posY, 5, 5);
		
		std::list<Edge* >::iterator iter;
		
		for (iter = myNodes.gameNodes[i].links.begin(); iter != myNodes.gameNodes[i].links.end(); ++iter)
		{
			if ((*iter)->edgeColour == 'r')
			{
				PLAY->app->m_2dRenderer->setRenderColour(255, 0, 0);
			}
			if ((*iter)->edgeColour == 'b')
			{
				PLAY->app->m_2dRenderer->setRenderColour(0, 255, 0);
			}
			PLAY->app->m_2dRenderer->drawLine(myNodes.gameNodes[(*iter)->keyOne].posX, myNodes.gameNodes[(*iter)->keyOne].posY,
				myNodes.gameNodes[(*iter)->keyTwo].posX, myNodes.gameNodes[(*iter)->keyTwo].posY);




			/*    (*iter)->dScore = 6;
			Edge gvd = *(*iter);
			Edge *fdgvd = (*iter);*/

		}
	}
	//myWall->render(200, 200);
}


bool playLoop::checkCollide(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2)
{
	//int x1Min = x1 - width1 / 2;
	//int x1Max = x1 + width1 / 2;
	//int y1Max = y1 + height1 / 2;
	//int y1Min = y1 - height1 / 2;

	//// AABB 2
	//int x2Min = x2 - width2 / 2;
	//int x2Max = x2 + width2 / 2;
	//int y2Max = y2 + height2 / 2;
	//int y2Min = y2 - height2 / 2;

	//if (x1Max < x2Min || x1Min > x2Max) return false;
	//if (y1Max < y2Min || y1Min > y2Max) return false;

	return true;
}

void playLoop::updateStateTimer(float dt)
{
	switchStateTimer += dt;
}
