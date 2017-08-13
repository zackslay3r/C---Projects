#pragma once

/** This state is an abstract class interface that describes how
other class objects will interact with it - Cannot be instantiated, must
have a child class inherit from it to use*/
//class PlayLoop;
class enemyStateUser;
class gameFSM;

namespace aie {
	class Renderer2D;
	class Font;
}
/*
* class IGameState
*
* this is the blueprint of each of the states within the game and what all states will have in my game.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/

class IGameState {
public:
	IGameState(enemyStateUser*_enemyStateUser, gameFSM *_gsm) : enemy(_enemyStateUser), gamefsm(_gsm) {};

	/* virtual ~IGameState() = default;
	* This is the virtual destructor for every state.
	* This is called when the main program has reached the end of its scope and this will be called on every state.
	*/

	virtual ~IGameState() = default;

	// These are pure virtual functions, all the other states have their own update and render functions that will take over these functions.
	
	/*	virtual void update(float dt) = 0;
	*	This function is a pure virtual function that every state should have. This is the update function, which will update every frame.
	*
	*	parameter 1 dt - Delta Time.
	*	@returns void.
	*/

	virtual void update(float dt) = 0;

	enemyStateUser* enemyStateMyself;



protected:
	
	aie::Font *m_font;
	enemyStateUser *enemy;
	gameFSM *gamefsm;

};
