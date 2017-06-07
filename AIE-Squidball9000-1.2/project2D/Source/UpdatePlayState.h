#pragma once
#include "State.h"
#include "Application2D.h"

class UpdatePlayState :public State
{

public:

    /**
    * Default constructor.
    */
    UpdatePlayState();

    /**
    * Default destructor.
    */
    virtual ~UpdatePlayState();

    /**
    * Get the state name.
    * @returns The state name.
    */
    inline std::string getName() { return "UpdatePlay"; };

    /**
    * Enter this state.
    * @returns void.
    */
    void enter();

    /**
    * Leave this state.
    * @returns void.
    */
    void leave();
    
    /**
    * Execute state update behaviour.
    * @returns void.
    */
    void update();

    /**
    * Execute state draw behaviour.
    * @returns void.
    */
    void draw();

};