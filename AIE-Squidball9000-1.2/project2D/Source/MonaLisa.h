#pragma once
#include "Entity.h"

/**
* MonaLisa is a predefined entity with the shape and appearance of the Mona Lisa. 
* MonaLisa is derived from the Entity class.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/
class MonaLisa : public Entity
{
public: 
	
	/**
	* Default constructor.
	*/
	MonaLisa();

	/**
	* Default destructor.
	*/
	virtual ~MonaLisa();

	/**
	* Get Entity type.
	* @returns Entity type
	*/
	inline virtual Et getType() const { return Et::MonaLisa; };

};