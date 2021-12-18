#include "bWizard.h"

bWizard::bWizard():bBoy()
{
	towards = 0;
}
bWizard::~bWizard()
{

}

void bWizard::operate(int key,int event)
{
	bBoy::operate(key,event);
	key = transpos(key);
	if (event==KEY_DOWN && VK_LEFT <= key && key <= VK_DOWN) 
		towards = key-VK_LEFT;
	if (key == 'J' && attackable) {
		Attack(); attackable = 0; 
		startTimer(2, 400);
	}
}

void bWizard::Attack()
{
	//using namespace Bullet;
	if (Bullet::nowNum < Bullet::maxNum) {
		bullet[++Bullet::nowNum] = new cBullet(*this, towards);
	}
}

