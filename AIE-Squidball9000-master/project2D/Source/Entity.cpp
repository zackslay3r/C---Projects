#include "Entity.h"
#include "Factory.h"
#include "AssetManager.h"

Entity::Entity()
{

    aabbMaxDistLeft = 0.0f;
    aabbMaxDistRight = 0.0f;
    aabbMaxDistUp = 0.0f;
    aabbMaxDistDown = 0.0f;
    rotatable = true;
    children.clear();
    colliderShapes.clear();
    renderShapes.clear();
    sprites.clear();

    resetNew();
}

Entity::~Entity()
{
	//Remove all children (if any) and tell my parent (if any) they have lost this child.
    resetExisting();
}

void Entity::addChild(Entity *pChild)
{
	aieASSERT(pChild != nullptr);
	
	//Search for this child in the vector array to prevent duplicates.
	/*std::vector*/ContLib::LinkedListIterator<Entity *> it = std::find(children.begin(), children.end(), pChild);

	//If we couldn't find this item in the vector array, add it.
	if (it == children.end())
	{
		children.push_back(pChild);
	}
}

void Entity::removeChild(Entity *pChild)
{
	aieASSERT(pChild != nullptr);

	//Search for this child in the vector array.
	/*std::vector*/ContLib::LinkedListIterator<Entity *> it = std::find(children.begin(), children.end(), pChild);

	//If we found the item in the vector array, remove it.
	if (it != children.end())
	{
		//Remove item from the things list of its type.
		children.erase(it);
	}
}

void Entity::resetNew()
{

    //Defaults.
    active = true;
    visible = true;

    localMatrix = Matrix3();
    globalMatrix = Matrix3();
    comLocalMatrix = Matrix3();

    velocity = Vector2();
    force = Vector2();

    sticky = false;
    stickyReceiver = false;

    restickTimeOut = 1.0f;
    restickTimer = 0.0f;

    parent = nullptr;
    root = this;

    lifeTimeExpiry = 0.0f;

    angVelocity = 0.0f;
    torque = 0.0f;
    mass = 0.0f;
    inverseMass = 0.0f;
    inertia = 0.0f;
    inverseInertia = 0.0f;
    comMass = 0.0f;
    comInverseMass = 0.0f;
    comInertia = 0.0f;
    comInverseInertia = 0.0f;
    restitution = 0.5f;
    staticFriction = 0.4f;
    dynamicFriction = 0.2f;
}

void Entity::resetExisting()
{
    //Remove all children. Loop over a COPY of the child list 
    //as we are removing elements from the original list as we loop.
    /*std::vector*/ContLib::LinkedList<Entity *> childrenCOPY = children;
    for (auto &var : childrenCOPY)
    {
        FACT->removeEntity(var);
        //FACT->releaseEntity(var);
    }

    //Tell my parent they have lost this child.
    if (parent != nullptr)
    {
        parent->removeChild(this);
    }

    resetNew();
}

void Entity::setParent(Entity *pParent)
{
	if (parent != pParent)
	{
		//We're about to change parent when we already had one.
		//So remove ourself from the old parent's child vector array.
		if (parent != nullptr)
		{
			parent->removeChild(this);
            //parent->root->updateCombinedMass();
            //parent->root->updateCombinedInertia();
            //parent->root->updateComLocalMatrix();
		}

		//Update parent pointer.
		parent = pParent;

		//Update our root pointer, and those of our children 
		//(and their children recursively), if we have any children.
		updateRoot();

		//Add ourself to the new parent's child vector array.
        if (pParent != nullptr)
        {
            pParent->addChild(this);
            //pParent->root->updateCombinedMass();
            //pParent->root->updateCombinedInertia();
            //pParent->root->updateComLocalMatrix();
        }

		//Set our local position and rotation to our current world position and rotation if we're now a top level entity.
		if (parent == nullptr)
		{
			localMatrix.setRotateZ(globalMatrix.getRotateZ());
			localMatrix.setTranslate(globalMatrix.getTranslate());
            //updateCombinedMass();
            //updateCombinedInertia();
            //updateComLocalMatrix();
		}
		
	}

	updateMatrixHeirarchy();
}

