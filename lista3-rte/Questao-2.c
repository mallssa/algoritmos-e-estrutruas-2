#include<stdio.h>
#include<string.h>

struct funcionario{
    char nome[50];
    float salario;
};
struct funcionario funcionarioOrdenacao[10];

void SelectionSort(struct funcionario F[],int n){
    
}

int main(){
    int cont;

    printf("=====CADASTRO DE FUNCIONARIOS=====\n");
    for(cont=0;cont<10;cont++){
        
        printf("Entre com o nome do %do funcionario: ",(cont+1));
        scanf("%[^\n]s",funcionarioOrdenacao[cont].nome);
        printf("Entre com o salario do %d funcionario: ",(cont+1));
        scanf("%f",&funcionarioOrdenacao[cont].salario);
        setbuf(stdin,NULL);
    }
    
    int i,j, menor_valor;

    char nomeAux[50] = {0};
    float salarioAux;
    for(i=0;i<9;i++){
        menor_valor = i;
        for(j=i+1;j<10;j++){
            if(funcionarioOrdenacao[j].salario>funcionarioOrdenacao[menor_valor].salario){
                menor_valor = j;
            }
        }
        strcpy(nomeAux,funcionarioOrdenacao[i].nome);
        salarioAux = funcionarioOrdenacao[i].salario;
        strcpy(funcionarioOrdenacao[i].nome,funcionarioOrdenacao[menor_valor].nome);
        funcionarioOrdenacao[i].salario = funcionarioOrdenacao[menor_valor].salario;
        strcpy(funcionarioOrdenacao[menor_valor].nome, nomeAux);
        funcionarioOrdenacao[menor_valor].salario = salarioAux;
    }



    printf("\n=====SAIDA ORDENADA POR SALARIO=====\n");
    for(cont=0;cont<10;cont++){
        printf("===Nome: %s  ||  ",funcionarioOrdenacao[cont].nome);
        printf("Salario: %.2f===\n",funcionarioOrdenacao[cont].salario);
    }

    for(i=0;i<9;i++){
        menor_valor = i;
        for(j=i+1;j<10;j++){
            if(strcmp(funcionarioOrdenacao[j].nome,funcionarioOrdenacao[menor_valor].nome)<0){
                menor_valor = j;
            }
        }
        strcpy(nomeAux,funcionarioOrdenacao[i].nome);
        salarioAux = funcionarioOrdenacao[i].salario;
        strcpy(funcionarioOrdenacao[i].nome,funcionarioOrdenacao[menor_valor].nome);
        funcionarioOrdenacao[i].salario = funcionarioOrdenacao[menor_valor].salario;
        strcpy(funcionarioOrdenacao[menor_valor].nome, nomeAux);
        funcionarioOrdenacao[menor_valor].salario = salarioAux;
    }

    printf("\n=====SAIDA ORDENADA POR ORDEM ALFABETICA=====\n");
    for(cont=0;cont<10;cont++){
        printf("===Nome: %s  ||  ",funcionarioOrdenacao[cont].nome);
        printf("Salario: %.2f===\n",funcionarioOrdenacao[cont].salario);
    }




    return 0;
}