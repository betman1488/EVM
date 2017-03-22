 
#ifndef __MYSIMPLECOMPUTER
#define __MYSIMPLECOMPUTER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/ioctl.h>

enum colors {
	black  = 0, 
	red    = 1, 
	green  = 2, 
	yellow = 3, 
	blue   = 4, 
	purple = 5, 
	cyan   = 6, 
	white  = 7} color;

int mt_clrscr (void);
int mt_gotoXY (int, int);
int mt_getscreensize (int * rows , int * cols);
int mt_setfgcolor (enum colors);
int mt_setbgcolor (enum colors);

#endif
