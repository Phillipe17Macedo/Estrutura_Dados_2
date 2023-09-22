#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <algorithm> // find
#include <iomanip>

using namespace std;

class Time{
public:
    string nome;
    int vitorias = 0;
    int derrotas = 0;
    int empates = 0;
    int golsMarcados = 0;
    int golsSofridos = 0;
    int pontos = 0;
    int saldoDeGols = 0;

    Time(const string &nome, int vitorias, int derrotas, int empates,
         int golsMarcados, int golsSofridos) : nome(nome), vitorias(vitorias), derrotas(derrotas), empates(empates),
         golsMarcados(golsMarcados), golsSofridos(golsSofridos){
        this->pontos = (vitorias * 3) + empates;
        this->saldoDeGols = golsMarcados - golsSofridos;
    }


    // substituindo o operador pra evitar ficar repetindo opções
    // percebi que era melhor fazer isso ao implementar o metodo de insertionSort
    bool operator> (const Time &outroTime) const {

        if(pontos == outroTime.pontos){
            if(vitorias == outroTime.vitorias){
                if(saldoDeGols == outroTime.saldoDeGols){
                    if(golsMarcados > outroTime.golsMarcados){
                        return true;
                    }
                }
                else if(saldoDeGols > outroTime.saldoDeGols){
                    return true;
                }
            }
            else if(vitorias > outroTime.vitorias){
                return true;
            }
        }
        else if(pontos > outroTime.pontos){
            return true;
        }

        return false;
    }

    bool operator< (const Time &outroTime) const {

        if(pontos == outroTime.pontos){
            if(vitorias == outroTime.vitorias){
                if(saldoDeGols == outroTime.saldoDeGols){
                    if(golsMarcados < outroTime.golsMarcados){
                        return true;
                    }
                }
                else if(saldoDeGols < outroTime.saldoDeGols){
                    return true;
                }
            }
            else if(vitorias < outroTime.vitorias){
                return true;
            }
        }
        else if(pontos < outroTime.pontos){
            return true;
        }

        return false;
    }
};

string escolherTime(vector<Time> times, fstream &arquivo){

    string linha;
    string time;
    while(!arquivo.eof()){
        getline(arquivo, linha);
        time = linha.substr(0, 3);

        auto it = find_if(times.begin(), times.end(),
                          [time](Time &t){ // aqui eu peguei de uma explicação do stackoverflow, nunca tinha ouvido falar sobre isso de predicado
                              return t.nome == time;
                          });

        if(it != times.end()){
            continue;
        }
        return time;
    }

    return "jaFoiTodos";
}

void trocar(vector<Time> &vetor, int j){
    Time aux = vetor[j];
    vetor[j] = vetor[j+1];
    vetor[j+1] = aux;
}

void bubbleSort(vector<Time> &vetor){

    for(int i = 0; i < vetor.size() - 1; i++){

        for(int j = 0; j < vetor.size() - 1; j++) {
            // todas comparações pra ver se tem maior saldo de gols, vitorias, etc; pode ficar bem confuso de ver
            /*if(vetor[j].vitorias == vetor[j+1].vitorias){
                if(vetor[j].saldoDeGols() == vetor[j+1].vitorias){
                    if(vetor[j].golsMarcados < vetor[j+1].golsMarcados){
                        trocar(vetor, j);
                    }
                }
                else if(vetor[j].saldoDeGols() < vetor[j+1].vitorias){
                    trocar(vetor, j);
                }
            }
            else if(vetor[j].vitorias < vetor[j+1].vitorias){
                trocar(vetor, j);
            }*/

            if(vetor[j] < vetor[j+1]){
                trocar(vetor, j);
            }
        }
    }
}

void selectionSort(vector<Time> &vetor){

    for(int i = 0; i < vetor.size() - 1; i++){
        int indiceDoMenor = i;

        for(int j = i + 1; j < vetor.size(); j++){

            /*if(vetor[j].vitorias == vetor[indiceDoMenor].vitorias){
                if(vetor[j].saldoDeGols == vetor[indiceDoMenor].vitorias){
                    if(vetor[j].golsMarcados > vetor[indiceDoMenor].golsMarcados){
                        indiceDoMenor = j;
                    }
                }
                else if(vetor[j].saldoDeGols > vetor[indiceDoMenor].vitorias){
                    indiceDoMenor = j;
                }
            }
            else if(vetor[j].vitorias > vetor[indiceDoMenor].vitorias){
                indiceDoMenor = j;
            }*/

            if(vetor[j] > vetor[indiceDoMenor]){
                indiceDoMenor = j;
            }
        }

        if(indiceDoMenor != i){
            Time aux = vetor[i];
            vetor[i] = vetor[indiceDoMenor];
            vetor[indiceDoMenor] = aux;
        }
    }

}

