#include "colision.h"
#include <cmath>
CollisionD1 collisiond1(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionD1 rev;
	
	float pDr = Amax - Bmin;
	float pDl = Bmax - Amin;

	rev.pendepth = fmin(pDr, pDl) ;

		rev.collNorm = copysignf(1, pDl - pDr);

	return rev;
}

bool CollisionD1::result() const
{
	return pendepth >= 0;
}

float CollisionD1::MTV() const
{
	return pendepth * collNorm;
}

SweptcollD1 swept(float Amax, float Amin, float Avel, float Bmin, float Bmax, float Bvel)
{
	SweptcollD1 rev;

	float tl = (Amax - Bmin) / (Bvel - Avel);
	float tr = (Bmax - Amin) / (Avel - Bvel);

	rev.entTime = fmin(tl, tr);
	rev.entTime = fmin(tl, tr);

	rev.collNorm = copysign(1, tl - tr);

	return SweptcollD1();
}

float SweptcollD1::MTV() const
{
	return 0.0f;
}

collData BoxColl(const AABB & A, const AABB & B)
{
	collData retval;

	CollisionD1 XCD = collisiond1(A.MIN().x, A.MAX().x, B.MIN().x, B.MAX().x);

	CollisionD1 YCD =
		collisiond1(A.MIN().y, A.MAX().y, B.MIN().y, B.MAX().y);

	if (XCD.pendepth < YCD.pendepth)
	{
		retval.pendepth = XCD.pendepth;
		retval.collNorm =
			vec2{ 1,0 } *XCD.collNorm;
	}
	else
	{
		retval.pendepth = YCD.pendepth;
		retval.collNorm =
			vec2{ 0,1 } *YCD.collNorm;
	}
	return retval;
}

bool collData::result() const
{
	return pendepth >= 0;
}

vec2 collData::MTV() const
{
	return collNorm * pendepth;
}

collDataSwept boxCollSwept(const AABB & A, const AABB & dA, const AABB & B, const AABB & dB)
{
	collDataSwept retval;

	// Discrete results in case there is no movement along the axis.
	CollisionD1 Xdis = collisiond1(A.MIN().x, A.MAX().x, B.MIN().x, B.MAX().x);
	CollisionD1 Ydis = collisiond1(A.MIN().x, A.MAX().x, B.MIN().x, B.MAX().x);

	// Swept results along each axis
	SweptcollD1  Xres = swept (A.MIN().x, A.MAX().x, dA.x,
		B.MIN().x, B.MAX().x, dB.x);

	SweptcollD1  Yres = swept (A.MIN().y, A.MAX().y, dA.y,
		B.MIN().y, B.MAX().y, dB.y);
	// whether or not to use swept along that axis.
	bool xSwept = (dA.x - dB.x != 0);
	bool ySwept = (dA.y - dB.y != 0);


	// if x is sweeping and happens latest OR y is not sweeping
	if (Yres.entryT < Xres.entryT || xSwept && !ySwept)
	{
		retval.collNorm = vec2{ 1,0 } *Xres.collNorm;
		retval.entryT = Xres.entryT ;

		retval.collides = ySwept || Ydis.result();
	}
	else if (ySwept)
	{
		retval.collNorm = vec2{ 0,1 } *Yres.collNorm;
		retval.entryT = Yres.entryT;
		retval.collides = xSwept || Xdis.result();
	}

	if (Yres.exitT < Xres.exitT|| ySwept && !xSwept)

		retval.exitT = Yres.exitT;
	else if (xSwept)
		retval.exitT = Xres.exitT;

	return retval;

}

bool collDataSwept::result() const
{
	return entryT >= 0 && entryT <= 1 && collides;
}
