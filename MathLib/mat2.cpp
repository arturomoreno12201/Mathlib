#include "mat2.h"
#include"Vect_2.h"
#include "FLOPS.h"
#include <iostream>

using namespace std;


mat2::mat2()
{for (int row = 0; row < 2; ++row)
	{
		for (int col = 0; col < 2; ++col) mm[col][row] = 0;
	}
}

float mat2::operator[](unsigned idx) const
{
	return m[idx];
}

float & mat2::operator[](unsigned idx)
{
	return mm[idx][idx];
}

bool operator==(const mat2 & a, const mat2 & b)
{
	return fequals (a.m[0], b.m[0])&&
			fequals(a.m[1], b.m[1]) && 
			fequals(a.m[2], b.m[2]) && 
			fequals(a.m[3], b.m[3]);
}

mat2 transpose()
{
	return mat2 {1,0,0,1};
}



mat2 transpose(const mat2 & a)
{
	mat2 retval = a;

	retval.mm[1][0] = a.mm[0][1];
	retval.mm[0][1] = a.mm[1][0];

	return a;
}

mat2 operator+(const mat2 & a, const mat2 & b)
{
	mat2 returnValue;

	for (int i = 0; i < 4; ++i)
	{
		returnValue[i] = a[i] + b[i];
	}

	return returnValue;
}

mat2 operator-(const mat2 & a, const mat2 & b)
{

	mat2 returnValue;

	for (int i = 0; i < 4; ++i)
	{
		returnValue[i] = a[i] - b[i];
	}

	return returnValue;
}

mat2 operator*(const mat2 &a, const mat2 &b)
{
	mat2 temp;

	for (int col = 0; col < 2; ++col)
	{
		for (int row = 0; row < 2; ++row)
		{
			for (int inner = 0; inner < 2; ++inner)
				temp.mm[col][row] += a.mm[col][inner] * b.mm[inner][row];
		}
	}

	return temp;
}

float determinat(const mat2 & a)
{
	return 0.0f;
}

mat2 invers(const mat2 & a)
{
	return mat2();
}
