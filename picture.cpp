#include "head.h"

ACL_Image IMG[150];

void Initpicture()
{
	//loadImage("dog.bmp", &img);
	//loadImage("dog.bmp", &IMG[icBase]);
	loadImage("jerry.bmp", &IMG[iaEnemy]);
	loadImage("duck.jpg", &IMG[iaThief]);
	loadImage("bumb.jpeg", &IMG[iaBomb]);
	loadImage("k1.bmp", &IMG[ibBoy]);
	loadImage("fireball0.bmp", &IMG[icBullet]);
	loadImage("fireball1.bmp", &IMG[icBullet+1]);
	loadImage("fireball2.bmp", &IMG[icBullet+2]);
	loadImage("fireball3.bmp", &IMG[icBullet+3]);


	loadImage("wizardleft0.bmp", &IMG[ibWizard]);
	loadImage("wizardleft1.bmp", &IMG[ibWizard + 1]);
	loadImage("wizardup0.bmp", &IMG[ibWizard + 2]);
	loadImage("wizardup1.bmp", &IMG[ibWizard + 3]);
	loadImage("wizardright0.bmp", &IMG[ibWizard + 4]);
	loadImage("wizardright1.bmp", &IMG[ibWizard + 5]);
	loadImage("wizarddown0.bmp", &IMG[ibWizard + 6]);
	loadImage("wizarddown1.bmp", &IMG[ibWizard + 7]);
	//loadImage("origin1.jpg", &IMG[ibBoy]);
}
