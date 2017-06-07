#pragma once
#include "Application2D.h"

#define GC GameCore::getInstance()



class GameCore
{
public:

    /**
    * Pointer to the application object.
    */
    Application2D *app;

    /**
    * Create or get static instance.
    * @returns A pointer to the single GameCore object.
    */
    static class GameCore *getInstance();

    /**
    * Game update behaviour.
    * @returns void.
    */
    void update();

    /**
    * Game draw behaviour.
    * @returns void.
    */
    void draw();

	/**
	* Initialise the game play field.
	* @returns void.
	*/
	void initialise();

private:

    /**
    * Default constructor.
    */
    GameCore();

    /**
    * Default destructor.
    */
    ~GameCore();

    /**
    * User input handler.
    */
    aie::Input* input;

    /**
    * Physics time passed.
    */
    double t;

    /**
    * Time passed since last frame.
    */
    double dt;

    /**
    * Min delta time as a fraction. Eg: 60fps = 1/60 = 0.016666.
    */
    double minDt;

    /**
    * Max delta time as a fraction. Eg: 60fps = 1/60 = 0.016666.
    */
    double maxDt;

    /**
    * Current physics time.
    */
    double currentTime;

    /**
    * Physics time accumulator.
    */
    double accumulator;

    /**
    * Max reported fps value.
    */
    int fpsMax;

};