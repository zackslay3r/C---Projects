#pragma once
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

class PauseState : public IState
{
public:
	PauseState(Application2D *_app, GSM *_gsm);
	~PauseState();

	virtual void update(float dt);
	virtual void render();


private:
	std::unique_ptr<aie::Font> m_font;
	
	Object* paddleLeft;
	Object* paddleRight;
	Object* Ball;
	aie::Input *input;
};