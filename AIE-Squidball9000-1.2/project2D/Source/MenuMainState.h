#pragma once
#include "State.h"

class MenuMainState :public State
{

public:

    /**
    * Default constructor.
    */
    MenuMainState();

    /**
    * Default destructor.
    */
    ~MenuMainState();

    /**
    * Get the state name.
    * @returns The state name.
    */
    inline std::string getName() { return "MenuMain"; };

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