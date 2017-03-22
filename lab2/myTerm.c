#include "myTerm.h"


int mt_clrscr (void) { //Очистка экрана и перенос указателя в левый верхний угол
    
	write(1, "\E[H\E[J", strlen("\E[H\E[J"));
	return 0;

}

int mt_gotoXY (int x, int y) { //Перенос указателя на расположение x и y
	
	char buffer[20];
	sprintf(buffer, "\E[0%d;%dH", x, y);
	write(1, buffer, strlen(buffer));
	return 0;
	
}

int mt_getscreensize (int * rows , int * cols) { //Размер консоли 
	
	struct winsize {
		unsigned short size_rows;
		unsigned short size_cols;
		unsigned short size_pix_x;
		unsigned short size_pix_y;
	} size;
	if (!ioctl(1, TIOCGWINSZ, &size)) {
		*rows = size.size_rows;
		*cols = size.size_cols;
		return 0;
	}
	else 
		return -1;
	
}


int mt_setfgcolor (enum colors color) { // цвет текста 
	
	if ((int)color < 0 || (int)color > 7)
		return -1;
	char buffer[8];
	sprintf(buffer, "\E[3%dm", (int)color);
	write(1, buffer, strlen(buffer));
	return 0;
}



int mt_setbgcolor (enum colors color) { // цвет фона
	
	if ((int)color < 0 || (int)color > 7)
		return -1;
	char buffer[8];
	sprintf(buffer, "\E[4%dm", (int)color);
	write(1, buffer, strlen(buffer));
	return 0;
}
