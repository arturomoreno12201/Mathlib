#include "PlayerREN.h"

Player::Player()
{
}

void Player::draw(const mat3 & T, Transform & star)
{

	mat3 glob = T * star.getGlobalTransform();
	vec3 F= glob* vec3 {0, 2, 1};
	vec3 L= glob* vec3{-1,-1,1};
	vec3 R= glob* vec3{1,-1,1};
	


}
