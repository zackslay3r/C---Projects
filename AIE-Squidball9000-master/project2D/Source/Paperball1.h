#pragma once
#include "Entity.h"

/**
* Paperball1 is a predefined entity with the shape and appearance of a screwed up paper ball. 
* Paperball1 is derived from the Entity class.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/
class Paperball1 : public Entity
{
public: 
	
	/**
	* Default constructor.
	*/
	Paperball1();

	/**
	* Default destructor.
	*/
	virtual ~Paperball1();

	/**
	* Get Entity type.
	* @returns Entity type
	*/
	inline virtual Et getType() const { return Et::Paperball1; };

};