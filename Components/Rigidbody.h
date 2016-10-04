#pragma once
#include "Transform.h"
#include "sfwdraw.h"
#include "Vect_2.h"
#include "FLOPS.h"

class Rigidbody
{

public:
	Rigidbody(); 
		vec2 velocity;
 float angularVelocity;
 vec2 changinvelocity;
 vec2 acceleration;
	void intrgrate(Transform &trans, float deltaTime);

};

