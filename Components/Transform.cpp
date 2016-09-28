#include "Transform.h"
#include "sfwdraw.h"

using namespace sfw;

Transform::Transform() : facing(0), position({ 0,0 }), scale({28,8})
{
	
}

Transform::Transform(float x, float y) : Transform()
{
	position.x = x;
	position.y = y;
}

vec2 Transform::getDirection()
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}

void Transform::debugDraw()
{
	drawCircle(position.x, position.y, 12);

	vec2 dirEnd = position + getDirection()* scale.x;
	vec2 upEnd = position + perp(getDirection()) * scale.y;

	drawLine(position.x, position.y, dirEnd.x, dirEnd.y, RED);

	drawLine(position.x, position.y, upEnd.x, upEnd.y, GREEN);
}

void Transform::update()
{
	//up
	if (getKey(KEY_UP))
	{
		
		position.y += getDeltaTime() * 500;
	}
	//down
	if (getKey(KEY_DOWN))
	{
		
		position.y -= getDeltaTime() * 500;
	}
	//right
	if (getKey(KEY_RIGHT))
	{
	
		position.x += getDeltaTime() * 500;
	}
	//left
	if (getKey(KEY_LEFT))
	{
		
		position.x -= getDeltaTime() * 500;
	}

	
	//up and down
	if (position.y < -50)
	{
		position.y = 600;
	}

	if (position.y > 600)
	{
		position.y = -50;
	}

	//left and right
	if (position.x < -50)
	{
		position.x = 800;
	}

	if (position.x > 800)
	{
		position.x = -50;
	}

}
