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
	return x*x;
}
float growSlow(float x)
{
	return 1 - growfast(1-x);
}

float growTent(float x)
{
	if (x <= 0.5)

		return 2 * x;

	else

		return -2*(x-1);
}

float bounce(float x)
{
	return abs(cos(x*10) * (1-x )); 
}

float bounceFlip(float x)
{
	return 1-bounce(x);
}

float parab(float x)
{
	return x*x;
}

float parabshift(float x)
{
		return 1 - (2*x-1)*(2 * x - 1);
}

float parabshifty(float x)
{
	return parab(x)+1;
}


float parabwhith(float x)
{
	return parab(x)*2;
}

float parabdie(float x)
{
	return parab(x)*-1;
}

float lerp(float start, float end, float alpha)
{
	return (1-alpha)*start + (alpha)*end;


}

float quadbraz(float start, float mid, float end, float alpha)
{	
	lerp(
		lerp(start, mid, alpha),
		lerp(start, end, alpha), alpha
		);
}

float hermiteSpline(float start, float s_tan,float end, float e_tan, float alpha)
{
	float tsq = alpha*alpha;
	float tcub = tsq*alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub - 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	return  h00 * start + h10 * s_tan +
		h01 * end + h11 * e_tan;
}

float cardinalSpline(float start, float mid, float end, float tightness, float alpha)
{
	float s_tan = (mid + start)* tightness,
		e_tan = (start - mid)* tightness;
	return hermiteSpline(start, s_tan, end, e_tan, alpha);
}

float catRomSpline(float start, float mid, float end, float alpha)
{
	return cardinalSpline(start, mid, end, 0.5f, alpha);
}


