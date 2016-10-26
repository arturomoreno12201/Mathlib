#include "ShapeDraw.h"

void drawCircle(const Circles & c, unsigned color)
{
	drawCircle(c.pos.x,c.pos.y,c.rad, 12U,BLUE);
}

void drawAABB(const AABB & box, unsigned color)
{
	vec2 A = vec2{ box.MIN().x, box.MAX().y };
	vec2 B = vec2{ box.MAX().x, box.MAX().y };
	vec2 C = vec2{ box.MAX().x, box.MIN().y };
	vec2 D = vec2{ box.MIN().x, box.MIN().y };

	sfw::drawLine(A.x, A.y, B.x, B.y, color);
	sfw::drawLine(B.x, B.y, C.x, C.y, color);
	sfw::drawLine(C.x, C.y, D.x, D.y, color);
	sfw::drawLine(D.x, D.y, A.x, A.y, color);
}
