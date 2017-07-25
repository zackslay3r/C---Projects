#include "Wall.h"
#include "PlayLoop.h"
#include "Application2D.h"


Wall::Wall(float positionx, float positiony)
{
	position.x = positionx;
	position.y = positiony;
	scale.x = 50.0f;
	scale.y = 50.0f;
	
}


Wall::~Wall()
{
}

void Wall::render()
{
	PLAY->app->m_2dRenderer->setRenderColour(255, 255, 255);
	PLAY->app->m_2dRenderer->drawBox(position.x,position.y,50.0f,50.0f,0.0f,1);
}

void Wall::update(float dt)
{
}


void Wall::setPos(int posx, int posy)
{
	position.x = float(posx);
	position.y = float(posy);
}
