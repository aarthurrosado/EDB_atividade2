#include <iostream>
#include <ctime>
using namespace std;
void bubblesort(int arr[], int n, int &comparacoes, int &trocas) {
    comparacoes = 0;
    trocas = 0;
    bool trocou;
    for (int i = 0; i < n - 1; i++) {
        trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocas++;
                trocou = true;
            }
        }
        if (!trocou) break; // se nao trocar, já está ordenado.
    }
}
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
