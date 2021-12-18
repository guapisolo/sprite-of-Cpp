#include "cBullet.h"


namespace Bullet {
	const int maxNum = 5000;
	int nowNum = 0;
};
cBullet* bullet[Bullet::maxNum + 5] = { 0 };

cBullet::cBullet(bBoy& Master, int Type) : bBoy()
{
	type = Type;
	hitpoint = 1, attack = 10; master = &Master;
	img = &IMG[icBullet + type];
	switch (type) {
	case 0: //left
		height = 16, width = 30; 
		dx = -10, dy = 0;
		x = master->x;
		y = (master->y + master->height / 2 - height / 2);
		break;
	case 1: //up
		height = 30, width = 16;
		dx = 0, dy = -10;
		y = master->y;
		x = (master->x + master->width / 2 - width / 2);
		break;
	case 2: //right
		height = 16, width = 30;
		dx = 10, dy = 0;
		x = master->x + width;
		y = (master->y + master->height / 2 - height / 2);
		break;
	case 3: //down
		height = 30, width = 16;
		dx = 0, dy = 10;
		y = master->y + height;
		x = (master->x + master->width / 2 - width / 2);
		break;
	}
}
int cBullet::move()
{
	x += dx, y += dy;
	if (x<0 || x>r.width - width || y<0 || y>r.height + height) return 1;
	return 0;
}
cBullet::~cBullet()
{
	
}

//Åö×²ÊÂ¼þ
//int cBullet::collision(aEnemy* a)
//{
//	rect r1 = { x,y,width,height };
//	rect r2 = { a->x,a->y,a->width,a->height };
//	int c = 1;
//	if ((r1.x < r2.x && r1.x + r1.width >r2.x) || (r1.x > r2.x && r2.x + r2.width > r1.x)) {
//		if ((r1.y > r2.y && r1.y < r2.y + r2.height) || (r1.y < r2.y && r1.y + r1.height >r2.y)) return c;
//	}
//	c = 0;
//	return c;
//}