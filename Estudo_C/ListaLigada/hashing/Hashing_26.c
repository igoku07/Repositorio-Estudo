/* exemplo função hash */
/* Arquivo: Hashing_26.c
   Autor: LISBETE MADSEN BARBOSA
   Data: 22/02/26 11:57
   Descrição - Este programa mostra um exemplo de função hash
*/

#include <stdio.h> 
#include "Booleano.h"
#define AMax 25
#define BMax 18

typedef unsigned int TipoChave;

unsigned char hash1(TipoChave);

int main (){
	int j;
	unsigned char hC;
	TipoChave key;
	
   	TipoChave A[AMax] = {359004,364269,359889,359136,358468,
						 360273,359598,359041,359591,360044,
						 359288,364001,359597,360225,358518,
						 359511,360136,320533,359586,359800,
						 297907,320481,359600,360609,358519};
						
	TipoChave B[BMax] = {347972,360466,363998,359934,319777,
						 321554,358134,362188,359303,325934,
						 324057,359896,359226,320062,325647,
						 359884,358744,359394};			

	printf("\nTurma A");
   	for (j=0;j<AMax; j++){
		key = A[j];
		hC = hash1(key);	
		printf("\n %2d  %7d   %4d ", j+1, key, hC);
	}
    printf("\n");
   	
//	printf("Turma B");
//   	for (j=0;j<BMax; j++){
//		key = B[j];
//		hC = hash1(key);	
//		printf("\n %2d  %7d   %4d ", j+1, key, hC);
//	}
//    printf("\n");
//
//    printf("\n fim");
    return 0;
}

unsigned char hash1(TipoChave K){
	unsigned char hCode;
	hCode = (K % 1000) % 31;
	return hCode;
}

//#define hash1(key) (key % 1000) % 31
