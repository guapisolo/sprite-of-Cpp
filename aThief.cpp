#pragma once
#include "aThief.h"
#include <math.h>

int Thiefwidth = 100, Thiefheight = 100;
aThief::aThief(int score1) :aEnemy(score1)
{
	img = &IMG[iaThief];
	r.height += height, r.width += width;
	RandOnBorder();
	x -= width / 2, y -= height / 2;
	oldx = dx, oldy = dy;
	bfirst = true;
}
aThief::aThief(aThief& sprite) :aEnemy(sprite)
{
	oldx = dx;
	oldy = dy;
	bfirst = true;
}

aThief::~aThief()
{

}

void aThief::move(rect ur)
{
	if (danger(ur))
	{
		if (x < ur.x) dx = -abs(dx);
		else dx = abs(dx);

		if (y < ur.y) dy = -abs(dy);
		else dy = abs(dy);

		//������
		x += 1.5 * dx;
		y += 1.5 * dy;
	} else
	{
		x += dx;
		y += dy;
	}

	//ʼ�ղ���ʧ,ѭ������
	if ((dx < 0) && (x < -width / 2)) x = r.width - width / 2;
	if ((dx > 0) && (x > (r.width - width / 2))) x = -width / 2;
	if ((dy < 0) && (y < -height / 2)) y = r.height - height / 2;
	if ((dy > 0) && (y > (r.height - height / 2))) y = -height / 2;

}
bool aThief::danger(rect ur)
{
	//С͵�����ĵ�
	int cx = x + width / 2;
	int cy = y + height / 2;
	//������ĵ�
	int ux = ur.x + ur.width / 2;
	int uy = ur.y + ur.height / 2;
	float dist = sqrt((cx - ux) * (cx - ux) + (cy - uy) * (cy - uy));
	if (dist < 150) return true;
	else return false;
}
