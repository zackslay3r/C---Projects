#pragma once
#include <memory>
#include "IGameState.h"
class GameEntity;
class Player;

namespace aie
{
	class Font;
}

class GameState : public IGameState {

public: 
	GameState(PongApp *app);
	virtual ~GameState();

	virtual void update(float dt);
	virtual void draw(aie::Renderer2D *rednerer);

protected:
	std::unique_ptr<aie::Font> m_font;
	float m_elapsedTime;

	std::unique_ptr<aie::Texture> m_tex;
	std::unique_ptr<Player>



};