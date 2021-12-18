//#ifndef aThief_h
//#define aThief_h

#pragma once
#include "aEnemy.h"

//extern int Thiefwidth, Thiefheight;
class aThief :
	public aEnemy
{
public:
	int oldx, oldy;
	bool danger(rect ur);
	bool bfirst;
	aThief(int score1);
	aThief(aThief &sprite);
	virtual ~aThief();

	virtual int move(rect ur);
};

//#endif
