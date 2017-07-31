#pragma once
#include "GameState.h"
#include "Node.h"
#include "Wall.h"
#include "Player.h"
#include "Enemy.h"
class Player;
class Enemy;
#define PLAY playLoop::getInstance()
/*
* class playLoop
*
* this is playLoop and main loop of my game. it runs the update and render functions seperate from the GameState itself.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class playLoop
{
public:
	/*	static playLoop *getInstance();
	*	This function is responsible getting the instance of the playLoop.
	*
	*	@returns playloop - the playloop itself.
	*/
	static playLoop *getInstance();
	
	Application2D *app;

	/*	void update(float dt);
	*	This function is responsible for updating the main game loop for every frame.
	*
	*	parameter 1 dt - Delta Time.
	*	@returns void
	*/
	void update(float dt, GSM* gsm);
	/*	 void render();
	*	This function is a virtual function that is responsible for drawing the items for the main game loop based on the update function.
	*
	*	@returns void
	*/
	void render();
private:
	/*
	* playLoop();
	*
	* This is the playLoop constructor.
	*
	*/
	playLoop();
	/*
	* ~playLoop();
	*
	* This is the playLoop destructor.
	*
	*/
	~playLoop();
	
	std::unique_ptr<aie::Font> m_font, m_stateFont;
	
	/*
	* bool checkCollide(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2);
	*
	* This function is responsible for checking the collisions between two objects.
	*
	* @parameter 1 x1 - position of the first object on the x axis
	* @parameter 2 y1 - position of the first object on the y axis
	* @parameter 3 width1 - width of the first object
	* @parameter 4 height1 -  height of the first object
	* @parameter 5 x2 - position of the second object on the x axis
	* @parameter 6 y2 - position of the second object on the y axis
	* @parameter 7 width2 - width of the second object
	* @parameter 8 height2 - width of the second object
	*
	* returns bool - true or false.
	*
	*/
	bool checkCollide(Object* obj1, Object* obj2);
	
	int ScoreOne, ScoreTwo;
	float winnerTimer;
	char *playerWinnerText;
	
	Object* paddleLeft;
	Object* paddleRight;
	Object* Ball;
	Player* player;
	Enemy* enemy;
	Enemy* enemy2;
	std::vector<Wall*> myWalls;
	aie::Input *input;
	double timer;
	bool displayPath;

	std::list<Node*> path;
	Node* tempPtr;

	
	/*	 void updateStateTimer(float dt);
	*	This function is responsible for updating the timer in the playloop.
	*
	*	parameter 1 dt - Delta Time.
	*
	*	@returns void
	*/
	bool TimerTick(float dt);
};