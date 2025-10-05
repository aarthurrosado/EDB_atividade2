#include <iostream>
#include <ctime>
using namespace std;

int particiona(int arr[], int inicio, int fim, int &comparacoes, int &trocas) {
    int pivo = arr[(inicio + fim) / 2]; // escolhe o elemento do meio como pivô
    int i = inicio; // ponteiro que avança da esquerda para a direita
    int j = fim;    // ponteiro que recua da direita para a esquerda

    while (i <= j) {
        // avança i enquanto o elemento for menor que o pivô
        while (arr[i] < pivo) {
            comparacoes++; // conta cada comparação feita
            i++;
        }

        // recua j enquanto o elemento for maior que o pivô
        while (arr[j] > pivo) {
            comparacoes++; // conta cada comparação feita
            j--;
        }

        // quando os ponteiros se cruzam, faz a troca se necessário
        if (i <= j) {
            if (i != j) { // evita trocar o mesmo elemento
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
                trocas++; // incrementa o contador de trocas
            }
            i++;
            j--;
        }
    }

    return i; // retorna o índice onde o vetor será dividido
}

// função recursiva responsável por ordenar as partições
void quickSort(int arr[], int inicio, int fim, int &comparacoes, int &trocas) {
    if (inicio < fim) { // condição de parada da recursão
        int indice = particiona(arr, inicio, fim, comparacoes, trocas); // particiona o vetor
        quickSort(arr, inicio, indice - 1, comparacoes, trocas); // ordena a parte esquerda
        quickSort(arr, indice, fim, comparacoes, trocas);        // ordena a parte direita
    }
}

/*
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
*/
