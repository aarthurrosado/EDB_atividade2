#include <iostream>
#include <ctime>
using namespace std;

void selectionsort(int arr[], int n, int &comparacoes, int &trocas) {
    comparacoes = 0;
    trocas = 0;

    // Percorre o vetor todo
    for (int i = 0; i < n - 1; i++) {
        int menor = i; // guarda a posição do menor valor

        // procura o menor elemtento
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (arr[j] < arr[menor]) {
                menor = j;
            }
        }
      // troca o menor elemento
      if (menor != i) {
            int aux = arr[i];
            arr[i] = arr[menor];
            arr[menor] = aux;
            trocas++;
        }
    }
}

int main() {
    int dados[] = {1, 2, 40, 21, 15, 99, 3, 6, 90};
    int n = sizeof(dados) / sizeof(dados[0]);
    int comparacoes, trocas;
    clock_t inicio = clock();
    selectionSort(dados, n, comparacoes, trocas);
    clock_t fim = clock();
    double tempo = double(fim - inicio) / CLOCKS_PER_SEC * 1000;
    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << dados[i] << " ";
    }
    cout << "\n";
    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas: " << trocas << endl;
    cout << "Tempo de execucao: " << tempo << " ms" << endl;

    return 0;
}
