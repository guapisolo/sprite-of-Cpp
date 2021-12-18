#include "cBase.h"

cBase::cBase()
{
	this->x = 0;
	this->y = 0;
	this->dx = 0;
	this->dy = 0;
	r = winRect;
	this->width = 0;
	this->height = 0;
	this->img = NULL;
	this->hitpoint = 10;
	this->attack = 0;
}
cBase::cBase(int x, int y, int dx, int dy)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	r = winRect;
	this->width = 0;
	this->height = 0;
	this->img = NULL;
	this->hitpoint = 10;
	this->attack = 0;
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

//Åö×²ÊÂ¼ş
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