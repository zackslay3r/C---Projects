#pragma once
#include <Vector2.h>
#include <Matrix3.h>
#include "Application.h"
#include "Object.h"
#include "Input.h"
#include "Shapes.h"
#include <vector>


/*
* class Player : public Object
*
* This class is the player object.  
* it is responsible for the tankbase as well as the tankTurret and the turret, as well is its rotation and scale
* based upon the Matrix3 of GlobalTranslate. it also contains the inital setup process of the player, the update function that updates the screen with
* each frame and a draw function, which allows the texture to be drawn as a part of the object class.
* It contains position, scale and rotation which is the same values of Object, which is needed for the local translate, with is then converting into a global translate.
* it also contains a origin value of the object, which will contain the centre of the sprite. it also contains 3 objects.
* which are the tank base, the tank turret base and the tank turret and a boolean that checks if the tank turret is attached.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Player : public Object
{
public:
	/* Player();
	*
	* This is the default constructor for a Player object.
	*
	*/
	Player();
	/* void SetUp(aie::Texture* texture, aie::Renderer2D*	Renderer, aie::Texture * turretTexture, aie::Texture * Barreltexture, aie::Texture * bullet)
	*
	* This is the setup function for the Object, which will set the texture, the renderer it will use.
	* shapetype, position, scale and the origin of the object.
	*
	* @param aie::Texture* - A texture that will be used for the tank base.
	* @param aie::Renderer2D* - A pointer to the Renderer of the bootstrap.
	* @param aie::Texture* turretTexture - A texture that will be used for the tank turretBase.
	* @param aie::Texture* BarrelTexture - A texture that would be used for the tank turret.
	* @param aie::Texture* bullet - a texture that wouldve been used for a bullet.
	* @returns void
	*/
	void SetUp(aie::Texture * Tanktexture, aie::Renderer2D * Renderer, 
		aie::Texture * turretTexture, aie::Texture * Barreltexture, aie::Texture * bullet);

	/* void Update(float DT, aie::Input* Input);
	*
	* This function updates the values of the player on the parameter of deltaTime (which is game time.) as we as input, which allows the user to input 
	* keyboard commands.
	*
	* @param float DT - This is deltatime.
	* @param aie::Input* - This allows for user input.
	* @returns void
	*/
	void Update(float DT, aie::Input* input);
	
	/* void Draw();
	*
	* This function draws the player object to the game screen when it is called based on its sprite, this draw will usually happen in update.
	*
	* @returns void
	*/
	void Draw();
	

	Object myTurretBase;
	Object myTurret;
	Object myBullet;
	std::vector<Object> Bullets;
	bool TankTurretAttached = true;

	/* ~Player();
	*
	* This is the default destructor for a Player object.
	*
	*/
	~Player();

	Vector2 velocity;
private:

	
};

