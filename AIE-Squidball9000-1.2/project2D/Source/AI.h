#pragma once
#include "Player.h"



/**
* AI is a computer controlled player.
* This is an abstract class and must be used with derived classes.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class AI : public Player
{
public:

	/**
	* Default constructor.
	*/
	AI();

	/**
	* Default destructor.
	*/
	virtual ~AI();

	/**
	* Get player type.
	* @returns The player type as defined in enum Pt.
	*/
	virtual inline Pt type() const { return Pt::AI; }

	/**
	* Get player subtype.
	* Pure virtual function.
	* @returns The player subtype as defined in enum Pst.
	*/
	virtual Pst subType() const = 0;

	/**
	* Perform player actions.
	* Pure virtual function.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	virtual void update(float dt) = 0;
};