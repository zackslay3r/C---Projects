#pragma once
#include "../bootstrap/Application.h"
#include "../bootstrap/Renderer2D.h"
#include "Global.h"
#include "../demo/demoList.h"
#include "Component.h"
using namespace Box;
class Object
{
public:

	
	Object();

	void SetUp( aie::Renderer2D Renderer, float PosX = 0, float PosY = 0, float velocityX = 0, float velocityY = 0);
	virtual void Update(float DT);
	virtual void Draw(aie::Renderer2D* m_2dRenderer);

	void addComponent(IComponent *_component);


	void setPos(float x, float y) { bounds.x = x; bounds.y = y; }
	void setSize(float width, float height) { bounds.width = width; bounds.height = height; }

	boxRec& getBounds() { return bounds; }
	~Object();

protected:
	List<IComponent*> m_components;
	boxRec bounds;
	float velocityX, velocityY;
	
};

