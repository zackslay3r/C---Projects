#include "Object.h"



Object::Object()
{

}

void Object::SetUp(aie::Renderer2D Renderer, float PosX, float PosY, float velocityX, float velocityY)
{
}

void Object::Update(float DT)
{
}

void Object::Draw(aie::Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawBox(posX, posY, widith, height);
}


Object::~Object()
{
}
