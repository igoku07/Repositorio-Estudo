#include <stdio.h>
#include "Booleano.h" 

#define MaxPilha 100
#define Sinal -1
#define Fantasma &

void criarPilhaVazia(Pilha *);
char acessarTopo(Pilha *); 
bool verificarPilhaVazia(Pilha *);
bool verificarPilhaCheia(Pilha *); 
int obterProfundidade(Pilha *); //qnts coisas tem 

void pushPilha(Pilha *, char); //botar coisas
void popPilha(Pilha *); //remover

typedef struct{
 int topo;
 char tabela[MaxPilha];
} Pilha;

main(){



}

//Armazenar a partir da Pos 1
void criarPilhaVazia(Pilha *ap){
    ap -> topo = Sinal;
}

//Retornar oque tem no Topo
char acessarTopo(Pilha *ap){
    int top;
    char Oque;

    top = ap -> topo; 
    Oque = ap -> tabela[top];
    return Oque;
}

bool verificarPilhaVazia(Pilha *ap){
    bool T = FALSE;

    if(ap -> topo == Sinal){
        T = TRUE;
    }

    return T;

}

bool verificarPilhaCheia(Pilha *ap){
    bool T = FALSE;

    if(ap -> topo == MaxPilha - 1){
        T = TRUE;
    }

    return T;

}

//qntd de coisas 
int obterProfundidade(Pilha *ap){
    int Quantas = 0;

    while(Quantas <= ap -> topo){
        Quantas++;
    }

    return Quantas;
}

void pushPilha(Pilha *ap, char item){
    int Top = 0;

    //só adiciona se nao tiver cheia, Ex topo 6. Maxpilha = 7. Pilha ta full já
    if(ap -> topo < MaxPilha){
        Top = ap -> topo;
        ap -> tabela[Top + 1] = item;
    }
}

void popPilha(Pilha *ap){
    //remover o ultimo, condiçoes?
    //pilha nao ser vazia
    if(ap -> topo != Sinal){
        ap -> topo = ap -> topo - 1;
    }
}
