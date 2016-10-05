#include "starControler.h"
#include "sfwdraw.h"

void StarControler::update(Star & loco)
{

	float hInput = 0.0f;
	hInput -= sfw::getKey('A');
	hInput += sfw::getKey('D');

	float vInput = 0.0f;
	vInput -= sfw::getKey('S');
	vInput += sfw::getKey('W');

	loco.doTurn(hInput);
	loco.doThrust(vInput);

}
