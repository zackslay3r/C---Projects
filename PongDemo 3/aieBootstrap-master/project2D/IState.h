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
/*
* class IState
*
* this is the blueprint of each of the states within the game and what all states will have in my game.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/

class IState {
public:
	IState(Application2D *_app, GSM *_gsm) : app(_app), gsm(_gsm) {};
	virtual ~IState() = default;

	// These are pure virtual functions, all the other states have their own update and render functions that will take over these functions.
	virtual void update(float dt) = 0;
	virtual void render() = 0;



protected:
	
	aie::Font *m_font;
	Application2D *app;
	GSM *gsm;

};
