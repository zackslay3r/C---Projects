#pragma once
#include "Entity.h"

/**
* Cleaver is a predefined entity with the shape and appearance of a meat cleaver. 
* Cleaver is derived from the Entity class.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/
class Cleaver : public Entity
{
public: 
	
	/**
	* Default constructor.
	*/
	Cleaver();

	/**
	* Default destructor.
	*/
	virtual ~Cleaver();

	/**
	* Get Entity type.
	* @returns Entity type
	*/
	inline virtual Et getType() const { return Et::Cleaver; };

};