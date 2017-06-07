#include "CollisionDetector.h"
#include "PhysicsCalculator.h"


CollisionDetector::CollisionDetector()
{
	
}

CollisionDetector::~CollisionDetector()
{

}

CollisionDetector *CollisionDetector::getInstance()
{
    static CollisionDetector collisionDetector;

    return &collisionDetector;
}

/*std::vector*/ContLib::LinkedList<CollisionDetector::AABBCollidingPairs> CollisionDetector::getAABBCollidingEntities() const
{

	/*std::vector*/ContLib::LinkedList<AABBCollidingPairs> collidingEntities;

    /*std::vector*/ContLib::LinkedList<Entity*> allEnts = FACT->getAllEntities();
    for (auto &A : allEnts)
    {

		//If this entity has no colliders, or is inactive, then skip it.
		if (A->colliderShapes.size() == 0 || !A->root->active) continue;

        ContLib::LinkedList<Entity*> allEnts2 = FACT->getAllEntities();
        ContLib::LinkedListIterator<Entity*> it;
        for (it = allEnts2.begin(); it != allEnts2.end(); it++)
        {
            //Dont try to compare if there is only one entity in the whole list.
            if (allEnts2.size() < 2) continue;
            
            //Always "A + 1" so we don't compare with ourselves, and we don't compare duplicates.
            if (it == allEnts2.begin() && allEnts2.size() > 1) it++;

            Entity *B = *it;

			//If this entity has no colliders, or is inactive, then skip it.
			if (B->colliderShapes.size() == 0 || !B->root->active) continue;

			//Cannot collide with ourself, or other entities in our matrix hieararchy.
			if (A->root == B->root) continue;

			float xMinA = A->getWorldPos().x + A->aabbMaxDistLeft;
			float xMaxA = A->getWorldPos().x + A->aabbMaxDistRight;
			float yMinA = A->getWorldPos().y + A->aabbMaxDistDown;
			float yMaxA = A->getWorldPos().y + A->aabbMaxDistUp;
			
			float xMinB = B->getWorldPos().x + B->aabbMaxDistLeft;
			float xMaxB = B->getWorldPos().x + B->aabbMaxDistRight;
			float yMinB = B->getWorldPos().y + B->aabbMaxDistDown;
			float yMaxB = B->getWorldPos().y + B->aabbMaxDistUp;

			//Standard AABB check for overlap of bounding boxes.
			if (!(xMaxB < xMinA || xMinB > xMaxA || 
				yMaxB < yMinA || yMinB > yMaxA))
			{
				AABBCollidingPairs pair;
				pair.A = A;
				pair.B = B;
				collidingEntities.push_back(pair);
			}
		}
	}

	return collidingEntities;
}

/*std::vector*/ContLib::LinkedList<Vector2> CollisionDetector::getNormalSATAxes(const Shape2 &shape) const
{
	/*std::vector*/ContLib::LinkedList<Vector2> axes;
	
	//Loop over the vertices.
	int size = shape.pointsWorld.size();
	for (int i = 0; i < size; i++) 
	{
		
		//Get the current vertex.
		Vector2 p1 = shape.pointsWorld[i];
		
		//Get the next vertex.
		Vector2 p2 = shape.pointsWorld[i + 1 == size ? 0 : i + 1];
		
		//Calculate the vector (edge) from the points.
		Vector2 edge = p1 - p2;
		
		//Calculate perpendicular vector (normal) pointing outwards from shape centre.
		//As all shapes use right-hand wrapping, we switch x and y, then switch the 
		//sign of the new y. This ensures the normal always points away from the shape.
		Vector2 normal = Vector2(edge.y, -edge.x);
		
		//Record the NORMALISED new axis normal.
		axes.push_back(normal.normalised());


	}

	return axes;
}

