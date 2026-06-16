
#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"

//implementacao de uma Lista Ligada com cabeca 

typedef struct Celula
{
    int item;
    struct Celula *next;

}Celula;

typedef struct
{
    int tam;
    Celula *inicio;

}Lista;

Lista criarLista(); //feito 
boo verificarListaVazia(Lista); //feito 
Lista inserirInicio(Lista,int); //feito 
void mostrarLista(Lista); //feito
Lista esvaziarLista(Lista); //tive q pensar um pouco, feito
void buscaRemove(Lista *,int); //quero modificar direto a Lista

main()
{
	Lista A;
	A = criarLista();
	mostrarLista(A);
	

	A = inserirInicio(A,10);
	A = inserirInicio(A,5);
	A = inserirInicio(A,12);
	mostrarLista(A);
	
	A = esvaziarLista(A);
	mostrarLista(A);
}

void buscaRemove(Lista *A,int y)
{
	Celula *Ap;
	Celula *Aux;
	
	Ap = A->inicio;
	Aux = NULL;
		
	while(Ap != NULL) //equanto nao ta vazia
	{
	    if(Ap->item == y) //se eu achei
	    {
	        if(Aux == NULL) //se e unico item da lista
	            A->inicio = Ap->next;
	        else //se nao e unico item
	            Aux->next = Ap->next;
	
	        free(Ap);
	        A->tam--;
	        return;
	    }
	
	    Aux = Ap;
	    Ap = Ap->next;
	}
}

Lista esvaziarLista(Lista A)
{
	Celula *Ap;
	Celula *Aux; //tenho que percorrer meus nos alocados
	Ap = A.inicio;
	
	if(Ap != NULL) //nao posso esvaziar uma lista vazia ne 
	{
		do
		{
			//entrei no primeiro no, pulo pro proximo com cursor, e esvazio anterior
			Aux = Ap;
			Ap = Ap->next;
			free(Aux);
			
		}while(Ap != NULL);
	
	}
	
	A.inicio = NULL;
	A.tam = 0;

	return A;
}

void mostrarLista(Lista A)
{
	Celula *Ap;
	Ap = A.inicio;
	
	if(Ap != NULL)
	{
		printf("\n[ ");
		do
		{
			printf(" %d ",Ap->item);
			Ap = Ap->next;
			
		}while(Ap != NULL);
		printf(" ]\n");
	}	
	else
	{
		printf("\nLista Vazia \n");
	}
}


Lista criarLista()
{
	Lista A;
	//criando lista vazia
	A.inicio = NULL;
	A.tam = 0;
	return A;
}

boo verificarListaVazia(Lista A)
{
	boo T = FALSE;
	
	//se ta vazia e true
	if(A.inicio == NULL) T = TRUE;
	
	return T;
}

Lista inserirInicio(Lista A, int coisa)
{
	Celula *Nova; //criei a celula
	
	Nova = malloc(sizeof(Celula)); //aloquei espaco
	
	Nova->item = coisa; //adicionei coisa no campo conteudo
	
	Nova->next = A.inicio; //disse que meu proximo vai ser onde estava meu inicio
	
	A.inicio = Nova; //disse que meu comeco e nova
	
	A.tam++;
	
	return A;
}

