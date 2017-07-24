#include "Player.h"
#include "Input.h"
#include <math.h>

//default constructor
Player::Player()
{

}


// The setup function.
void Player::SetUp(aie::Texture * Tanktexture, aie::Renderer2D * Renderer, aie::Texture * turretTexture, 
	aie::Texture * Barreltexture, aie::Texture * bullettexture)
{

	Object::SetUp(Tanktexture, Renderer,shape::shapeType::Square,200,200);
	myTurretBase.SetUp(turretTexture, Renderer, shape::shapeType::Square);
	myTurretBase.setParent(this);
	
	myTurret.SetUp(Barreltexture, Renderer, shape::shapeType::Square,myTurretBase.position.x, myTurretBase.position.y,1,1,0.5,0);
	myTurret.setParent(&myTurretBase);

	myBullet.SetUp(bullettexture, Renderer, shape::shapeType::Square, myTurret.position.x, myTurret.position.y);

}




// The update function.
void Player::Update(float DT, aie::Input* input)
{

	// Move forward based on rotation.
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		//This vector2 uses the standard forward moving
		Vector2 forwards = GlobalTranslate * Vector2(0.0f, -1.0f);

		forwards -= position;

		forwards = forwards * -1.10f;

		//Applys the velocity vector to move forwards in the correct way added onto the forwards vector.
		velocity += forwards * 100 * DT;

	}
	// Move backward based on rotation.
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{

		Vector2 backwards = GlobalTranslate * Vector2(0.0f, -1.0f);
		backwards -= position;
		backwards = backwards * 1.10f;

		//Applys the velocity vector to move forwards in the correct way added onto the forwards vector.
		velocity += backwards * 100 * DT;


	}
	// Move rotation to the left.
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		rotation += 5 * DT;
	}
	// Move rotation to the right.
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		rotation -= 5 * DT;
	}


	// if the tank turret is attached, rotate the tank barrel to the left.
	if (input->isKeyDown(aie::INPUT_KEY_Q))
	{
		if (TankTurretAttached == true)
		{
			myTurret.rotation += 10 * DT;
		}
	}
	// if the tank turret is attached, rotate the tank barrel to the right.
	if (input->isKeyDown(aie::INPUT_KEY_E))
	{
		if (TankTurretAttached == true)
		{
		myTurret.rotation -= 10 * DT;
		}
	}
	
	// if the tank has the turret attached, set the turretBases position equal to the tanks position and rotation
	// then detach it had have it parent set to null.
	if (input->isKeyDown(aie::INPUT_KEY_P))
	{
		if (TankTurretAttached == true)
		{
			
			myTurretBase.position = position;

			myTurretBase.rotation = rotation;
			myTurretBase.setParent(nullptr);
			TankTurretAttached = false;

		}
	}
	// if the tank has the turret detached, set the turretBases position equal to the tanks position and rotation
	// then attach it had have it parent set to the tank base.
	if (input->isKeyDown(aie::INPUT_KEY_O))
	{
		if (TankTurretAttached == false)
		{
			Vector2 basePos = GlobalTranslate * Origin;
			myTurretBase.position = { 0,0 };
			myTurretBase.rotation = 0;
			myTurretBase.setParent(this);
			TankTurretAttached = true;
		}
		





	}

	// if the space bar was pressed, sqawn a bullet.
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		myBullet.position = GlobalTranslate * myTurret.position;
		myBullet.Update(DT);

	}
	// if the tank has the turret attached, all the tank base itself to rotate to the right.
	if (input->isKeyDown(aie::INPUT_KEY_1))
	{
		if (TankTurretAttached == true)
		{
			myTurretBase.rotation += 0.001;
		}
	}
	// if the tank has the turret attached, all the tank base itself to rotate to the left.
	if (input->isKeyDown(aie::INPUT_KEY_2))
	{
		if (TankTurretAttached == true)
		{
			myTurretBase.rotation -= 0.001;
		}
	}

	
	
	// This has added friction to the tank.
	velocity = velocity * pow(0.95f, DT * 60.0f);
	// This enables the drifiting of the tank based on its friction.	
	position = position + velocity * 10 * DT;
	
	// All the update functions.
	Object::Update(DT);
	myTurret.Update(DT);
	myTurretBase.Update(DT);



 }

void Player::Draw()
{

	// draws the player objects.
	Object::Draw();
	myTurretBase.Draw();
	myTurret.Draw();
	myBullet.Draw();
}

//Destructor
Player::~Player()
{
}
