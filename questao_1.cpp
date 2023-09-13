#include <stdio.h>


void bubbleSort(int arr[], int n) {
    printf("\nBubbleSort\n");
}

void selectionSort(int arr[], int n) {
    printf("\nselectionSort\n");
}

void insertionSort(int arr[], int n) {
    printf("\ninsertionSort\n");
}

void mergeSort(int arr[], int l, int r) {
    printf("\nmergeSort\n");
}

void imprimirMenu(){
    printf("Menu:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

int main(){
    int opcao;
    FILE *arquivo;
    char linha[100];
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    arquivo = fopen("C:\\Users\\phsto\\OneDrive\\Documentos\\Faculdade\\EstruturaII\\Atividade_Ordenacao\\nomes2.txt.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }
    fclose(arquivo);

    do{
        imprimirMenu();
        printf("ESCOLHA UMA OPCAO: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                bubbleSort(arr, n);
                break;
            case 2:
                selectionSort(arr, n);
                break;
            case 3:
                insertionSort(arr, n);
                break;
            case 4:
                mergeSort(arr, 0, n - 1);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente\n");
        }
    }while(opcao != 5);
    
    return 0;
}
