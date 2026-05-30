/*
    Lista Ligada Com Cabeça
    Arquivo: ListaLigada1 
    Autor: Igor
    Data: 12/05/26
    Implementar O Tipo lista com representação por encadeamento.
*/

/*
    Quais são as operações
    
    Criar Lista vazia
    Mostrar Lista
    Verificar Lista Vazia
    Obter Tamanho
    Inserir
    Obter Elemento

*/

#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#define Fantasma 0 //DEPENDE DO TIPO DA LISTA E COMO ELA ABRANGE


typedef struct Celula
{
    int elemento;
    struct Celula *next; //um pointer para A celula, 

}Celula;

typedef struct
{
    int Tamanho;
    Celula *inicio; //Poninter para a cabeça da lista

}Lista;

/*  INTERFACE DA LISTA ENCADEADA */
Lista criarListaVazia();

bool verificarListaVazia(Lista);

void mostrarLista(Lista); //nao terminei

Lista inserirLista(Lista, int);

Lista removerItem(Lista ,int); //faz nada � s� base

int main()
{
    //modelo de testes 
    Lista L;
    int a = 10;
    L = criarListaVazia();
    L = inserirLista(L,2);
	L = inserirLista(L,4);

	
	mostrarLista(L);
	
	L = removerItem(L,2);
	printf("\n");
	mostrarLista(L);
    
    return 0;
}

//CRIANDO DA LISTA VAZIA 

Lista criarListaVazia()
{
    Lista a;

    a.Tamanho = 0; // DEFINI O TAMANHO DELA, COMO ZERO

    a.inicio = NULL; //ATERRO A LISTA

    return a;
}

//A LISTA É VAZIA??

bool verificarListaVazia(Lista a)
{
    bool t = FALSE;
    if(a.Tamanho == 0) // OU O TAMANHO OU SE A LISTA E NULL
    {
        t = TRUE;
    }
    return t;    
}

//MOSTRA AI

void mostrarLista(Lista a)
{
    //crio um ponteiro que vai percorrer minha "lista"
    Celula *p;
	p = a.inicio;
    //EU MANDO FANTASMA SE A LISTA FOR VAZIA
    if(a.Tamanho != 0)
        {
            //tenho que fazer enquanto nao e null
            do
            {
                printf(" %d ", p ->elemento );
                //como eu fa�o pra pegar o proximo da celula?
               
                p = p-> next;
 
            }while(p != NULL);

        }
    else //caso lista vazia
        {
            printf("Lista Vazia\n");
        }

}

Lista inserirLista(Lista a,int y){

    Celula *novo;
    novo = malloc(sizeof(Celula)); // alocação basica

    novo -> elemento = y; // EU COLOCO O ELEMENTO NO MEU NOVO

    novo -> next = a.inicio;  //DEPOIS EU PEGO O ANTERIOR / ATERRADO

    a.inicio = novo; // EU DIGO AO MEU INICIO ONDE ESTÁ O MEU NOVO COMEÇO, QUE JA POSSUI A INFORMAÇÃO DO PROXIMO

    a.Tamanho++; // E AUMENTO O TAM DE CABEÇA

    return a; 
} 

Lista esvaziarLista(Lista A)
{
	A.inicio = NULL;
	return A;
}


Lista removerItem(Lista a,int item)
{
	//eu to procurando um item X,e preciso ver antes de chegar no NULL
	//do tipo 
	
	Celula *ap;
	Celula *ant;
	ant = NULL;
	ap = a.inicio; //PRIMEIRA CELULA

	if(ap != NULL ){ // se a lista n e vazia eu busco
		

		//ENQUANTO NAO ENCONTRO MEU ITEM E NAO ACHEI MEU ULTIMO
		while((ap->elemento != item) && (ap->next != NULL))
		{
			ant = ap; 
			ap = ap->next;
		}
		printf("\n ACHOU: %d",ap ->elemento);
		printf("\n ACHOU ANT : %d",ant ->elemento);
	
		//Pergunto se por acaso eu achei, para caso ele tenha chego no ultimo
		if(ap -> elemento == item)
		{
			if(ant == NULL)
			{
				a.inicio = NULL;
			}
			else
			{
				ant->next = ap ->next;
			}
			free(ap);
			a.Tamanho--;
			//achei o item faco algo	
		}
	}
	
	return a;
}


	
Lista inserirListaCrescente(Lista a,int item)
{
	Celula *ap;
	Celula *ap2;
	
	ap = a.inicio;
	/*quando eu vou inserir?
		
	a lista ta vazia bota no inicio e cabo
		se nao ta vazia, v� qual � o valor do cara
			o que eu to colocando � maior? entao proximo, contando que nao chegue no fim.
	
	*/
	
	if(ap == NULL) //ta vazia bota no come�o
	{
		ap = malloc(sizeof(Celula)); // aloco memoria para minha celula nova
		ap->elemento = item; 
		ap->next = a.inicio;
		a.inicio = ap;
		a.Tamanho++;
		//termino de criar a celula e coloco enere�o certinho
	}
	else // se a lista nao ta vazia, eu tenho mais casos
	{
		//o meu Elemento, � o maior?
		
		
		//se eu nao achei meu LUGAR e O proximo campo n � NULL, eu continuo
		while( (item > ap -> elemento) && (ap -> next != NULL)) ap2 = ap; ap = ap->next;
		
		//PERGUNTO SE EU ENCONTREI UM CARA MAIOR QUE MEU ITEM, OU SEJA, EU VENHO ANTES
		if(ap -> elemento > item){
			
		}	
		
	}
	
}
    
