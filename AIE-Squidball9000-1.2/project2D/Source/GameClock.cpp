#include "GameClock.h"



GameClock::GameClock()
{

	//Initialise high performance timer.
	//Idea borrowed from an example by Jeff Cotter AIE 2017.
	LARGE_INTEGER ticksPerSec;
	highPerformance = QueryPerformanceFrequency(&ticksPerSec) == TRUE;
	frequency = 1.0 / (highPerformance ? ticksPerSec.QuadPart : 1000);

	secondsElapsedSinceExecution = 0;

	lastTime = highPerformanceClock();
}

GameClock::~GameClock()
{
}

GameClock *GameClock::getInstance()
{
	static GameClock gameClock;

	return &gameClock;
}

LONGLONG GameClock::highPerformanceClock() const
{
	//Idea borrowed from an example by Jeff Cotter AIE 2017.
	if (highPerformance)
	{
		LARGE_INTEGER hp;
		QueryPerformanceCounter(&hp);
		return hp.QuadPart;
	}
	else
	{
		return GetTickCount();
	}
}

void GameClock::incrementTime()
{

	//Current time in TICKS.
	LONGLONG currentTime = highPerformanceClock();

	//Time elapsed since last frame, in TICKS.
	LONGLONG ticksElapsedThisFrame = currentTime - lastTime;

	double secondsElapsedThisFrame = ticksElapsedThisFrame * frequency;

	//Limit to minimum frame rate time in SECONDS having passed per frame.
	//This avoids pauses from the OS and CPU from allowing a single frame to occur
	//too long after the last, which messes up timing calculations. So we'll get 
	//lag (like slow motion) but not sudden skips in time.
	if (secondsElapsedThisFrame >= 1.0 / FRAME_RATE_MIN)
	{
		secondsElapsedThisFrame = 1.0 / FRAME_RATE_MIN;
	}

	//Increment timer in SECONDS.
	secondsElapsedSinceExecution += secondsElapsedThisFrame;
	lastTime = currentTime;
}

double GameClock::ticksToSeconds(LONGLONG ticks) const
{
	return frequency * ticks;
}

double GameClock::getTimeSeconds() const
{
	return secondsElapsedSinceExecution;
}

LONGLONG GameClock::getTimeActualTicks() const
{
	return highPerformanceClock();
}

double GameClock::getTimeActualSeconds() const
{
	return highPerformanceClock() * frequency;
}
