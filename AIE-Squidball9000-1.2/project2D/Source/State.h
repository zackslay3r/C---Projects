#pragma once

#include <string>

/**
* A game state. This is an abstract root class and must be used with derived classes.
* @author Ashley Flynn - AIE - 2017.
*/

class State
{

public:

    /**
    * Default constructor.
    */
    State();

    /**
    * Default destructor.
    */
    virtual ~State();

    /**
    * Get the state name.
    * Pure virtual function.
    * @returns The state name.
    */
    virtual std::string getName() = 0;

    /**
    * Enter this state.
    * Pure virtual function.
    * @returns void.
    */
    virtual void enter() = 0;

    /**
    * Leave this state.
    * Pure virtual function.
    * @returns void.
    */
    virtual void leave() = 0;

    /**
    * Execute state update behaviour.
    * Pure virtual function.
    * @returns void.
    */
    virtual void update() = 0;

    /**
    * Execute state draw behaviour.
    * Pure virtual function.
    * @returns void.
    */
    virtual void draw() = 0;

};