#pragma once

/** This Gamestate is an abstract class interface that describes how
other class objects will interact with it - Cannot be instantiated, must
have a child class inherit from it to use*/
class Application2D;

namespace aie {
	class Renderer2D;
	class Font;
}

class IState {
public:
	IState(Application2D *_app) : app(_app) {};
	virtual ~IState() = default;

	/** only virtual functions can '= 0'. What this does is it describes this
	function as "Pure Virtual", meaning: This class will not have the definition.
	Definition will be provided by children of this class*/
	virtual void update(float dt) = 0;
	virtual void render(aie::Renderer2D*	m_2dRenderer) = 0;

	// I want the states to act as 'mini applications', so they will have their own render and update
	// Bear in mind that this is for the GAME. AI state managers may not have an update or render function, for example
	// How states behave is entirely context sensitive

protected:
	aie::Renderer2D *m_renderer;
	aie::Font *m_font;
	Application2D *app;

};
