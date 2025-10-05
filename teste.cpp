// main.cpp
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "codigos_implementados/bubblesort.cpp"
#include "codigos_implementados/insertionsort.cpp"
#include "codigos_implementados/selectionsort.cpp"
#include "codigos_implementados/mergesort.cpp"
#include "codigos_implementados/quicksort.cpp"
using namespace std;
 void gerarVetor(int vetor[], int tamanho, int tipo) {
    int i; // contador 
    if (tipo == 1) {
        //tipo 1, vetor aleatório
        for (i = 0; i < tamanho; i++) {
            int num = rand() % 1000; // limite menor pra variar mais
            vetor[i] = num;
        }
    }
    else if (tipo == 2) {
        //tipo 2, quase ordenado
        for (i = 0; i < tamanho; i++) {
            vetor[i] = i; // inicia ordenado
            if (i % 10 == 0) { 
                // de vez em quando bagunça um pouco
                vetor[i] += rand() % 5;
            }
        }
    }
    else {
        // tipo 3, inversamente ordenado
        int valor = tamanho;
        for (i = 0; i < tamanho; i++) {
            vetor[i] = valor;
            valor--; // vai descendo
        }
    }
}


int main() {
    srand(time(NULL));
    ofstream saida("../dados/resultados.csv");
    saida << "algoritmo,tamanho,tipo,tempo,comparacoes,trocas\n";

    int tamanhos[] = {1000, 5000, 10000, 20000};

    for (int tipo = 1; tipo <= 3; tipo++) {
        for (int n : tamanhos) {
            int *vetor = new int[n];
            gerarVetor(vetor, n, tipo);

            int c = 0, t = 0;
            clock_t ini, fim;
            double tempo;

            // Bubble
            gerarVetor(vetor, n, tipo);
            c = t = 0;
            ini = clock();
            bubblesort(vetor, n, c, t);
            fim = clock();
            tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
            tempo = tempo * 1000; // converte pra ms
            saida << "BubbleSort," << n << "," << tipo << "," << tempo << "," << c << "," << t << "\n";

            // Insertion
            gerarVetor(vetor, n, tipo);
            c = t = 0;
            ini = clock();
            insertionsort(vetor, n, c, t);
            fim = clock();
            tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
            tempo = tempo * 1000; // converte pra ms
            saida << "InsertionSort," << n << "," << tipo << "," << tempo << "," << c << "," << t << "\n";

            // Selection
            gerarVetor(vetor, n, tipo);
            c = t = 0;
            ini = clock();
            selectionSort(vetor, n, c, t);
            fim = clock();
            tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
            tempo = tempo * 1000; // converte pra ms
            saida << "SelectionSort," << n << "," << tipo << "," << tempo << "," << c << "," << t << "\n";

            // Merge
            gerarVetor(vetor, n, tipo);
            c = t = 0;
            ini = clock();
            mergesort(vetor, n, c, t);
            fim = clock();
            tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
            tempo = tempo * 1000; // converte pra ms
            saida << "MergeSort," << n << "," << tipo << "," << tempo << "," << c << "," << t << "\n";

            // Quick
            gerarVetor(vetor, n, tipo);
            c = t = 0;
            ini = clock();
            quicksort(vetor, n, c, t);
            fim = clock();
            tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
            tempo = tempo * 1000; // converte pra ms
            saida << "QuickSort," << n << "," << tipo << "," << tempo << "," << c << "," << t << "\n";

            delete[] vetor;
        }
    }

    saida.close();
    cout << "Fim, salvo em dados/resultados.csv" << endl;
    return 0;
}
