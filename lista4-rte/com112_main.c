#include <stdio.h>
#include <stdlib.h>
#include "com112_file.h"
#include "com112_sort.h"
#include <stdbool.h>
#include <time.h>


//merge - mesma quantidade de trocas independente do vetor / comparacoes diminui
//bubble - 0 
//selection - 0
//quick - 0 / 


void waiter()
{
    char str[50];
    while (1)
    {
        printf("\n\nDigite qualquer tecla e pressione enter para continuar!\n\n");
        scanf("%s", str);
        break;
    }
}

void relatorio(int var[])
{
    int q = var[0];
    printf("Numero de elementos ordenados: %d\n", var[0]);
    printf("Metodo Bubble Sort               \n");
    printf("    Tempo de execucão: %f        \n", (var[q + 7]) / 100000.0);
    printf("    Numero de comparacoes %d     \n", var[q + 1]);
    printf("    Numero de movimentacoes: %d  \n", var[q + 2]);
    printf("Metodo Selection Sort            \n");
    printf("    Tempo de execucão: %f        \n", (var[q + 8]) / 100000.0);
    printf("    Numero de comparacoes %d     \n", var[q + 3]);
    printf("    Numero de movimentacoes: %d  \n", var[q + 4]);
    printf("Metodo Insertion Sort            \n");
    printf("    Tempo de execucão: %f        \n", (var[q + 9]) / 100000.0);
    printf("    Numero de comparacoes %d     \n", var[q + 5]);
    printf("    Numero de movimentacoes: %d  \n", var[q + 6]);
    printf("Metodo Merge Sort            \n");
    printf("    Tempo de execucão: %f        \n", (var[q + 12]) / 100000.0);
    printf("    Numero de comparacoes %d     \n", var[q + 10]);
    printf("    Numero de movimentacoes: %d  \n", var[q + 11]);
    printf("Metodo Quick Sort            \n");
    printf("    Tempo de execucão: %f        \n", (var[q + 13]) / 100000.0);
    printf("    Numero de comparacoes %d     \n", var[q + 14]);
    printf("    Numero de movimentacoes: %d  \n", var[q + 15]);
    
    escreverArquivoRelatorio(var);

}

void showVector(int vet[]){
    int i,quantidade = vet[0]+1;
    for(i=1;i<quantidade;i++){
        printf("%d ",vet[i]);
    }
    printf("\n\n\n");
}

int calculaTempo(int time1,int time2){
    return ((time2 - time1) / 1000.0) * 100000;
}

