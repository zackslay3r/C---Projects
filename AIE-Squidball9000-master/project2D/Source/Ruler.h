#pragma once
#include "Entity.h"

/**
* Ruler is a predefined entity with the shape and appearance of a traditional wooden ruler. 
* This class is derived from the Entity class.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/
class Ruler : public Entity
{
public: 
	
	/**
	* Default constructor.
	*/
	Ruler();

	/**
	* Default destructor.
	*/
	virtual ~Ruler();

	/**
	* Get Entity type.
	* @returns Entity type
	*/
	inline virtual Et getType() const { return Et::Ruler; };

};