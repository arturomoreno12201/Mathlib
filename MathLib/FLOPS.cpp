#include "FLOPS.h"
#include <cfloat>
#include <cmath>


bool fequals(float lhs, float rhs)
{
	return fabsf(lhs - rhs) <= 0.000001f;
}

float deg2rad(float deg)
{
	return (deg * 3.14) / 180;
}

float rad2deg(float rad)
{
	return (rad * 180) / 3.14;
}

float 
linearHalf(float x)
{
	return 0.5f;
}

float growfast(float x)
{
	return x*x*x*x;
}