int* menu(int vet[])
{
    int op, tempo1, tempo2, quantidade;
    int *v = NULL;
    quantidade = vet[0];
    vet[quantidade + 10] = 0;
    vet[quantidade + 11] = 0;
    while ((op != 1) && (op != 2) && (op != 3) && (op != 4) && (op != 5) && (op != 6))
    {
        printf("\e[H\e[2J");
        printf("\n\n\n\n\n");
        printf("                    ==========Metodos de ordenacao==========\n");
        printf("                    =         1 - Bubble Sort              =\n");
        printf("                    =         2 - Selection Sort           =\n");
        printf("                    =         3 - Insertion Sort           =\n");
        printf("                    =         4 - Merge Sort               =\n");
        printf("                    =         5 - Quick Sort               =\n");
        printf("                    =         6 - Relatorio                =\n");
        printf("                    ========================================\n");
        printf("\n");

        printf("              Entre com a opcao desejada (Digite o numero da opcao): ");
        
        scanf("%d", &op);
        
        switch (op)
        {
        case 1:
            tempo1 = clock();
            v = bubbleSort(vet);
            tempo2 = clock();
            quantidade = v[0];
            v[quantidade + 7] = calculaTempo(tempo1,tempo2);
            printf("\nVetor ordenado através do BubbleSort!\n");
            showVector(v);
            break;
        case 2:
            tempo1 = clock();
            v = selectionSort(vet);
            tempo2 = clock();
            printf("\nVetor ordenado através do SelectionSort!\n");
            quantidade = v[0];
            v[quantidade + 8] = calculaTempo(tempo1,tempo2);
            showVector(v);
            break;
        case 3:
            tempo1 = clock();
            v = insertionSort(vet);
            tempo2 = clock();
            printf("\nVetor ordenado através do InsertionSort!\n");
            quantidade = v[0];
            v[quantidade + 9] = calculaTempo(tempo1,tempo2);
            showVector(v);
            break;
        case 4:
            tempo1 = clock();
            v = mergeSort(vet, 1, vet[0] - 1);
            tempo2 = clock();
            printf("\nVetor ordenado através do MergeSort!\n");
            quantidade = v[0];
            v[quantidade + 12] = calculaTempo(tempo1,tempo2);
            showVector(v);
            break;
        case 5:
            tempo1 = clock();
            v = quickSort(vet,0,vet[0]-1);
            tempo2 = clock();
            printf("\nVetor ordenado através do Quick Sort!\n");
            quantidade = v[0];
            v[quantidade+13] = calculaTempo(tempo1,tempo2);
            showVector(v);
            break;
        case 6:
            tempo1 = clock();
            v = bubbleSort(vet);
            tempo2 = clock();
            v[quantidade + 7] = calculaTempo(tempo1,tempo2);
            tempo1 = clock();
            v = selectionSort(vet);
            tempo2 = clock();
            v[quantidade + 8] = calculaTempo(tempo1,tempo2);
            tempo1 = clock();
            v = insertionSort(vet);
            tempo2 = clock();
            v[quantidade + 9] = calculaTempo(tempo1,tempo2);
            tempo1 = clock();
            v = mergeSort(vet, 1, vet[0] - 1);
            tempo2 = clock();
            v[quantidade + 12] = calculaTempo(tempo1,tempo2);
            tempo1 = clock();
            v = quickSort(vet,0,vet[0]-1);
            tempo2 = clock();
            quantidade = v[0];
            v[quantidade+13] = calculaTempo(tempo1,tempo2);
            showVector(v);
            relatorio(vet);
            break;
        }
    }
    return v;
}

int main()
{
    int op, i;
    int *vetor;
    int cont = 0;
    while (op != 4)
    {
        printf("\e[H\e[2J");
        printf("\n\n\n\n\n");
        printf("                    ==========Metodos de ordenacao==========\n");
        printf("                    =                                      =\n");
        printf("                    =         1 - Metodos de Ordenacao     =\n");
        printf("                    =         2 - Gerar Numeros            =\n");
        printf("                    =         3 - Creditos                 =\n");
        printf("                    =         4 - Sair                     =\n");
        printf("                    =                                      =\n");
        printf("                    ========================================\n");
        printf("\n");

        printf("              Entre com a opcao desejada (Digite o numero da opcao): ");
        scanf("%d", &op);

        if (op == 1)
        {

            if (cont == 0)
            {
                vetor = lerArquivoEntrada();
                cont++;
            }
            int* result = menu(vetor);
            
            
            printf("\n\n");
            abrirArquivoSaida(result, result[0]);
            waiter();
        }
        
        else if (op == 2)
        {
            int quantidade, i;
            int *vet;
            bool result_of_archive;
            printf("\e[H\e[2J");
            printf("Entre com a quantidade de numeros a serem gerados: ");
            scanf("%d", &quantidade);

            vet = malloc(quantidade * sizeof(vet));

            for (i = 0; i < quantidade; i++)
            {
                vet[i] = rand() % 1000;
            }

            printf("Numeros gerados de forma aleatoria:\n");

            for (i = 0; i < quantidade; i++)
            {
                printf("%d ", vet[i]);
            }
            printf("\n");

            abrirArquivoEntrada(vet, quantidade);

            

            waiter();
            free(vet);
            cont = 0;
        }
        else if (op == 3)
        {
            printf("\e[H\e[2J");
            printf("                    ==========Creditos======================\n");
            printf("                    =                                      =\n");
            printf("                    =                                      =\n");
            printf("                    =         Marcelo Magalhaes Silva      =\n");
            printf("                    =         2020004243                   =\n");
            printf("                    =         COM112                       =\n");
            printf("                    ========================================\n");
            waiter();
        }
    }

    return 0;
}