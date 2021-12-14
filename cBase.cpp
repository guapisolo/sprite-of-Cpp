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

void cBase::RandOnBorder()
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
}