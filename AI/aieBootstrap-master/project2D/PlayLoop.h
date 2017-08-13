#pragma once
#include "GameState.h"
#include "Node.h"
#include "Wall.h"
#include "Player.h"
#include "NodeManager.h"
#include "Enemy.h"
#include "blackBoard.h"
#include "enemyStateUser.h"
#include "FlockCube.h"
class Player;
class Enemy;
class enemyStateUser;
class FlockCube;
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
	
	NodeManager myNodes;
	
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
	std::vector<Enemy*> enemies;
	std::vector<enemyStateUser*> stateEnemy;
	std::vector<FlockCube*> flock;
	int nullBeheaviours = 0;
	Player* player;
	blackBoard* theBoard;
	std::vector<Wall*> myWalls;
	
	bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	bool lineRec(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh);
	bool nodeCollision(Vector2 pos1, Vector2 pos2);
	bool checkCollide(Object* obj1, Object* obj2);
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
	
	
	
	aie::Input *input;
	double timer;
	bool displayPath;

	std::list<Node*> path;
	Node* tempPtr;

	
	

	bool TimerTick(float dt);
};