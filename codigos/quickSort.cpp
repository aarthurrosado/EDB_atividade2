#include <iostream>
#include <ctime>
using namespace std;

int particiona(int arr[], int inicio, int fim, int &comparacoes, int &trocas) {
    int pivo = arr[(inicio + fim) / 2]; // peguei o do meio pra variar
    int i = inicio;
    int j = fim;

    while (i <= j) {
        // anda com o i até achar algo maior que o pivô
        while (arr[i] < pivo) {
            comparacoes++;
            i++;
        }

        // anda com o j até achar algo menor que o pivô
        while (arr[j] > pivo) {
            comparacoes++;
            j--;
        }

        // se cruzaram, hora de trocar
        if (i <= j) {
            if (i != j) {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
                trocas++;
            }
            i++;
            j--;
        }
    }

    return i; // nova posição de corte
}

// A função recursiva que faz a “bagunça virar ordem”
void quickSort(int arr[], int inicio, int fim, int &comparacoes, int &trocas) {
    if (inicio < fim) {
        int indice = particiona(arr, inicio, fim, comparacoes, trocas);
        // resolve o lado esquerdo
        quickSort(arr, inicio, indice - 1, comparacoes, trocas);
        // e o direito
        quickSort(arr, indice, fim, comparacoes, trocas);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparacoes = 0, trocas = 0;

    clock_t inicio = clock();
    quickSort(arr, 0, n - 1, comparacoes, trocas);
    clock_t fim = clock();

    double tempo = double(fim - inicio) / CLOCKS_PER_SEC * 1000;

    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas: " << trocas << endl;
    cout << "Tempo: " << tempo << " ms" << endl;

    return 0;
}
