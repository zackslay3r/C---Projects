#pragma once
#include "IGameState.h"
#include <memory>

namespace aie
{
	class Font;
}


class PauseState : public IGameState
{
	PauseState(PongApp *app);
	virtual ~PauseState();

	virtual void update(float dt);
	virtual void render(aie::Renderer2D *renderer);

private:
	std::unique_ptr<aie::Font> m_font;

};