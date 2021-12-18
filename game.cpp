#include "game.h"

rect winRect;
void timerEvent(int id);
void createData(aEnemy **enemy);
void createData(bBoy **usr);
void keyEvent(int key, int event);
void paint();

int nowNum = 0;
const int maxNum = 1000;
int tasknum[4] = { 60,100,150,1000 };
const int winWidth = 1200, winHeight = 700;
aEnemy* enemy[maxNum+5] = { 0 };
bBoy* usr = NULL;

void InitWindow()
{
	winRect.x = DEFAULT;
	winRect.y = DEFAULT;
	winRect.width = winWidth;
	winRect.height = winHeight;
	initWindow("auto sprite", DEFAULT, DEFAULT, winWidth, winHeight);
}

int Setup()
{
	srand((unsigned)time(NULL));
	InitWindow();
	Initpicture();
	createData(&usr);  //创建玩家
	registerTimerEvent(timerEvent); 
	registerKeyboardEvent(keyEvent);
	startTimer(0, 30); //每30ms移动一次
	startTimer(1, 300); //每300ms生成一个怪物
	return 0;
}

void updatemap()
{
	bBoy* tusr;
	for (int i = 0; i < Bullet::nowNum; i++) if(bullet[i])
	{
		int flag = 0;
		for (int j = 0;j < nowNum;j++) if(enemy[j]){
			if (bullet[i]->collision(enemy[j]))
			{
				if (enemy[j]->hitpoint > bullet[i]->attack) {
					enemy[j]->hitpoint -= bullet[i]->attack;
					flag = 1;
					break;
				}
				tusr = bullet[i]->master;
				tusr->score += enemy[j]->score;
				//tusr->hitpoint -= enemy[j]->attack;
				delete(enemy[j]); enemy[j] = NULL;
				flag = 1;
				break;
			}
		}
		if (flag) { delete(bullet[i]); bullet[i] = NULL;  }
	}
	for (int i = 0; i < nowNum; i++)
	{
		if (enemy[i])
		{
			if (usr->collision(enemy[i]))
			{
				usr->score += enemy[i]->score;
				usr->hitpoint -= enemy[i]->attack;
				delete(enemy[i]); enemy[i] = NULL;
			}
		}
	}
	usr->move();
}
void nextgeneration()
{
	if (task == 4) {
		static bool gamepassprint = 0;
		if (gamepassprint) return;
		gamepassprint = 1;
		char gamepasstxt[50];
		sprintf_s(gamepasstxt, "You Win!!!\n Thank for your time. \n Your score is %d", usr->score);
		MessageBoxA(NULL, gamepasstxt, "spirit game", MB_ICONERROR);
		exit(0);
		return;
	}
	for (int i = 0;i < Bullet::nowNum;i++) {
		if (bullet[i]) {
			delete(bullet[i]);
			bullet[i] = NULL;
		}
	}
	Bullet::nowNum = 0;
	usr->clear();
	nowNum = 0;
}
void checkmap()
{
	if (nowNum < tasknum[task]-1) return;
	int flag = 1;
	for (int i = 0; i < nowNum; i++)
	{
		if (enemy[i]) { flag = 0; break; }
	}
	if (flag) task++, nextgeneration();
}

void timerEvent(int id)
{
	int i = 0;
	switch (id)
	{
	case 0:
		for (i = 0; i < nowNum; i++)
			if (enemy[i])
			{
				rect ur = usr->getRect();
				int moveflag = enemy[i]->move(ur);
				if (moveflag) delete(enemy[i]), enemy[i] = NULL;
			}
		for(int i=0;i<Bullet::nowNum;i++)
			if (bullet[i])
			{
				bullet[i]->move();
			}
		usr->updatelevel();
		updatemap();
		checkmap();
		break;
	case 1:
		if (nowNum < tasknum[task])
		{
			createData(enemy);
		}
		break;
	case 2:
		usr->attackable = 1; break;
	case 3:
		usr->swapimage = 0; break;
	}//end switch
	paint();
	//多线程
	if (usr->hitpoint <= 0) {
		static bool gameoverprint = 0;
		if (gameoverprint) return;
		gameoverprint = 1;
		char gameovertxt[50];
		sprintf_s(gameovertxt, "Game over\n Your score is %d", usr->score);	
		MessageBoxA(NULL, gameovertxt, "spirit game", MB_ICONERROR);
		//PostQuitMessage(0);
		exit(0);
		return;
	}
}
void createData(aEnemy **enemy)
{
	int t = rrand() % 200;
	//winRect：窗口界面
	if (0 <= t && t < 80) enemy[nowNum++] = new aEnemy(rrand() % 3 + 1);
	else if (80 <= t && t < 100) enemy[nowNum++] = new aThief(10);
	else enemy[nowNum++] = new aBomb(0);
}
void createData(bBoy **usr)
{
	//*usr = new bBoy();dd
	*usr = new bWizard();
}
void paint()
{
	beginPaint();
	clearDevice();
	int i = 0;
	for (int i = 0;i < Bullet::nowNum;i++) {
		if (bullet[i])
		{
			bullet[i]->drawSprite();
		}
	}
	for (i = 0; i < nowNum; i++)
	{
		if (enemy[i])
		{
			enemy[i]->drawSprite();
		}
	}
	if (usr)
	{
		usr->drawSprite();
		static char paint_txt[20];
		setTextSize(20);
		sprintf_s(paint_txt, "Score:%d", usr->score);
		paintText(10, 10, paint_txt);
		sprintf_s(paint_txt, "Hitpoint:%d", usr->hitpoint);
		paintText(10, 30, paint_txt);
		sprintf_s(paint_txt, "level:%d", usr->level);
		paintText(10, 50, paint_txt);
	}
	endPaint();
}
void keyEvent(int key, int event)
{
	//if (event != KEY_DOWN) return;
	if(usr) usr->operate(key,event);
	//updatemap();
	//paint();
}