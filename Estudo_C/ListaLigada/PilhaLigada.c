#include <stdio.h>
#include <stdlib.h>
#define fantasma -1

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

void verificarTopo(Pilha);

Pilha esvaziarPilha(Pilha);

main()
{
    Pilha C;
    C = criarPilha();
    
    //---------------------
    C = inserirPilha(C,10);
    C = inserirPilha(C,5);
    C = inserirPilha(C,6);
    C = inserirPilha(C,7);
    C = inserirPilha(C,8);
    mostrarPilha(C);
        
    //-----------------------
    C = removerPilha(C);
    C = removerPilha(C);
    C = removerPilha(C);
    mostrarPilha(C);
    
    //-----------------------
	verificarTopo(C);
	C = inserirPilha(C,500);
	mostrarPilha(C);
	verificarTopo(C);
	
	//-----------------------
	C = esvaziarPilha(C);
	mostrarPilha(C);

	
}

Pilha esvaziarPilha(Pilha P)
{
	//eu tenho que percorrer e ir esvaziando todos os nos
	Celula *Ap;
	Celula *Aux;
	
	Ap = P;
	if(Ap != NULL) //significa que tem algo na pilha pra esvaziar
	{
		do
		{
			Aux = Ap;
			Ap = Ap->next; //percorro e limpo todos os nos
			free(Aux); //ate encontrar o ultimo
			
		}while(Ap != NULL);
	}
	
	//oque e garantido
	P = NULL;
	return P;
}

void verificarTopo(Pilha P) //esse seria o peek da pilha
{
	Celula *Ap;
	Ap = P;
	if(Ap != NULL) // tem alguma coisa na pilha
	{
		printf("\nAtual Topo:  [ %d ] \n", Ap->Item);
	}
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
        printf("\n|---|\n");
        do
        {
            printf("|%d \n",Ap->Item);
            Ap = Ap->next;

        }while(Ap != NULL);
        printf("|---|\n");
    }
    else
	{
		printf("\n PILHA VAZIA \n");
	}

}
