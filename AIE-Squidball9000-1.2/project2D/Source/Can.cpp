#include "Can.h"

Can::Can()
{

	float width = 34.0f;
	float height = 59.0f;

	//These points are relative to Photoshop coords with top left corner of sprite 
	//being 0,0 and y- is the upward direction.
    //NOTE: std::vector used here instead of my custom LinkedList because the MathsLib requires a std::vector as input.
	std::vector<Vector2> tmpPoints;
	tmpPoints.push_back(Vector2(1,1));
	tmpPoints.push_back(Vector2(33,1));
	tmpPoints.push_back(Vector2(32,54));
	tmpPoints.push_back(Vector2(25,58));
	tmpPoints.push_back(Vector2(6, 58));
	tmpPoints.push_back(Vector2(1, 54));

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
	rsp.texture = "/textures/can.png";
	rsp.textureWidth = width;
	rsp.textureHeight = height;
	sprites.push_back(rsp);

}

Can::~Can()
{
}
