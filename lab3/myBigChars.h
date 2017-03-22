#ifndef __MYSIMPLECOMPUTER
#define __MYSIMPLECOMPUTER

#include '../lab2/myTerm.h'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/ioctl.h>

int bc_printA(char * str);
int bc_box(int x1, int y1, int x2, int y2);
int bc_printbigchar(int [2], int x, int y, enum color, enum color);
int bc_setbigcharpos(int * big, int x, int y, int value);
int bc_getbigcharpos(int * big, int x, int y, int * value);
int bc_bigcharwrite(int fb, int * big, int count);
int bc_bigcharread(int fb, int * big, int need_count, int * count);

#endif 
