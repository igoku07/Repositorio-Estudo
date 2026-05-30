#include <stdio.h>
#include <stdlib.h>

//*void malloc(size_t Quantidade de Bytes);
/* é nesse caso que entra o sizeof(int), que calcula a
   a qnt de bytes que um INT utiliza na sua maquina */



int main(){
	int Var;
	int *ptr;
	
	//mesma ideia de ponteiros mas agora, usando Malloc
	// para alocação Dinamica
	
	printf("Quantidade de numeros\n");
	scanf("%d",&Var);
	
	/*	meu ponteiro vai ser oq?
	 	a memoria que eu quero alocar * A qntds de Bytes que eu tenho em um inteiro
		na minha maquina */	
	ptr = (int*) malloc(Var * sizeof(int));
	
	for(int k = 1; k<= Var; k++){
		//qntds de numeros entrando
		printf("Numero %d\n",k);
		scanf("%d",&ptr[k]);
	}
	
	printf("Numeros lidos:\n");
	for(int j=1; j<= Var; j++){
		printf("%d\t",ptr[j]);
	}
	
	
	return 0;	
}
