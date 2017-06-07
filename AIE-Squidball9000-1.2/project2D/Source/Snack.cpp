#include "Snack.h"

Snack::Snack()
{

	float width = 44.0f;
	float height = 63.0f;

    //NOTE: std::vector used here instead of my custom LinkedList because the MathsLib requires a std::vector as input.

	//These points are relative to Photoshop coords with top left corner of sprite 
    //being 0,0 and y- is the upward direction.
	std::vector<Vector2> tmpPoints1;
	tmpPoints1.push_back(Vector2(1,3));
	tmpPoints1.push_back(Vector2(43,1));
	tmpPoints1.push_back(Vector2(39,31));
	tmpPoints1.push_back(Vector2(6,31));

	std::vector<Vector2> tmpPoints2;
	tmpPoints2.push_back(Vector2(6, 31));
	tmpPoints2.push_back(Vector2(38, 31));
	tmpPoints2.push_back(Vector2(43, 62));
	tmpPoints2.push_back(Vector2(4, 62));

	//Translate points to game space coords system so centre of sprite is 0,0 
	//and y+ is the upward direction.
	for (auto &var : tmpPoints1)
	{
		var.y = -var.y;

		var.x = var.x - width / 2.0f;
		var.y = var.y + height / 2.0f;
	}
	for (auto &var : tmpPoints2)
	{
		var.y = -var.y;

		var.x = var.x - width / 2.0f;
		var.y = var.y + height / 2.0f;
	}

	colliderShapes = { Shape2(tmpPoints1), Shape2(tmpPoints2) };
	for (auto &var : colliderShapes) var.updateNormals();
	rotatable = true;
	updateAABBFromColliders();
	setMass(10.0f);

	////Display collider box for testing.
	//Entity::RenderShape rs;
	//rs.shape = Shape2(Shape2(tmpPoints1));
	//rs.colour = Colour(0.0f,1.0f,0.0f,1.0f);
	//rs.lineThickness = 1.0f;
	//rs.depth = 0.0f;
	//renderShapes.push_back(rs);
	//rs.shape = Shape2(Shape2(tmpPoints2));
	//rs.colour = Colour(0.0f, 1.0f, 0.0f, 1.0f);
	//rs.lineThickness = 1.0f;
	//rs.depth = 0.0f;
	//renderShapes.push_back(rs);
	//for (auto &var : renderShapes) var.shape.updateNormals();

	//Add sprite.
	Entity::RenderSprite rsp;
	//rsp.depth = 1.0f;
	rsp.texture = "/textures/snacks.png";
	rsp.textureWidth = width;
	rsp.textureHeight = height;
	sprites.push_back(rsp);

}

Snack::~Snack()
{
}
