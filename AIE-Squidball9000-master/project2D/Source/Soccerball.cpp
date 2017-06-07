#include "Soccerball.h"

Soccerball::Soccerball()
{

	float size = 40.0f;

	//Create root entity.
	colliderShapes = { Shape2(size) };
	for (auto &var : colliderShapes) var.updateNormals();
	rotatable = true;
	updateAABBFromColliders();
	setMass(10.0f);

	//Add sprite.
	Entity::RenderSprite rsp;
	//rsp.depth = 1.0f;
	rsp.texture = "/textures/soccerball.png";
	rsp.textureWidth = size * 2.0f;
	rsp.textureHeight = size * 2.0f;
	sprites.push_back(rsp);

}

Soccerball::~Soccerball()
{
}
