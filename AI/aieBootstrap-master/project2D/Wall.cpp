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
	PLAY->app->m_2dRenderer->drawBox(posX - 25, posY - 25, 50, 50);
}

void Wall::setPos(int posx, int posy)
{
	posX = posx;
	posY = posy;
}
