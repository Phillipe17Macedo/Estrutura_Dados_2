#include <stdio.h>


void bubbleSort(int arr[], int n) {
    printf("BubbleSort\n");
}

void selectionSort(int arr[], int n) {
    printf("selectionSort\n");
}

void insertionSort(int arr[], int n) {
    printf("insertionSort\n");
}

void mergeSort(int arr[], int l, int r) {
    printf("mergeSort");
}

int main() {
    int opcao;
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    do {
        printf("Menu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
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
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
