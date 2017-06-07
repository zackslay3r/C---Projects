#include "Squid.h"
#include "Factory.h"
#include "Player.h"

Squid::Squid()
{
	baseMaxVelocity = 500.0f;
	maxVelocity = baseMaxVelocity;

	Entity::RenderShape rs;
	float sizeX;
	float sizeY;
	float offsetX;
	float offsetY;

	/****************************
	* BODY
	*****************************/

	//Create root entity, the squid's body.
	rootEntity = FACT->addEntity(Entity::Et::BasicShape);
	sizeX = 50.0f;
	sizeY = 50.0f;
	rootEntity->colliderShapes = { Shape2({ Vector2(-sizeX, sizeY), Vector2(sizeX, sizeY), Vector2(sizeX, -sizeY), Vector2(-sizeX, -sizeY) }) };
	for (auto &var : rootEntity->colliderShapes) var.updateNormals();
	rootEntity->rotatable = true;
	rootEntity->updateAABBFromColliders();
	rs.shape = Shape2({ Vector2(-sizeX, sizeY), Vector2(sizeX, sizeY), Vector2(sizeX, -sizeY), Vector2(-sizeX, -sizeY) });
	rs.colour = Colour(0.0f, 1.0f, 1.0f, 0.8f);
	rs.lineThickness = 1.0f;
	rootEntity->renderShapes.push_back(rs);
	
	//Eyes
	sizeX = 10.0f;
	sizeY = 10.0f;
	offsetX = -20.0f;
	offsetY = 20.0f;
	rs.shape = Shape2({ Vector2(-sizeX + offsetX, sizeY + offsetY), Vector2(sizeX + offsetX, sizeY + offsetY),
		Vector2(sizeX + offsetX, -sizeY + offsetY), Vector2(-sizeX + offsetX, -sizeY + offsetY) });
	rs.colour = Colour(0.0f, 1.0f, 1.0f, 0.8f);
	rs.lineThickness = 1.0f;
	rootEntity->renderShapes.push_back(rs);
	offsetX = 20.0f;
	offsetY = 20.0f;
	rs.shape = Shape2({ Vector2(-sizeX + offsetX, sizeY + offsetY), Vector2(sizeX + offsetX, sizeY + offsetY),
		Vector2(sizeX + offsetX, -sizeY + offsetY), Vector2(-sizeX + offsetX, -sizeY + offsetY) });
	rs.colour = Colour(0.0f, 1.0f, 1.0f, 0.8f);
	rs.lineThickness = 1.0f;
	rootEntity->renderShapes.push_back(rs);

	//Mouth
	sizeX = 30.0f;
	sizeY = 10.0f;
	offsetX = 0.0f;
	offsetY = -20.0f;
	rs.shape = Shape2({ Vector2(-sizeX + offsetX, sizeY + offsetY), Vector2(sizeX + offsetX, sizeY + offsetY),
		Vector2(sizeX + offsetX, -sizeY + offsetY), Vector2(-sizeX + offsetX, -sizeY + offsetY) });
	rs.colour = Colour(0.0f, 1.0f, 1.0f, 0.8f);
	rs.lineThickness = 1.0f;
	rootEntity->renderShapes.push_back(rs);
	
	for (auto &var : rootEntity->renderShapes) var.shape.updateNormals();
	
	rootEntity->setMass(100000.0f);
	
	//ALWAYS call setLocalPosition last as it automatically calls the essential updateMatrixHeirarchy.
	rootEntity->setLocalPosition(Vector2());


	/****************************
	* LIMBS
	*****************************/

	//Limb 1.
	//HAS COLLIDERS
	limb1_1 = newLimbSegment(true);
	limb1_1->setLocalPosition(Vector2(-37.0f, -45.0f));
	limb1_1->setParent(rootEntity);

	limb1_2 = newLimbSegment(true);
	limb1_2->setLocalPosition(Vector2(0.0f, -55.0f));
	limb1_2->setParent(limb1_1);

	limb1_3 = newLimbSegment(true);
	limb1_3->setLocalPosition(Vector2(0.0f, -55.0f));
	limb1_3->setParent(limb1_2);

	//Limb 2.
	//NO COLLIDERS
	limb2_1 = newLimbSegment(false);
	limb2_1->setLocalPosition(Vector2(-12.0f, -45.0f));
	limb2_1->setParent(rootEntity);

	limb2_2 = newLimbSegment(false);
	limb2_2->setLocalPosition(Vector2(0.0f, -55.0f));
	limb2_2->setParent(limb2_1);

	limb2_3 = newLimbSegment(false);
	limb2_3->setLocalPosition(Vector2(0.0f, -55.0f));
	limb2_3->setParent(limb2_2);

	//Limb 3.
	//NO COLLIDERS
	limb3_1 = newLimbSegment(false);
	limb3_1->setLocalPosition(Vector2(13.0f, -45.0f));
	limb3_1->setParent(rootEntity);

	limb3_2 = newLimbSegment(false);
	limb3_2->setLocalPosition(Vector2(0.0f, -55.0f));
	limb3_2->setParent(limb3_1);

	limb3_3 = newLimbSegment(false);
	limb3_3->setLocalPosition(Vector2(0.0f, -55.0f));
	limb3_3->setParent(limb3_2);

	//Limb 4.
	//HAS COLLIDERS
	limb4_1 = newLimbSegment(true);
	limb4_1->setLocalPosition(Vector2(37.0f, -45.0f));
	limb4_1->setParent(rootEntity);

	limb4_2 = newLimbSegment(true);
	limb4_2->setLocalPosition(Vector2(0.0f, -55.0f));
	limb4_2->setParent(limb4_1);

	limb4_3 = newLimbSegment(true);
	limb4_3->setLocalPosition(Vector2(0.0f, -55.0f));
	limb4_3->setParent(limb4_2);

	//Limb segment starting rotation direction.
	limb1_1_dir = mt.rng(0,1) == 0 ? 1 : -1;
	limb2_1_dir = mt.rng(0,1) == 0 ? 1 : -1;
	limb3_1_dir = mt.rng(0,1) == 0 ? 1 : -1;
	limb4_1_dir = mt.rng(0,1) == 0 ? 1 : -1;
	limb1_2_dir = mt.rng(0,1) == 0 ? 1 : -1;
	limb2_2_dir = mt.rng(0,1) == 0 ? 1 : -1;
	limb3_2_dir = mt.rng(0,1) == 0 ? 1 : -1;
	limb4_2_dir = mt.rng(0,1) == 0 ? 1 : -1;
	limb1_3_dir = mt.rng(0,1) == 0 ? 1 : -1;
	limb2_3_dir = mt.rng(0,1) == 0 ? 1 : -1;
	limb3_3_dir = mt.rng(0,1) == 0 ? 1 : -1;
	limb4_3_dir = mt.rng(0,1) == 0 ? 1 : -1;

	//Limb segment rotation limits.
	limb1RotStartDeg = -15.0f;
	limb1RotEndDeg = 15.0f;
	limb2RotStartDeg = -15.0f;
	limb2RotEndDeg = 15.0f;
	limb3RotStartDeg = -15.0f;
	limb3RotEndDeg = 15.0f;
	limb4RotStartDeg = -15.0f;
	limb4RotEndDeg = 15.0f;

	//Limb segment starting rotation position.
	limb1_1->setRotation((float)mt.rng(MathsLib::deg2rad(limb1RotStartDeg), MathsLib::deg2rad(limb1RotEndDeg)));
	limb2_1->setRotation((float)mt.rng(MathsLib::deg2rad(limb2RotStartDeg), MathsLib::deg2rad(limb2RotEndDeg)));
	limb3_1->setRotation((float)mt.rng(MathsLib::deg2rad(limb3RotStartDeg), MathsLib::deg2rad(limb3RotEndDeg)));
	limb4_1->setRotation((float)mt.rng(MathsLib::deg2rad(limb4RotStartDeg), MathsLib::deg2rad(limb4RotEndDeg)));
	limb1_2->setRotation((float)mt.rng(MathsLib::deg2rad(limb1RotStartDeg), MathsLib::deg2rad(limb1RotEndDeg)));
	limb2_2->setRotation((float)mt.rng(MathsLib::deg2rad(limb2RotStartDeg), MathsLib::deg2rad(limb2RotEndDeg)));
	limb3_2->setRotation((float)mt.rng(MathsLib::deg2rad(limb3RotStartDeg), MathsLib::deg2rad(limb3RotEndDeg)));
	limb4_2->setRotation((float)mt.rng(MathsLib::deg2rad(limb4RotStartDeg), MathsLib::deg2rad(limb4RotEndDeg)));
	limb1_3->setRotation((float)mt.rng(MathsLib::deg2rad(limb1RotStartDeg), MathsLib::deg2rad(limb1RotEndDeg)));
	limb2_3->setRotation((float)mt.rng(MathsLib::deg2rad(limb2RotStartDeg), MathsLib::deg2rad(limb2RotEndDeg)));
	limb3_3->setRotation((float)mt.rng(MathsLib::deg2rad(limb3RotStartDeg), MathsLib::deg2rad(limb3RotEndDeg)));
	limb4_3->setRotation((float)mt.rng(MathsLib::deg2rad(limb4RotStartDeg), MathsLib::deg2rad(limb4RotEndDeg)));

	//One final call to update the matrix heirarchy for the whole lot.
	rootEntity->updateMatrixHeirarchy();
}

