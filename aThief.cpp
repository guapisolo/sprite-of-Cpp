#pragma once
#include "aThief.h"
#include <math.h>

//int Thiefwidth = 100, Thiefheight = 100;
aThief::aThief(int score1) :aEnemy(score1)
{
	width = 60 - task * 5, height = 60 - task * 5;
	dx = rand() % (5+task) + 1, dy = rand() % (5+task) + 1;
	img = &IMG[iaThief];
	r.width += width, r.height += height;
	RandOnBorder();
	x -= width / 2, y -= height / 2;
	oldx = dx, oldy = dy;
	cwalltime = 5;
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

int aThief::move(rect ur)
{
	if (danger(ur))
	{
		if (x < ur.x) dx = -abs(dx);
		else dx = abs(dx);

		if (y < ur.y) dy = -abs(dy);
		else dy = abs(dy);

		//加速润
		x += (1.5+task*0.2) * dx;
		y += (1.5+task*0.2) * dy;
	} else
	{
		x += dx;
		y += dy;
	}


	//始终不消失,循环出现
	if ((dx < 0) && (x < -width / 2)) x = r.width - width / 2, cwalltime--;
	if ((dx > 0) && (x > (r.width - width / 2))) x = -width / 2, cwalltime--;
	if ((dy < 0) && (y < -height / 2)) y = r.height - height / 2, cwalltime--;
	if ((dy > 0) && (y > (r.height - height / 2))) y = -height / 2, cwalltime--;

	if (!cwalltime) return 1;
	return 0;
}
bool aThief::danger(rect ur)
{
	//小偷的中心点
	int cx = x + width / 2;
	int cy = y + height / 2;
	//玩家中心点
	int ux = ur.x + ur.width / 2;
	int uy = ur.y + ur.height / 2;
	float dist = sqrt((cx - ux) * (cx - ux) + (cy - uy) * (cy - uy));
	if (dist < 100+task*50) return true;
	else return false;
}
