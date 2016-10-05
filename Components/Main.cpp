#include "Rigidbody.h"
#include "Transform.h"
#include "sfwdraw.h"
#include "Vect_2.h"
#include "FLOPS.h"
#include "star.h"
#include "starControler.h"
using namespace sfw;

void main()
{
	float SCREEN_WIDTH = 400, SCREEN_HEIGHT = 400;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	float steps = 100;

	vec2 start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0, 1100 };

	Transform playerTransform(200, 200);
	playerTransform.scale = { 5,5 };

	Rigidbody playerRigidbody;

	StarControler  playerCtrl;
	Star playerLoco;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		// Wrap the player's position within the screen bounds
		if (playerTransform.position.x > SCREEN_WIDTH)
			playerTransform.position.x = 0.0f;
		else if (playerTransform.position.x < 0.0f)
			playerTransform = SCREEN_WIDTH;

		if (playerTransform.position.y > SCREEN_HEIGHT)
			playerTransform.position.y = 0.0f;
		else if (playerTransform.position.y < 0.0f)
			playerTransform.position.y = SCREEN_HEIGHT;

		// Apply rigidbody forces
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

		// Draw the player
		playerTransform.debugDraw();
	}
	sfw::termContext();
}