#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
	mass = 1;
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	acceleration = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAcceleration = 0.0f;
}

void Rigidbody::addForce(const vec2 &force)
{
	acceleration += force;
}

void Rigidbody::addImpulse(const vec2 &impulse)
{
	velocity += impulse;
}

void Rigidbody::addTorque(float a_torque)
{
	torque += a_torque;
	 
	angularAcceleration += torque;
}

void Rigidbody::integrate(Transform &trans, float deltaTime)
{
	acceleration = force / mass;
	velocity = velocity + acceleration * deltaTime;
	angularVelocity = angularVelocity + angularAcceleration * deltaTime;
	force = impulse = { 0,0 };

	angularAcceleration = torque / mass;
	trans.position = trans.position + velocity * deltaTime;
	trans.facing = trans.facing + angularVelocity * deltaTime;
}