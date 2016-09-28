#pragma once
#include "Vect_2.h"

class Vector 
{

public:
	Vector();
	Vector(float x, float y);

	vec2 position;
	vec2 scale;
	float facing;

	vec2 getDirection();
	void setDirection(const vec2 &dir);

	void debugDraw();

	void update();


};