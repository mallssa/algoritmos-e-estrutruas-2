#include <stdio.h>
#include <string.h>

struct Product
{
    int codigo;
    char descricao[50];
    float preco;
};
struct Product produto[10];

int main()
{
    int contador;

    printf("\n=====CADASTRO DE PRODUTOS=====\n");
    for (contador = 0; contador < 10; contador++)
    {
        printf("\nDigite o codigo do %do produto: ", (contador + 1));
        scanf("%d", &produto[contador].codigo);
        setbuf(stdin, NULL);
        printf("Digite a descricao do %do produto: ", (contador + 1));
        scanf("%[^\n]s", produto[contador].descricao);
        printf("Digite o valor do %d produto: ", (contador + 1));
        scanf("%f", &produto[contador].preco);
    }

    int i, j, codigoAux;
    float precoAux;
    char descricaoAux[50];

    for (i = 0; i < 10; i++)
    {
        codigoAux = produto[i].codigo;
        strcpy(descricaoAux, produto[i].descricao);
        precoAux = produto[i].preco;
        j = i - 1;
        while (j >= 0 && strcmp(produto[j].descricao, descricaoAux) > 0)
        {
            produto[j + 1].codigo = produto[j].codigo;
            produto[j + 1].preco = produto[j].preco;
            strcpy(produto[j + 1].descricao, produto[j].descricao);

            j = j - 1;
        }
        produto[j + 1].codigo = codigoAux;
        produto[j + 1].preco = precoAux;
        strcpy(produto[j + 1].descricao, descricaoAux);
    }

    printf("\n==========CADASTROS ORDENADOS==========\n");
    for (i = 0; i < 10; i++)
    {
        printf("Codigo: %d||", produto[i].codigo);
        printf("Descricao: %s||", produto[i].descricao);
        printf("Valor: %.2f\n", produto[i].preco);
    }
    int codigo;
    printf("\n\nDigite o codigo que deseja pesquisar: ");
    scanf("%d", &codigo);

    for (i = 0; i < 10; i++)
    {
        if (produto[i].codigo == codigo)
        {
            printf("\nO produto foi encontrado em %d iteracoes.\n\n", (i + 1));
            printf("Codigo: %d||", produto[i].codigo);
            printf("Descricao: %s||", produto[i].descricao);
            printf("Valor: %.2f\n", produto[i].preco);
            return 0;
        }
    }

    printf("Nao foi possivel encontrar o produto. ");

    return 0;
}