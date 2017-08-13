#pragma once
#include "../bootstrap/Application.h"
#include "../bootstrap/Renderer2D.h"
#include "Vector2.h"
#include "IBehavior.h"
#include <list>

// Forward declaration of a class.
class IBehavior;
/*
* class Object
*
* This is an Object class.
* This is the parent class for every object in my game and all objects have the values within Object.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Object
{
public:
	// This is an AgentType, which will be used for each Agent.
	enum AgentType {PLAYER, BEHAVIOURUSINGENEMY, STATEUSINGENEMY, FLOCKCUBE};
	AgentType type;
	/*
	* Object();
	*
	* This is the Object constructor.
	*
	*/
	Object();
	// These two values are to determine position.
	Vector2 position;
	// These two values are to determine movement along the x and y axis of the screen.
	Vector2 velocity;
	// These values help determine the size of a particular object based on widith and height.
	Vector2 scale;


	/*	 void render();
	*	This function is a virtual function that is responsible for drawing the objects. 
	*
	*	@returns void
	*/
	virtual void render() = 0;
	
	/*	 void update(float DT);
	*	This function is a virtual function that is responsible for updating the objects.
	*
	*	@returns void
	*/
	virtual void update(float DT) = 0;
	// This is the object destructor.
	~Object();

protected:
	// This is a list of IBehaviours.
	std::list<IBehavior*> m_behaviours;

};

