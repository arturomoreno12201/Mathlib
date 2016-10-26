#include "shapes.h"
#include "vec3.h"
Circles operator*(const mat3 & T, const Circles & c)
{
	Circles rev;

	rev.pos = (T*vec3{ c.pos.x,c.pos.y,1 }).xy;
	
	float Cx = magnitude(T*vec3{ 0,c.rad,0 });
	float Cy = magnitude(T*vec3{ c.rad,0,0 });

	return rev;
}

bool operator==(const Circles & A, const Circles & B)
{
	return false;
}



vec2 AABB::MIN() const
{
	return pos - he;
}

vec2 AABB::MAX() const
{
	return pos + he;
}

AABB operator*(const mat3 & T, const AABB & c)
{
	AABB rev = c;
	vec3 tp[4];

	tp[0] = T * vec3{ c.MIN().x,c.MIN().y,1 };
	tp[1] = T * vec3{ c.MAX().x,c.MAX().y,1 };
	tp[2] = T * vec3{ c.MIN().x,c.MAX().y,1 };
	tp[3] = T * vec3{ c.MAX().x,c.MIN().y,1 };

	rev.pos = (T * vec3{ c.pos.x, c.pos.y, 1 }).xy;

	//vec2 box1 = (T * vec3{c.MIN().x,c.MIN().y,1}).xy;
	//vec2 box2 = (T * vec3{ c.MAX().x,c.MAX().y,1 }).xy;
	//vec2 box3 = (T * vec3{ c.MIN().x,c.MAX().y,1 }).xy;
	//vec2 box4 = (T * vec3{ c.MAX().x,c.MIN().y,1 }).xy;

	//float XPOS[4] = { box1.x,box2.x,box3.x,box4.x };
	//float YPOS[4] = { box1.x,box2.x,box3.x,box4.x };

	/*float xMIN = box1.x;
	float xMAX = box1.x;
	float yMIN = box1.y;
	float yMAX = box1.y;*/
	
	vec2 minv = tp[0].xy;
	vec2 maxv = tp[0].xy;

	for (int i = 1 ; i < 4 ; ++i)
	{

		minv = min(minv, tp[i].xy);
		minv = max(minv, tp[i].xy);

		/*if (XPOS[i] < xMIN)
			xMIN = XPOS[i];
		if (XPOS[i] < xMAX)
			xMAX = XPOS[i];

		if (YPOS[i] < yMIN)
			yMIN = YPOS[i];
		if (YPOS[i] < yMAX)
			yMAX = YPOS[i];*/
	}


	/*rev.pos.x = (xMAX + xMIN) / 2;
	rev.pos.y = (yMAX + yMIN) / 2;
	rev.he.x = (xMAX - xMIN) / 2;
	rev.he.y= (yMAX -  yMIN) / 2;*/

	rev.pos = (minv = maxv) / 2;
	rev.he = (maxv - minv) / 2;
	return rev;
}
