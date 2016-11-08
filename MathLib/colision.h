#pragma once
#include "Vect_2.h"
#include "shapes.h"
struct CollisionD1
{
	bool result() const;
	float pendepth;
	float collNorm;
	float MTV() const;

};

CollisionD1 collisiond1(float Amin, float Amax, float Bmin, float Bmax);

struct SweptcollD1 
{
	float entTime, exTime;
	float collNorm;

	bool result();
	float MTV()   const;
};

SweptcollD1  swept(float Amax, float Amin, float Avel, float Bmin, float Bmax, float Bvel);

struct collData 
{

	float pendepth;
	vec2 collNorm;

	bool result() const;
	vec2 MTV() const;
		

}; 
collData BoxColl(const AABB &A, const AABB &B);
 
struct collDataSwept
{	
	float entryT, exit;
	vec2 collNorm;
	bool collides;

	

};
collDataSwept boxCollSwept(const AABB &A, const AABB &dA, const AABB &B, const AABB &dB);

col