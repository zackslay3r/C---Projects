#include "Node.h"
#include <math.h>


Node::Node()
{
}


Node::~Node()
{
}

float Node::getFScore()
{
	return fScore;
}

float Node::getHScore()
{
	return hScore;
}

float Node::getdScore()
{
	return dScore;
}

void Node::setFScore(float newFScore)
{
	fScore = newFScore;
}

void Node::setHScore(float newHScore)
{
	hScore = newHScore;
}

void Node::setdScore(float newdScore)
{
	dScore = newdScore;
}

int Node::getKey()
{
	return key;
}

float Node::magnitude()
{
	return sqrt((posX*posX) + (posY*posY));
}

//void Node::normalise()
//{
//	float tempMag = magnitude();
//	posX /= tempMag;
//	posY /= tempMag;
//}



