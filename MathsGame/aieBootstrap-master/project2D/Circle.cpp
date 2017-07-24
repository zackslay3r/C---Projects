
#include "Circle.h"


//default constructor
Circle::Circle()
{
}
// Constructor with values
Circle::Circle(aie::Texture * texture, aie::Renderer2D * Renderer)
{
	Object::SetUp(texture, Renderer, shape::shapeType::Circle, 200, 200);

}


//Update function
void Circle::Update(float DT, aie::Input * Input)
{
	//This vector2 uses the standard forward moving
	Vector2 forwards = GlobalTranslate * Vector2(0.0f, -1.0f);

	forwards -= position;

	if (bounceUp == true)
	{
		forwards = forwards * -1.10f;
	}
	else
	{
		forwards = forwards * 1.10f;
	}
	//Applys the velocity vector to move forwards in the correct way added onto the forwards vector.
	velocity += forwards * 100 * DT;
	
	velocity = velocity * pow(0.95f, DT * 60.0f);
	position = position + velocity * 10 * DT;

	// update matrix
	calMatrix();
	Object::Update(DT);
	MyShape.Update();
}
//Draw function
void Circle::Draw()
{
//draw the sprite
m_2dRenderer->drawSpriteTransformed3x3(m_texture, GlobalTranslate, textureSize.x, textureSize.y, 1,
		Origin.x, Origin.y);
// draw the shape
	//MyShape.DrawDebug(m_2dRenderer);
}
// Destructor
Circle::~Circle()
{
}

