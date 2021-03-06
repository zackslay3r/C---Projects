#pragma once

/** This Gamestate is an abstract class interface that describes how
other class objects will interact with it - Cannot be instantiated, must
have a child class inherit from it to use*/
class Application2D;
class GSM;
namespace aie {
	class Renderer2D;
	class Font;
}

class IState {
public:
	IState(Application2D *_app, GSM *_gsm) : app(_app), gsm(_gsm) {};
	virtual ~IState() = default;

	/** only virtual functions can '= 0'. What this does is it describes this
	function as "Pure Virtual", meaning: This class will not have the definition.
	Definition will be provided by children of this class*/
	virtual void update(float dt) = 0;
	virtual void render() = 0;

	// I want the states to act as 'mini applications', so they will have their own render and update
	// Bear in mind that this is for the GAME. AI state managers may not have an update or render function, for example
	// How states behave is entirely context sensitive

protected:
	
	aie::Font *m_font;
	Application2D *app;
	GSM *gsm;

};
