#include <stdio.h>
int *bubbleSort(int arr[])
{
    int compara = 0, trocas = 0;
    int n = arr[0];
    int i, j;
    for (i = 1; i < n + 1; i++)

        // Os últimos i elementos estão no lugar certo
        for (j = 1; j < n - i + 1; j++)
        {
            compara++;
            if (arr[j] > arr[j + 1])
            {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                trocas++;
            }
        }
    arr[n + 1] = compara;
    arr[n + 2] = trocas;

    return arr;
}

int *selectionSort(int arr[])
{
    int n = arr[0];
    int i, j, min_idx;
    int compara = 0, trocas = 0;
    // Move um item por vez
    for (i = 1; i < n; i++)
    {
        // Acha o menor elemento no array desordenado
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            compara++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Troca o minimo elemento encontrado pra posicao correta
        trocas++;
        int aux = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = aux;
    }
    arr[n + 3] = compara;
    arr[n + 4] = trocas;

    return arr;
}

int *insertionSort(int arr[])
{
    int compara = 0, trocas = 0;
    int n = arr[0];
    int i, key, j;
    arr[n+6] = 0;
    arr[n+5] = 0;
    for (i = 2; i < n + 1; i++)
    {
        key = arr[i];
        j = i - 1;

        
        compara++;
        while (j >= 0 && arr[j] > key)
        {
            arr[n+6]++;
            arr[j + 1] = arr[j];
            j = j - 1;
            
        }

        arr[j + 1] = key;
    }
    
    arr[n + 5] = compara;
    
    

    return arr;
}

void merge(int arr[], int l, int m, int r)
{
    int quantidade = arr[0];
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //Cria arrays temporarios
    int L[n1], R[n2];

    //Copia as informacoes do array para os respectivos vetor L[] e R[] para fazer a junção
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Indice inicial do primeiro subarray
    j = 0; // Indice inicial do segundo subarray
    k = l; // Indice inicial do array misturado
    while (i < n1 && j < n2)
    {
        arr[quantidade + 10]++;
        if (L[i] <= R[j])
        {
            arr[quantidade + 11]++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[quantidade + 11]++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copia os elementos restantes de L[] se existir */
    while (i < n1)
    {
        arr[quantidade + 11]++;
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copia os elementos restantes de R[] se existir */
    while (j < n2)
    {
        arr[quantidade + 11]++;
        arr[k] = R[j];
        j++;
        k++;
    }
}


int *mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        
        int m = l + (r - l) / 2;

        // Ordena a primeira e segunda metade
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
    return arr;
}

int partition(int arr[], int low, int high)
{
    int trocas = 0,comparacoes = 0;
    int pivot = arr[high]; // pivo
    int i = (low - 1);     // index do menor elemento

    for (int j = low; j <= high - 1; j++)
    {
        // se um elemento especifico é menor do que o pivo
        comparacoes++;
        if (arr[j] < pivot)
        {
            i++; // incrementa o indice do elemento especifico
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            trocas++;
        }
    }
    int t = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = t;
    trocas++;
    int q = arr[0];
    arr[q+14] += trocas;
    arr[q+15] += comparacoes;
    return (i + 1);
}


int *quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //pi é apenas um indíce de particionamento, o lemento da posicão pi está no lugar certo
        int pi = partition(arr, low, high);

        //Separadamente o algoritmo ordena os elementos de antes da partição e de depois
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    return arr;
}