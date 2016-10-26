#pragma once
#include "Transform.h"
#include "vec3.h"
class Player
{
public:

	unsigned int color;	// color of planet
	float size;			// radius of planet
	Player();

	void draw(const mat3& T, Transform &star);
}; 
