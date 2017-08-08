#include "Avoidance.h"
#include <math.h>
#include "PlayLoop.h"
#include "Global.h"





Avoidance::Avoidance(Object * myself, float angle)
{
	mySelf = myself;
	type = BehaviourNames::AVOIDANCE;
	feelerAngle = angle;
	behaviourWeight = 1.5f;
}

Vector2 Avoidance::Update(float dt)
{
	
	//((Enemy*)mySelf)->feelers.clear();
		//float feelerAngle = 0.25 * GAMESETTINGS->pi;
		float pushAngle = -feelerAngle;
		float speed = 100.0f;
		
		///* ahead starts off as myself's position.
		//Vector2 ahead = mySelf->position;
		//
		// then get the normalised velocity..
		//Vector2 tempVec = mySelf->velocity;
		//tempVec.normalise();
		//
		//and add that to ahead...
		//ahead = ahead + tempVec;

		// then times by the max distance that can be in front of the object.
		//ahead = ahead * 300.0f;

		// make a second ahead vector, but cut that length in half.
		//Vector2 ahead2 = ahead * 0.5;*/

		Vector2 linePos1 = mySelf->position;
		lineEnd = rotateVector(mySelf->velocity, feelerAngle);
		lineEnd.normalise() ;
		lineEnd = lineEnd * 100;
		lineEnd = lineEnd + mySelf->position;

		// for each wall, do a collision check against the feeler line.
		int wallcheckerCounter = 0;
		for (auto &walls : PLAY->myWalls)
		{
			
			// if the collision check is true
			if (lineRec(linePos1.x, linePos1.y, lineEnd.x, lineEnd.y, walls->position.x, walls->position.y, walls->scale.x, walls->scale.y))
			{
				Vector2 tempVec;
				tempVec = (mySelf->position + lineEnd) - linePos1 ;
				tempVec.normalise();
				if (tempVec.x != 0.0f && tempVec.y != 0.0f)
				{
					return (tempVec * speed);
				}
				
			}
			else
			{
				wallcheckerCounter++;
				if (wallcheckerCounter >= PLAY->myWalls.size())
				{
					PLAY->nullBeheaviours++;
					return {0,0};
				}
			}
			
		}
	//((Enemy*)mySelf)->feelers.push_back(linePos2);
}

Vector2 Avoidance::rotateVector(Vector2 feelerPos, float degrees)
{
	Vector2 tempVec;

	float rad = degrees * (GAMESETTINGS->pi / 180.0f);

	float sine = sin(rad);
	float coss = cos(rad);

	tempVec.x = feelerPos.x;
	tempVec.y = feelerPos.y;

	tempVec.x = (coss * feelerPos.x) - (sine * feelerPos.y);
	tempVec.y = (sine * feelerPos.x) + (coss * feelerPos.y);

	return tempVec;

}

bool Avoidance::lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	 {

		// calculate the direction of the lines
		float uA = ((x4 - x3)*(y1 - y3) - (y4 - y3)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));
		float uB = ((x2 - x1)*(y1 - y3) - (y2 - y1)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));

		// if uA and uB are between 0-1, lines are colliding
		if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {

			return true;
		}
		return false;
	}
}

bool Avoidance::lineRec(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh)
{
	// check if the line has hit any of the rectangle's sides
	// uses the Line/Line function below
	bool left = lineLine(x1, y1, x2, y2, rx, ry, rx, ry + rh);
	bool right = lineLine(x1, y1, x2, y2, rx + rw, ry, rx + rw, ry + rh);
	bool top = lineLine(x1, y1, x2, y2, rx, ry, rx + rw, ry);
	bool bottom = lineLine(x1, y1, x2, y2, rx, ry + rh, rx + rw, ry + rh);

	// if ANY of the above are true, the line
	// has hit the rectangle
	if (left || right || top || bottom) {
		return true;
	}
	return false;
}

Avoidance::~Avoidance()
{
}
