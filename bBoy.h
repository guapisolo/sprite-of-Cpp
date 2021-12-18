//#ifndef bBoy_h
//#define bBoy_h

#pragma once
#include "cBase.h"

extern int Boywidth, Boyheight;
class bBoy :
	public cBase
{
public:
	int score, level;
	int mov[4];
	int attackable;
	bBoy();
	bBoy(bBoy& sprite);
	~bBoy();

//	void move(int x,int y);
	virtual void operate(int key, int event);
	virtual int move();
	virtual int move(rect r);
	virtual void updatelevel();
	virtual void clear();
	//int collision(cBase*);
};

//#endif
