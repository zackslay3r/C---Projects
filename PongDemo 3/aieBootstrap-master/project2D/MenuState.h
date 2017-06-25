#pragma once
#include "IState.h"

#include <Font.h>
#include <memory>
#include <Input.h>
namespace aie {

	class Font;
	class Renderer2D;
}
/*
* class MenuState
*
* this is MenuState and is the second state of my game. this is based on the IState.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class MenuState : public IState
{
public:
	MenuState::MenuState(Application2D *_app, GSM *_gsm);
	~MenuState();


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
	std::unique_ptr<aie::Font> m_font;
	float switchStateTimer;
	void updateStateTimer(float dt);
	int WhatsSelected, maxMenuOption;

	aie::Input *input;

};
