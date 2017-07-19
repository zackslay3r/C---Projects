#include "Wall.h"
#include "PlayLoop.h"
#include "Application2D.h"


Wall::Wall()
{
}


Wall::~Wall()
{
}

void Wall::render(int posX, int posY)
{
	PLAY->app->m_2dRenderer->setRenderColour(255, 255, 255);
	PLAY->app->m_2dRenderer->drawBox(float(posX)+25.0f,float(posY)+25.0f,50.0f,50.0f);
}

void Wall::setPos(int posx, int posy)
{
	posX = float(posx);
	posY = float(posy);
}
