//#ifndef aEnemy_h
//#define aEnemy_h

#pragma once
#include "cBase.h"

//extern int Enemywidth, Enemyheight;

class aEnemy : public cBase
{
public:
	int score;
	aEnemy(int score1);
	aEnemy(int x, int y, int dx, int dy, int score);
	//aEnemy(int x, int y, int dx, int dy, rect r1, int score, int width);
	aEnemy(aEnemy &sprite);
	~aEnemy();

	virtual int move(rect r);
};

//#endif
