#pragma once


#include <Application.h>
#include "Renderer2D.h"
#include "Player.h"
#include "GSM.h"



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
	GSM *getGSM() { return gsm; }



protected:
	aie::Renderer2D*	m_2dRenderer;
	GSM *gsm;
	Player* m_playerLeft;

};