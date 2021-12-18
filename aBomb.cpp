#include "aBomb.h"

//int Bombwidth = 100, Bombheight = 100;

aBomb::aBomb(int score1) : aEnemy(score1)
{
	img = &IMG[iaBomb];
	width = 100, height = 100;
	r.width += width, r.height += height;
	hitpoint = 1, attack = 10; 
	resttime = 25; boom = 0; cwalltime = 5;
	RandOnBorder();
	x -= width / 2, y -= height / 2;
	dx = rrand() % 10 + 1, dy = rrand() % 10 + 1;
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

