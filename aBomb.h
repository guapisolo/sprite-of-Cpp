#pragma once
#pragma once
#include "aEnemy.h"

//extern int Thiefwidth, Thiefheight;
class aBomb : public aEnemy
{
public:
	int resttime, cwalltime;
	bool boom;
	~aBomb();
	aBomb(int score1);
	void explode();
	virtual int move(rect ur);
};
