#include "Rigidbody.h"
#include "Transform.h"
#include "sfwdraw.h"
#include "Vect_2.h"
#include "FLOPS.h"
#include "star.h"
#include "starControler.h"
#include "fallower.h"
#include <vector>
#include "planet.h"
#include "PlanetREN.h"
#include "PlayerREN.h"
#include "ShapeDraw.h"


using namespace std;
using namespace sfw;

void main()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	float steps = 100;

	vec2 start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0, 1100 };

	//Fallower fallow;
	/*vec2 WP[] = { { 12,-8 },{ 15,8 },{ 5,8 },{ -22, 5 },{ 4, -2 },{ -6,9 },{ 18,88 },{ -22,-90 } };
	mat3 RES = translate(12, -8) * rotate(80);

	for (int i = 0; i < 8; ++i)
	{
		vec2 bet = WP[i + 9] - WP[i];

		mat3 R = rotate(angle(bet) - angle(RES[0].xy));
		mat3 T = translate(magnitude(bet), 0);
	}*/



	//Transform sunT;
	//Transform playerTransform(200, 200);
	//*Transform st1(-50,-20);
	//Transform st2(40,50);
	//Transform st3(80, 100);
	//st1.m_parent = &playerTransform;
	//st2.m_parent = &st1;
	//st3.m_parent = &st2;*/
	//

	//Rigidbody playerRigidbody;

	//StarControler playerCtrl;
	//Star playerLoco;

	
	//
	///*sunT.m_position = vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	//Rigidbody sunR;
	//Planet moe;
	//moe.m_rotationSpeed = 5;


	//Transform APlanet(400,400);
	//APlanet.m_position = vec2{100,0};
	//APlanet.m_parent = &sunT;

	//Rigidbody sunR1;
	//Planet moe1;
	//moe1.m_rotationSpeed = 5;*/

	

	Transform playerTransform(200, 200);
	Rigidbody playerRigidbody;
	StarControler playerCtrl;
	Star playerLoco;
	Player pREN;

	// Sun
	Transform sunTransform;
	sunTransform.m_position = vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	Rigidbody sunRbody;
	Planet sunMotor;
	sunMotor.m_rotationSpeed = 5;
	PlanetRender sunRenderer(YELLOW, 100);

	// Planet
	Transform plan1;
	plan1.m_position = vec2{ 150, 0 };
	plan1.m_parent = &sunTransform;
	Rigidbody plan1RB;
	Planet  plan1motor;
	plan1motor.m_rotationSpeed = 7;
	PlanetRender plan1renderer(GREEN, 20);

	// Moon
	Transform moon1;
	moon1.m_position = vec2{ 50, 0 };
	moon1.m_parent = &plan1;
	Rigidbody moon1RB;
	Planet  moon1motor;
	moon1motor.m_rotationSpeed = 12;
	PlanetRender moon1renderer(WHITE, 7);


	Transform cameraTransform;
	
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		// Wrap the player's position within the screen bounds
		/*if (playerTransform.m_position.x > SCREEN_WIDTH)
			playerTransform.m_position.x = 0.0f;
		else if (playerTransform.m_position.x < 0.0f)
			playerTransform.m_position.x = SCREEN_WIDTH;

		if (playerTransform.m_position.y > SCREEN_HEIGHT)
			playerTransform.m_position.y = 0.0f;
		else if (playerTransform.m_position.y < 0.0f)
			playerTransform.m_position.y = SCREEN_HEIGHT;
*/
		// Apply rigidbody forces
		//fallow.update(playerTransform);
		/*playerCtrl.update(playerLoco, playerCtrl.act);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);
*/
		// Draw the player
		//playerTransform.debugDraw();
	//	playerRigidbody.debugDraw(playerTransform);
		//playerCtrl.debugDraw(playerLoco, &playerTransform);

		/*moe.update(sunR);
		sunR.integrate(sunT, deltaTime);
		sunT.debugDraw();
		
		APlanet.debugDraw();
		APlanet1.debugDraw();*/

		//fallow.debugDraw();
		/*st1.debugDraw(deltaTime);
		st2.debugDraw(deltaTime);
		st3.debugDraw();*/

	

		// Apply rigidbody forces
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

		// Draw the player

		// Update Logic
		sunMotor.update(sunRbody);
		plan1motor.update(plan1RB);
		moon1motor.update(moon1RB);

		moon1RB.integrate(moon1, deltaTime);
		plan1RB.integrate(plan1, deltaTime);
		sunRbody.integrate(sunTransform, deltaTime);

		// Drawing
		//sunRenderer.draw(sunTransform);
		//plan1renderer.draw(plan1);
		//moon1renderer.draw(moon1);

		// Use a lerp to chase the player's ship
		cameraTransform.m_position
			= lerp(cameraTransform.m_position,
				playerTransform.getGlobalPosition(),
				sfw::getDeltaTime() * 10);
		//cameraTransform.m_position = playerTransform.getGlobalPosition();

		// translation is the position of the camera ON THE SCREEN
		// the scale describes the zoom
		mat3 proj = translate(600, 600) * scale(2, 2);
		mat3 view = inverse(cameraTransform.getGlobalTransform());

		mat3 camera = proj * view;


		playerTransform.debugDraw(camera);
		sunTransform.debugDraw(camera);
		plan1.debugDraw(camera);
		moon1.debugDraw(camera);
		cameraTransform.debugDraw(camera);

		playerRigidbody.debugDraw(camera, playerTransform);

		sunRenderer.draw(camera, sunTransform);
		plan1renderer.draw(camera, plan1);
		moon1renderer.draw(camera, moon1);

		pREN.draw(camera, playerTransform);


		//drawAABB(AABB{ 0,0,1200,1200 }, 0x888888FF);

	}
	sfw::termContext();
}