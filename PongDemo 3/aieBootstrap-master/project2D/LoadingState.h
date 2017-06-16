
#pragma once
#include "IState.h"

class LoadState :
	public IState {
public:
	LoadState(Application2D *_app, GSM *_gsm);
	virtual ~LoadState();

	// Since we inherit from the GameState interface, we must override the functions
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