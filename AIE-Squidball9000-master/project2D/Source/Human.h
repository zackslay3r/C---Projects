#pragma once
#include "Player.h"
#include <Input.h>



/**
* Human is a huamn controlled Player, accepting input from keyboard to direct its movement.
* This is an abstract class and must be used with derived classes.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class Human : public Player
{
public:

	/**
	* Default constructor.
	*/
	Human();

	/**
	* Default destructor.
	*/
	virtual ~Human();

	/**
	* Key input class.
	*/
	aie::Input *input;

	/**
	* Up key code.
	*/
	aie::EInputCodes upKey;

	/**
	* Down key code.
	*/
	aie::EInputCodes downKey;

	/**
	* Get player type.
	* @returns The player type as defined in enum Pt.
	*/
	virtual inline Pt type() const { return Pt::Human; }

	/**
	* Get player subtype.
	* Pure virtual function.
	* @returns The player subtype as defined in enum Pst.
	*/
	virtual Pst subType() const = 0;

	/**
	* Perform player actions.
	* @params dt Delta time since last frame.
	* @returns void.
	*/
	virtual void update(float dt);
};