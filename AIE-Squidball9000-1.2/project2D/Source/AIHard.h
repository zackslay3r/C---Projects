#pragma once
#include "AI.h"



/**
* AIHard is an AI with hard difficulty, playing the most challenging game against its opponent.
* This is an abstract class and must be used with derived classes.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class AIHard : public AI
{
public:
	/**
	* Default constructor.
	*/
	AIHard();

	/**
	* Default destructor.
	*/
	~AIHard();

	/**
	* Get player subtype.
	* @returns The player subtype as defined in enum Pst.
	*/
	virtual inline Pst subType() const { return Pst::AIHard; }

	/**
	* Perform player actions.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	virtual void update(float dt);

};