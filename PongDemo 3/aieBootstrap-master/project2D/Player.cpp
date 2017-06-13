#include "Player.h"



Player::Player()
{
	
}

void Player::SetUp(aie::Renderer2D Renderer, float PosX, float PosY, float widith, float height,float velocityX, float velocityY)
{
	Object::SetUp(Renderer, 200, 200, 5,20);
}

void Player::Update(float DT)
{
}

void Player::Draw(aie::Renderer2D*	m_2dRenderer)
{
	Object::Draw(m_2dRenderer);
}


Player::~Player()
{
}
