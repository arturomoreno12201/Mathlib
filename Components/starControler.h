#pragma once
#include "star.h"

#include "transform.h"
class StarControler 
{

public:
	  
	Transform* act;

	unsigned CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_SWITCH, CTR_BREAK;

	StarControler(unsigned CTR_LEFT = 'A', unsigned CTR_RIGHT = 'D',
		unsigned CTR_UP = 'W', unsigned CTR_DOWN = 'S',
		unsigned CTR_BREAK = ' ');

	void update(Star &loco);
	
};