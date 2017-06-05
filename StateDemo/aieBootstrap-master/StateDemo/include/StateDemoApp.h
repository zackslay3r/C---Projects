#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <memory>

class GameStateManager;

class StateDemoApp : public aie::Application {
public:

	StateDemoApp();
	virtual ~StateDemoApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();


	GameStateManager* getGameStateManager() { return m_gameStateManager.get(); }

protected:

	std::shared_ptr<aie::Renderer2D>	m_2dRenderer;
	aie::Font*			m_font;


	enum class EStateID {SPLASH, GAME, PAUSE};

	std::unique_ptr<GameStateManager> m_gameStateManager;
};