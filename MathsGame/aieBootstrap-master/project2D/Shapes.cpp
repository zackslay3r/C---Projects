#include "Shapes.h"
#include <cmath>


// Default constructor
shape::shape()
{
	SetShape(Vector2(100, 100), &Matrix3(), myShapeChoice);
}

// Constructor that takes the parameters of sclae and the global translate
shape::shape(Vector2 scale, Matrix3 *Global)
{
	SetShape(scale, Global, myShapeChoice);
}

// Sets the shape based on the parameters
void shape::SetShape(Vector2 Setscale, Matrix3 * Global, shapeType shapeSelection, Vector2 Origion)
{
	scale = Setscale;
	shapeMatrix = Global;
	Origin = Origion;
	myShapeChoice = shapeSelection;

	ReCalcShape();
}

// Recalculate the shape based on the square points
void shape::ReCalcShape()
{
	float oX = (scale.x * 0.5) - (scale.x * Origin.x);
	float oY = (scale.y * 0.5) - (scale.y * Origin.y);

	square.points[0] = { (oX) - (scale.x * 0.5f), oY + (scale.y * 0.5f) };
	square.points[1] = { (oX )+ (scale.x * 0.5f), oY + (scale.y * 0.5f) };
	square.points[2] = { (oX) + (scale.x * 0.5f), oY - (scale.y * 0.5f) };
	square.points[3] = {( oX) - (scale.x * 0.5f), oY - (scale.y * 0.5f) };

	square.points[0] = (*shapeMatrix) *  square.points[0];
	square.points[1] = (*shapeMatrix) *  square.points[1];
	square.points[2] = (*shapeMatrix) *  square.points[2];
	square.points[3] = (*shapeMatrix) *  square.points[3];
}

// Recalculate the shape during the update function.
void shape::Update()
{
	ReCalcShape();


}

// Draw the shape based on the square points.
void shape::DrawDebug(aie::Renderer2D*	Renderer)
{
	if (DEBUG_SHOW)
	{
		for (int i = 0; i < (4 - 1); ++i)
		{
			//Renderer->setRenderColour(50, 50, 50, 1);
			Renderer->drawLine(square.points[i].x, square.points[i].y,
				square.points[i + 1].x, square.points[i + 1].y, 2, 1);
		}
		Renderer->drawLine(square.points[0].x, square.points[0].y,
			square.points[3].x, square.points[3].y, 2, 0);
	}
}






// This gets the normals of each of the square points
ArraySquare shape::getNormals()
{
	ArraySquare tempSquare;
	ArraySquare edges;

	edges.points[0] = square.points[0] - square.points[1];
	edges.points[1] = square.points[1] - square.points[2];
	edges.points[2] = square.points[2] - square.points[3];
	edges.points[3] = square.points[3] - square.points[0];

	for (int i = 0; i < 4; i++)
	{
		tempSquare.points[i].x = -edges.points[i].y;
		tempSquare.points[i].y = edges.points[i].x;
		tempSquare.points[i].normalise();
	}

	return tempSquare;
}


// this gets the normals that are unnormalized.
ArraySquare shape::getNormalsUnNormalized()
{
	ArraySquare tempSquare;
	ArraySquare edges;

	edges.points[0] = square.points[0] - square.points[1];
	edges.points[1] = square.points[1] - square.points[2];
	edges.points[2] = square.points[2] - square.points[3];
	edges.points[3] = square.points[3] - square.points[0];

	for (int i = 0; i < 4; i++)
	{
		tempSquare.points[i].x = -edges.points[i].y;
		tempSquare.points[i].y = edges.points[i].x;
	}

	return tempSquare;
}



//This projects the polygon based upon the x and y axis.
Vector2 shape::ProjectPolygon(Vector2 AxisNorm)
{

	
	Vector2 MinMax(INFINITY, -INFINITY);





	for (int i = 0; i < 4; i++)
	{

		float testDot = AxisNorm.dot(square.points[i]);

		if (testDot < MinMax.x)
		{
			MinMax.x = testDot;
		}
		if (testDot > MinMax.y)
		{
			MinMax.y = testDot;
		}
	}


	return MinMax;
}


