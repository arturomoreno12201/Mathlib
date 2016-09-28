#pragma once
#include "sfwdraw.h"
#include "Transform.h"
#include "Vect_2.h"

using namespace sfw;

class Fallower
{
public:
	Fallower();
	Fallower(float x, float y);

	vec2 position;
	vec2 scale;
	float facing;
	
	vec2 getDirection();
	void setDirection(const vec2 &dir);
	void debugDraw();

	void update(const Transform & trans);
};