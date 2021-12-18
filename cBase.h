//#ifndef cBase_h
//#define cBase_h

#pragma once
#include "head.h"

class cBase
{
public:
	int x, y;
	int dx, dy;
	rect r; // 限制的活动范围
	int width, height;
	int hitpoint, attack;
	ACL_Image *img,*img1;
	int swapimage;
public:
	//构造&析构函数
	cBase();
	cBase(int x, int y, int dx, int dy);
	//cBase(int x, int y, int dx, int dy, rect r1);
	cBase(cBase & cBase);
	virtual ~cBase();

	//随机位置生成器
	int RandOnBorder();
	//移动函数
	virtual int move(rect r)=0;
	//按指定大小绘图
	void drawSprite(int w, int h);
	//默认比例绘图
	void drawSprite();
	rect getRect();

	int collision(cBase* a);
};

//#endif
