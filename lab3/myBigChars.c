#include 'myBigChars.h'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int bc_printA(char * str) 
{
	
	write(1, "\e(0", 3);
	write(1, str, sizeof(char) * strlen(str));
	write(1, "\e(B", 3);
	return 0;
	
}

int bc_box(int x1, int y1, int x2, int y2) 
{
	
	
	
}
