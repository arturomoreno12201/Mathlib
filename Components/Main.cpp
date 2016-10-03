#include "sfwdraw.h"
#include "Vect_2.h"
#include "Transform.h"
#include "fallower.h"
#include "FLOPS.h"

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

		for (int i = 0; i < 100; ++i)
		{

			float	x1 = i / 100.f;
			float y1 = linearHalf(x1);

			float	x2 = growfast(x1);
			float y2 = growfast(x2);

			x1 *= 800;
			x2 *= 800;
			y1 *= 800;
			y2 *= 800;

			drawLine(x1,y1,x2,y2);
		}

	}


	termContext();
}