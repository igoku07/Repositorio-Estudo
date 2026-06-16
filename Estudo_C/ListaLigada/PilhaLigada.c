#include <stdio.h>
#include <stdlib.h>
#define fasntasma -1

typedef struct Celula
{
    struct Celula *next;
    int Item;
}Celula;

typedef Celula *Pilha; //TODO TIPO PILHA E UM PONTEIRO


Pilha criarPilha();
void mostrarPilha(Pilha );
Pilha inserirPilha(Pilha,int);
Pilha removerPilha(Pilha);

main()
{
    Pilha C;
    C = criarPilha();
    mostrarPilha(C);
    C = inserirPilha(C,10);
    C = inserirPilha(C,5);
    C = inserirPilha(C,6);
    C = inserirPilha(C,7);
    C = inserirPilha(C,8);
    mostrarPilha(C);
    C = removerPilha(C);
    mostrarPilha(C);
    C = removerPilha(C);
    C = removerPilha(C);
    C = removerPilha(C);
    mostrarPilha(C);
    C = removerPilha(C);
        
	mostrarPilha(C);
}

Pilha removerPilha(Pilha P) //equivalente a remocao do topo
{
	//nao posso remover se a fila ta vazia
	Celula *Ap;
	Ap = P;
	if(Ap != NULL)
	{
		P = Ap->next;
		free(Ap);
	}
	return P;
}


Pilha inserirPilha(Pilha P,int coisa) //equivalente a inserecao no inicio
{
    //numa pilha o primeiro que entra o primeiro que sai
    Celula *Ap;
    Ap = malloc(sizeof(Celula));
    
    Ap ->Item = coisa;
    Ap -> next = P;

    P = Ap;
	return P;
}


Pilha criarPilha() // criacao de uma pilha vazia
{
    Pilha P;
    P = NULL;
    return P;
}

void mostrarPilha(Pilha P)
{
    Celula *Ap; //meu cursor
    
    Ap = P;
    if(Ap != NULL) //pilha nao pode ser vazia 
    {
        printf("\n|---| topo \n");
        do
        {
            printf("|%d \n",Ap->Item);
            Ap = Ap->next;

        }while(Ap != NULL);
        printf("|---|\n");
    }
    else
	{
		printf("\n LISTA VAZIA \n");
	}

}
