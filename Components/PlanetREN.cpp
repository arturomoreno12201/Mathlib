#include "PlanetREN.h"
#include "sfwdraw.h"
#include "vec3.h"

PlanetRender::PlanetRender(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void PlanetRender::draw(const mat3& T,Transform & planetTrans)
{
	mat3 glob = planetTrans.getGlobalTransform();

	float xrad = magnitude(glob * vec3{ size,0,0 });
	float yrad = magnitude(glob * vec3{ 0,size,0 });

	vec2 pos = glob[2].xy;

	float rad = xrad > yrad ? xrad:yrad ;

	sfw::drawCircle(pos.x, pos.y, rad ,12U, color);
}
