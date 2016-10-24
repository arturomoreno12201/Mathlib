#include "planet.h"


void Planet::update(Rigidbody & b)
{
	b.addTorque(m_rotationSpeed);
	//Make it not accelerate
	//b.angVel = 0;
}