#include "Computer.h"

Computer::Computer()
{

	float width = 100.0f;
	float height = 87.0f;

	//These points are relative to Photoshop coords with top left corner of sprite 
	//being 0,0 and y- is the upward direction.

    //NOTE: std::vector used here instead of my custom LinkedList because the MathsLib requires a std::vector as input.

	//Monitor.
	std::vector<Vector2> tmpPoints1;
	tmpPoints1.push_back(Vector2(5, 43)); 
	tmpPoints1.push_back(Vector2(8, 11));
	tmpPoints1.push_back(Vector2(23, 1));
	tmpPoints1.push_back(Vector2(26, 1));
	tmpPoints1.push_back(Vector2(66, 4));
	tmpPoints1.push_back(Vector2(71, 42));
	tmpPoints1.push_back(Vector2(24, 45));

	//Base seg 1.
	std::vector<Vector2> tmpPoints2;
	tmpPoints2.push_back(Vector2(2,47));
	tmpPoints2.push_back(Vector2(6,46));
	tmpPoints2.push_back(Vector2(24,49));
	tmpPoints2.push_back(Vector2(2,59));
	
	//Base seg 2.
	std::vector<Vector2> tmpPoints3;
	tmpPoints3.push_back(Vector2(2,59));
	tmpPoints3.push_back(Vector2(24,49));
	tmpPoints3.push_back(Vector2(40,85));
	tmpPoints3.push_back(Vector2(3,64));

	//Base seg 3.
	std::vector<Vector2> tmpPoints4;
	tmpPoints4.push_back(Vector2(40, 85));
	tmpPoints4.push_back(Vector2(40, 80));
	tmpPoints4.push_back(Vector2(42, 85));

	//Base seg 4.
	std::vector<Vector2> tmpPoints5;
	tmpPoints5.push_back(Vector2(42, 85));
	tmpPoints5.push_back(Vector2(40, 80));
	tmpPoints5.push_back(Vector2(95, 65));
	tmpPoints5.push_back(Vector2(94, 69));

	//Base seg 5.
	std::vector<Vector2> tmpPoints6;
	tmpPoints6.push_back(Vector2(95, 65));
	tmpPoints6.push_back(Vector2(97, 61));
	tmpPoints6.push_back(Vector2(99, 64));

	//Base seg 6.
	std::vector<Vector2> tmpPoints7;
	tmpPoints7.push_back(Vector2(40, 80));
	tmpPoints7.push_back(Vector2(24, 49));
	tmpPoints7.push_back(Vector2(64, 44));
	tmpPoints7.push_back(Vector2(74, 49));
	tmpPoints7.push_back(Vector2(97, 61));
	tmpPoints7.push_back(Vector2(95, 65));

	//Base seg 7.
	std::vector<Vector2> tmpPoints8;
	tmpPoints8.push_back(Vector2(64, 44));
	tmpPoints8.push_back(Vector2(72, 44));
	tmpPoints8.push_back(Vector2(74, 49));


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
	for (auto &var : tmpPoints3)
	{
		var.y = -var.y;

		var.x = var.x - width / 2.0f;
		var.y = var.y + height / 2.0f;
	}
	for (auto &var : tmpPoints4)
	{
		var.y = -var.y;

		var.x = var.x - width / 2.0f;
		var.y = var.y + height / 2.0f;
	}
	for (auto &var : tmpPoints5)
	{
		var.y = -var.y;

		var.x = var.x - width / 2.0f;
		var.y = var.y + height / 2.0f;
	}
	for (auto &var : tmpPoints6)
	{
		var.y = -var.y;

		var.x = var.x - width / 2.0f;
		var.y = var.y + height / 2.0f;
	}
	for (auto &var : tmpPoints7)
	{
		var.y = -var.y;

		var.x = var.x - width / 2.0f;
		var.y = var.y + height / 2.0f;
	}
	for (auto &var : tmpPoints8)
	{
		var.y = -var.y;

		var.x = var.x - width / 2.0f;
		var.y = var.y + height / 2.0f;
	}

	colliderShapes = { Shape2(tmpPoints1), Shape2(tmpPoints2), Shape2(tmpPoints3), 
		Shape2(tmpPoints4), Shape2(tmpPoints5), Shape2(tmpPoints6), Shape2(tmpPoints7),
		Shape2(tmpPoints8) };
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
	//rs.shape = Shape2(tmpPoints3);
	//rs.colour = Colour(0.0f, 1.0f, 0.0f, 1.0f);
	//rs.lineThickness = 1.0f;
	//rs.depth = 0.0f;
	//renderShapes.push_back(rs);
	//rs.shape = Shape2(tmpPoints4);
	//rs.colour = Colour(0.0f, 1.0f, 0.0f, 1.0f);
	//rs.lineThickness = 1.0f;
	//rs.depth = 0.0f;
	//renderShapes.push_back(rs);
	//rs.shape = Shape2(tmpPoints5);
	//rs.colour = Colour(0.0f, 1.0f, 0.0f, 1.0f);
	//rs.lineThickness = 1.0f;
	//rs.depth = 0.0f;
	//renderShapes.push_back(rs);
	//rs.shape = Shape2(tmpPoints6);
	//rs.colour = Colour(0.0f, 1.0f, 0.0f, 1.0f);
	//rs.lineThickness = 1.0f;
	//rs.depth = 0.0f;
	//renderShapes.push_back(rs);
	//rs.shape = Shape2(tmpPoints7);
	//rs.colour = Colour(0.0f, 1.0f, 0.0f, 1.0f);
	//rs.lineThickness = 1.0f;
	//rs.depth = 0.0f;
	//renderShapes.push_back(rs);
	//rs.shape = Shape2(tmpPoints8);
	//rs.colour = Colour(0.0f, 1.0f, 0.0f, 1.0f);
	//rs.lineThickness = 1.0f;
	//rs.depth = 0.0f;
	//renderShapes.push_back(rs);
	//for (auto &var : renderShapes) var.shape.updateNormals();

	//Add sprite.
	Entity::RenderSprite rsp;
	//rsp.depth = 1.0f;
	rsp.texture = "/textures/computer.png";
	rsp.textureWidth = width;
	rsp.textureHeight = height;
	sprites.push_back(rsp);

}

Computer::~Computer()
{
}
