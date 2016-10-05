#pragma once
#include "Rigidbody.h"
class Star
{
	
	float vertThrust;	
	float horzThrust;	

	float speed;		
	float maxSpeed;		

public:
	Star();
	void doThrust(float value);
	void doTurn(float value);

	void update(const Transform &trans, Rigidbody &rigidbody);
};