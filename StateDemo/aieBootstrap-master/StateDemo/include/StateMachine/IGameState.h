#pragma once
class StateDemoApp;


namespace aie {
	class Renderer2D;

}


class IGameState
{
public:
	IGameState(StateDemoApp *_app);
	virtual ~IGameState();

	// "= 0" means the function is pure virtual. Any child class MUST implment a defininition
	// of this function. It also means that the class IGameState cannot be instantiated.
	// as the class is a pure abstract class.
	virtual void update(float dt) = 0;
	virtual void render(aie::Renderer2D *renderer) = 0;

	StateDemoApp* getApp() { return app; }

protected:
	StateDemoApp* app;
};