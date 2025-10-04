#include <iostream>
#include <ctime>
using namespace std;

void insertionSort(int arr[], int n, int &comparacoes, int &trocas) {
    comparacoes = 0;
    trocas = 0;
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        // elementos maiores para direita
        while (j >= 0 && arr[j] > chave) {
            comparacoes++;
            arr[j + 1] = arr[j];
            j--;
            trocas++;
        }
        if (j >= 0) comparacoes++;
        arr[j + 1] = chave;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparacoes, trocas;
    clock_t inicio = clock();
    insertionSort(arr, n, comparacoes, trocas);
    clock_t fim = clock();
    double tempo = double(fim - inicio) / CLOCKS_PER_SEC * 1000;
    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas: " << trocas << endl;
    cout << "Tempo de execucao: " << tempo << " ms" << endl;

    return 0;
}
