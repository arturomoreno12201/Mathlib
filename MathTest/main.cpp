#include <cassert>
#include <cstdio>
#include "test.h"

#include <cmath>
#include "Vect_2.h"
#include "vec3.h"
#include "FLOPS.h"

#include "mat2.h"
#include "mat3.h"


int main()
{
	assert(fequals(0, 0.000001));

	assert(fequals(magnitude(vec2{ 5,0 }), 5));

	// magnitude of the normal should be 1
	vec2 N = normal(vec2{ 1,1 });
	assert(fequals(magnitude(N), 1));

	// Dot product with an AXIS should give us the coordinate value
	// along that axis.
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));

	// Anglebetween the X-Axis should give us the angle of the vector.
	assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 1,0 }), deg2rad(90)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), deg2rad(45)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 })));

	// Angle of 0 should be the X-Axis
	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));
	assert((fromAngle(deg2rad(45))) == normal(vec2{ 1,1 }));



	assert(fequals(lerp(.23, 124, 0), .23));
	assert(fequals(lerp(.23, 124, 1), 124));



	assert(fequals(hermiteSpline(15, 40, 21, 10, 0), 15));
	assert(fequals(hermiteSpline(15, 40, 21, 10, 1), 21));

	assert(fequals(cardinalSpline(15, 40, 21, .2f, 0), 15));
	assert(fequals(cardinalSpline(15, 40, 21, .1f, 1), 21));

	assert(fequals(catRomSpline(15, 40, 21, 0), 15));
	assert(fequals(catRomSpline(15, 40, 21, 1), 21));


	/*mat2 m0 = mat2{ 0,0,0,0 };
	mat2 mI = mat2Identity();
	mat2 t0 = mat2{ 4,3,0,1 };
	vec2 v0 = vec2{ 1,0 };
	assert(m0 == m0);
	assert(mI * 2 == 2 * mI);
	assert((mI * 2 == mat2{ 2,0,0,2 }));
	assert(mI + m0 == mI);
	assert(mI - mI == m0);
	assert(mI*-1 == -mI);

	assert(mI * mI == mI);
	assert(mI * (mat2{ 1,2,3,4 }) == (mat2{ 1,2,3,4 }));

	assert(mI * v0 == v0);
	assert((t0 * v0 == vec2{ 4,0 }));

	assert(transpose(mI) == mI);

	auto fff = determinant(mI);
	mat2 bbb = inverse(mI);
	assert(inverse(mI) == mI);
*/
/*bbb = inverse(t0) * t0;*/


	mat3 t03 = {};
	mat3 mI3 = mat3Identity();


	assert(mI3*inverse(mI3) == mI3);



	vec3 j = { 2,5,1 };

	assert((scale(5, 1) * j == vec3{ 10,5,1 }));

	assert((rotate(deg2rad(90)) * j == vec3{ -5,2,1 }));

	assert((translate(0, 3)*j == vec3{ 2,8,1 }));

	mat3 S = scale(2, 1);
	mat3 T = translate(4, 3);
	mat3 R = rotate(deg2rad(90));

	mat3 RES = { 0,-1,0, 2,0,0, 4,3,1 };

	bool r0 = (S*T*R == RES);
	bool r1 = (S*R*T == RES);
	bool r2 = (R*S*T == RES);
	bool r3 = (R*T*S == RES);
	bool r4 = (T*S*R == RES);
	bool r5 = (T*R*S == RES);




	vec3 test
		= rotate(deg2rad(-90)) * translate(10, 0) *
		rotate(deg2rad(45))  * translate(4, 0) *
		rotate(deg2rad(45))  * translate(-6, 0) *
		translate(6, 4)      *  vec3 { 0, 0, 1 };

	assert((test == vec3{ 2 * sqrtf(2), -6 - 2 * sqrtf(2) , 1 }));

	return 0;
}