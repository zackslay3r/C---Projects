#pragma once
#include "AI.h"



/**
* AIMedium is an AI with medium difficulty, playing a moderately challenging game 
* against its opponent. It has built in hesitation to simulate an imperfect human player.
* This is an abstract class and must be used with derived classes.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class AIMedium : public AI
{
public:
	/**
	* Default constructor.
	*/
	AIMedium();

	/**
	* Default destructor.
	*/
	~AIMedium();

	/**
	* Get player subtype.
	* @returns The player subtype as defined in enum Pst.
	*/
	virtual inline Pst subType() const { return Pst::AIMedium; }

	/**
	* Perform player actions.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	virtual void update(float dt);

private:

	/**
	* Hesitation timer.
	*/
	float hesitateTimer;

	/**
	* Hesitation chance timer.
	*/
	float hesitateChanceTimer;
};