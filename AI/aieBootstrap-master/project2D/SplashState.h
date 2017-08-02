
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
class SplashState : public IState {
public:
	SplashState(Application2D *_app, GSM *_gsm);
	
	/*	virtual ~SplashState();
	*	This function is a virtual destructor that should exist so that the state has a destructor.
	*
	*
	*/
	virtual ~SplashState();

	/*	virtual void update(float dt);
	*	This function is a virtual function that is responsible for updating this state every frame.
	*
	*	parameter 1 dt - Delta Time.
	*	@returns void
	*/
	virtual void update(float dt);
	
	
	/*	virtual void render();
	*	This function is a virtual function that is responsible for drawing the items in this state every frame based on the update function.
	*
	*	@returns void
	*/
	virtual void render();

private:
	char *SplashText;
	const float delayTime = 0.3f;
	float switchStateTimer;
	void updateStateTimer(float dt);
	aie::Input *input;
};