#pragma once
#include "State.h"

class DrawPlayState :public State
{

public:

    /**
    * Default constructor.
    */
    DrawPlayState();

    /**
    * Default destructor.
    */
    ~DrawPlayState();

    /**
    * Get the state name.
    * @returns The state name.
    */
    inline std::string getName() { return "DrawPlay"; };

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