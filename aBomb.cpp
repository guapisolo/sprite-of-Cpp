#include "aBomb.h"

//int Bombwidth = 100, Bombheight = 100;

aBomb::aBomb(int score1) : aEnemy(score1)
{
	img = &IMG[iaBomb];
	width = 80 + task * 20, height = 80 + task * 20;
	r.width += width, r.height += height;
	hitpoint = 10 + task * 10, attack = 10 + task * 5;
	resttime = 25; boom = 0; cwalltime = 4 + task * 2;
	RandOnBorder();
	x -= width / 2, y -= height / 2;
	dx = rrand() % (10 + task * 5) + 1, dy = rrand() % (10 + task) + 1;
	if (rrand() % 2 == 0) dx *= -1;
	if (rrand() % 2 == 0) dy *= -1;
}
aBomb::~aBomb()
{

}
void aBomb::explode()
{
	x -= width / 2, y -= height / 2;
	width *= 2, height *= 2;
}
int aBomb::move(rect r1)
{
	if (!boom) {
		x += dx;
		y += dy;
		int t = rand() % 100;
		if (t == 0) boom = 1;
		if (x<-width / 2 || x>(r.width - width / 2) || y<-height / 2 || y>(r.height - height / 2)) {
			if (cwalltime) cwalltime--, dx *= -1, dy *= -1;
			else boom = 1;
		}
	} else {
		if (!resttime) return 1;
		resttime--;
		if (resttime==1) {
			explode();
		}
	}
	return 0;
}

