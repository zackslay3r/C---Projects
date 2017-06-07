#pragma once
namespace aie {
	class Renderer2D;
}
class PongApp;

class IGameState {
public:
	IGameState(PongApp *app) : m_app(app) {}
	virtual ~IGameState() = default;

	virtual void update(float dt) = 0;
	virtual void render(aie::Renderer2D *renderer) = 0;

	PongApp *getApp() { return m_app; }

protected:
	PongApp *m_app;
};

