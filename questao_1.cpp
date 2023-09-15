#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NOME_MAXIMO 1000
#define TAMANHO_MAX_NOME 100

void bubbleSort(char arr[][TAMANHO_MAX_NOME], int n) {
    int i, j;
    char tempo[TAMANHO_MAX_NOME];
    for (i = 0; i < n; i++){
        for (j = 0; j < n - 1 - i; j++){
            if (strcmp(arr[j], arr[j + 1]) > 0){
                strcpy(tempo, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], tempo);
            }
        }
    }
}

void selectionSort(char arr[][TAMANHO_MAX_NOME], int n) {
    int mudou;
    char tempo[TAMANHO_MAX_NOME];

    for(int i = 0; i < n - 1; i++){
        mudou = i;
        for(int j = i + 1; j < n; j++){
            if (strcmp(arr[j], arr[mudou]) < 0){
                mudou = j;
            } 
        }
        if(mudou != i){
            strcpy(tempo, arr[i]);
            strcpy(arr[i], arr[mudou]);
            strcpy(arr[mudou], tempo);
        }
    }
}

void insertionSort(char arr[][TAMANHO_MAX_NOME], int n) {
    int trocar;
    char chave[TAMANHO_MAX_NOME];
    for(int i = 1; i < n; i++){
        strcpy(chave, arr[i]);
        trocar = i - 1;
        while(trocar >= 0 && strcmp(arr[trocar], chave) > 0){
            strcpy(arr[trocar + 1], arr[trocar]);
            trocar = trocar - 1;
        }
        strcpy(arr[trocar + 1], chave);
    }
}
void merge(char V[][TAMANHO_MAX_NOME], int inicio, int meio, int fim){
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    i = 0;
    j = 0;
    k = inicio;
    char L[n1][TAMANHO_MAX_NOME], R[n2][TAMANHO_MAX_NOME];

    for (i = 0; i < n1; i++)
        strcpy(L[i], V[inicio + i]);
    for (j = 0; j < n2; j++)
        strcpy(R[j], V[meio + 1 + j]);

    while (i < n1 && j < n2){
        if (strcmp(L[i], R[j]) <= 0){
            strcpy(V[k], L[i]);
            i++;
        }else{
            strcpy(V[k], R[j]);
            j++;
        }
        k++;
    }
    while (i < n1){
        strcpy(V[k], L[i]);
        i++;
        k++;
    }
    while (j < n2){
        strcpy(V[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char arr[][TAMANHO_MAX_NOME], int inicio, int fim) {
    if (inicio < fim)    {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
}

void imprimirMenu(){
    printf("Menu:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

int main(){
    int opcao;
    
    do{
        char nomes[NOME_MAXIMO][TAMANHO_MAX_NOME];
        int n = 0;
        imprimirMenu();
        scanf("%d",&opcao);

        FILE *arquivo = fopen("C:\\Users\\phsto\\OneDrive\\Documentos\\Faculdade\\EstruturaII\\Atividade_Ordenacao\\nomes2.txt.txt", "r");
        if (arquivo == NULL){
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
        while (fgets(nomes[n], sizeof(nomes[n]), arquivo) != NULL && n < NOME_MAXIMO){
            n++;
        }

        fclose(arquivo);

        for (int i = 0; i < n; i++){
            int len = strlen(nomes[i]);
            if (len > 0 && nomes[i][len - 1] == '\n'){
                nomes[i][len - 1] = '\0';
            }
        }
        switch (opcao){
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
        case 5:
            printf("SAINDO\n");
            break;
        default:
            printf("Opcao Invalida. Tente novamente\n");
        }
    }while(opcao != 5);

    return 0;
}
