#pragma once
#include <Mersenne.h>
#include <MathsLib.h>
#include "Application.h"
#include "Renderer2D.h"
#include "Input.h"
#include "Audio.h"
#include "CollisionDetector.h"
#include "GameClock.h"
#include "HumanLeft.h"
#include "HumanRight.h"
#include "AISimple.h"
#include "AIMedium.h"
#include "AIHard.h"

/**
* This is a modified version of the Application2D class provided with Bootstrap.
* It provides the core program flow and functionality of the application.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017.
*/

class Application2D : public aie::Application {
public:

	/**
	* Default constructor.
	*/
	Application2D();

	/**
	* Default destructor.
	*/
	virtual ~Application2D();

	/**
	* Startup process.
	* @returns void.
	*/
	virtual bool startup();

	/**
	* Shutdown process.
	* @returns void.
	*/
	virtual void shutdown();

	/**
	* Update process. Performs physics and object updates.
	* @params deltaTime Time passed since last frame.
	* @returns void.
	*/
	virtual void update(float deltaTime);

	/**
	* Draw objects.
	* @returns void.
	*/
	virtual void draw();

    /**
    * Scene renderer.
    */
    aie::Renderer2D* m_2dRenderer;

protected:

	/**
	* Camera position.
	*/
	float m_cameraX, m_cameraY;

};