
#pragma once
#include "IState.h"
#include <Input.h>


/*
* class SplashState
*
* this is SplashState and is the first state of my game. this is based on the IState.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class SplashState :
	public IState {
public:
	SplashState(Application2D *_app, GSM *_gsm);
	virtual ~SplashState();

	
	virtual void update(float dt);
	virtual void render();

private:
	char *SplashText;
	const float delayTime = 0.3f;
	float switchStateTimer;
	void updateStateTimer(float dt);
	aie::Input *input;
};