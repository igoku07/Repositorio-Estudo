#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define fantasma 0
#define Max 27
#define sinal -1

typedef struct {
int tam;
int Tab[Max];
} ListaP;

ListaP copyLista(ListaP*);
// devolver uma cópia da lista 

void mostrarLista(ListaP*);
//adivinha?

ListaP criarLista(int);
//criar a lista ordenada

void clearLista(ListaP*);
// esvaziar a lista 

void extendLista(ListaP*, ListaP*);
//lista 2 no final da lista 1

int main(){
    int a,b,c;
    ListaP O;
    ListaP *P;

    //alocando memoria para lista no heap
    P = (ListaP*) malloc(sizeof(ListaP)); 
    
    //atribuindo ao conteudo do Ponteiro
    *P = criarLista(12);
     printf("Lita p\n");
    mostrarLista(P);

    //devo chamar o endereço do ponteiro?
    O = copyLista(P);
    printf("\nLita o\n");
    mostrarLista(&O);

    //funciona fodase comentarios
    extendLista(P,&O);
    printf("\nLista extendida\n");
    mostrarLista(P);


}

void extendLista(ListaP *A,ListaP *B){
    //qual ideia aqui
    //segiundo a mesma logica, mas usando ponteiro pra modificar direto a lista
    
    int fim,qtd,soma;
    
    fim = A -> tam;
    soma = fim + B -> tam;

    if(soma > Max - 1) soma = Max - 1;  // proteção

    qtd = 1;
    A -> tam = soma;

    for(fim = fim+1 ;fim <= A -> tam; fim++){
        A -> Tab[fim] = B -> Tab[qtd];
        qtd++;
    }

}

//finalizado
void clearLista(ListaP *ap){
    ap -> tam = 0;
}

//finalizado
ListaP copyLista(ListaP *ap){
    ListaP A;
    int k;
    int vasco = ap -> tam; 
    A.tam = vasco;

    for(k = 1; k <= A.tam; k++){
        A.Tab[k] = ap ->Tab[k];
    }
    return A;
}



//finalizado
void mostrarLista(ListaP *A){
    int k;
    for(k = 1; k <= A ->tam ; k++ ){
        printf("%d ",A -> Tab[k]);
    }
}

//finalizado
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