Squid::~Squid()
{

	/*std::vector*/ContLib::LinkedList<Entity *> parts = {
		limb1_3,
		limb1_2,
		limb1_1,

		limb2_3,
		limb2_2,
		limb2_1,

		limb3_3,
		limb3_2,
		limb3_1,

		limb4_3,
		limb4_2,
		limb4_1,

		rootEntity
	};

	for (auto &var : parts)
	{
		if (var != nullptr)
		{
			FACT->removeEntity(var);
		}
	}

	limb1_3 = nullptr;
	limb1_2 = nullptr;
	limb1_1 = nullptr;

	limb2_3 = nullptr;
	limb2_2 = nullptr;
	limb2_1 = nullptr;
		   
	limb3_3 = nullptr;
	limb3_2 = nullptr;
	limb3_1 = nullptr;
		  
	limb4_3 = nullptr;
	limb4_2 = nullptr;
	limb4_1 = nullptr;

	rootEntity = nullptr;
}

void Squid::updatePhysics(float dt)
{
	//Only active actors update.
	if (!active) return;

	//Squid main body is not permitted to rotate.
	rootEntity->setRotation(0);

	//Squid main body is not permitted to gain X velocity.
	rootEntity->velocity.x = 0;

	//Keep velocity below maximum.
	float maxVel = maxVelocity;
	float maxVelSqr = maxVel * maxVel;

	float curVelSqr = rootEntity->velocity.magnitudeSqr();

	if (curVelSqr > maxVelSqr)
	{
		rootEntity->velocity.normalise();
		rootEntity->velocity = rootEntity->velocity * maxVel;
	}

	//Squid main body is clamped to a range in Y dimension.
	float tempY = rootEntity->getLocalPos().y;
	MathsLib::clamp(tempY, player->clampYMin, player->clampYMax);

	//ALWAYS call setLocalPosition last as it automatically calls the essential updateMatrixHeirarchy.
	rootEntity->setLocalPosition({ player->clampX, tempY});

}