void Entity::updateRoot()
{
	//Update our root entity pointer.
	if (parent != nullptr)
	{
		root = parent->root;
	}
	else
	{
		root = this;
	}

	if (children.size() > 0)
	{
		for (Entity *var : children)
		{
			var->updateRoot();
		}
	}
}

Vector2 Entity::getWorldPos() const
{
	return globalMatrix.getTranslate();
}

Vector2 Entity::getWorldPosCOM() const
{
    return (globalMatrix * comLocalMatrix).getTranslate();
}

Vector2 Entity::getLocalPos() const
{
	return localMatrix.getTranslate();
}

void Entity::setLocalPosition(const Vector2 &newPos)
{
	localMatrix.setTranslate(newPos);

	//As setLocalPosition should only be called infrequently on an object,
	//it's safe to assume we want to updateMatrixHeirarchy automatically.
	updateMatrixHeirarchy();
}

void Entity::addToLocalPosition(const Vector2 &pos)
{
	localMatrix.translate(pos);
}

void Entity::setRotation(float radians)
{
	Vector2 trans = localMatrix.getTranslate();

	localMatrix.setRotateZ(radians);

	localMatrix.setTranslate(trans);
}

void Entity::addRotation(float radians)
{
	Vector2 trans = localMatrix.getTranslate();

	localMatrix.rotateZ(radians);

	localMatrix.setTranslate(trans);
}

void Entity::clampRotation(float min, float max)
{

	Vector2 trans = localMatrix.getTranslate();

	float rotation = localMatrix.getRotateZ();

	MathsLib::clamp(rotation, min, max);

	localMatrix.setRotateZ(rotation);

	localMatrix.setTranslate(trans);

}

void Entity::setMass(float nMass)
{
	mass = nMass;

	if (nMass == 0)
	{
		inverseMass = 0.0f;
		setInertia(0.0f);
	}
	else
	{
		//Set inertia for the object.
		//https://en.wikipedia.org/wiki/List_of_moments_of_inertia
		
        float I = nMass * pow(std::max({ aabbMaxDistLeft, aabbMaxDistRight, aabbMaxDistUp, aabbMaxDistDown }), 2);

		setInertia(I);
		
		inverseMass = 1.0f / nMass;
	}
}

void Entity::setInertia(float nInertia)
{
	inertia = nInertia;
	if (nInertia == 0)
	{
		inverseInertia = 0.0f;
	}
	else
	{
		inverseInertia = 1.0f / nInertia;
	}
}

void Entity::updateComLocalMatrix()
{
    //////////////
    // Centre of mass calculation.
    // See https://en.wikipedia.org/wiki/N-body_problem 
    // "Hamilton's Equation" for centre of mass. "Translational symmetry of the problem results in the center of mass..."
    // "The moment of inertia of an n-body system is given by..."
    //////////////

    //Centre of mass
    //c = sum each(mass * pos) / sum each(mass)

    /*std::vector*/ContLib::LinkedList<Entity*> tmpChildren;
    //Retrieve all children and subchildren.
    getChildEntities(tmpChildren, true);

    //Start with our own mass and position.
    Vector2 c = mass * Vector2();
    float sumMass = mass;

    for (auto &var : tmpChildren)
    {
        c += var->mass * (globalMatrix.inverted() * var->getWorldPos());
        sumMass += var->mass;
    }

    c /= sumMass;

    //Position is in world space. Convert to local.
    //c = globalMatrix.inverted() * c;

    comLocalMatrix.setTranslate(c);
}

void Entity::updateCombinedMass()
{
    //////////////
    // Centre of mass calculation.
    // See https://en.wikipedia.org/wiki/N-body_problem 
    // "Hamilton's Equation" for centre of mass. "Translational symmetry of the problem results in the center of mass..."
    // "The moment of inertia of an n-body system is given by..."
    //////////////

   /* std::vector*/ContLib::LinkedList<Entity*> tmpChildren;
    //Retrieve all children and subchildren.
    getChildEntities(tmpChildren, true);

    //Start with our own mass.
    float sumMass = mass;

    for (auto &var : tmpChildren)
    {
        sumMass += var->mass;
    }

    comMass = sumMass;
    comInverseMass = 1.0f / comMass;

}

