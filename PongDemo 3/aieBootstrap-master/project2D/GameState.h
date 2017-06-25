#pragma once
#include "IState.h"

#include <Font.h>
#include <memory>
#include "Object.h"
#include <Input.h>
namespace aie {

	class Font;
	class Renderer2D;
}

/*
* class GameState
*
* this is GameState and is the fourth state of my game. this is based on the IState.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class GameState : public IState
{
public:
	GameState(Application2D *_app, GSM *_gsm);
	~GameState();


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
	
};