void Squid::update(float dt)
{

	if (!active) return;

	//Move squid limbs.

	if (limb1_1->localMatrix.getRotateZ() > MathsLib::deg2rad(limb1RotEndDeg) || limb1_1->localMatrix.getRotateZ() < MathsLib::deg2rad(limb1RotStartDeg)) limb1_1_dir = -limb1_1_dir;
	limb1_1->clampRotationDeg(limb1RotStartDeg, limb1RotEndDeg);
	if (limb1_2->localMatrix.getRotateZ() > MathsLib::deg2rad(limb1RotEndDeg) || limb1_2->localMatrix.getRotateZ() < MathsLib::deg2rad(limb1RotStartDeg)) limb1_2_dir = -limb1_2_dir;
	limb1_2->clampRotationDeg(limb1RotStartDeg, limb1RotEndDeg);
	if (limb1_3->localMatrix.getRotateZ() > MathsLib::deg2rad(limb1RotEndDeg) || limb1_3->localMatrix.getRotateZ() < MathsLib::deg2rad(limb1RotStartDeg)) limb1_3_dir = -limb1_3_dir;
	limb1_3->clampRotationDeg(limb1RotStartDeg, limb1RotEndDeg);

	if (limb2_1->localMatrix.getRotateZ() > MathsLib::deg2rad(limb2RotEndDeg) || limb2_1->localMatrix.getRotateZ() < MathsLib::deg2rad(limb2RotStartDeg)) limb2_1_dir = -limb2_1_dir;
	limb2_1->clampRotationDeg(limb2RotStartDeg, limb2RotEndDeg);
	if (limb2_2->localMatrix.getRotateZ() > MathsLib::deg2rad(limb2RotEndDeg) || limb2_2->localMatrix.getRotateZ() < MathsLib::deg2rad(limb2RotStartDeg)) limb2_2_dir = -limb2_2_dir;
	limb2_2->clampRotationDeg(limb2RotStartDeg, limb2RotEndDeg);
	if (limb2_3->localMatrix.getRotateZ() > MathsLib::deg2rad(limb2RotEndDeg) || limb2_3->localMatrix.getRotateZ() < MathsLib::deg2rad(limb2RotStartDeg)) limb2_3_dir = -limb2_3_dir;
	limb2_3->clampRotationDeg(limb2RotStartDeg, limb2RotEndDeg);

	if (limb3_1->localMatrix.getRotateZ() > MathsLib::deg2rad(limb3RotEndDeg) || limb3_1->localMatrix.getRotateZ() < MathsLib::deg2rad(limb3RotStartDeg)) limb3_1_dir = -limb3_1_dir;
	limb3_1->clampRotationDeg(limb3RotStartDeg, limb3RotEndDeg);
	if (limb3_2->localMatrix.getRotateZ() > MathsLib::deg2rad(limb3RotEndDeg) || limb3_2->localMatrix.getRotateZ() < MathsLib::deg2rad(limb3RotStartDeg)) limb3_2_dir = -limb3_2_dir;
	limb3_2->clampRotationDeg(limb3RotStartDeg, limb3RotEndDeg);
	if (limb3_3->localMatrix.getRotateZ() > MathsLib::deg2rad(limb3RotEndDeg) || limb3_3->localMatrix.getRotateZ() < MathsLib::deg2rad(limb3RotStartDeg)) limb3_3_dir = -limb3_3_dir;
	limb3_3->clampRotationDeg(limb3RotStartDeg, limb3RotEndDeg);

	if (limb4_1->localMatrix.getRotateZ() > MathsLib::deg2rad(limb4RotEndDeg) || limb4_1->localMatrix.getRotateZ() < MathsLib::deg2rad(limb4RotStartDeg)) limb4_1_dir = -limb4_1_dir;
	limb4_1->clampRotationDeg(limb4RotStartDeg, limb4RotEndDeg);
	if (limb4_2->localMatrix.getRotateZ() > MathsLib::deg2rad(limb4RotEndDeg) || limb4_2->localMatrix.getRotateZ() < MathsLib::deg2rad(limb4RotStartDeg)) limb4_2_dir = -limb4_2_dir;
	limb4_2->clampRotationDeg(limb4RotStartDeg, limb4RotEndDeg);
	if (limb4_3->localMatrix.getRotateZ() > MathsLib::deg2rad(limb4RotEndDeg) || limb4_3->localMatrix.getRotateZ() < MathsLib::deg2rad(limb4RotStartDeg)) limb4_3_dir = -limb4_3_dir;
	limb4_3->clampRotationDeg(limb4RotStartDeg, limb4RotEndDeg);

	float rotSpeedDeg;
	float rotSpeed;
	float rotSpeedRangeStartDeg = 10.0f;
	float rotSpeedRangeEndDeg = 20.0f;

	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb1_1->setRotation(limb1_1->localMatrix.getRotateZ() + (rotSpeed * limb1_1_dir * dt));
	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb1_2->setRotation(limb1_2->localMatrix.getRotateZ() + (rotSpeed * limb1_2_dir * dt));
	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb1_3->setRotation(limb1_3->localMatrix.getRotateZ() + (rotSpeed * limb1_3_dir * dt));
	
	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb2_1->setRotation(limb2_1->localMatrix.getRotateZ() + (rotSpeed * limb2_1_dir * dt));
	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb2_2->setRotation(limb2_2->localMatrix.getRotateZ() + (rotSpeed * limb2_2_dir * dt));
	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb2_3->setRotation(limb2_3->localMatrix.getRotateZ() + (rotSpeed * limb2_3_dir * dt));
											 						
	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb3_1->setRotation(limb3_1->localMatrix.getRotateZ() + (rotSpeed * limb3_1_dir * dt));
	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb3_2->setRotation(limb3_2->localMatrix.getRotateZ() + (rotSpeed * limb3_2_dir * dt));
	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb3_3->setRotation(limb3_3->localMatrix.getRotateZ() + (rotSpeed * limb3_3_dir * dt));
	
	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb4_1->setRotation(limb4_1->localMatrix.getRotateZ() + (rotSpeed * limb4_1_dir * dt));
	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb4_2->setRotation(limb4_2->localMatrix.getRotateZ() + (rotSpeed * limb4_2_dir * dt));
	rotSpeedDeg = (float)mt.rng(rotSpeedRangeStartDeg, rotSpeedRangeEndDeg);
	rotSpeed = MathsLib::deg2rad(rotSpeedDeg);
	limb4_3->setRotation(limb4_3->localMatrix.getRotateZ() + (rotSpeed * limb4_3_dir * dt));

	rootEntity->updateMatrixHeirarchy();
}

