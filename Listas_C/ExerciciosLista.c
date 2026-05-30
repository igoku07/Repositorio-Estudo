#include <stdio.h>
#define fantasma 0
#define Max 27
#define sinal -1

typedef struct {
int tam;
int Tab[Max];
} ListaP;

ListaP copyLista(ListaP);
// devolver uma cópia da lista 

ListaP clearLista(ListaP);
// esvaziar a lista  

ListaP criarLista(int);
//criar a lista ordenada

void mostrarLista(ListaP);
//adivinha?

ListaP extendLista(ListaP, ListaP);
// acrescentar a 2ª lista no final da 1ª lista

int maximo(ListaP);
// devolver o maior elemento da lista ou zero, 
// se a lista é vazia

ListaP reverse(ListaP); 
// inverter a ordem dos elementos da lista 

int main(){

    //Variaveis para testes
    ListaP P;
    int Tam = 10;

    P = criarLista(Tam);
    mostrarLista(P);
   
    ListaP I;
    I = copyLista(P);
    printf("Copia\n");
    mostrarLista(I);

    //teste Limpar Lista
    /*
    I = clearLista(I);
    printf("Copia vazia\n");
    mostrarLista(I);
    */
    
    I = extendLista(I,P);
    printf("Lista extendida\n");
    mostrarLista(I);
    
    printf("Maior Numero\n");
    maximo(I);

    printf("\nReverse Lista\n");
    //tinha esquecido de atribuir o retorno, animal...
    I = reverse(I);
    mostrarLista(I);

    
}

ListaP reverse(ListaP A){
    int k=1;
    int MAX,aux,aux2;
    MAX = A.tam;

    do{
        aux = A.Tab[k];
        A.Tab[k] = A.Tab[MAX];
        A.Tab[MAX] = aux; 
        MAX--; k++;
            
    }while(MAX > k);
       
    
    return A;
}

/*
int maximo(ListaP A){
    int k,j;
    int max = 0;

    if(A.tam > 0){
        for(k = 1; k <= A.tam; k++){
            if(A.Tab[k] > max){
                max = A.Tab[k];
            }
        }
    }
    printf("%d\n",max);
    return max;
}
*/

int maximo(ListaP A){
    int maior = A.Tab[1];
    int k;
    if(A.tam == 0) maior = 0;
    for(k = 2; k <= A.tam; k++)
    {
        if(A.Tab[k] > maior)
        {
            maior = A.Tab[k];
        }

    }
    printf("%d",maior);
    return maior;
}

ListaP extendLista(ListaP A,ListaP B){
    int fim,qtd,soma;
    
    fim = A.tam;
    
    soma = A.tam + B.tam;
    if(soma > Max - 1) soma = Max - 1;  // proteção

    qtd = 1;
    A.tam = soma;

    for(fim = fim+1 ;fim <= A.tam; fim++){
        A.Tab[fim] = B.Tab[qtd];
        qtd++;
    }

    return A;
}

/*
//finalizado
ListaP copyLista(ListaP B){
    ListaP A; int k;
    A.tam = B.tam;
    
    for(k = 1; k <= A.tam; k++){
        A.Tab[k] = B.Tab[k];
    }
    return A;
}
*/

ListaP copyLista(ListaP A){
	ListaP B;
	B = A;
	return B;
}


//finalizado
ListaP clearLista(ListaP B){
    B.tam = 0;
    return B;
}

ListaP criarLista(int B){
    ListaP A; 
    int k; 
    int nl = 0;

    if ((B > 0) && (B <= Max - 1))  nl = B; else nl = Max - 1;
   
    A.tam = nl;
    
    for(k = 1; k<= A.tam; k++){
        A.Tab[k] = k;
    }
    return A;
}

void mostrarLista(ListaP L){
	int k;

	for(k = 1; k <= L.tam ; k++){
		printf("%d ",L.Tab[k]);
	}
	printf("\n\n");
}