CollisionDetector::Projection CollisionDetector::axisDotProductProject(const Shape2 &shape, const Vector2 &axis) const
{
    std::vector<Vector2> points = shape.pointsWorld;

	//If this shape has only one point, then it is a circle.
	//This means the points are to be parallel to the test axis, 
	//one radius distance from the circle centre.
	if (points.size() == 1)
	{
		Vector2 centre = points[0];
		points.clear();
		points.push_back(Vector2(centre + (axis * shape.radius)));
		points.push_back(Vector2(centre - (axis * shape.radius)));
	}

    Vector2 minV; 
    Vector2 maxV;

	float min = axis.dot(points[0]);
    minV = points[0];
	float max = min;
    maxV = points[0];
	int size = points.size();
	for (int i = 1; i < size; i++) 
	{
		float p = axis.dot(points[i]);
		
        if (p < min)
		{
			min = p;
            minV = points[i];
		} 
        else if (p > max) 
		{
			max = p;
            maxV = points[i];
		}
	}

	return Projection(min, minV, max, maxV);
}

bool CollisionDetector::checkContainment(const CollisionDetector::Projection & proj1, const CollisionDetector::Projection & proj2) const
{
	return (proj1.min < proj2.min && proj1.max > proj2.max);
}

bool CollisionDetector::checkOverlap(const CollisionDetector::Projection& proj1, const CollisionDetector::Projection& proj2) const
{
    return getOverlap(proj1, proj2) >= 0;
}

float CollisionDetector::getOverlap(const CollisionDetector::Projection& proj1, 
	const CollisionDetector::Projection& proj2) const
{
    return std::min(proj1.max, proj2.max) - std::max(proj1.min, proj2.min);
}

/*std::vector*/ContLib::LinkedList<Vector2> CollisionDetector::getMaxSupports(const Shape2 *sh, const Vector2 &dir) const
{
    float bestProjection = -100000.0f;
    Vector2 v1;
    Vector2 v2;
    bool hasV2 = false;

    /*std::vector*/ContLib::LinkedList<Vector2> bestVertexes;
    
    //NOTE: std::vector used here instead of my custom LinkedList because the MathsLib requires a std::vector as input.
	std::vector<Vector2> points = sh->pointsWorld;

	size_t size = points.size();

	for (size_t i = 0; i < size; i++)
	{
		//It there's just one point, then this shape is a circle.
		//Create two virtual vertexes at one radius distance from the centre
		//of the circle along the direction vector.
		if (size == 1)
		{
			Vector2 centre = points[i];
			points.clear();
			points.push_back(Vector2(centre + (dir * sh->radius)));
			points.push_back(Vector2(centre - (dir * sh->radius)));
		}

		Vector2 v = points[i];
		float projection = v.dot(dir);

		if (projection > bestProjection)
		{
            v1 = v;
			bestProjection = projection;
            hasV2 = false;
		} 
        else if
        (projection == bestProjection)
        {
            v2 = v;
            hasV2 = true;
            bestProjection = projection;
        }
	}

    bestVertexes.push_back(v1);
    if (hasV2) bestVertexes.push_back(v2);

	return bestVertexes;
}

