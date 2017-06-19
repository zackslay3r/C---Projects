#include "Object.h"
#include "PlayLoop.h"
#include "Application2D.h"

Object::Object()
{}


//Object::Object(float positionx = 0, float positiony = 0, float wid = 0, float hei = 0, float veloX = 0, float veloY = 0)
//{
//	posX = positionx;
//	posY = positiony;
//	width = wid;
//	height = hei;
//
//	velocityX = veloX;
//	velocityY = veloY;
//
//}

//void Object::SetUp(float PosX, float PosY, float velocityX, float velocityY)
//{
//}

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
