#include "fallower.h"
#include "Vect_2.h"

using namespace sfw;

Fallower::Fallower() : facing(0), position({ 0,0 }), scale({ 28,8 })
{
}

Fallower::Fallower(float x, float y) : Fallower()
{
	position.x = x;
	position.y = y;
}

vec2 Fallower::getDirection()
{
	return fromAngle(facing);
}

void Fallower::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}

void Fallower::debugDraw()
{
	drawCircle(position.x, position.y, 12);

	vec2 dirEnd = position + getDirection()* scale.x;
	vec2 upEnd = position + perp(getDirection()) * scale.y;

	drawLine(position.x, position.y, dirEnd.x, dirEnd.y, RED);

	drawLine(position.x, position.y, upEnd.x, upEnd.y, GREEN);
}



void Fallower::update(const Transform & trans)
{
	//fallow up&down
	if (trans.m_position.y > position.y-- || position.y < trans.m_position.y)
	{
		position.y += getDeltaTime() * 400;
	}
	if (trans.m_position.y < position.y++ || position.y > trans.m_position.y)
	{
		position.y -= getDeltaTime() * 400;
	}
	//FAllOW left&right
	if (trans.m_position.x > position.x-- || position.x< trans.m_position.x)
	{
		position.x += getDeltaTime() * 400;
	}
	if (trans.m_position.x < position.x++ || position.x > trans.m_position.x)
	{
		position.x -= getDeltaTime() * 400;
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
