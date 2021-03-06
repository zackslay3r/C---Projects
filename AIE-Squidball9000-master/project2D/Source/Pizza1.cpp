#include "Pizza1.h"

Pizza1::Pizza1()
{

	float width = 38.0f;
	float height = 42.0f;

	//Create root entity.

    //NOTE: std::vector used here instead of my custom LinkedList because the MathsLib requires a std::vector as input.

	std::vector<Vector2> tmpPoints;

	//These points are relative to Photoshop coords with top left corner of sprite 
	//being 0,0 and y- is the upward direction.
	tmpPoints.push_back(Vector2(0,41));
	tmpPoints.push_back(Vector2(10,1));
	tmpPoints.push_back(Vector2(15,1));
	tmpPoints.push_back(Vector2(38,20));

	//Translate points to game space coords system so centre of sprite is 0,0 
	//and y+ is the upward direction.
	for (auto &var : tmpPoints)
	{
		var.y = -var.y;

		var.x = var.x - width / 2.0f;
		var.y = var.y + height / 2.0f;
	}

	colliderShapes = { Shape2(tmpPoints) };
	for (auto &var : colliderShapes) var.updateNormals();
	rotatable = true;
	updateAABBFromColliders();
	setMass(10.0f);

	////Display collider box for testing.
	//Entity::RenderShape rs;
	//rs.shape = Shape2(Shape2(tmpPoints));
	//rs.colour = Colour(0.0f,1.0f,0.0f,1.0f);
	//rs.lineThickness = 1.0f;
	//rs.depth = 0.0f;
	//renderShapes.push_back(rs);
	//for (auto &var : renderShapes) var.shape.updateNormals();

	//Add sprite.
	Entity::RenderSprite rsp;
	//rsp.depth = 1.0f;
	rsp.texture = "/textures/pizza1.png";
	rsp.textureWidth = width;
	rsp.textureHeight = height;
	sprites.push_back(rsp);

}

Pizza1::~Pizza1()
{
}
