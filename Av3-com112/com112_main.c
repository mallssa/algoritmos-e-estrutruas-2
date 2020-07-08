#include<stdio.h>
#include<stdlib.h>
#include"com112_hash.h"

int menu(){
    int opcao;
    printf("==========MENU==========\n\n\n");
    printf("1 - Criar tabela hash\n");
    printf("2 - Liberar tabela hash\n");
    printf("3 - Inserir elemento ( sem colisao)\n");
    printf("4 - Consultar elemento (sem colisao)\n");
    printf("5 - Sair\n");
    printf("Opcao: ");
    scanf("%d",&opcao);

    return opcao;
}


int main(){
    int op, tamanho,result,matricula;
    Hash* ha;
    struct aluno al;
    while(op!=5){
    op = menu();

        switch(op){
            case 1:
                printf("Entre com o tamanho da tabela (Preferencialmente numero primo e sem ser potencia de dois): ");
                scanf("%d", &tamanho);
                ha = criaHash(tamanho);
                if(ha == NULL)
                    printf("Nao foi possivel criar a tabela hash, tente novamente!");
                else
                    printf("Tabela hash criada com sucesso!\nAgora eh possivel fazer operacoes de adicao e listagem!\n\n");       
                break;

            case 2:
                liberaHash(ha);
                break;

            case 3:
                printf("Entre com a matricula do aluno: ");
                scanf("%d",&al.matricula);
                printf("Entre com o nome do aluno: ");
                scanf("%s",al.nome);
                printf("Entre com a nota 1: ");
                scanf("%f",&al.n1);
                printf("Entre com a nota 2: ");
                scanf("%f",&al.n2);
                result = insereHash_SemColisao(ha,al);
                if(result==0){
                    printf("Nao foi possivel adicionar o aluno!\nTente Novamente!\n");
                }
                else{
                    printf("Aluno cadastrado com sucesso!\n\n");
                }
                break;

            case 4:
                printf("Entre com a matricula do aluno: ");
                scanf("%d",&matricula);

                result = buscaHash_SemColisao(ha,matricula, &al);
                if(result == 1){
                    printf("\nMatricula do aluno: %d\n", al.matricula);
                    printf("Nome do aluno: %s\n",al.nome);
                    printf("Nota 1: %.2f\n", al.n1);
                    printf("Nota 2: %.2f\n", al.n2);
                    printf("Media: %.2f\n\n", (al.n1+al.n2)/2);
                }
                else{
                    printf("Não foi possivel buscar o aluno.\n");
                }
                break;

            case 5:
                liberaHash(ha);
                
                return 0;
                break;
        }
    }


    
}