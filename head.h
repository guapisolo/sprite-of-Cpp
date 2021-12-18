//#pragma once

#pragma once
#include "acllib.h"
#include "picture.h"
#include <bits/stdc++.h>  

extern const double sq2;
extern const int winWidth, winHeight;
extern int attackable;
extern rect winRect;
int RandOnBorder(rect& r, int& x, int& y,int w,int h);
int rrand();
int transpos(int c);
