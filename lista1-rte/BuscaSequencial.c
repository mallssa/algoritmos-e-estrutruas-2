#include<stdio.h>
#include<stdlib.h>

int BuscaSequencial(int V[], int numero, int size){
    int i;

    for(i=0;i<size;i++){
        if(V[i]==numero){
            return true;
        }
    }
    return false;
} 



int main(){
    int* vetor;
    int quantidadeDeValores,contador,numero;

    printf("Entre com a quantidade de valores do vetor: ");
    scanf("%d", &quantidadeDeValores);

    vetor = malloc(sizeof(quantidadeDeValores));

    for(contador = 0;contador<quantidadeDeValores;contador++){
        printf("Entre com o valor da %d posicao do vetor: ", contador+1);
        scanf("%d",&vetor[contador]);
    }

    printf("Entre com o valor que deseja buscar: ");
    scanf("%d",&numero);

    printf("Foi necessário um total de %d comparacoes para se encontrar o valor desejado\n", BuscaSequencial(vetor,numero,quantidadeDeValores));
    free(vetor);

}
