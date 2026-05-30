/*
    Lista Ligada Sem Cabeça
    Arquivo: ListaLigada2
    Autor: Igor
    Data: 12/05/26
    Implementar O Tipo lista com representação por encadeamento.
*/


#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#define Fantasma 0 //DEPENDE DO TIPO DA LISTA E COMO ELA ABRANGE

typedef struct Celula
{
    int item;
    struct Celula *next;
}Celula;

//SEM CABEÇA, OU SEJA A PARTE LISTA É APENAS UM POINTER PARA O COMEÇO
typedef Celula *Lista;

/*
    Quais são as operações
    
    Criar Lista vazia
    Mostrar Lista
    Verificar Lista Vazia
    Obter Tamanho
    Inserir
    Obter Elemento

*/

Lista criarListaVazia(); //sem cabeça, fica como?

bool verificarListaVazia(Lista);

int main()
{
    return 0;
}


//como nao há cabeça, basta definir que o começo é NULL
Lista criarListaVazia()
{
    Lista a;
    a = NULL;
    return a;
}

bool verificarListaVazia(Lista a)
{
    bool T = FALSE;
    
    if(a == NULL) T = TRUE;
    return T;
}

