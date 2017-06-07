#include "PhysicsCalculator.h"



PhysicsCalculator::PhysicsCalculator()
{

}

PhysicsCalculator::~PhysicsCalculator()
{

}

PhysicsCalculator *PhysicsCalculator::getInstance()
{
    static PhysicsCalculator physicsCalculator;

    return &physicsCalculator;
}

PhysicsCalculator::Derivative PhysicsCalculator::rk4Evaluate(const Entity *initial,
	float t, float dt, const PhysicsCalculator::Derivative &d) const
{
	Derivative output;

	output.dx = initial->velocity.x + d.dxv * dt;
	output.dxv = (initial->force.x * initial->inverseMass + gravity.x);

	output.dy = initial->velocity.y + d.dyv * dt;
	output.dyv = initial->force.y * initial->inverseMass + gravity.y;

	output.dr = initial->angVelocity + d.drv * dt;
	output.drv = initial->torque * initial->inverseInertia;

	return output;
}

void PhysicsCalculator::rk4Integrate(Entity *state, float t, float dt) const
{

	//Immovable objects of infinite mass don't require integration.
	if (state->inverseMass == 0.0f) return;

	Derivative a, b, c, d;

	a = rk4Evaluate(state, t, 0.0f, Derivative());
	b = rk4Evaluate(state, t, dt*0.5f, a);
	c = rk4Evaluate(state, t, dt*0.5f, b);
	d = rk4Evaluate(state, t, dt, c);

	float dxdt = 1.0f / 6.0f *
		(a.dx + 2.0f*(b.dx + c.dx) + d.dx);

	float dydt = 1.0f / 6.0f *
		(a.dy + 2.0f*(b.dy + c.dy) + d.dy);

	float dxvdt = 1.0f / 6.0f *
		(a.dxv + 2.0f*(b.dxv + c.dxv) + d.dxv);

	float dyvdt = 1.0f / 6.0f *
		(a.dyv + 2.0f*(b.dyv + c.dyv) + d.dyv);

	float drdt = 1.0f / 6.0f *
		(a.dr + 2.0f*(b.dr + c.dr) + d.dr);
	
	float drvdt = 1.0f / 6.0f *
		(a.drv + 2.0f*(b.drv + c.drv) + d.drv);

	state->addToLocalPosition({ dxdt * dt, dydt * dt });

	state->velocity.x = state->velocity.x + dxvdt * dt;
	state->velocity.y = state->velocity.y + dyvdt * dt;

	state->addRotation(drdt * dt);
	state->angVelocity = state->angVelocity + drvdt * dt;

	//Bleed off a small amount of angular velocity over time.
	if (abs(state->angVelocity) > EPSILON) state->angVelocity -= 0.005f * state->angVelocity;
}

void PhysicsCalculator::eulerIntegrate(Entity * ent, float dt) const
{
	ent->velocity += gravity + ent->force * ent->inverseMass * dt;
	ent->addToLocalPosition(ent->velocity * dt);

	ent->angVelocity += ent->torque * ent->inverseInertia * dt;
	ent->addRotation(ent->angVelocity * dt);
}

