#pragma once
#include <MathsLib.h>
#include <Mersenne.h>
#include "Font.h"
#include "AssetManager.h"
#include "Player.h"
#include "Actor.h"
#include "aieException.h"
#include "Renderer2D.h"



#define SCOR ScoreKeeper::getInstance()

/**
* A class that manages the game rules including: resetting the ball after goals
* or when the ball has gone out of bounds, deciding when goals are scored or 
* matches won and spawning junk on the game field at the start of rounds. 
* It also displays the score, ball countdown and win/goal messages.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class ScoreKeeper
{

public:

	/**
    * Create or get static instance.
    * @returns A pointer to the single ScoreKeeper object.
    */
	static class ScoreKeeper *getInstance();

	/**
	* Position in middle of game field to start ball.
	*/
	Vector2 ballStartPosition;

	/**
	* Minimum X extent, considered out of bounds for left player.
	*/
	float minXExtent;

	/**
	* Maximum X extent, considered out of bounds for right player.
	*/
	float maxXExtent;

	/**
	* Minimum Y extent, considered out of bounds with no player scoring.
	*/
	float minYExtent;

	/**
	* Maximum Y extent, considered out of bounds with no player scoring.
	*/
	float maxYExtent;

	/**
	* Player left score.
	*/
	int scoreLeft;

	/**
	* Player right score.
	*/
	int scoreRight;

	/**
	* The winning score for a match.
	*/
	int winScore;

	/**
	* Update actions for ScoreKeeper.
	* @params dt Time since last frame.
	* @returns void.
	*/
	void update(float dt);

	/**
	* Draw the scores.
	* @param renderer A pointer to the Renderer2D object for this scene.
	* @returns void.
	*/
	void draw(aie::Renderer2D* renderer) const;

	/**
	* Reset ball to start position.
	* @returns void.
	*/
	void resetBall() const;

	/**
	* Reset scores.
	* @returns void.
	*/
	void resetScores();

	/**
	* Reset actor for player.
	* @params player Pointer to the player to reset the actor for.
	* @returns void.
	*/
	void resetActor(Player *player) const;

	/**
	* Start goal process.
	* @returns void.
	*/
	void goalProcessStart();

	/**
	* End goal process.
	* @returns void.
	*/
	void goalProcessEnd();

	/**
	* Start win process.
	* @returns void.
	*/
	void winProcessStart();

	/**
	* End win process.
	* @returns void.
	*/
	void winProcessEnd();

	/**
	* Start ball countdown timer.
	* @returns void.
	*/
	void ballCountdown();

	/**
	* Spawn junk on the game field. Some of it may be "sticky", which can attach itself to the ball on contact.
	* @returns void.
	*/
	void spawnJunk() const;

	/**
	* Clean junk outside game field.
	* @returns void.
	*/
	void cleanOutsideJunk() const;

	/**
	* Clean up all junk.
	* @returns void.
	*/
	void cleanAllJunk() const;

	/**
	* Reset state for a new match.
	* @returns void.
	*/
	void resetState();

private:

	/**
	* Default constructor.
    * Private to prevent class being created on the stack.
    */
	ScoreKeeper();

	/**
	* Default destructor.
	* Private to prevent class being created on the stack.
	*/
	~ScoreKeeper();

	/**
	* Mersenne Twister random number generator.
	*/
	Mersenne mt;

	/**
	* Show the goal message.
	*/
	bool goalMessage;

	/**
	* Show the winner message.
	*/
	bool winnerMessage;

	/**
	* Goal process time end.
	*/
	float goalTimeEnd;

	/**
	* Win process time end.
	*/
	float winTimeEnd;

	/**
	* Ball countdown.
	*/
	float ballCountdownEnd;

	/**
	* Which side scored the last goal?
	* True means left, false means right.
	*/
	bool goalSide;
};