#include<stdio.h>
#include<stdlib.h>
int PesquisaBinaria (int x, int* v[], int e, int d)
{
 int meio = (e + d)/2;
 int vMeio = v[meio];
 if (vMeio == x)
    return meio;
 if (e >= d)
    return -1; // não encontrado
 else
     if (vMeio < x)
        return PesquisaBinaria(x, v, meio+1,d);
     else
        return PesquisaBinaria(x, v,e, meio-1);
}

int main(){
    int* V;
    int quant,i;
    printf("Entre com a quantidade de numeros");
    scanf("%d",&quant);
    V = malloc(sizeof(quant));
    for(i=0;i<quant;i++){
        scanf("%d",V[i]);
    }
    
    printf(PesquisaBinaria(V,5,V[0],V[quant]));
}