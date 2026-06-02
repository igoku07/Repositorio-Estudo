#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#define Fantasma 0 //DEPENDE DO TIPO DA LISTA E COMO ELA ABRANGE



typedef struct  Celula
{
    int Item;
    struct Celula *next;
    struct Celula *ante;
}Celula;


typedef struct{
    Celula *inicio;
    Celula *fim;
    int Qtd;
}Lista;

/*
    TESTES PARA UMA LISTA DUPLAMENTE LIGADA,
    SEGUINDO A MESMA IDEIA DAS ANTERIORES

*/


// INTERFACE DOS MEUS METODOS 

Lista criarListaVazia(); //criacao de lsita vazia

Lista mostrarListaDoInicio(Lista); //mostro a lista inteira
Lista mostrarListaDoFim(Lista);

Lista inserirNoInicio(Lista,int);

int main()
{
    Lista B;

    B = criarListaVazia();

    mostrarListaDoInicio(B);

    B = inserirNoInicio(B,10);
	B =	inserirNoInicio(B,5);
	B =	inserirNoInicio(B,7);
	B =	inserirNoInicio(B,0);
	
    mostrarListaDoInicio(B);
	
	mostrarListaDoFim(B);
    
	B =	inserirNoInicio(B,67);
	
	mostrarListaDoFim(B);
	
	mostrarListaDoInicio(B);
	
	return 0;
}

Lista criarListaVazia()
{
    Lista A;
    A.inicio = NULL;
    A.fim = NULL;
    A.Qtd = 0;
    return A;
}

Lista mostrarListaDoInicio(Lista A)
{
    Celula *Ap; //meu cursor
    Ap = A.inicio; //recebo minha Localizacao

    //Se nao está vazia procuro 
    if(Ap != NULL)
    {   
    	printf("\n [ ");
        do
        {
            //primeiro vou ir buscando até acabar
            printf(" %d ", Ap -> Item);
            Ap = Ap -> next;

        }while(Ap != NULL);
        	printf(" ] \n");
    }
    else
    {
        printf("\n Lista Vazia \n");
    }
}

Lista mostrarListaDoFim(Lista A)
{
    Celula *Ap; //meu cursor
    Ap = A.fim; //recebo minha Localizacao
	
	
    //Se nao está vazia procuro 
    if(Ap != NULL)
    {   
    	printf("\n [ ");
        do
        {	
            //primeiro vou ir buscando até acabar
            printf(" %d ", Ap -> Item);
            Ap = Ap -> ante;

        }while(Ap != NULL); //mantenho porque o anterior do primeiro é null
    		printf(" ] \n");
	}
    else
    {
        printf("Lista Vazia \n");
    }

}

Lista inserirNoInicio(Lista A,int item) //creio que ta certo 
{
    Celula *Nova;
    Celula *Ap; //cursor
    
    Nova = malloc(sizeof(Celula));
    
    //criei a celula, faço a primeira operação

    Nova -> Item = item;

    Nova -> next = A.inicio;
    Nova -> ante = NULL;

    //mas e o anterior? faz oque?

    //se tem segundo, é porque tem outra coisa na lista 
    if(A.inicio != NULL)
    {
        //se tem outra coisa na lista eu preciso pegar o anterior dele 
        Ap = A.inicio;
        Ap -> ante = Nova;
        //aqui eu setei que a minha outra Celula pega meu anterior (NOVO COMEÇO)
    }
    else
	{
		A.fim = Nova;
	}

    A.inicio = Nova;

    A.Qtd++;

	return A;
}
