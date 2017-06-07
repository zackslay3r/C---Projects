#pragma once
#include "AI.h"



/**
* AISimple is an AI with simple difficulty, playing a barely challenging game
* against its opponent. It has built in hesitation to simulate an imperfect human player.
* This is an abstract class and must be used with derived classes.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class AISimple : public AI
{
public:
	/**
	* Default constructor.
	*/
	AISimple();

	/**
	* Default destructor.
	*/
	~AISimple();

	/**
	* Get player subtype.
	* @returns The player subtype as defined in enum Pst.
	*/
	virtual inline Pst subType() const { return Pst::AISimple; }

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