#include <iostream>
#include <ctime>
using namespace std;
void bubblesort(int arr[], int n, int &comparacoes, int &trocas) {
    comparacoes = 0; // inicializa comparacoes com 0
    trocas = 0; // inicializa comparacoes com 0
    bool trocou; // condicinal de trocou
    for (int i = 0; i < n - 1; i++) { //  controla o numero de passagens pelo vetor
        trocou = false; // indica se houve troca
        for (int j = 0; j < n - i - 1; j++) { // laco interno, percorre o vetor comparando os elementos
            comparacoes++; // incrementa quando uma comparacao for feita
            if (arr[j] > arr[j + 1]) { // realiza troca quando o elemento for maior do que o elemento ao lado
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; // finaliza a troca
                trocas++; // conta a troca
                trocou = true; // indica se houve troca
            }
        }
        if (!trocou) break; // se nao trocar, já está ordenado.
    }
}
/*
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long comparacoes, trocas;

    clock_t start = clock();
    bubbleSort(arr, n, comparacoes, trocas);
    clock_t fim = clock();

    double tempo = double(start - inicio) / CLOCKS_PER_SEC * 1000;

    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas: " << trocas << endl;
    cout << "Tempo de execucao: " << tempo << " ms" << endl;

    return 0;
}
*/
