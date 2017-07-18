#include "Object.h"
#include "PlayLoop.h"
#include "Application2D.h"

Object::Object()
{
}


void Object::render()
{
	PLAY->app->m_2dRenderer->drawBox(posX, posY, width, height);
}




Object::~Object()
{
}
