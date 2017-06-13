#pragma once
#include "Object.h"

#include "../bootstrap/Application.h"
#include "../bootstrap/Input.h"

class Player : Object
{
public:

	Player(Object *_parent);

	void SetUp(aie::Renderer2D Renderer, float PosX = 0, float PosY = 0, float widith = 1, float height = 1,  float velocityX = 0, float velocityY = 0);
	virtual void Update(float DT);
	virtual void Draw(aie::Renderer2D*	m_2dRenderer);



	~Player();
};

