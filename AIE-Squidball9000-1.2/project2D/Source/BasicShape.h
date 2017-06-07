#pragma once
#include "Entity.h"

/**
* BasicShapes are simple shapes such as circles and polygons. 
* BasicShape is derived from the Entity class.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/
class BasicShape : public Entity
{
public: 
	
	/**
	* Default constructor.
	*/
	BasicShape();

	/**
	* Default destructor.
	*/
	virtual ~BasicShape();

	/**
	* Get Entity type.
	* @returns Entity type
	*/
	inline virtual Et getType() const { return Et::BasicShape; };

};