
#pragma once

#include "Rigidbody.h"

class Planet
{
public:
	
	float m_rotationSpeed;

	void update(Rigidbody &planetRbody);
};
