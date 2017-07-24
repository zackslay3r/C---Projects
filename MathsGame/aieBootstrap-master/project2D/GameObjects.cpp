#include "GameObjects.h"

void gameObject::SetUp(aie::Texture * texture, aie::Renderer2D * Renderer)
{
	position.x = 0;
	position.y = 0;

	rotation = 0;

	scale.x = 1;
	scale.y = 1;


	Origin.x = 0.5f;
	Origin.y = 0.5f;

	Parent = nullptr;

	m_texture = texture;
	m_2dRenderer = Renderer;

}
