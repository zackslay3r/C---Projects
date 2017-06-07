#include "Cleaver.h"

Cleaver::Cleaver()
{

	float width = 123.0f;
	float height = 42.0f;

	//These points are relative to Photoshop coords with top left corner of sprite 
	//being 0,0 and y- is the upward direction.
	
    //NOTE: std::vector used here instead of my custom LinkedList because the MathsLib requires a std::vector as input.

	//Blade.
	std::vector<Vector2> tmpPoints1;
	tmpPoints1.push_back(Vector2(2,33));
	tmpPoints1.push_back(Vector2(8,1));
	tmpPoints1.push_back(Vector2(16,2));
	tmpPoints1.push_back(Vector2(37,6));
	tmpPoints1.push_back(Vector2(70,7));
	tmpPoints1.push_back(Vector2(69,19));
	tmpPoints1.push_back(Vector2(70,39));
	tmpPoints1.push_back(Vector2(38,39));
	tmpPoints1.push_back(Vector2(20,37));

	//Handle.
	std::vector<Vector2> tmpPoints2;
	tmpPoints2.push_back(Vector2(70, 7));
	tmpPoints2.push_back(Vector2(119, 6));
	tmpPoints2.push_back(Vector2(121, 16));
	tmpPoints2.push_back(Vector2(71, 17));

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
	//rs.shape = Shape2(tmpPoints1);
	//rs.colour = Colour(0.0f,1.0f,0.0f,1.0f);
	//rs.lineThickness = 1.0f;
	//rs.depth = 0.0f;
	//renderShapes.push_back(rs);
	//rs.shape = Shape2(tmpPoints2);
	//rs.colour = Colour(0.0f, 1.0f, 0.0f, 1.0f);
	//rs.lineThickness = 1.0f;
	//rs.depth = 0.0f;
	//renderShapes.push_back(rs);
	//for (auto &var : renderShapes) var.shape.updateNormals();

	//Add sprite.
	Entity::RenderSprite rsp;
	//rsp.depth = 1.0f;
	rsp.texture = "/textures/cleaver.png";
	rsp.textureWidth = width;
	rsp.textureHeight = height;
	sprites.push_back(rsp);

}

Cleaver::~Cleaver()
{
}
