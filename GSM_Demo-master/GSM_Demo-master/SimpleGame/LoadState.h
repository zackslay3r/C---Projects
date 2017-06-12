#pragma once
#include "IGameState.h"

class LoadState :
	public IGameState {
public:
	LoadState(SimpleGameApp * _app);
	virtual ~LoadState();

	// Since we inherit from the GameState interface, we must override the functions
	virtual void update(float dt);
	virtual void render();

private:
	char *loadText;
	const float delayTime = 0.3;
	float switchStateTimer;
	void updateLoadText(float dt);
	void updateStateTimer(float dt);
};

