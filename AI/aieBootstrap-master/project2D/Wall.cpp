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
	PLAY->app->m_2dRenderer->drawBox(float(posX),float(posY),50.0f,50.0f,0.0f,1);
}


void Wall::setPos(int posx, int posy)
{
	position.x = float(posx);
	position.y = float(posy);
}
