
#pragma once
#include "IState.h"
/*
* class LoadState
*
* this is LoadState and is the third state of my game. this is based on the IState.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class LoadState :
	public IState {
public:
	LoadState(Application2D *_app, GSM *_gsm);
	virtual ~LoadState();

	
	virtual void update(float dt);
	virtual void render();

private:
	char *loadText;
	char *playerControls;
	const float delayTime = 0.3f;
	float switchStateTimer;
	void updateLoadText(float dt);
	void updateStateTimer(float dt);
	aie::Font *m_instructFont;
};