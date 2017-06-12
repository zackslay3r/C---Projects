#pragma once
#include "IGameState.h"

#include <Font.h>
#include <memory>
namespace aie {

	class Font;
	class Renderer2D;
}

class GameState : public IGameState
{
public:
	GameState(SimpleGameApp * _app);
	~GameState();

	virtual void update(float dt);
	virtual void render();
	

private: 
	std::unique_ptr<aie::Font> m_font;
	aie::Renderer2D* m_renderer;
};

