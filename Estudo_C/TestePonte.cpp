//teste ponteiro
#include <stdio.h>

main(){

//Ponteiro : Aponta para um endere�o de memoria
int Var;
int *pt;
int fe = 21;

Var = 13;
pt = &fe;
    

printf("Endereco Var %d\n",&Var);
printf("Conteudo de Var %d\n",Var);

printf("Conteudo de Pt %d\n",*pt);
printf("Conteudo de Pt/Endereco %d\n",pt);

}
