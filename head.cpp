#include "head.h"

int rrand() 
{
	return (rand() << 15) + rand();
}
