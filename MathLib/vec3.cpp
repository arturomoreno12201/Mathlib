#include <cmath>
#include "vec3.h"
#include "FLOPS.h"

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.y };
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}

vec3 operator*(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator*(float rhs, const vec3 & lhs)
{
	return vec3{ rhs * lhs.x, rhs * lhs.y, rhs * lhs.z };
}

vec3 operator/(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}

vec3 operator/(float rhs, const vec3 & lhs)
{
	return vec3{ rhs / lhs.x, rhs / lhs.y, rhs / lhs.z };
}

vec3 operator-(const vec3 & v)
{
	return vec3{ -v.x, -v.y, -v.z };
}

vec3 operator+(const vec3 & v)
{
	return vec3{ +v.x, +v.y, +v.z };
}

vec3 & operator+=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs + rhs;
}

vec3 & operator-=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs - rhs;
}

vec3 & operator/=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs.x / rhs, lhs.y / rhs, lhs.z / rhs;
}

vec3 & operator*=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs.x * rhs, lhs.y * rhs, lhs.z * rhs;
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y && lhs.z != rhs.z;
}

float magnitude(const vec3 & v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

vec3 normal(const vec3 & v)
{
	return v / magnitude(v);
}

float dot(const vec3 & rhs, const vec3 & lhs)
{
	return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

float angleBetween(const vec3 & rhs, const vec3 & lhs)
{
	return acos(dot(normal(lhs), normal(rhs)));
}

vec3 cross(const vec3 & lhs, const vec3 & rhs)
{
	return{ (lhs.y * rhs.z) - (lhs.z * rhs.y), (lhs.z * rhs.x) - (lhs.x * rhs.z), (lhs.x * rhs.y) - (rhs.x * lhs.y) };
}