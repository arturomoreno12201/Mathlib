#include "colision.h"
#include <cmath>
CollisionD1 collisiond1(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionD1 rev;
	
	float pDr = Amax - Bmin;
	float pDl = Bmax - Amin;

	rev.pendepth = fmin(pDr, pDl) ;



		rev.CallNorm = copysignf(1, pDl - pDr);


		


	return rev;
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
