#include "head.h"

const double sq2 = sqrt(2);
int task = 0;

int rrand() 
{
	return (rand() << 15) | rand();
}
int transpos(int c)
{
	switch (c)
	{
	case 'A': return VK_LEFT;
	case 'W': return VK_UP;
	case 'D': return VK_RIGHT;
	case 'S': return VK_DOWN;
	}
	return c;
}