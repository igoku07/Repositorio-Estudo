#include <stdio.h>
#include <stdlib.h>

/*
    ISSO E UMA IMPLEMENTACAO DE UMA FILA SEM SER CIRCULAR, 
    LEVANDO EM CONSIDERACAO QUE AS OPERACOES SAO 
    PUSH POP PEEK
    
    OU SEJA, VOU ADICIONAR ALGUEM NA FILA ENTRA NO FIM 
    QUERO REMOVER ALGUEM NA FILA SO POSSO REMOVER O PRIMEIRO DA FILA
    E PEEK, MOSTRO O PRIMEIRO DA FILA
*/


typedef struct Celula
{
    struct Celula *next;
    int Item;
}Celula;

typedef struct Fila
{
    //modo comum de uma lista ligada
    Celula *inicio;
    Celula *fim;

}Fila;

//quais sao as operacoes em uma fila?
Fila criarFila();
void mostrarFila(Fila);
Fila inserirNoFim(Fila,int);
Fila removerInicio(Fila);

main()
{

    Fila F;
    int i;

    F = criarFila();
    mostrarFila(F);

    for(i = 0; i<=7; i++)
    {
        F = inserirNoFim(F,i);
    }

    
    mostrarFila(F);

    for(i = 0; i<=5; i++)
    {
        F = removerInicio(F);
    }
    mostrarFila(F);

}

Fila removerInicio(Fila F)
{
    Celula *Ap;
    Celula *Aux;

    Ap = F.inicio;
    if(Ap != NULL) // se a lista nao e vazia tem alguma coisa
    {
        Aux = Ap;

        if(Ap ->next == NULL) //e pq e unico da fila ai tem q mexer no Fim
        {
            F.fim = NULL;
            F.inicio = NULL;
        }
        else
        {
            Ap = Ap->next;
            F.inicio = Ap;
        }
        free(Aux);
    }
    return F;

}

Fila inserirNoFim(Fila F,int coisa)
{
    Celula *nova;
    Celula *Aux;
    //e garantido q isso aconteca

    nova = malloc(sizeof(Celula));
    

    nova->Item = coisa;
    nova->next = NULL;

    if(F.inicio == NULL)
    { 
        F.inicio = nova; //unico caso q o q mexo no inicio, onde é a primeira
    }
    else
    {
        //sem tem coisa na lista tenho q alterar meu antigo ultimo
        Aux = F.fim;
        Aux ->next = nova;

    }
    
    F.fim = nova;

    return F;
}

void mostrarFila(Fila F)
{
    Celula *Ap;
    Ap = F.inicio;
    if(Ap != NULL) // se nao tem ngm na fila, nao mostro
    {
         printf("\n |Fim da Fila| -> ");
        do
        {
            printf(" %d ",Ap ->Item);
            Ap = Ap->next;
            //percorro a fila inteira, a partir do final

        }while(Ap != NULL);
        printf(" <-|Comeco Fila | \n");
    }
    else
    {
        printf("\n |Fila Vazia| \n");
    }

}

Fila criarFila()
{
    Fila A;
    //como eu crio uma Fila vazia?
    A.inicio = NULL;
    A.fim = NULL;
    return A; 
}

