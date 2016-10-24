#include "star.h"
#include "sfwdraw.h"
using namespace sfw;

Star::Star()
{

	vertThrust = 0.0f;
	horzThrust = 0.0f;
	stopAction = 0.0f;
	breakPoint = 4.0f;

	
	turnSpeed = 10.0f;

	
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

void Star::doStop(float value)
{

	stopAction += value;

}

void Star::update(const Transform &trans, Rigidbody & rigidbody)
{
	rigidbody.addForce(trans.getUp() * speed * vertThrust);
	rigidbody.addTorque(turnSpeed * horzThrust);

	rigidbody.addForce(-rigidbody.velocity * breakPoint * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPoint * stopAction);

	horzThrust = vertThrust = stopAction = 0;


}


