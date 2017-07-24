#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "Matrix2.h"
#include "Circle.h"
// Constructor
Application2D::Application2D() {

}
//Destructor
Application2D::~Application2D() {

}
// Startup
bool Application2D::startup() {

	// Get all the textures.
	m_2dRenderer = new aie::Renderer2D();
	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_textureLoad = new aie::Texture("./textures/tankRednoTurret.png");
	m_turretBase = new aie::Texture("./textures/tankRedturret.png");
	m_tankbarrel = new aie::Texture("./textures/barrelRed.png");
	m_wall = new aie::Texture("./textures/wall.jpg");
	m_bullet = new aie::Texture("./textures/bullet.png");
	m_circle = new aie::Texture("./textures/ball.png");
	
	// Setup all game objects.
	TestBox.SetUp(m_textureLoad, m_2dRenderer, m_turretBase, m_tankbarrel,m_bullet);/*, */
	wall1.SetUp(m_wall, m_2dRenderer, shape::shapeType::Square,  20,			720*0.5,	 0.3, 5 );
	wall2.SetUp(m_wall, m_2dRenderer, shape::shapeType::Square, 20,		 720-20,	 12, 0.3);
	wall3.SetUp(m_wall, m_2dRenderer, shape::shapeType::Square, 1280,		  720*0.5,		 0.3, 5);
	wall4.SetUp(m_wall, m_2dRenderer, shape::shapeType::Square, 1280*0.5,    20,		 12, 0.3);
	myCircle.SetUp(m_circle, m_2dRenderer, shape::shapeType::Circle, 400, 400);


	// return true onces startup is done.
	return true;
}
// when shutdown happens, delete all textures
void Application2D::shutdown() {

	delete m_texture;
	delete m_2dRenderer;
	delete m_textureLoad;
	delete m_tankbarrel;
	delete m_wall;
	delete m_turretBase;
	delete m_bullet;
}

// While updating each frame....
void Application2D::update(float deltaTime) {

	// get the input
	aie::Input* input = aie::Input::getInstance();
	// update each game object by deltatime and sometimes input
	TestBox.Update(deltaTime, input);
	wall1.Update(deltaTime);
	wall2.Update(deltaTime);
	wall3.Update(deltaTime);
	wall4.Update(deltaTime);
	myCircle.Update(deltaTime, input);
	

	// With each wall, test collisions with the tank and the tank turret if its attached.
	
	// Wall 1
	CollisionResults W1 = TestBox.MyShape.isCollidingExtra(wall1.MyShape);
	CollisionResults B1 = TestBox.myTurret.MyShape.isCollidingExtra(wall1.MyShape);


	if (W1.colliding)
	{
		
		TestBox.position += W1.pushOutVector * 1.01f;
		W1.pushOutVector.normalise();

		float VdN = TestBox.velocity.dot(W1.pushOutVector);

		TestBox.velocity = -2 *	VdN * W1.pushOutVector + TestBox.velocity;
	}
	if (B1.colliding && TestBox.TankTurretAttached == true)
	{
		
		TestBox.position += B1.pushOutVector * 1.01f;
		B1.pushOutVector.normalise();

		float VdN = TestBox.velocity.dot(B1.pushOutVector);

		TestBox.velocity = -2 * VdN * B1.pushOutVector + TestBox.velocity;
	}

	// Wall 2
	CollisionResults W2 = TestBox.MyShape.isCollidingExtra(wall2.MyShape);
	CollisionResults B2 = TestBox.myTurret.MyShape.isCollidingExtra(wall2.MyShape);
	if (W2.colliding)
	{

		TestBox.position += W2.pushOutVector * 1.01f;
		W2.pushOutVector.normalise();

		float VdN = TestBox.velocity.dot(W2.pushOutVector);

		TestBox.velocity = -2 * VdN * W2.pushOutVector + TestBox.velocity;
	}
	if (B2.colliding && TestBox.TankTurretAttached == true)
	{
		TestBox.position += B2.pushOutVector * 1.01f;
		B2.pushOutVector.normalise();

		float VdN = TestBox.velocity.dot(B2.pushOutVector);

		TestBox.velocity = -2 * VdN * B2.pushOutVector + TestBox.velocity;
	}

	// Wall 3
	CollisionResults W3 = TestBox.MyShape.isCollidingExtra(wall3.MyShape);
	CollisionResults B3 = TestBox.myTurret.MyShape.isCollidingExtra(wall3.MyShape);

	if (W3.colliding)
	{

		TestBox.position += W3.pushOutVector * 1.01f;
		W3.pushOutVector.normalise();

		float VdN = TestBox.velocity.dot(W3.pushOutVector);

		TestBox.velocity = -2 * VdN * W3.pushOutVector + TestBox.velocity;
	}
	if (B3.colliding && TestBox.TankTurretAttached == true)
	{
	
		TestBox.position += B3.pushOutVector * 1.01f;
		B3.pushOutVector.normalise();

		float VdN = TestBox.velocity.dot(B3.pushOutVector);

		TestBox.velocity = -2 * VdN * B3.pushOutVector + TestBox.velocity;
	}

	// Wall 4
	CollisionResults W4 = TestBox.MyShape.isCollidingExtra(wall4.MyShape);
	CollisionResults B4 = TestBox.myTurret.MyShape.isCollidingExtra(wall4.MyShape);

	if (W4.colliding)
	{

		TestBox.position += W4.pushOutVector * 1.01f;
		W4.pushOutVector.normalise();

		float VdN = TestBox.velocity.dot(W4.pushOutVector);

		TestBox.velocity = -2 * VdN * W4.pushOutVector + TestBox.velocity;
	}
	if (B4.colliding && TestBox.TankTurretAttached == true)
	{
	
		TestBox.position += B4.pushOutVector * 1.01f;
		B4.pushOutVector.normalise();

		float VdN = TestBox.velocity.dot(B4.pushOutVector);

		TestBox.velocity = -2 * VdN * B4.pushOutVector + TestBox.velocity;
	}



	// Allows the Circle to bounce between walls 2 and 4.
	CollisionResults C1 = myCircle.MyShape.isCollidingExtra(wall2.MyShape);
	{
		if (C1.colliding)
		{
			myCircle.position += C1.pushOutVector * 1.01f;
	
			myCircle.velocity = myCircle.velocity * -1;

			myCircle.bounceUp = false;
		}
	}

	CollisionResults C2 = myCircle.MyShape.isCollidingExtra(wall4.MyShape);
	{
		if (C2.colliding)
		{
			myCircle.position += C2.pushOutVector * 1.01f;
		
			myCircle.velocity = myCircle.velocity * -1;

			myCircle.bounceUp = true;
		}
	}


	// If the user presses ESC, exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
 }

 // Draw each game object.
void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	

	// begin drawing sprites
	m_2dRenderer->begin();

	
	
	

	TestBox.Draw();
	wall1.Draw();
	wall2.Draw();
	wall3.Draw();
	wall4.Draw();
	myCircle.Draw();




	// done drawing sprites
	m_2dRenderer->end();
}