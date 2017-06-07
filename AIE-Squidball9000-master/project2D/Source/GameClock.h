#pragma once
#include <ctime>
#define NOMINMAX
#include <Windows.h>



#define GCLK GameClock::getInstance()

/**
* A class that manages game time. Minimum and maximum frame times are defined
* to ensure a consistent video framerate and physics simulation.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class GameClock
{

public:

	/**
	* Target framerate in n frames per second.
	* A max frame rate is defined to ensure the consistent appearance of animation 
	* and movement, and to limit impact of this game on CPU time. A min frame rate 
	* ensures physics calculations are run at a suitable minimum frequency, so the 
	* game will appear to run in slow motion but won't jump and stutter if there 
	* are pauses or lag in processing.
	*/
	const double FRAME_RATE_MAX = 60.0;
	const double FRAME_RATE_MIN = 30.0;

	/**
    * Create or get static instance.
    * @returns A pointer to the single GameClock object.
    */
	static class GameClock *getInstance();

    /**
	* Get elapsed game execution time.
    * @returns Elapsed time in SECONDS.
    */
	double getTimeSeconds() const;

	/**
	* Get actual elapsed ticks since start of game execution from CPU timer.
	* @returns Elapsed time in TICKS.
	*/
	LONGLONG getTimeActualTicks() const;

	/**
	* Get actual elapsed seconds since start of game execution from CPU timer.
	* @returns Elapsed time in SECONDS.
	*/
	double getTimeActualSeconds() const;

    /**
	* Add time to the game time counter, incremeted at a rate between min and max frame rate.
	* This means the elapsed game time will never "jump" if execution is paused.
	* @returns void.
    */
	void incrementTime();

	/**
	* Convert a time in TICKS to SECONDS.
	* @param ticks Number of ticks.
	* @returns Number of seconds.
	*/
	double ticksToSeconds(LONGLONG ticks) const;

private:

	/**
	* Default constructor.
    * Private to prevent class being created on the stack.
    */
	GameClock();

	/**
	* Default destructor.
	* Private to prevent class being created on the stack.
	*/
	~GameClock();

    /**
	* Elapsed game time in SECONDS since execution, incremeted at a rate between min and max frame rate.
	* This means the elapsed game time will never "jump" if execution is paused.
    */
	double secondsElapsedSinceExecution;

	/**
	* Last TICK count since game execution.
	*/
	LONGLONG lastTime;

	/**
	* Is the high perfomance timer available?
	*/
	bool highPerformance;

	/**
	* Clock tick frequency for tick to seconds conversion.
	*/
	double frequency;

	/**
	* Query the high performance clock for the number of TICKS since game execution.
	* @returns The number of TICKS since game execution.
	*/
	LONGLONG highPerformanceClock() const;
};