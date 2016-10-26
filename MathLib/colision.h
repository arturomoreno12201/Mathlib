#pragma once
#include "Vect_2.h"
struct CollisionD1
{
	bool results;
	float pendepth;
	float CallNorm;
	float MTV;

};

CollisionD1 collisiond1(float Amin, float Amax, float Bmin, float Bmax);

struct SweptcollD1 
{

	float entTime, exTime;
	float collNorm;

	bool result();



};

SweptcollD1  swept(float Amax, float Amin, float Avel, float Bmin, float Bmax, float Bvel);

struct collData 
{

	float penetDeph;
	vec2 ollNorm;

	bool results();
		vec2 MTV();

};