void Squid::explode()
{

	float velXmin = -100.0f;
	float velXmax = 100.0f;
	float velYmin = -100.0f;
	float velYmax = 100.0f;
	
	/*std::vector*/ContLib::LinkedList<Entity *> parts = {
		limb1_3,
		limb1_2,
		limb1_1,
		limb2_3,
		limb2_2,
		limb2_1,
		limb3_3,
		limb3_2,
		limb3_1,
		limb4_3,
		limb4_2,
		limb4_1, 
		rootEntity
	};

	for (auto &var : parts)
	{
		//Skip already removed parts.
		if (var == nullptr) continue;

		var->setParent(nullptr);
		var->velocity = Vector2((float)mt.rng(velXmin, velXmax), (float)mt.rng(velYmin, velYmax));
		var->angVelocity = MathsLib::deg2rad((float)mt.rng(-60.28319f, 60.28319f));
		var->setLifeTimeExpiry((float)mt.rng(5.0f, 5.5f));
	}

	limb1_3 = nullptr;
	limb1_2 = nullptr;
	limb1_1 = nullptr;
		   
	limb2_3 = nullptr;
	limb2_2 = nullptr;
	limb2_1 = nullptr;
		  
	limb3_3 = nullptr;
	limb3_2 = nullptr;
	limb3_1 = nullptr;
		   
	limb4_3 = nullptr;
	limb4_2 = nullptr;
	limb4_1 = nullptr;

	rootEntity = nullptr;

	active = false;

	player->actor = nullptr;

	FACT->removeActor(this);
}

