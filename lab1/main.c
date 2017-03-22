#include "mySimpleComputer.h"

int main(){
	sc_memoryInit(); 
	sc_memorySet(9,3);
	sc_memorySet(5,1);
	sc_memorySet(60,3);
	sc_memorySet(95,21);
	
	int m_get1 = sc_memoryGet(5,&m_get1);
	int m_get2 = sc_memoryGet(99,&m_get2);
	printf("m_get1=%d, m_get2=%d\n\n", m_get1, m_get2);
	
	sc_memorySave("my_memory.bin");
	my_print();
	
	sc_memoryLoad ("my_memory.bin");
	my_print();
	
	sc_regInit(); 
	printf("reg=%d\n",reg);
	
	//sc_regSet(T, 1); 
	//sc_regSet(E, 1);
	//sc_regSet(O, 1);
	//sc_regSet(P, 1);
	//sc_regSet(M, 1);
	printf("reg=%d",reg);
	
	int flg_T = sc_regGet(T, &flg_T); 
	int flg_O = sc_regGet(O, &flg_O); 
		printf("\nflg_T=%d, flg_O=%d\n",flg_T, flg_O); 
			
	int cmd_encode = sc_commandEncode(0x21, 4, &cmd_encode); 
		printf("\ncmd_encode=%d\n",cmd_encode);
	
	int op_decode, cmd_decode;
		sc_commandDecode(cmd_encode, &cmd_decode, &op_decode); 
		printf("\ncmd_decode=%d, op_decode=%d\n\n",cmd_decode, op_decode); 
			
	return 0;	
}