// This calculates the interval distance between two shapes min and max dot product.
float shape::IntervalDistance(Vector2 minMaxa, Vector2 minMaxb)
{
	if (minMaxa.x < minMaxb.x)
	{
		float var;
		var = minMaxb.x - minMaxa.y;
		return var;
	}
	else if (minMaxa.x > minMaxb.x)
	{

		float var;
		var = (minMaxa.x) - (minMaxb.y);
		return var;
	}
}

// This tests if two polygons are colliding based upon their normals.
bool shape::isColliding(shape other)

{
	bool Result = true;

	
		ArraySquare thisNormals = getNormalsUnNormalized();
		ArraySquare otherNormals = other.getNormalsUnNormalized();
		Vector2 thisMinMax;
		Vector2 otherMinMax;

		for (int i = 0; i < 4; i++)
		{
			Vector2 CurrentNormal = thisNormals.points[i];

			thisMinMax = ProjectPolygon(CurrentNormal);
			otherMinMax = other.ProjectPolygon(CurrentNormal);
			float INVal = IntervalDistance(thisMinMax, otherMinMax);
			if (INVal > 0)
			{
				Result = false;
			}
		}
		for (int j = 0; j < 4; j++)
		{
			Vector2 CurrentNormal = otherNormals.points[j];

			thisMinMax = ProjectPolygon(CurrentNormal);
			otherMinMax = other.ProjectPolygon(CurrentNormal);

			float INVal = IntervalDistance(otherMinMax, thisMinMax);
			if (INVal > 0)
			{
				Result = false;
			}
		}
	

	return Result;
}

// This will calculate the direction that the object should push towards and gives the push out vector as
// well.
CollisionResults shape::isCollidingExtra(shape other)
{

	bool Result = true;
	float PenDist = INFINITY;
	Vector2 TranslationAxis;

	
		ArraySquare thisNormals = getNormals();
		ArraySquare otherNormals = other.getNormals();
		Vector2 thisMinMax;
		Vector2 otherMinMax;

		for (int i = 0; i < 4; i++)
		{
			Vector2 CurrentNormal = thisNormals.points[i];

			thisMinMax = ProjectPolygon(CurrentNormal);
			otherMinMax = other.ProjectPolygon(CurrentNormal);
			float INVal = IntervalDistance(thisMinMax, otherMinMax);
			if (INVal > 0)
			{
				Result = false;
			}
			if (abs(INVal) < PenDist)
			{
				// Checking if this is smallest penteration distance, if so, storing it and storing the normal direction.
				PenDist = abs(INVal);
				TranslationAxis = CurrentNormal;
			}
		
		for (int j = 0; j < 4; j++)
		{
			Vector2 CurrentNormal = otherNormals.points[j];

			thisMinMax = ProjectPolygon(CurrentNormal);
			otherMinMax = other.ProjectPolygon(CurrentNormal);

			float INVal = IntervalDistance(otherMinMax, thisMinMax);
			if (INVal > 0)
			{
				Result = false;
			}
			if (abs(INVal) < PenDist)
			{
				// Checking if this is smallest penteration distance, if so, storing it and storing the normal direction.
				PenDist = abs(INVal);
				TranslationAxis = CurrentNormal;
			}
		}


		if (Result)
		{
			Vector2 currentCentre = (square.points[0] + square.points[1] + square.points[2] + square.points[3]) / 4;
			Vector2 otherCentre = (other.square.points[0] + other.square.points[1] + other.square.points[2] + other.square.points[3]) / 4;

			Vector2 shapeCenters = currentCentre - otherCentre;
			float DotR = shapeCenters.dot(TranslationAxis);
			if (DotR < 0)
			{
				TranslationAxis = TranslationAxis * -1;
			}
		}


		CollisionResults ResultExtra;
		ResultExtra.colliding = Result;
		ResultExtra.pushOutVector = TranslationAxis * PenDist;



		return ResultExtra;
	}
}



