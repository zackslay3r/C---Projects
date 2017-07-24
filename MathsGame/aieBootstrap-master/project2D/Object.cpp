#include "Object.h"
#include <Texture.h>

Object::Object()
{
	
}

void Object::SetUp(aie::Texture * texture, aie::Renderer2D * Renderer, shape::shapeType shapePick, float PosX, float PosY, float ScaleX, float ScaleY, float OriginX, float OriginY)
{
	// Sets all the values.
	m_texture = texture;
	m_2dRenderer = Renderer;


	position.x = PosX;
	position.y = PosY;

	rotation = 0;

	scale.x = ScaleX;
	scale.y = ScaleY;
	textureSize.x = (float)(m_texture)->getWidth();
	textureSize.y = (float)m_texture->getHeight();



	Origin.x = OriginX;
	Origin.y = OriginY;
	// Default the parent to nullptr.
	Parent = nullptr;

	// Sets the globalTranslate.
	calMatrix();

	// Set the shape of the object.
	MyShape.SetShape(textureSize,
	&GlobalTranslate,shapePick, Origin);
	// Calls the shape update.
	MyShape.Update();




}

// This is the setParent function.
void Object::setParent(Object * newParent)
{
	Parent = newParent;
}


// This is the update function.
void Object::Update(float DT)
{


	calMatrix();

	MyShape.Update();
}

// This is the draw function.
void Object::Draw()
{
	//m_2dRenderer->setUVRect(0, 0, 1, 1);

	m_2dRenderer->drawSpriteTransformed3x3(m_texture, GlobalTranslate, textureSize.x, textureSize.y,1,
		Origin.x, Origin.y);

	MyShape.DrawDebug(m_2dRenderer);
}

// This is the destructor.
Object::~Object()
{
}

// This is the calMatrix function, calculating the GlobalTranslate.
void Object::calMatrix()
{
	//Matrix3 PosM;

	


	//PosM[2][0] = position.x;
	//PosM[2][1] = position.y;

	LocalTranslate =
					Matrix3::setPosition(position) *
					Matrix3::SetRotateZ(rotation) * 
					Matrix3::setScale(scale);
	
	
	


	GlobalTranslate.identity();
	GlobalTranslate = LocalTranslate * GlobalTranslate;

	Object * CurrentParentPonter = Parent;
	while (CurrentParentPonter != nullptr)
	{
		GlobalTranslate = CurrentParentPonter->LocalTranslate * GlobalTranslate;
		CurrentParentPonter = CurrentParentPonter->Parent;
	}

}
