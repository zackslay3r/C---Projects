#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Object.h"
#include "Player.h"
#include "Circle.h"
#include "Walls.h"

/*
* class Application2D : public aie::Application
*
* This class is the Application2D object.
* it is responsible for the startup and shutdown of the game, as well as updating each frame
* and drawing each opject within the gameworld.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Application2D : public aie::Application {
public:

	/* Application2D();
	*
	* This function is the constructor.
	*
	* 
	*/
	Application2D();
	/* virtual ~Application2D();
	*
	* This function is the destructor.
	* It is meant to be overridden. 
	*
	*/
	virtual ~Application2D();
	/* virtual bool startup();
	*
	* This function is for the startup of the application.
	* It is meant to be overridden.
	*	
	*
	* @returns bool
	*/
	virtual bool startup();
	
	/* virtual void shutdown();
	*
	* This function is for the shutdown of the application.
	* It is meant to be overridden.
	*
	*
	* @returns void
	*/
	virtual void shutdown();
	/* virtual void update();
	*
	* This function is for the updating of the application based upon deltatime.
	* It is meant to be overridden.
	*
	*
	* @param float deltaTime - gametime.
	* @returns void
	*/
	virtual void update(float deltaTime);
	
	/* virtual void draw();
	*
	* This function is for the drawing the game objects in the application.
	* It is meant to be overridden.
	*
	*
	* @returns void
	*/
	virtual void draw();

protected:
	// Renderer
	aie::Renderer2D*	m_2dRenderer;
	// object texture
	aie::Texture*		m_texture;
	// Turretbase
	aie::Texture*		m_turretBase;
	aie::Texture*		m_textureLoad;
	//TankBarrel
	aie::Texture*		m_tankbarrel;

	//Walls
	aie::Texture*		m_wall;
	// Circle
	aie::Texture*		m_circle;
	//bullet
	aie::Texture*		m_bullet;




	// Player object, circle and the walls.
	Player TestBox;
	Circle myCircle;
	Wall wall1;
	Wall wall2;
	Wall wall3;
	Wall wall4;
	
};