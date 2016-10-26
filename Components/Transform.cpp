#include "Transform.h"
#include "sfwdraw.h"
#include "ShapeDraw.h"


Transform::Transform(float x, float y,
	float w, float h, float a)
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;

	m_parent = nullptr;
	
}

vec2 Transform::getUp() const
{
	return -perp(getDirection());
}

// to the right.
vec2 Transform::getDirection() const
{
	return fromAngle(m_facing);
}

void Transform::setDirection(const vec2 &dir)
{
	m_facing = angle(dir);
}



mat3 Transform::getLocelTransform() const
{
	mat3 T = translate(m_position.x, m_position.y);
	mat3 S = scale(m_scale.x, m_scale.y);
	mat3 R = rotate(m_facing);


	return T * R * S;
}

mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
		return getLocelTransform();
	else
	return m_parent->getGlobalTransform()*getLocelTransform();
}

vec2 Transform::getGlobalPosition() const
{
	return getGlobalTransform()[2].xy;
}

vec2 Transform::getGlobalright() const
{
	return getGlobalTransform()[0].xy;
}

vec2 Transform::getGlobalup() const
{
	return getGlobalTransform()[1].xy;
}

float Transform::getGlobalAngle() const
{
	return angle(getGlobalright());
}

void Transform::debugDraw(const mat3 &T) const
{
	mat3 L = T * getGlobalTransform();

	vec3 pos = L[2];
	
	vec3 right = L * vec3{ 10, 0, 1 };
	vec3 up = L * vec3{ 0, 10, 1 };

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);

	vec3 sgp = m_parent ?  T* m_parent->getGlobalTransform()[2] : pos;
	sfw::drawLine(sgp.x, sgp.y, pos.x, pos.y, BLUE);

	sfw::drawCircle(pos.x, pos.y, 12, 12, 0x888888FF);
	
	drawAABB(L * AABB { 0,0,25,25},0x888888FF);

}