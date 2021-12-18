//#ifndef cBase_h
//#define cBase_h

#pragma once
#include "head.h"

class cBase
{
public:
	int x, y;
	int dx, dy;
	rect r; // ���ƵĻ��Χ
	int width, height;
	int hitpoint, attack;
	ACL_Image *img,*img1;
	int swapimage;
public:
	//����&��������
	cBase();
	cBase(int x, int y, int dx, int dy);
	//cBase(int x, int y, int dx, int dy, rect r1);
	cBase(cBase & cBase);
	virtual ~cBase();

	//���λ��������
	int RandOnBorder();
	//�ƶ�����
	virtual int move(rect r)=0;
	//��ָ����С��ͼ
	void drawSprite(int w, int h);
	//Ĭ�ϱ�����ͼ
	void drawSprite();
	rect getRect();

	int collision(cBase* a);
};

//#endif
