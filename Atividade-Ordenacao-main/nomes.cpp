#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void imprimirVetor(string nomes[], int qtd){

    cout << "Nomes ordenados: " << endl;
    for(int i = 0; i < qtd; i++){
        cout << nomes[i] << endl;
    }
}

void bubbleSort(string nomes[], int qtd){

    for(int i = 0; i < qtd - 1; i++){
        bool houveTroca = false;
        for(int j = 0; j < qtd - 1; j++){
            if(nomes[j] > nomes[j + 1]){
                houveTroca = true;
                string aux = nomes[j];
                nomes[j] = nomes[j+1];
                nomes[j+1] = aux;
            }
        }

        if(!houveTroca){
            break;
        }
    }

    imprimirVetor(nomes, qtd);

}

void selectionSort(string nomes[], int qtd){

    for(int i = 0; i < qtd - 1; i++){
        int indiceDoMenor = i;

        for(int j = i + 1; j < qtd; j++){

            if(nomes[j] < nomes[indiceDoMenor]){
                indiceDoMenor = j;
            }
        }

        if(indiceDoMenor != i){
            string aux = nomes[i];
            nomes[i] = nomes[indiceDoMenor];
            nomes[indiceDoMenor] = aux;
        }
    }

    imprimirVetor(nomes, qtd);
}

void insertionSort(string nomes[], int qtd){

    for(int i = 1; i < qtd; i++){
        string aux = nomes[i];
        int j;

        for(j = i - 1; j >= 0 && nomes[j] > aux; j--){
            nomes[j+1] = nomes[j];
        }

        nomes[j+1] = aux;
    }

    imprimirVetor(nomes, qtd);
}

void conquista(string nomes[], int inicio, int meio, int fim){

    int i = inicio, j = meio + 1, k = 0;

    string temp[(fim - inicio) + 1];

    while(i <= meio && j <= fim){

        if(nomes[i] < nomes[j]){
            temp[k++] = nomes[i++];
        }
        else {
            temp[k++] = nomes[j++];
        }
    }

    while(i <= meio){
        temp[k++] = nomes[i++];
    }

    while(j <= fim){
        temp[k++] = nomes[j++];
    }

    for(i = inicio, k = 0; i <= fim; i++, k++){
        nomes[i] = temp[k];
    }

}

void divisao(string nomes[], int inicio, int fim){

    if(inicio < fim){

        int meio = (inicio + fim) / 2;
        divisao(nomes, inicio, meio);
        divisao(nomes, meio + 1, fim);
        conquista(nomes, inicio, meio, fim);
    }
}

void mergeSort(string nomes[], int qtd){
    divisao(nomes, 0, qtd-1);
    imprimirVetor(nomes, qtd);
}

int main() {

    cout << "Selecione uma opcao: " << endl;
    cout << "1 - Bubble Sort" << endl;
    cout << "2 - Selection Sort" << endl;
    cout << "3 - Insertion Sort" << endl;
    cout << "4 - Merge Sort" << endl;
    cout << "5 - Sair" << endl;

    int opcao;
    cin >> opcao;

    fstream arquivo;
    arquivo.open("nomes2.txt", fstream::in);

    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo, verifique se ele está no diretório correto";
        return 1;
    }

    int qtdNomes = 0;
    string nomes[1001];

    while (!arquivo.eof()) {
        string linha;
        getline(arquivo, linha);
        if(linha.empty()) break;
        nomes[qtdNomes] = linha;
        qtdNomes++;
    }

    arquivo.close();

    switch(opcao){

        case 1:
            bubbleSort(nomes, qtdNomes);
            break;
        case 2:
            selectionSort(nomes, qtdNomes);
            break;
        case 3:
            insertionSort(nomes, qtdNomes);
            break;
        case 4:
            mergeSort(nomes, qtdNomes);
            break;
        case 5:
            cout << "Saindo..." << endl;
            return 0;
        default:
            cout << "Opcao invalida!" << endl;
    }

    return 0;
}
