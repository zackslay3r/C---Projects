#pragma once


#include <Application.h>
#include <Renderer2D.h>
#include <memory>



class aie::Font;
class IGameState;
class GameStateManager;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	std::unique_ptr<aie::Renderer2D> m_renderer;
	std::unique_ptr<GameStateManager> m_gameStateManager;

};