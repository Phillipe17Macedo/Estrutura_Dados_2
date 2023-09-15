#include <stdio.h>
#include <string.h>

#define MAX_NOMES 1000
#define MAX_TAM_NOME 100

void bubbleSort(char V[][MAX_TAM_NOME], int Fim)
{
    int i, j;
    char temp[MAX_TAM_NOME];

    for (i = 0; i < Fim; i++)
    {
        for (j = 0; j < Fim - 1 - i; j++)
        {
            if (strcmp(V[j], V[j + 1]) > 0)
            {
                strcpy(temp, V[j]);
                strcpy(V[j], V[j + 1]);
                strcpy(V[j + 1], temp);
            }
        }
    }
}

void selectionSort(char V[][MAX_TAM_NOME], int Fim)
{
    int i, j;
    char temp[MAX_TAM_NOME];

    for (i = 0; i < Fim - 1; i++)
    {
        int minIndex = i;
        for (j = i + 1; j < Fim; j++)
        {
            if (strcmp(V[j], V[minIndex]) < 0)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            strcpy(temp, V[i]);
            strcpy(V[i], V[minIndex]);
            strcpy(V[minIndex], temp);
        }
    }
}

void insertionSort(char V[][MAX_TAM_NOME], int Fim)
{
    int i, j;
    char temp[MAX_TAM_NOME];

    for (i = 1; i < Fim; i++)
    {
        strcpy(temp, V[i]);
        j = i - 1;
        while (j >= 0 && strcmp(V[j], temp) > 0)
        {
            strcpy(V[j + 1], V[j]);
            j--;
        }
        strcpy(V[j + 1], temp);
    }
}

void merge(char V[][MAX_TAM_NOME], int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    char L[n1][MAX_TAM_NOME], R[n2][MAX_TAM_NOME];

    for (i = 0; i < n1; i++)
        strcpy(L[i], V[inicio + i]);
    for (j = 0; j < n2; j++)
        strcpy(R[j], V[meio + 1 + j]);

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2)
    {
        if (strcmp(L[i], R[j]) <= 0)
        {
            strcpy(V[k], L[i]);
            i++;
        }
        else
        {
            strcpy(V[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        strcpy(V[k], L[i]);
        i++;
        k++;
    }

    while (j < n2)
    {
        strcpy(V[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char V[][MAX_TAM_NOME], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(V, inicio, meio);
        mergeSort(V, meio + 1, fim);

        merge(V, inicio, meio, fim);
    }
}

int main()
{
    int opcao;
    printf("Escolha o n�mero correspondente a cada fun��o:\n");
    printf("1- Bubble Sort\n");
    printf("2- Selection Sort\n");
    printf("3- Insertion Sort\n");
    printf("4- Merge Sort\n");
    printf("5- SAIR\n");

    scanf("%d", &opcao);

    if (opcao >= 1 && opcao <= 4)
    {
        char nomes[MAX_NOMES][MAX_TAM_NOME];
        int n = 0;

        FILE *arquivo = fopen("nomes2.txt", "r");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

        while (fgets(nomes[n], sizeof(nomes[n]), arquivo) != NULL && n < MAX_NOMES)
        {
            n++;
        }
        fclose(arquivo);

        for (int i = 0; i < n; i++)
        {
            int len = strlen(nomes[i]);
            if (len > 0 && nomes[i][len - 1] == '\n')
            {
                nomes[i][len - 1] = '\0';
            }
        }

        switch (opcao)
        {
        case 1:
            bubbleSort(nomes, n);
            break;
        case 2:
            selectionSort(nomes, n);
            break;
        case 3:
            insertionSort(nomes, n);
            break;
        case 4:
            mergeSort(nomes, 0, n - 1);
            break;
        }

        for (int i = 0; i < n; i++)
        {
            printf("%s\n", nomes[i]);
        }
    }
    else if (opcao == 5)
    {
        printf("Saindo...\n");
    }
    else
    {
        printf("Op��o inv�lida.\n");
    }

    return 0;
}
