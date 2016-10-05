#include "star.h"
#include "sfwdraw.h"
using namespace sfw;

Star::Star()
{

	vertThrust = 0.0f;
	horzThrust = 0.0f;

	speed = 900.0f;
	maxSpeed = 1000.0f;

}

void Star::doThrust(float value)
{
	vertThrust = value;
}

void Star::doTurn(float value)
{
	horzThrust = value;
}

void Star::update(const Transform &trans, Rigidbody & rigidbody)
{
	rigidbody.addForce(trans.getDirection()* speed * vertThrust);

	trans.getDirection()*speed*vertThrust;

	rigidbody.addTorque(horzThrust *speed* vertThrust);
	vertThrust = 0;
/*
	rigidbody.acceleration.x = horzThrust * speed;
	rigidbody.acceleration.y = vertThrust * speed;

	
	if (magnitude(rigidbody.velocity) > maxSpeed)
	{
		
		vec2 dir = normal(rigidbody.velocity);

		
		rigidbody.velocity = dir * maxSpeed;
	}

	
	vertThrust = 0.0f;
	horzThrust = 0.0f;*/
}
