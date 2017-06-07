#pragma once
#include "Human.h"



/**
* HumanRight is the right side keyboard Player, accepting input from keyboard to direct its movement.
* This is an abstract class and must be used with derived classes.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class HumanRight : public Human
{
public:
	/**
	* Default constructor.
	*/
	HumanRight();

	/**
	* Default destructor.
	*/
	~HumanRight();

	/**
	* Get player subtype.
	* @returns The player subtype as defined in enum Pst.
	*/
	virtual inline Pst subType() const { return Pst::HumanRight; }

};