CollisionDetector::SATCollidingPairs CollisionDetector::getSATCollidingEntities(
	const CollisionDetector::AABBCollidingPairs &pair) const
{

	//Based on ideas from:
	//http://www.metanetsoftware.com/technique/tutorialA.html#section1
	//http://www.phailed.me/2011/02/polygonal-collision-detection/
	//http://buildnewgames.com/gamephysics/
	//http://www.metanetsoftware.com/2016/n-tutorial-a-collision-detection-and-response
	//https://gamedevelopment.tutsplus.com/tutorials/collision-detection-using-the-separating-axis-theorem--gamedev-169
	//http://www.dyn4j.org/2010/01/sat/#sat-notes

	//If at least one of the entities is inactive, then don't process this collission.
	if (!pair.A->root->active || !pair.B->root->active) return SATCollidingPairs();

	//Compare all collider shapes on entity A with all on entity B.
	for (const Shape2 &shapeA : pair.A->colliderShapes)
	{
		for (const Shape2 &shapeB : pair.B->colliderShapes)
		{
			bool noOverlap = false;

			//The most efficient collision detection method is selected based on the combination
			//of the two collider shapes.

			//Circle vs Circle
			if (shapeA.pointsWorld.size() == 1 && shapeB.pointsWorld.size() == 1)
			{
				//Get squared distance between the circles.
				float distX = shapeA.pointsWorld[0].x - shapeB.pointsWorld[0].x;
				float distY = shapeA.pointsWorld[0].y - shapeB.pointsWorld[0].y;
				float distSqr = (distX*distX) + (distY*distY);

				//Calculate max distance squared for these circles to be overlapping.
				float maxDistSqr = (shapeA.radius + shapeB.radius) * (shapeA.radius + shapeB.radius);

				//If circles are too far apart to overlap, skip to next shape.
				if (distSqr > maxDistSqr) continue;

				Vector2 contact;
				Vector2 mtv;
				float overlap = sqrt(maxDistSqr) - sqrt(distSqr);

				//Circles are overlapping so find the point of contact.
				//Find the circle with the shortest radius and use its edge as the shortest
				//poissible penetration depth into the circle with the larger radius.
				if (shapeA.radius < shapeB.radius)
				{
					mtv = shapeA.pointsWorld[0] - shapeB.pointsWorld[0];
					mtv.normalise();
					contact = shapeB.pointsWorld[0] + mtv * shapeB.radius;
					mtv = -mtv;
				}
				else
				{
					mtv =  shapeB.pointsWorld[0] - shapeA.pointsWorld[0];
					mtv.normalise();
					contact = shapeA.pointsWorld[0] + mtv * shapeA.radius;
				}

				//Add the overlap we found.
				SATCollidingPairs pairTmp;
				pairTmp.A = pair.A;
				pairTmp.B = pair.B;
				pairTmp.penetration = overlap;
				pairTmp.normal = mtv;
				pairTmp.contactWorldPos = contact;

				//Show contact point.
				drawContactPoint(contact);

				//Return this collision information as we only every report the first detected collision.
				return pairTmp;

			}
			//Circle vs Polygon
			else if ((shapeA.pointsWorld.size() == 1 && shapeB.pointsWorld.size() > 2)
			||
			//Polygon vs Circle
			(shapeA.pointsWorld.size() > 2 && shapeB.pointsWorld.size() == 1)
			||
			//Polygon vs Polygon
			(shapeA.pointsWorld.size() > 2 && shapeB.pointsWorld.size() > 2))
			{

				float overlap = FLT_MAX;
				Vector2 mtv;

				//Test shape A and shape B.
				Shape2 shapeTest[2]{ shapeA, shapeB };
				for (auto &sh : shapeTest)
				{
					/*std::vector*/ContLib::LinkedList<Vector2> axes;

					//If this shape is a circle, the only axis to test is the one from its midpoint
					//to the nearest vertex on the other shape (or is it nearest point on the other shape?).
					if (sh.pointsWorld.size() == 1)
					{
						const Shape2 *poly;
						const Shape2 *circle;
						//Check which way around the pairs are (circle vs poly or poly vs circle).
						if (shapeA.pointsWorld.size() == 1)
						{
							circle = &shapeA;
							poly = &shapeB;
						}
						else
						{
							circle = &shapeB;
							poly = &shapeA;
						}

						//Test distance from circle centre to all vertexes of the polygon.
						//The nearest vertex is the one we use to create the axis.
						float minSqrDist = FLT_MAX;
						Vector2 minVect;
						for (Vector2 vert : poly->pointsWorld)
						{
							float thisSqrDist = MathsLib::sqrDistance(circle->pointsWorld[0], vert);
							if (thisSqrDist < minSqrDist)
							{
								minSqrDist = thisSqrDist;
								minVect = vert - circle->pointsWorld[0];
							}
						}
						axes.push_back(minVect.normalised());
					}
					else
					{
						//If this shape is a polygon, use the normals of the shape edges as axes.
						axes = getNormalSATAxes(sh);
					}

					//Project both shapes onto normals for all axes of this shape.
					int size = axes.size();
					for (int i = 0; i < size; i++)
					{
						Vector2 axis = axes[i];

						//Project both shapes onto the axis
						Projection p1 = axisDotProductProject(shapeTest[0], axis);
						Projection p2 = axisDotProductProject(shapeTest[1], axis);
						
						//Do the projections overlap?
						if (!checkOverlap(p1, p2))
						{
							//If not then we can guarantee that the shapes do not overlap.
							noOverlap = true;
							//Stop checking this shape.
							break;
						}
						else
						{
							//Get the overlap amount.
							float o = getOverlap(p1, p2);

							//Check for containment (one shape's shadow entirely enclosed by the other).
							if (checkContainment(p1, p2) || checkContainment(p2, p1))
							{
								//Get the overlap plus the distance from the minimum end points
								float mins = abs(p1.min - p2.min);
								float maxs = abs(p1.max - p2.max);
								if (mins < maxs)
								{
									o += mins;
								}
								else
								{
									o += maxs;
								}
							}

							//If smaller than the current minimum, record it.
							if (o < overlap)
							{
								overlap = o;
								mtv = axis;
							}
						}
					}

					//If we found any evidence of separation between the shapes, move on to the next pair.
					if (noOverlap) break;
				}

				//If we found any evidence of separation between the shapes, move on to the next pair.
				if (noOverlap) continue;

                //Flip mtv if required so we always point the correct direction.
                Vector2 d = pair.B->getWorldPos() - pair.A->getWorldPos();
                if (d.dot(mtv) < 0)
                    mtv = -mtv;

                //Calculate the point of contact in world position between shapeA and shapeB.
                Vector2 contact;

				//Get support points on each shape closest to the other shape along the mtv.
                /*std::vector*/ContLib::LinkedList<Vector2> supportA = getMaxSupports(&shapeA, mtv);
                /*std::vector*/ContLib::LinkedList<Vector2> supportB = getMaxSupports(&shapeB, -mtv);
                
                //If just a single vertex on either shape is touching the other shape,
                //then use that as the collision contact point.
                if (supportA.size() == 1)
                {
                    contact = supportA[0];
                } 
                else if (supportB.size() == 1)
                {
                    contact = supportB[0];
                }
                else
                {
                    //More than one vertex on each object may be involved in the collision.
                    //Check if one objects vertexes are contained by the other's along
                    //ther line perpendicular to the mtv.
                    //If so, then use the average of those contained points as the contact point.

                    Vector2 mtvPerp = Vector2(-mtv.y, mtv.x);
                    Projection p1 = axisDotProductProject(Shape2({ { supportA[0] },{ supportA[1] } }), mtvPerp);
                    Projection p2 = axisDotProductProject(Shape2({ { supportB[0] },{ supportB[1] } }), mtvPerp);
                    if (checkContainment(p1, p2))
                    {
                        contact = (supportB[0] + supportB[1]) / 2.0f;
                    }
                    else if (checkContainment(p2, p1))
                    {
                        contact = (supportA[0] + supportA[1]) / 2.0f;
                    }
                    else
                    {
                        //Vertex pairs of each object are overlapping along the line perpendicular to the mtv.
                        //So get the innermost two points of the combined four points, and use the average of
                        //those two as the contact point.
                        
                        if (p1.min < p2.min)
                        {
                            contact = (p1.maxV + p2.minV) / 2.0f;
                        }
                        else
                        {
                            contact = (p1.minV + p2.maxV) / 2.0f;
                        }

                    }
                }

				//Create collision data object.
				SATCollidingPairs pairTmp;
				pairTmp.A = pair.A;
				pairTmp.B = pair.B;
				pairTmp.penetration = overlap;
				pairTmp.normal = mtv;
				pairTmp.contactWorldPos = contact;

				//Show contact point on screen.
				drawContactPoint(contact);

				//Return this collision information.
				return pairTmp;
			}
			else
			{
				//Either no points are defined for one or both shapes,
				//or one or both shapes are lines.
				//In this case we do not perform any collission detection.	
			}
		}
	}

	//No collisions found.
	return SATCollidingPairs();
}

void CollisionDetector::drawContactPoint(const Vector2 &point) const
{
    //////////
	//DISABLED
	//////////
	return;


	Entity *p = FACT->addEntity(Entity::Et::BasicShape);
	float sizeX = 5.0f;
	float sizeY = 5.0f;

	//Draw a mark where the collision ocurred.
	Entity::RenderShape rs;
	rs.shape = Shape2(4.0f);
	rs.colour = Colour(0.6f, 0.6f, 0.3f, 0.4f);
	rs.lineThickness = 1.0f;
	p->renderShapes = { rs };

	for (auto &var : p->renderShapes) var.shape.updateNormals();
	//ALWAYS call setLocalPosition last as it automatically calls the essential updateMatrixHeirarchy.
	p->setLocalPosition(point);

	//The mark will disappear after a short amount of time.
	p->setLifeTimeExpiry(0.25f);
}