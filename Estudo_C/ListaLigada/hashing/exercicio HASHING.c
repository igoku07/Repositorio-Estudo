/* exercicio HASHING */
/* Arquivo: EXPF26.c
   Autor: LISBETE MADSEN BARBOSA
   Data: 22/02/26 11:57
   Descrição - Exercício adaptado do texto sobre Hash do prof. Paulo Feofiloff
*/

#include <stdio.h> 
#include "Booleano.h"
#define Max 47

typedef unsigned int TipoChave;

unsigned char Hash(TipoChave);

// Deve ser feito Mod por 13

int main (){
	int j,c,k;
	unsigned char hC;
	unsigned char Matriz[Max][2];

	TipoChave key;
	
   	TipoChave A[Max] = {17,21,19,4,26,30,20,22,23,31,
	   					16,66,33,35,54,81,60,38,42,69,
						133,109,121,55,107,82,57,34,47,44,
						148,24,11,49,12,50,75,62,74,89,
						105,108,122,61,37,63,76};
						
	printf("\nLista A\n");
	c=0;
   	for (j=0; j<Max; j++){
		key = A[j];
		printf(" %4d ",key); c++;
		if(c==10) {
			printf("\n"); c = 0; 
		}	
	}
    printf("\n");


	key = 0;
	for(k = 0; k < Max; k++)
	{
		key = A[k]; //pego o valor numerico da chave
		unsigned char indice = Hash(key);
		 //aqui eu monto o indice do array, das chaves, hasheando espalhando
			Matriz[indice][0] = indice;
			Matriz[indice][1] = key;
	}


	for(k = 0; k < Max; k++)
	{

		for(j = 0; j < 2; j++)
		{
			printf("indice %d  key %d \n",Matriz[k][j]);
		}

	}

    printf("\n fim");
    return 0;
}

unsigned char Hash(TipoChave key)
{
	unsigned char indexTabela;
	indexTabela = (key % 13); //ex se for 17 fica 4, ai o indice é 4 do array
	return indexTabela; //chama se hash code

}

