
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define Max 100

typedef struct{ 
int tam; 
int Tab[Max]; 
}Lista;

 
// A lista contem M numeros na faixa de 1 a M 

Lista construirListaAleatoriaM(int N,int a,int b); 
void mostrarLista(Lista L);
Lista construirListaAleatoriaSN(int N, int a, int b);
Lista inverterLista(Lista L);


int main(){
	
	int c,d,n;
	Lista A;
	n = 10;
	c = 1;
	d = 20;
	
	//semente
	srand((int) time(NULL));
	
	A = construirListaAleatoriaSN(n,c,d);
	printf("Lista aleatoria SN\n");
	mostrarLista(A);
	
	A = construirListaAleatoriaM(n,c,d);
	printf("Lista aleatoria M\n");
	mostrarLista(A);
	
	printf("Lista invertida M\n");
	mostrarLista(inverterLista(A));
	return 0;
}

Lista construirListaAleatoriaM(int N,int a,int b){
	
Lista L;                                 
int j,r,lo,hi,nL; 
double g; 
lo = a; hi = b;
 
if((N>0)&&(N<=Max-1))nL = N; else nL = Max-1;
 
L.tam = nL; 
 

for(j=1;j<=nL;j++){ 
		g = ((double)rand()/((double)RAND_MAX + 1)); r = g*(hi-lo +1) + lo; 
		L.Tab[j] = r; 
	} 
return L; 
} 


Lista construirListaAleatoriaSN(int N, int a, int b) {
    Lista L;                              
    int j, p, r, lo, hi, nL;
    int duplicata;
    double g; 
    lo = a; hi = b;

    if ((N > 0) && (N <= Max - 1)) nL = N; else nL = Max - 1;
    L.tam = nL; 

    j = 1;
    while (j <= nL) {                          // loop at� preencher nL elementos
        g = ((double)rand() / ((double)RAND_MAX + 1)); 
        r = g * (hi - lo + 1) + lo; 

        // Verificar duplicatas nos elementos j� inseridos
        duplicata = 0;
        for (p = 1; p < j; p++) {
            if (L.Tab[p] == r) {
                duplicata = 1;
                break;
            }
        }

        // S� avan�a j se n�o for duplicata
        if (!duplicata) {
            L.Tab[j] = r;
            j++;
        }
    }
    return L; 
}

void mostrarLista(Lista L){
	int k;
	for(k = 1; k<L.tam ; k++){
		printf("%d ",L.Tab[k]);
	}
	printf("\n\n");
}
	
Lista inverterLista(Lista L){
	Lista P;
	P.tam = L.tam;
	int k,a,j;
	
	for(k = L.tam-1; k >= 1; k--){
		P.Tab[P.tam-k] = L.Tab[k];
		
		// printf("%d ",P.Tab[k]);
	}
	return P;
}

