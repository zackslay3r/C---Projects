#pragma once
#include "IState.h"

#include <Font.h>
#include <memory>
#include <Input.h>
namespace aie {

	class Font;
	class Renderer2D;
}

class MenuState : public IState
{
public:
	MenuState::MenuState(Application2D *_app, GSM *_gsm);
	~MenuState();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D*	m_2dRenderer);
	

private:
	std::unique_ptr<aie::Font> m_font;
	aie::Renderer2D* m_renderer;
	int WhatsSelected, maxMenuOption;
	void newGame();
	aie::Input *input;

};
