#pragma once
#include "mat3.h"
struct Circles 
{ 
	vec2 pos; 
	float rad;

};
Circles operator*(const mat3 &T, const Circles &c);
bool operator == (const Circles &A, const Circles &B);

struct AABB
{
	vec2 pos, he;

	vec2 MIN() const;
	vec2 MAX() const;

};
AABB operator*(const mat3 &T, const AABB &c);
bool  operator==(const AABB &A, const AABB &B);


struct Plane {};
Plane operator*(const mat3 &T, const Plane &c);
struct Ray{};
Ray operator*(const mat3 &T, const Ray &c);
struct Hull{};
Hull operator*(const mat3 &T, const Hull &c);



