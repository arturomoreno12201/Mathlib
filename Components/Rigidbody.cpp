#include "Rigidbody.h"

Rigidbody::Rigidbody()
{

	acceleration = vec2(0,0);
	velocity = vec2(0, 0);
	angularVelocity = vec2(0, 0);
		


}

void Rigidbody::intrgrate(Transform & trans, float deltaTime)
{

	trans.position = trans.position + velocity * deltaTime;
	trans.facing = trans.angularVelocity *deltaTime;


}
