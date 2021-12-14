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
	startTimer(0, 40); //每40ms移动一次
	startTimer(1, 1000); //每1000ms生成一个怪物
	return 0;
}

void updatemap()
{
	for (int i = 0; i < nowNum; ++i)
	{
		if (enemy[i])
		{
			if (usr->collision(enemy[i]))
			{
				usr->score += enemy[i]->score;
				usr->hitpoint -= enemy[i]->attack;
				delete(enemy[i]);
				enemy[i] = NULL;
			}
		}
	}
}
void timerEvent(int id)
{
	int i = 0;
	switch (id)
	{
	case 0:
		for (i = 0; i < nowNum; ++i)
			if (enemy[i])
			{
				rect ur = usr->getRect();
				enemy[i]->move(ur);
			}
		updatemap();
		break;
	case 1:
		if (nowNum < maxNum)
		{
			createData(enemy);
		}
		break;
	}//end switch
	paint();
}
void createData(aEnemy **enemy)
{
	int t = rrand() % 100;
	//winRect：窗口界面
	if (t < 80)
		enemy[nowNum++] = new aEnemy(rrand() % 3 + 1);
	else 
		enemy[nowNum++] = new aThief(10);
}
void createData(bBoy **usr)
{
	*usr = new bBoy();
}
void paint()
{
	beginPaint();
	clearDevice();
	int i = 0;
	for (i = 0; i < nowNum; ++i)
	{
		if (enemy[i])
		{
			enemy[i]->drawSprite();
		}
	}
	if (usr)
	{
		usr->drawSprite();
		char txt[10];
		sprintf_s(txt, "Score:%d", usr->score);
		setTextSize(20);
		paintText(10, 10, txt);
		paintText(10, 30, txt);
	}
	endPaint();
}
void keyEvent(int key, int event)
{
	if (event != KEY_DOWN)return;
	if(usr)usr->move(key);
	updatemap();
	paint();
}