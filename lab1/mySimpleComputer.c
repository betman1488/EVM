#include "mySimpleComputer.h"


int commands[] = { 	
0x10, 0x11, 0x20, 0x21, 0x30, 0x31, 0x32,
0x33, 0x40, 0x41, 0x42, 0x43, 0x51, 0x52,
0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 
0x67, 0x68, 0x69, 0x70, 0x71, 0x72, 0x73, 
0x74, 0x75, 0x76
};

void my_print(){
	int i;
	for(i = 0; i < MEMSIZE; i++){
		if (i != 0 && i % 10 == 0)
			printf("\n");
		printf("%d ", my_memory[i]);
	}
	printf("\n\n");
}

int sc_memoryInit (){
	int i;
	for(i = 0; i < MEMSIZE; i++)
		my_memory[i] = 0;
return 0;
}

int sc_memorySet (int address, int value){
	if(address < 0 || address >= MEMSIZE) {
		sc_regSet(E, 1);
		return -1;
	}
	else 
	my_memory[address] = value;
	return 0;		
}

int sc_memoryGet (int address, int *value){
	if(address < 0 || address >= MEMSIZE){
		sc_regSet(E, 1);
		return -1;
	}
	else  return *value = my_memory[address];	
	//return 0;
}

int sc_memorySave (char *filename){
	FILE *f ;
	f = fopen(filename, "w+b");
	if(f == NULL) {
		sc_regSet(E, 1);
		return -1;
	}
	int i;
	for(i = 0; i < MEMSIZE; i++)
		fwrite(&my_memory[i], sizeof(int), 1, f);
	fclose(f); 
	return 0;
}

int sc_memoryLoad (char * filename){
	FILE *f ;
	f = fopen(filename,"rb");
	if(f == NULL) {
		sc_regSet(E, 1);
		
		return -1;
	}
	int i;
	for(i = 0; i < MEMSIZE; i++)
		fread(my_memory, sizeof(my_memory), 1, f);
	fclose(f);
	return 0;
}

int sc_regInit (){
	reg = 0;
	return 0;
}

int sc_regSet (int my_reg, int value){
	if ((value < 0) || (value > 1))
		return -1;
	
	 if ((my_reg < 0) || (my_reg > 5))
	 		return -1;
	
	if (value == 1)
		reg = reg | (1 << (my_reg - 1)); 
	else 
		reg = reg & (~(1 << (my_reg - 1)));
	return 0;
}

int sc_regGet (int my_reg, int * value){
	if ((my_reg > 0) && (my_reg < 5))
		return	*value = (reg >> (my_reg - 1)) & 0x1;
	else 
		return -1;
//	return 0;
}

int sc_commandEncode (int command, int operand, int * value){
	int i, f = 0;
	
	for (i = 0; i < COMMANDS_COUNT; ++i)
		if (commands[i] == command)	{
			f = 1;
			break;
		}

	if (f) {
		sc_regSet(E, 0); 
		return *value = (command & 0x7F) << 7 | (operand & 0x7F);
	//	return 0;
	}

	sc_regSet(E, 1); 
	return -1;
}

int sc_commandDecode (int value, int * command, int * operand){
	if (!value || value >> 14 || !command || !operand) {
		sc_regSet(E, 1); 
		return -1;
	}

	*operand = value & 0x7F;
	*command = (value >> 7) & 0x7F;
	return 0;
}
