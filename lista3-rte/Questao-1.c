#include<stdio.h>
#include<stdlib.h>


void BubbleSort(int V[],int n){
    int ultimo,i;
    for(ultimo = n-1;ultimo>0;ultimo--){
        for(i=0;i<ultimo;i++){
            if(V[i]<V[i+1]){
                int aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
            }
        }
    }
}

int main(){
    int V[10],cont;

    printf("=====ENTRADA DOS 10 NUMEROS=====");
    for(cont = 0 ; cont <10;cont++){
        printf("\nEntre com o %do numero: ", (cont+1));
        scanf("%d",&V[cont]);
    }
    BubbleSort(V,10);
    printf("=====VETOR ORDENADO=====\n");
    printf("[");
    for(cont = 0; cont<10 ;cont++){
        printf("%d",V[cont]);
        if(cont!=9){
            printf(",");
        }
    }
    printf("]\n");


    

    return 0;
}
