#pragma once
#include "Entity.h"

/**
* Pizza1 is a predefined entity with the shape and appearance of a pizza slice. 
* Pizza1 is derived from the Entity class.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/
class Pizza1 : public Entity
{
public: 
	
	/**
	* Default constructor.
	*/
	Pizza1();

	/**
	* Default destructor.
	*/
	virtual ~Pizza1();

	/**
	* Get Entity type.
	* @returns Entity type
	*/
	inline virtual Et getType() const { return Et::Pizza1; };

};