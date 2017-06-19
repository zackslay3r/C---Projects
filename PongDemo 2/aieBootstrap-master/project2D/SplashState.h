
#pragma once
#include "IState.h"
#include <Input.h>

class SplashState :
	public IState {
public:
	SplashState(Application2D *_app, GSM *_gsm);
	virtual ~SplashState();

	// Since we inherit from the GameState interface, we must override the functions
	virtual void update(float dt);
	virtual void render();

private:
	char *SplashText;
	const float delayTime = 0.3f;
	float switchStateTimer;
	void updateStateTimer(float dt);
	aie::Input *input;
};