void tabela(vector<Time> vetor){

    cout << setw(5) << "TIME" // deixar bonitinha a tabela
         << setw(5) << "P" <<
         setw(5) << "V" <<
         setw(5) << "E" <<
         setw(5) << "D" <<
         setw(5) << "SG" <<
         setw(5) << "GP" <<
         setw(5) << "GC" << endl;

    for(Time aux : vetor){

        cout << setw(5) << aux.nome
             << setw(5) << aux.pontos
             << setw(5) << aux.vitorias
             << setw(5) << aux.empates
             << setw(5) << aux.derrotas
             << setw(5) << aux.saldoDeGols
             << setw(5) << aux.golsMarcados
             << setw(5) << aux.golsSofridos << endl;
    }

}

void insertionSort(vector<Time> &vetor){

    for(int i = 1; i < vetor.size(); i++){
        Time aux = vetor[i];
        int j;

        for(j = i - 1; j >= 0 && vetor[j] < aux; j--){
            vetor[j+1] = vetor[j];
        }

        vetor[j+1] = aux;
    }

}

void conquista(vector<Time> &vetor, int inicio, int meio, int fim){

    int i = inicio, j = meio + 1, k = 0;

    vector <Time> temp;

    while(i <= meio && j <= fim){

        if(vetor[i] > vetor[j]){
            temp.push_back(vetor[i++]);
        }
        else {
            temp.push_back(vetor[j++]);
        }
    }

    while(i <= meio){
        temp.push_back(vetor[i++]);
    }

    while(j <= fim){
        temp.push_back(vetor[j++]);
    }

    for(i = inicio, k = 0; i <= fim; i++, k++){
        vetor[i] = temp[k];
    }

}

void divisao(vector<Time> &vetor, int inicio, int fim){

    if(inicio < fim){

        int meio = (inicio + fim) / 2;
        divisao(vetor, inicio, meio);
        divisao(vetor, meio + 1, fim);
        conquista(vetor, inicio, meio, fim);
    }
}

void mergeSort(vector<Time> &vetor){
    divisao(vetor, 0, vetor.size()-1);
}

int main(){

    vector<Time> times;

    fstream arquivo;
    arquivo.open("dados.txt", fstream::in);

    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo";
        return 1;
    }

    while(!arquivo.eof()){
        string linha;

        string nomeTime = escolherTime(times, arquivo);
        if(nomeTime == "jaFoiTodos"){
            break;
        }

        int vit = 0, der = 0, golsM = 0, golsS = 0, emp = 0;
        fstream arquivoAux;
        arquivoAux.open("dados.txt", fstream::in);
        while(!arquivoAux.eof()){

            getline(arquivoAux, linha);

            if(linha.find(nomeTime) != string::npos){

                // logica pra ver se o time vem antes ou depois do X
                if(linha.find(nomeTime) == 0){

                    int gp = stoi(linha.substr(4)); //logica que eu podia ter usado na maratona pra fazer mais uma questão =(
                    int gs = stoi(linha.substr(6));

                    if(gp == gs) emp++;
                    if(gp > gs) vit++;
                    if(gs > gp) der++;

                    golsM += gp;
                    golsS += gs;

                }
                else{
                    int gp = stoi(linha.substr(6));
                    int gs = stoi(linha.substr(4));

                    if(gp == gs) emp++;
                    if(gp > gs) vit++;
                    if(gs > gp) der++;

                    golsM += gp;
                    golsS += gs;
                }

            }

        }
        Time aux(nomeTime, vit, der, emp, golsM, golsS);

        times.push_back(aux); // adicionando o time para o vetor, para nas prox garantir que eu nao conte os dados dele dnv
        arquivoAux.close();
        arquivo.seekp(0); // resetando o ponteiro do arquivo pro inicio

    }

    arquivo.close();

    cout << "Selecione uma opcao: " << endl;
    cout << "1 - Bubble Sort" << endl;
    cout << "2 - Selection Sort" << endl;
    cout << "3 - Insertion Sort" << endl;
    cout << "4 - Merge Sort" << endl;
    cout << "5 - Sair" << endl;

    int opcao;
    cin >> opcao;

    switch(opcao){

        case 1:
            bubbleSort(times);
            break;
        case 2:
            selectionSort(times);
            break;
        case 3:
            insertionSort(times);
            break;
        case 4:
            mergeSort(times);
            break;
        case 5:
            cout << "Saindo..." << endl;
            return 0;
        default:
            cout << "Opcao invalida!" << endl;
    }

    tabela(times);

    return 0;
}


