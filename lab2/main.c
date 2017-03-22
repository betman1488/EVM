 #include "myTerm.h"
 
 int main() {
	 mt_clrscr();
	 mt_gotoXY(5, 10);
	 int rows, cols;
	 mt_getscreensize(&rows, &cols);
	 mt_setfgcolor(red);
	 mt_setbgcolor(black);
	 printf("Даниил\n");
	 
	 
	 mt_gotoXY(8, 6);
	 mt_getscreensize(&rows, &cols);
	 mt_setfgcolor(green);
	 mt_setbgcolor(white);
	 printf("ИВ-521\n");
	 
	 
	 mt_gotoXY(10, 1);
     printf("\e[0m");
	 return 0;
 }