Entity *Squid::newLimbSegment(bool addColliders) const
{
	Entity *p;
	Entity::RenderShape rs;

	float sizeX = 10.0f;
	float sizeY = 30.0f;
	float offsetX = 0.0f;
	float offsetY = -30.0f;

	p = FACT->addEntity(Entity::Et::BasicShape);
	if (addColliders)
	{
		p->colliderShapes = { Shape2({ Vector2(-sizeX + offsetX, sizeY + offsetY), Vector2(sizeX + offsetX, sizeY + offsetY),
			Vector2(sizeX + offsetX, -sizeY + offsetY), Vector2(-sizeX + offsetX, -sizeY + offsetY) }) };
		for (auto &var : p->colliderShapes) var.updateNormals();
		p->rotatable = true;
		p->updateAABBFromColliders();
	}
	rs.shape = Shape2({ Vector2(-sizeX + offsetX, sizeY + offsetY), Vector2(sizeX + offsetX, sizeY + offsetY),
		Vector2(sizeX + offsetX, -sizeY + offsetY), Vector2(-sizeX + offsetX, -sizeY + offsetY) });
	rs.colour = Colour(0.0f, 1.0f, 1.0f, 0.8f);
	rs.lineThickness = 1.0f;
	p->renderShapes.push_back(rs);
	for (auto &var : p->renderShapes) var.shape.updateNormals();
	p->setMass(5.0f);

	return p;
}
