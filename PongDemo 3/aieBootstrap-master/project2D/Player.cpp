#include "Player.h"
#include "PlayerController.h"


Player::Player(Object *_parent) : Object(_parent)
{
	addComponent(new CPlayerController(this));
}

Player::Player(Object * _parent)
{
}

void Player::SetUp(aie::Renderer2D Renderer, float PosX, float PosY, float widith, float height,float velocityX, float velocityY)
{
	Object::SetUp(Renderer, 200, 200, 5,20);
}

void Player::Update(float DT)
{
	Object::Update(DT);
}

void Player::Draw(aie::Renderer2D*	m_2dRenderer)
{
	Object::Draw(m_2dRenderer);
}


Player::~Player()
{
}
