#pragma once
#include "../bootstrap/Application.h"
#include "../bootstrap/Renderer2D.h"

class Object
{
public:
	float posX, posY;
	float velocityX, velocityY;
	float width, height;
	
	Object(float PosX, float PosY, float width, float height,float veloX, float veloY);

	void SetUp(float PosX = 0, float PosY = 0, float velocityX = 0, float velocityY = 0);
	virtual void Update(float DT);
	virtual void Draw();
	


	~Object();

protected:
	
};

