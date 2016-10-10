#include "starControler.h"
#include "sfwdraw.h"



StarControler::StarControler(unsigned a_CTR_LEFT, unsigned a_CTR_RIGHT, unsigned a_CTR_UP, unsigned a_CTR_DOWN, unsigned a_CTR_BREAK)
{

	CTR_LEFT = a_CTR_LEFT;
	CTR_RIGHT = a_CTR_RIGHT;
	CTR_UP = a_CTR_UP;
	CTR_DOWN = a_CTR_DOWN;
	CTR_BREAK = a_CTR_BREAK;

}

void StarControler::update(Star & loco)
{

	float hInput = 0.0f;
	hInput -= sfw::getKey(CTR_LEFT);
	hInput += sfw::getKey(CTR_RIGHT);

	float vInput = 0.0f;
	vInput -= sfw::getKey(CTR_DOWN);
	vInput += sfw::getKey(CTR_UP);

	loco.doTurn(hInput);
	loco.doThrust(vInput);

}
