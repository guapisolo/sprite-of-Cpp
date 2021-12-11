#include "aEnemy.h"

int Enemywidth = 100, Enemyheight = 100;

aEnemy::aEnemy(int score1):cBase()
{
	width = Enemywidth, height = Enemyheight;
	score = score1;
	img = &IMG[iaEnemy];
	//x = rand() % (r.width - width), y = rand() % (r.height - height);
	RandOnBorder();
	dx = rand() % 5 + 1, dy = rand() % 5 + 1;
}
aEnemy::aEnemy(int x1, int y1, int dx1, int dy1, int score1):cBase(x,y,dx,dy)
{
	width = Enemywidth, height = Enemyheight;
	x = x1, y = y1, dx = dx1, dy = dy1, score = score1;
}
aEnemy::aEnemy(aEnemy &sprite):cBase(sprite)
{
	score = sprite.score;
}

aEnemy::~aEnemy()
{

}
void aEnemy::move(rect r1)
{
	//���ھ�ת
	if (x<0 || x>(r.width - width)) dx *= -1;
	if (y<0 || y>(r.height - height)) dy *= -1;
	x += dx;
	y += dy;
}