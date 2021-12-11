#include "bBoy.h"

int Boywidth = 100, Boyheight = 100;

bBoy::bBoy():cBase()
{
	img = &IMG[ibBoy];
	width = Boywidth, height = Boyheight;
	x = (r.width - width) / 2, y = (r.height - height) / 2;
	dx = 5, dy = 5;
	hitpoint = 50, attack = 10, score = 0; 
}
bBoy::bBoy(bBoy& sprite) :cBase(sprite)
{
	hitpoint = 50; attack = 10, score = 0;
}
bBoy::~bBoy() {}

/*
void bBoy::move(int xx, int yy)
{
	x = xx;
	y = yy;
	if (x < r.x)x = r.x;
	if (x >(r.x + r.width - width))x = (r.x + r.width - width);
	if (y < r.y)y = r.y;
	if (y >(r.y + r.height - height))y = (r.y + r.height - height);

}
*/

void bBoy::move(rect r1)
{
	x = r1.x;
	y = r1.y;
	if (x < r.x) x = r.x;
	if (x > (r.x + r.width - width)) x = (r.x + r.width - width);
	if (y < r.y) y = r.y;
	if (y > (r.y + r.height - height)) y = (r.y + r.height - height);

}

void bBoy::move(int key)
{
	switch (key)
	{
	case 'W':
	case VK_UP:
		y -= dx;
		if (y < 0) y = 0;
		break;
	case 'S':
	case VK_DOWN:
		y += dy;
		if (y > (r.height - height)) y = (r.height - height);
		break;
	case 'A':
	case VK_LEFT:
		x -= dx;
		if (x < r.x)x = r.x;
		break;
	case 'D':
	case VK_RIGHT:
		x += dx;
		if (x > (r.width - width)) x = (r.width - width);

		break;
	}
}

//Åö×²ÊÂ¼þ
int bBoy::collision(cBase* a)
{
	rect r1 = { x,y,width,height };
	rect r2 = { a->x,a->y,a->width,a->height };
	int c = 1;
	if ( (r1.x < r2.x && r1.x + r1.width >r2.x) || (r1.x > r2.x && r2.x + r2.width > r1.x) ) {
		if ( (r1.y > r2.y && r1.y < r2.y + r2.height) || (r1.y < r2.y && r1.y + r1.height >r2.y) ) return c;
	}
	c = 0;
	return c;
}
