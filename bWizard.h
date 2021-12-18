#pragma once
#include "bBoy.h"
#include "cBullet.h"

extern int Wizardwidth, Wizardheight;
class bWizard :
	public bBoy
{
public:
	int towards;
	bWizard();
	~bWizard();

	/*virtual void move(int key);
	virtual int move(rect r);
	virtual void updatelevel();*/

	//virtual void move(int key,int event);
	virtual void operate(int key,int event);
	virtual void Attack();

	//int collision(cBase*);
};