#pragma once
#include "Rigidbody.h"
class Star
{
	Star();

	float thrust;
	float maxThrust;
	float ThrustSpeed;

	float turn;
	float maxTurn;
	float turnSpeed;

	float speed;

public:
	void doThrust();
	void doTern();


	void update(Rigidbody &rigidbody, float deltaTime);
};