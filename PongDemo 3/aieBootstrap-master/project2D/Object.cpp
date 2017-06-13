#include "Object.h"



Object::Object()
{

}

void Object::SetUp(aie::Renderer2D Renderer, float PosX, float PosY, float velocityX, float velocityY)
{
}

void Object::Update(float DT)
{
	for (auto iter = m_components.begin(); iter != m_components.end(); iter++) {
		(*iter)->update(DT);
	}
}

void Object::Draw(aie::Renderer2D * m_2dRenderer)
{
	for (auto iter = m_components.begin(); iter != m_components.end(); iter++) {
		(*iter)->render(m_2dRenderer);
	}
	m_2dRenderer->drawBox(bounds.x, bounds.y, bounds.width, bounds.height);
}

void Object::addComponent(IComponent * _component)
{
	m_components.pushBack(_component);

}


Object::~Object()
{
}
