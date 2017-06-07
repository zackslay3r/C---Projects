#define NOMINMAX
#include <Windows.h>
#include <string>
#include <LinkedList.h>
#include <LinkedListIterator.h>
#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Factory.h"
#include "PhysicsCalculator.h"
#include "AssetManager.h"
#include "ScoreKeeper.h"
#include "Menu.h"
#include "Settings.h"
#include "GameStateManager.h"
#include "GameCore.h"

//HACK TESTING
#include "SoundManager.h"

Application2D::Application2D() 
{

}

Application2D::~Application2D() 
{

}

bool Application2D::startup() {

	//Vsync locks the draw and physics update timesteps to monitor refresh rate.
	//This can help prevent visual issues such as screen tearing.
	setVSync(true);

	//Hide the mouse if we're in fullscreen mode.
	setShowCursor(!SETT->fullscreen);

	////////////////
	//Camera and renderer.
	////////////////

	m_2dRenderer = new aie::Renderer2D();

	m_cameraX = 0;
	m_cameraY = 0;

	//Set the camera position before we begin rendering.
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	//Register this application with the game core object.
	GC->app = this;

	//Initialise game core.
	GC->initialise();

	return true;
}

void Application2D::shutdown() {

	delete m_2dRenderer;

}

void Application2D::update(float deltaTime) {

    //Wipe the screen to the background colour.
	clearScreen();

    //Begin drawing.
    m_2dRenderer->begin();

    //Quit if no states to execute.
    if (!GSM->count()) quit();

	//Execute states.
	GSM->update();

	////HACK TEST
	//GSM->removeState("MenuMain");
	//GSM->removeState("DrawPlay");
	//GSM->removeState("UpdatePlay");
	//GSM->activateState("MenuMain");
	//GSM->activateState("DrawPlay");
	//GSM->activateState("UpdatePlay");

	GSM->draw();
	
    //Finish drawing.
    m_2dRenderer->end();

}

void Application2D::draw() {
	

}