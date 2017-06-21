#include "Object.h"
#include "PlayLoop.h"
#include "Application2D.h"

Object::Object()
{}




void Object::Update(float DT)
{
}

void Object::Draw()
{
	PLAY->app->m_2dRenderer->drawBox(posX, posY, width, height);
}




Object::~Object()
{
}
