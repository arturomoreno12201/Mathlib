#pragma once
#include "Transform.h"
class PlanetRender
{
public:
	PlanetRender(unsigned a_color = 0xffffffff, float a_size = 20.f);

	unsigned int color;	// color of planet
	float size;			// radius of planet

	void draw(Transform &planetTrans);
};