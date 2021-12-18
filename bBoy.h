//#ifndef bBoy_h
//#define bBoy_h

#pragma once
#include "cBase.h"

extern int Boywidth, Boyheight;
class bBoy :
	public cBase
{
public:
	int score, level, mov[4];
	bBoy();
	bBoy(bBoy& sprite);
	~bBoy();

//	void move(int x,int y);
	virtual void operate(int key, int event);
	virtual int move();
	virtual int move(rect r);
	virtual void updatelevel();

	//int collision(cBase*);
};

//#endif
