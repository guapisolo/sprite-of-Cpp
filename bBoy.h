//#ifndef bBoy_h
//#define bBoy_h

#pragma once
#include "cBase.h"

extern int Boywidth, Boyheight;
class bBoy :
	public cBase
{
public:
	int score;
	bBoy();
	bBoy(bBoy &sprite);
	~bBoy();

//	void move(int x,int y);
	void move(int key);
	void move(rect r);

	int collision(cBase*);
};

//#endif
