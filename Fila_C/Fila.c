
#include <stdio.h>
#include "Booleano.h"
#define Max 100
#define Fantasma 0
#define sinal -1

typedef struct{
int inicio; //o campo inicio aponta para o primeiro da fila, se fmaxi
int fim; //o campo fim aponta para o último da fila, se maximo for 7, sempre que (6+1)% 7 volta pra 1
int vetor[Max];
} Fila;

// interface
Fila criarFila( ); //cria a fila vazia
// bool FilaVazia(Fila); //devolve TRUE se a fila é vazia, FALSE, caso contrário
// bool FilaCheia(Fila); //devolve TRUE se a fila está cheia, FALSE, caso contrário
int acessarFila(Fila); //devolve o primeiro item da fila
Fila pushFila(Fila, int); //coloca um item no fim da fila
Fila popFila(Fila); //remove o primeiro item da fila
// Fila esvaziaFila(Fila) //esvazia a fila


int main(){

Fila a;

a = criarFila();
printf("%d ",acessarFila(a));

return 0;
}

//criar Fila Vazia - First in First Out
Fila criarFila()
{
    Fila I;
    I.inicio = sinal;
    I.fim = sinal;
    return I;
}

//verifico se a fila é vazia, se for vazia ou nao tiver fila mando o sinal.
//se tiver algo na fina != sinal, mando I.inicio
int acessarFila(Fila I)
{   
    if(I.inicio != sinal) return I.vetor[I.inicio]; 
    else return Fantasma;
}

Fila pushFila(Fila I,int item)
{
    int pfim;
    //pra eu colocar algo na fila, eu verifico se ela é vazia
    if(I.fim == sinal)
    {
        I.vetor[0] = item;
        I.inicio = 0;
        I.fim = 0;
    }
    else if((I.fim + 1 )% Max != I.inicio)
    {
        pfim = (I.fim + 1 )% Max;
        I.vetor[pfim] = item;
        I.fim = (I.fim + 1 )% Max;
    }
    return I;
}

Fila popFila(Fila I)
{
    
    //eu só retiro se tem uma coisa ou mais.
    if(I.inicio == I.fim)
    { //com uma coisa só eu esvazio a fila
         I.inicio = sinal;
         I.fim = sinal;
    } 
    else { // aq é garantido que tem mais de uma coisa, então eu apago um e vou pro proximo
        I.inicio = (I.inicio + 1) % Max;
    }




    return I;
}
