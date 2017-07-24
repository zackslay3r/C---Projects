#pragma once
#include <Vector2.h>
#include <Matrix3.h>
#include "Application.h"
#include "Renderer2D.h"
#include "Shapes.h"
/*
* class Object
*
* This class is used to for the production of the player object. it is responsible for the position of the player, as well is its rotation and scale 
* based upon the Matrix3 of GlobalTranslate. it also contains the inital setup process of the game object, the update function that updates the screen with 
* each frame and a draw function, which allows the texture to be drawn as a part of the object class. 
* it also contains the setParent function, which allows for the use of a matrix3 hierachy, which in this case, is Object being the tank base, followed by the tankTurret 
* and then the turret itself. It contains position, scale and rotation, which is needed for the local translate, with is then converting into a global translate.
* it also contains a origin value, which will contain the centre of the image.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/



class Object
{
public:
	
	Vector2 position ;
	Vector2 scale;
	Vector2 Origin;
	Vector2 textureSize;
	float rotation ;
	Matrix3 LocalTranslate;
	Matrix3 GlobalTranslate;



	/* Object();
	*
	* This is the default constructor for an Object class.
	*
	*/
	Object();
	/* void SetUp(aie::Texture* texture, aie::Renderer2D*	Renderer, shape::shapeType shapePick, float PosX = 0, float PosY = 0, 
		float ScaleX = 1, float ScaleY = 1, float OriginX = 0.5f, float OriginY = 0.5f );
	*
	* This is the setup function for the Object, which will set the texture, the renderer it will use.
	* shapetype, position, scale and the origin of the object.
	*
	* @param aie::Texture* - A texture that will be used for a particular object
	* @param aie::Renderer2D* - A pointer to the Renderer of the bootstrap.
	* @param shape::shapeType - A enum value of a shapetype.
	* @param float PosX - a float value that stores position.x defaulted to 0.
	* @param float PosY - a float value that stores position.y defaulted to 0.
	* @param float ScaleX - a float value that stores scale.x defaulted to 1.
	* @param float ScaleY - a float value that stores scale.y defaulted to 1.
	* @param float OriginX - a float value that stores origin.x defaulted to 0.5.
	* @param float OriginY - a float value that stores origin.y defaulted to 0.5.
	* @returns void
	*/
	void SetUp(aie::Texture* texture, aie::Renderer2D*	Renderer, shape::shapeType shapePick, float PosX = 0, float PosY = 0, 
		float ScaleX = 1, float ScaleY = 1, float OriginX = 0.5f, float OriginY = 0.5f );

	/* void setParent(Object* newParent);
	*
	* This function sets the parent of an object which is important for the matrix hierarchy.
	*
	* @param Object* newParent - An object pointer that the user wants to be the parent.
	* @returns void
	*/
	void setParent(Object* newParent);
	
	//Allows for the object to have a shape, used for drawing it.
	shape MyShape ;
	
	/* virtual void Update(float DT);
	*
	* This virtual function Updates the values of the object class based upon the parameter of deltaTime (which is game time.) 
	* This function gets redefined when an object calls its own update function.
	*
	* @param float DT - This is deltatime.
	* @returns void
	*/
	virtual void Update(float DT);
	/* virtual void Draw();
	*
	* This virtual function draws an object to the game screen when it is called based on its sprite, this draw will usually happen in update.
	* This function gets redefined when an object calls its own draw function.
	*
	* @returns void
	*/
	virtual void Draw();
	
	
	/* virtual CalMatrix();
	*
	* This function will update the GlobalTranslate based on the localTranslate, which is then based on the objects
	* scale, position and rotation. this needs to be done so that an object can be drawn and updated correctly.
	*
	* @returns void
	*/
	void calMatrix();
	
	/* ~Object();
	*
	* This is the default destructor for an Object class.
	*
	*/
	~Object();

protected:

	
	// This ensures that an object has a parent set, even if it is null.
	Object* Parent;
	// this is the texture of the object.
	aie::Texture* m_texture;
	// This is the aie renderer.
	aie::Renderer2D*	m_2dRenderer;
};