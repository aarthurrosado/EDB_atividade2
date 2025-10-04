#include <iostream>
#include <ctime>
using namespace std;

void junta(int arr[], int inicio, int meio, int fim, int &comparacoes, int &trocas) {
    int tam1 = meio - inicio + 1;
    int tam2 = fim - meio;

    // Cria vetores temporários
    int L[100000], R[100000];

    // Copia os pedaços pra esses vetores
    for (int i = 0; i < tam1; i++) L[i] = arr[inicio + i];
    for (int j = 0; j < tam2; j++) R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < tam1 && j < tam2) {
        comparacoes++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            trocas++; // considera troca quando muda a origem
        }
        k++;
    }

    // Copia o resto (se sobrou alguma coisa em L)
    while (i < tam1) {
        arr[k++] = L[i++];
    }

    // Copia o resto (se sobrou alguma coisa em R)
    while (j < tam2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int inicio, int fim, int &comparacoes, int &trocas) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        // quebra a lista em duas e ordena cada metade
        mergeSort(arr, inicio, meio, comparacoes, trocas);
        mergeSort(arr, meio + 1, fim, comparacoes, trocas);

        // junta tudo ordenado no final
        junta(arr, inicio, meio, fim, comparacoes, trocas);
    }
}

int main() {
    int arr[] = {5, 34, 20, 12, 25, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparacoes = 0, trocas = 0;

    clock_t inicio = clock();
    mergeSort(arr, 0, n - 1, comparacoes, trocas);
    clock_t fim = clock();

    double tempo = double(fim - inicio) / CLOCKS_PER_SEC * 1000;

    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas (aproximadas): " << trocas << endl;
    cout << "Tempo: " << tempo << " ms" << endl;

    return 0;
}
