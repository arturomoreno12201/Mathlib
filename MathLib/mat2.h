#pragma once
#include"Vect_2.h"
#include "FLOPS.h"

union mat2
{
	mat2();

	float m[4];
	float mm[2][2];
	vec2 c[2];

	float operator[](unsigned idx)const;
	float &operator[](unsigned idx);
};

bool operator==(const mat2 &a,const mat2 &b );
mat2 transpose();
mat2 transpose(const mat2 &a);

mat2 operator +(const mat2 &a, const mat2 &b);
mat2 operator -(const mat2 &a, const mat2 &b);

//mat2 operator*(const mat2 &a, float s);
//mat2 operator*(float s, const mat2 &a);
//mat2 operator*(const mat2 &a, const mat2 &b);
//mat2 operator*(const mat2 &a, const mat2 &v);

mat2 operator*(const mat2 &a, const mat2 &b);


float determinat(const mat2 &a);
mat2 invers(const mat2 &a);