void Entity::updateCombinedInertia()
{
    //////////////
    // Centre of mass calculation.
    // See https://en.wikipedia.org/wiki/N-body_problem 
    // "Hamilton's Equation" for centre of mass. "Translational symmetry of the problem results in the center of mass..."
    // "The moment of inertia of an n-body system is given by..."
    //////////////

    //Inertia
    //I = sum each (mass * pos.magnitude^2)

    /*std::vector*/ContLib::LinkedList<Entity*> tmpChildren;
    //Retrieve all children and subchildren.
    getChildEntities(tmpChildren, true);

    //Start with our own inertia.
    float sumI = inertia;

    for (auto &var : tmpChildren)
    {
        //Comnvert global position of object tgo local position relative to us.
        sumI += var->mass * (globalMatrix.inverted() * var->getWorldPos()).magnitudeSqr();
    }

    comInertia = sumI;
    comInverseInertia = 1.0f / comInertia;

}

void Entity::updateMatrixHeirarchy()
{

	//Concatenate with our parent matrix, if available.
	if (parent != nullptr)
	{
		globalMatrix = parent->globalMatrix * localMatrix;
	}
	else
	{
		globalMatrix = localMatrix;
	}

	//Update all our children.
	for (Entity *var : children)
	{
		var->updateMatrixHeirarchy();
	}

	//Update our collider shapes.
	for (auto var = colliderShapes.begin(); var != colliderShapes.end(); var++)
	{
		var->updatePointsWorldByMatrix(globalMatrix);
	}

	//Update our render shapes.
	for (auto var = renderShapes.begin(); var != renderShapes.end(); var++)
	{
		var->shape.updatePointsWorldByMatrix(globalMatrix);
	}
}

void Entity::updateAABBFromColliders()
{
	//If we're a polygon...

	float maxUp, maxDown, maxLeft, maxRight, maxMagnitudeSqr;
	maxUp = maxDown = maxLeft = maxRight = maxMagnitudeSqr = 0.0f;

	//Go through each collider and check for min and max bounds in the up, down, left and right directions.
	for (auto &sh : colliderShapes)
	{
		//Is this a circle or a polygon?
		if (sh.pointsLocal.size() == 1)
		{
			//CIRCLE...
			if (sh.pointsLocal[0].x - sh.radius < maxLeft) maxLeft = sh.pointsLocal[0].x - sh.radius;
			if (sh.pointsLocal[0].x + sh.radius > maxRight) maxRight = sh.pointsLocal[0].x + sh.radius;
			if (sh.pointsLocal[0].y - sh.radius < maxDown) maxDown = sh.pointsLocal[0].y - sh.radius;
			if (sh.pointsLocal[0].y + sh.radius > maxUp) maxUp = sh.pointsLocal[0].y + sh.radius;
		}
		else
		{
			//POLYGON...
			//Go through each point in the shape.
			for (auto &pt : sh.pointsLocal)
			{
				if (pt.x < maxLeft) maxLeft = pt.x;
				if (pt.x > maxRight) maxRight = pt.x;
				if (pt.y < maxDown) maxDown = pt.y;
				if (pt.y > maxUp) maxUp = pt.y;
			}
		}
	}

	//If this object is rotatable then get the max magnitude of any of the four box corners and use that as the max distance.
	if (rotatable)
	{
		float tmpSqr;
		
		tmpSqr = (maxUp * maxUp) + (maxRight * maxRight);
		if (tmpSqr > maxMagnitudeSqr) maxMagnitudeSqr = tmpSqr;
		
		tmpSqr = (maxDown * maxDown) + (maxRight * maxRight);
		if (tmpSqr > maxMagnitudeSqr) maxMagnitudeSqr = tmpSqr;

		tmpSqr = (maxUp * maxUp) + (maxLeft * maxLeft);
		if (tmpSqr > maxMagnitudeSqr) maxMagnitudeSqr = tmpSqr;

		tmpSqr = (maxDown * maxDown) + (maxLeft * maxLeft);
		if (tmpSqr > maxMagnitudeSqr) maxMagnitudeSqr = tmpSqr;

		//Convert squared distance to real distance.
		float tmpSqrt = sqrt(tmpSqr);
		aabbMaxDistLeft = -tmpSqrt;
		aabbMaxDistRight = tmpSqrt;
		aabbMaxDistUp = tmpSqrt;
		aabbMaxDistDown = -tmpSqrt;
	}
	else
	{
		//Otherwise use the individual values.
		aabbMaxDistLeft = maxLeft;
		aabbMaxDistRight = maxRight;
		aabbMaxDistUp = maxUp;
		aabbMaxDistDown = maxDown;
	}
}

