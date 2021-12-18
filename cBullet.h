#pragma once
#include "bBoy.h"
#include "aEnemy.h"

namespace Bullet {
	extern const int maxNum;
	extern int nowNum;
};

class cBullet : public bBoy {

public:
	bBoy* master; int type;
	cBullet(bBoy& Master, int Type);
	~cBullet();
	virtual int move();
	//virtual int collision(aEnemy* a);
};

extern cBullet* bullet[5005];