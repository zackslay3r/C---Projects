#pragma once

#include "Application.h"
#include "Renderer2D.h"

//include the Game state manager.
#include "GSM.h"

class SimpleGameApp : public aie::Application {
public:

	SimpleGameApp();
	virtual ~SimpleGameApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	GSM *getGSM() { return gsm; }

protected:

	// Creates a new pointer of a GSM which will allow for the use of the GSM
	GSM *gsm;
	
	
};