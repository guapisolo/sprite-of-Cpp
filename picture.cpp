#include "head.h"

ACL_Image IMG[35];

void Initpicture()
{
	//loadImage("dog.bmp", &img);
	loadImage("dog.bmp", &IMG[icBase]);
	loadImage("jerry.bmp", &IMG[iaEnemy]);
	loadImage("duck.jpg", &IMG[iaThief]);
	loadImage("tom.bmp", &IMG[ibBoy]);
}
