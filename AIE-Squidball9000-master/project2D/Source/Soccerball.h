#pragma once
#include "Entity.h"

/**
* Soccerball is a predefined entity with the shape and appearance of a soccerball. 
* Soccerball is derived from the Entity class.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/
class Soccerball : public Entity
{
public: 
	
	/**
	* Default constructor.
	*/
	Soccerball();

	/**
	* Default destructor.
	*/
	virtual ~Soccerball();

	/**
	* Get Entity type.
	* @returns Entity type
	*/
	inline virtual Et getType() const { return Et::Soccerball; };

};