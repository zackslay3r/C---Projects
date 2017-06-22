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

	virtual void update(float dt);
	virtual void render();
	

private:
	std::unique_ptr<aie::Font> m_font;
	float switchStateTimer;
	void updateStateTimer(float dt);
	int WhatsSelected, maxMenuOption;

	aie::Input *input;

};
