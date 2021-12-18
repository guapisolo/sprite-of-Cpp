#include "game.h"

//int autoWidth = 100, autoHeight = 100;
//int usrWidth = 100, usrHeight = 100;
rect winRect;
void timerEvent(int id);
void createData(aEnemy **enemy);
void createData(bBoy **usr);
void keyEvent(int key, int event);
void paint();

int nowNum = 0;
const int maxNum = 500;
const int winWidth = 800, winHeight = 600;
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
	createData(enemy); //创造怪物
	createData(&usr);  //创建玩家
	registerTimerEvent(timerEvent); 
	registerKeyboardEvent(keyEvent);
	startTimer(0, 30); //每30ms移动一次
	startTimer(1, 300); //每300ms生成一个怪物
	//startTimer(2, 300);
	return 0;
}

void updatemap()
{
	bBoy* tusr;
	for (int i = 0; i < Bullet::nowNum; i++) if(bullet[i])
	{
		for (int j = 0;j < nowNum;j++) if(enemy[j]){
			if (bullet[i]->collision(enemy[j]))
			{
				tusr = bullet[i]->master;
				tusr->score += enemy[j]->score;
				//tusr->hitpoint -= enemy[j]->attack;
				delete(enemy[j]); enemy[j] = NULL;
				delete(bullet[i]); bullet[i] = NULL;
				break;
			}
		}
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
		break;
	case 1:
		if (nowNum < maxNum)
		{
			createData(enemy);
		}
		break;
	case 2:
		attackable = 1;
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