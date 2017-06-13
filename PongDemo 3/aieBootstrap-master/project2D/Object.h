#pragma once
#include "../bootstrap/Application.h"
#include "../bootstrap/Renderer2D.h"

class Object
{
public:
	float posX, posY;
	float velocityX, velocityY;
	float widith, height;
	
	Object();

	void SetUp( aie::Renderer2D Renderer, float PosX = 0, float PosY = 0, float velocityX = 0, float velocityY = 0);
	virtual void Update(float DT);
	virtual void Draw(aie::Renderer2D* m_2dRenderer);



	~Object();

protected:
	
};

