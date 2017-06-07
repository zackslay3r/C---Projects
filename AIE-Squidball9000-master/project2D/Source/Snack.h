#pragma once
#include "Entity.h"

/**
* Snack is a predefined entity with the shape and appearance of a chip packet. 
* This class is derived from the Entity class.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/
class Snack : public Entity
{
public: 
	
	/**
	* Default constructor.
	*/
	Snack();

	/**
	* Default destructor.
	*/
	virtual ~Snack();

	/**
	* Get Entity type.
	* @returns Entity type
	*/
	inline virtual Et getType() const { return Et::Snack; };

};