void PhysicsCalculator::resolveCollision(CollisionDetector::SATCollidingPairs &satPair) const
{

	/**
	* Based on concepts from:
	* https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-the-basics-and-impulse-resolution--gamedev-6331
	* https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-friction-scene-and-jump-table--gamedev-7756
	* https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-the-core-engine--gamedev-7493
	* http://www.randygaul.net/2013/03/27/game-physics-engine-part-1-impulse-resolution/
	* http://buildnewgames.com/gamephysics/
	*/

	//Define contact points on both objects relative to their COM.
	Vector2 rA = satPair.contactWorldPos - satPair.A->root->getWorldPos();
	Vector2 rB = satPair.contactWorldPos - satPair.B->root->getWorldPos();

	//Calculate relative velocity between the colliding objects.
	Vector2 rv = satPair.B->root->velocity + PHYS->cross(satPair.B->root->angVelocity, rB) - 
		satPair.A->root->velocity - PHYS->cross(satPair.A->root->angVelocity, rA);

	//Calculate relative velocity in the normal direction.
	float velAlongNormal = rv.dot(satPair.normal);

	//Early exit if objects are separating.
	if (velAlongNormal > 0) return;

	//Calculate total restitution (bouncyness) in this interaction.
	float e = satPair.e;

	float rACrossN = rA.cross(satPair.normal);
	float rBCrossN = rB.cross(satPair.normal);
	float invMassSum = satPair.A->root->inverseMass + satPair.B->root->inverseMass
		+ ((rACrossN*rACrossN) * satPair.A->root->inverseInertia) 
		+ ((rBCrossN*rBCrossN) * satPair.B->root->inverseInertia);

	//Calculate impulse scalar
	float j = -(1.0f + e) * velAlongNormal;
	j /= invMassSum;

	//If we're a sticky joined to a conglomerate, chance to decouple on impact.
	if (satPair.A->sticky && satPair.A->root->stickyReceiver)
	{
		if (mt.rng(0, 5) == 0)
		{
			satPair.A->breakAway();
			satPair.A->root->restickTimer = (float)GCLK->getTimeSeconds() + satPair.A->root->restickTimeOut;
		}
	}
	else if (satPair.B->sticky && satPair.B->root->stickyReceiver)
	{
		if (mt.rng(0, 5) == 0)
		{
			satPair.B->breakAway();
			satPair.B->root->restickTimer = (float)GCLK->getTimeSeconds() + satPair.B->root->restickTimeOut;
		}
	}

	//Are these objects a sticky and stickyReceiver pair? If so, join them together.
	if (satPair.A->root->sticky && satPair.B->root->stickyReceiver && satPair.A->root->restickTimer == 0.0f)
	{
		satPair.A->root->fuseTo(satPair.B);
	}
	else if (satPair.A->root->stickyReceiver && satPair.B->root->sticky && satPair.B->root->restickTimer == 0.0f)
	{
		satPair.B->root->fuseTo(satPair.A);
	}

	//Calculate impulse.
	Vector2 impulse = satPair.normal * j;

	//Apply impulse
	applyImpulse(satPair.A->root, -impulse, rA);
	applyImpulse(satPair.B->root, impulse, rB);

	//Friction impulse.
	//See https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-friction-scene-and-jump-table--gamedev-7756

	//Calculate relative velocity between the colliding objects.
	rv = satPair.B->root->velocity + PHYS->cross(satPair.B->root->angVelocity, rB) -
		satPair.A->root->velocity - PHYS->cross(satPair.A->root->angVelocity, rA);

	Vector2 t = rv - (satPair.normal * rv.dot(satPair.normal));
	t.normalise();

	//Tangent magnitude
	float jt = -rv.dot(t);
	jt /= invMassSum;

	//Don't apply tiny friction impulses.
	if (equal(jt, 0.0f)) return;

	//Coulumb's law.
	Vector2 tangentImpulse;
	if (std::abs(jt) < j * satPair.sf)
		tangentImpulse = t * jt;
	else
		tangentImpulse = t * -j * satPair.df;

	////Apply friction impulse
	//applyImpulse(satPair.A->root, -tangentImpulse, rA);
	//applyImpulse(satPair.B->root, tangentImpulse, rB);

	//Only allow friction to affect angular velociy (rotation) so it doesn't interfere with our special ball physics.
	satPair.A->root->angVelocity += satPair.A->root->inverseInertia * rA.cross(-tangentImpulse);
	satPair.B->root->angVelocity += satPair.B->root->inverseInertia * rB.cross(tangentImpulse);
}

void PhysicsCalculator::applyImpulse(Entity *pEnt, const Vector2 &force, const Vector2 &com) const
{
	//Immovable things don't have impulse forces applied.
	if (pEnt->inverseMass == 0.0f) return;
	
	pEnt->velocity += pEnt->inverseMass * force;
	
	//Angular/rotational force.
	pEnt->angVelocity += pEnt->inverseInertia * com.cross(force);
	
}
