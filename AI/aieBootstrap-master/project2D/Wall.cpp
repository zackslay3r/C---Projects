#include "Wall.h"
#include "PlayLoop.h"
#include "Application2D.h"


Wall::Wall(float positionx, float positiony)
{
	// sets the position and scale.
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
	// This is rendering a cube.
	PLAY->app->m_2dRenderer->setRenderColour(255, 255, 255);
	PLAY->app->m_2dRenderer->drawBox(position.x,position.y,scale.x,scale.y,0.0f,1);
}

void Wall::update(float dt)
{
}




void Wall::setPos(float posx, float posy)
{
	// sets the position.
	position.x = posx;
	position.y = posy;
}