void Entity::draw(bool cascade, aie::Renderer2D* renderer)
{

	aieASSERT(renderer);

	//Draw ourself.

	//Don't draw invisible entities.
	if (!root->visible) return;

    //SHAPES
	for (auto var = renderShapes.begin(); var != renderShapes.end(); var++)
	{

		//Set rendering colour.
		renderer->setRenderColour(/*var->*/(*var).colour.r, /*var->*/(*var).colour.g, var->colour.b, var->colour.a);

		int pointsSize = var->shape.pointsWorld.size();
		//Is this shape a circle?
		if (pointsSize == 1)
		{
			//Draw a circle.
			renderer->drawCircle(var->shape.pointsWorld[0].x, var->shape.pointsWorld[0].y, 
                var->shape.radius, var->depth);
		}
		//Is this shape a line?
		else if (pointsSize == 2)
		{
			renderer->drawLine(var->shape.pointsWorld[0].x, var->shape.pointsWorld[0].y, 
				var->shape.pointsWorld[1].x, var->shape.pointsWorld[1].y, var->lineThickness, var->depth);
		}
		//Is this shape a polygon?
		else if (pointsSize > 2)
		{
			//Draw a polygon.
			for (int i = 0; i < pointsSize; i++)
			{
				float currPointX = var->shape.pointsWorld[i].x;
				float currPointY = var->shape.pointsWorld[i].y;
				float nextPointX;
				float nextPointY;

				//Is this the final point in the series?
				if (i == pointsSize - 1)
				{
					//If so, draw a line segment back to the start point.
					nextPointX = var->shape.pointsWorld[0].x;
					nextPointY = var->shape.pointsWorld[0].y;
				}
				else
				{
					//If not, draw the next line segment of the polygon.
					nextPointX = var->shape.pointsWorld[i + 1].x;
					nextPointY = var->shape.pointsWorld[i + 1].y;
				}

				renderer->drawLine(currPointX, currPointY, nextPointX, nextPointY, var->lineThickness, var->depth);
			}
		}
		else
		{
			//No points defined, so draw nothing.
		}
	}

    //SPRITES
    for (auto var : sprites)
    {
        renderer->setRenderColour(var.colour.r, var.colour.g, var.colour.b, var.colour.a);
        renderer->drawSpriteTransformed3x3(AMAN->getTexture(var.texture), globalMatrix, var.textureWidth, var.textureHeight,
            var.depth, 0.5f, 0.5f);
    }

	//Draw our children recursively, if requested.
	if (cascade)
	{
		for (Entity *var : children)
		{
			var->draw(true, renderer);
		}
	}
}

void Entity::update(bool cascade)
{

	//Don't update inactive entities.
	if (!root->active) return;

	if (restickTimer < GCLK->getTimeSeconds()) restickTimer = 0.0f;

	//DO STUFF HERE
	//...

	//Update our children recursively, if requested.
	if (cascade)
	{
		for (Entity *var : children)
		{
			var->update(true);
		}
	}
}

void Entity::setLifeTimeExpiry(float time)
{
	lifeTimeExpiry = (float)GCLK->getTimeSeconds() + time;
}

void Entity::getChildEntities(/*std::vector*/ContLib::LinkedList<Entity*> &vectorarray, bool recursive) const
{
	for (Entity *ch : children)
	{
		vectorarray.push_back(ch);
		if (recursive) ch->getChildEntities(vectorarray, true);
	}
}

void Entity::fuseTo(Entity *ent)
{
	//Convert our local position from world space to local space relative to parent.
	localMatrix = ent->globalMatrix.inverted() * localMatrix;

	velocity = Vector2();
	angVelocity = 0;
	setParent(ent);
}

void Entity::breakAway()
{
	if (parent == nullptr) return;

	velocity = Vector2();
	angVelocity = 0;
	setParent(nullptr);
}
