#pragma once
#include "Entity.h"

/**
* Computer is a predefined entity with the shape and appearance of an old computer. 
* This class is derived from the Entity class.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/
class Computer : public Entity
{
public: 
	
	/**
	* Default constructor.
	*/
	Computer();

	/**
	* Default destructor.
	*/
	virtual ~Computer();

	/**
	* Get Entity type.
	* @returns Entity type
	*/
	inline virtual Et getType() const { return Et::Computer; };

};