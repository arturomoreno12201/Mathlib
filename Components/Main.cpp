#include "sfwdraw.h"
#include "Vect_2.h"
#include "Transform.h"
#include "fallower.h"

using namespace sfw;

void main()
{
	initContext();
	Transform trans(400, 300);
	Fallower fall (300,200);

	int j = int(4);
	int k(4);
	int l = { 4 };
	int n{4};
	//trans.position = vec2{ 400,300 };
	trans.facing = 0;
	trans.scale = vec2{ 28,8 };
	fall.facing = 0;
	fall.scale = vec2{28,8};


	while (stepContext())
	{
		
		trans.facing += getDeltaTime();
		trans.debugDraw();
		trans.update();

		fall.facing += getDeltaTime();
		fall.debugDraw();
		fall.update(trans);
	}


	termContext();
}