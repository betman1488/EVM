#ifndef __MYSIMPLECOMPUTER
#define __MYSIMPLECOMPUTER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define P 1
#define O 2
#define M 3
#define T 4
#define E 5

#define MEMSIZE 100
#define COMMANDS_COUNT 37 

int operand; 
int command; 
int my_memory[MEMSIZE];
int reg; 

void my_print(); 

int sc_memoryInit (); 
int sc_memorySet (int address, int value); 
int sc_memoryGet (int address, int * value);
int sc_memorySave (char * filename); 
int sc_memoryLoad (char * filename); 


int sc_regInit (); 
int sc_regSet (int my_reg, int value); 
int sc_regGet (int my_reg, int * value); 
int sc_commandEncode (int command, int operand, int * value); 
int sc_commandDecode (int value, int * command, int * operand); 


#endif
