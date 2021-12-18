#include "bBoy.h"

int Boywidth = 70, Boyheight = 70;

bBoy::bBoy():cBase()
{
	img = &IMG[ibBoy];
	width = Boywidth, height = Boyheight;
	x = (r.width - width) / 2, y = (r.height - height) / 2;
	dx = 5, dy = 5;
	hitpoint = 50, attack = 10, score = 0, level = 0;
	for (int i = 0;i < 4;i++) mov[i] = 0;
}
//bBoy::bBoy(bBoy& sprite) :cBase(sprite)
//{
//	hitpoint = 50; attack = 10, score = 0;
//}
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
void bBoy::updatelevel()
{
	int dlevel = score / 10 - level;
	if (!dlevel) return;
	//width += dlevel * 10, height += dlevel * 10;
	width = Boywidth + pow(dlevel, 0.7) * 10, height = Boyheight + pow(dlevel, 0.7) * 10;
	hitpoint += dlevel * 10;
	dx = 5 + level / 5, dy = 5 + level / 5;
	level = score / 10;
}
int bBoy::move(rect r1)
{
	x = r1.x;
	y = r1.y;
	if (x < r.x) x = r.x;
	if (x > (r.x + r.width - width)) x = (r.x + r.width - width);
	if (y < r.y) y = r.y;
	if (y > (r.y + r.height - height)) y = (r.y + r.height - height);
	return 0;
}

int bBoy::move()
{
	if (mov[0] + mov[1] + mov[2] + mov[3] == 1) {
		if (mov[0]) x -= dx;
		if (mov[1]) y -= dy;
		if (mov[2]) x += dx;
		if (mov[3]) y += dy;
	} else {
		if (mov[0]) x -= ceil(1.0 * dx / sq2);
		if (mov[1]) y -= ceil(1.0 * dy / sq2);
		if (mov[2]) x += ceil(1.0 * dx / sq2);
		if (mov[3]) y += ceil(1.0 * dy / sq2);
	}
	if (x < r.x)x = r.x;
	if (y < 0) y = 0;
	if (x > (r.width - width)) x = (r.width - width);
	if (y > (r.height - height)) y = (r.height - height);
	return 0; 
}
//ÊäÈë²Ù×÷
void bBoy::operate(int key,int event)
{
	if (event == KEY_DOWN) {
		switch (key)
		{
		case 'A':
		case VK_LEFT:
			mov[0] = 1;
			break;
		case 'W':
		case VK_UP:
			mov[1] = 1;
			break;
		case 'D':
		case VK_RIGHT:
			mov[2] = 1;
			break;
		case 'S':
		case VK_DOWN:
			mov[3] = 1;
			break;
		}
	} else {
		switch (key)
		{
		case 'A':
		case VK_LEFT:
			mov[0] = 0;
			break;
		case 'W':
		case VK_UP:
			mov[1] = 0;
			break;
		case 'D':
		case VK_RIGHT:
			mov[2] = 0;
			break;
		case 'S':
		case VK_DOWN:
			mov[3] = 0;
			break;
		}
	}
}

