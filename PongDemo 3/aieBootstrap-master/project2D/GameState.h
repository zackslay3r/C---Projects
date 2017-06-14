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

class GameState : public IState
{
public:
	GameState(Application2D *_app, GSM *_gsm);
	~GameState();

	virtual void update(float dt);
	virtual void render();
	

private:

};

