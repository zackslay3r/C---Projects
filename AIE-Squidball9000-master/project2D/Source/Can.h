#pragma once
#include "Entity.h"

/**
* Can is a predefined entity with the shape and appearance of tinned squid. 
* This class is derived from the Entity class.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/
class Can : public Entity
{
public: 
	
	/**
	* Default constructor.
	*/
	Can();

	/**
	* Default destructor.
	*/
	virtual ~Can();

	/**
	* Get Entity type.
	* @returns Entity type
	*/
	inline virtual Et getType() const { return Et::Can; };

};