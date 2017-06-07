#pragma once


#include <Application.h>
#include <Renderer2D.h>
#include <memory>



class aie::Font;
class IGameState;
class GameStateManager;

class Application2D : public aie::Application {
public:

	//Constructor
	Application2D();


	// Destructor
	virtual ~Application2D();

	//Startup
	virtual bool startup();
	
	//Shutdown
	virtual void shutdown();

	// Update via deltatime
	virtual void update(float deltaTime);
	
	//draws the objects.
	virtual void draw();


	//Scene renderer.
	aie::Renderer2D m_renderer;

protected:

	// Camera position
	float m_cameraX, m_cameraY;

};