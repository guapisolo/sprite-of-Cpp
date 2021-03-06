#include "cBase.h"

cBase::cBase()
{
	x = 0, y = 0; dx = 0, dy = 0;
	r = winRect; width = 0, height = 0;
	hitpoint = 10, attack = 0;
	img = img1 = NULL; swapimage = 0;
}
cBase::cBase(int X, int Y, int Dx, int Dy)
{
	x = X, y = Y; dx = Dx, dy = Dy;
	r = winRect; width = 0, height = 0;
	hitpoint = 10, attack = 0;
	img = img1 = NULL; swapimage = 0;
}
cBase::cBase(cBase & sprite)
{
	x = sprite.x;
	y = sprite.y;
	width = sprite.width;
	height = sprite.height;
	dx = sprite.dx;
	dy = sprite.dy;
	img = sprite.img;
	r = sprite.r;
	hitpoint = sprite.hitpoint;
	attack = sprite.attack;
}
cBase::~cBase()
{

}


void cBase::drawSprite(int w, int h)
{
	putImageScale(img, x, y, w, h);
}
void cBase::drawSprite()
{
	putImageScale(img, x, y, width, height);
}
rect cBase::getRect()
{
	rect r = { x, y, width, height };
	return r;
}

int cBase::RandOnBorder()
{
	int t = rrand() % 4;
	switch (t)
	{
	case 0: //up
		x = rrand() % (r.width - width);
		y = r.height - height;
		break;
	case 1: //down
		x = rrand() % (r.width - width);
		y = 0;
		break;
	case 2: //left
		x = 0;
		y = rrand() % (r.height - height);
		break;
	case 3: //right
		x = r.width - width;
		y = rrand() % (r.height - height);
		break;
	}
	return t;
}

//??ײ?¼?
int cBase::collision(cBase* a)
{
	rect r1 = { x,y,width,height };
	rect r2 = { a->x,a->y,a->width,a->height };
	int c = 1;
	if ((r1.x < r2.x && r1.x + r1.width >r2.x) || (r1.x > r2.x && r2.x + r2.width > r1.x)) {
		if ((r1.y > r2.y && r1.y < r2.y + r2.height) || (r1.y < r2.y && r1.y + r1.height >r2.y)) return c;
	}
	c = 0;
	return c;
}