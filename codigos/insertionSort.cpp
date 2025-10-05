#include <iostream>
#include <ctime>
using namespace std;

void insertionsort(int vetor[], int tam, int &contaComp, int &contaTroca) {
    contaComp = 0;   // inicia o contador de comparacoes
    contaTroca = 0;  // inicia o contador de trocas 

    // percorre o vetor, a partir do segundo elemento do vetor
    for (int i = 1; i < tam; i++) {
        int pivo = vetor[i];   // elemento a ser inserido na parte ordenada
        int k = i - 1;         // indice do elemento anterior

        // desloca elementos maiores que o pivo
        while (k >= 0 && vetor[k] > pivo) {
            contaComp++;               // insere as comparacoes
            vetor[k + 1] = vetor[k];   
            k--;                       
            contaTroca++;              // Conta o deslocamento
        }

        if (k >= 0)
            contaComp++; // incrementa a comparacao

        vetor[k + 1] = pivo;  // insere pivo na posicao correta
    }
}

/*
int main() {
    int lista[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(lista) / sizeof(lista[0]);
    int comps, trocas;
    clock_t ini = clock();
    insertionsort(lista, n, comps, trocas);
    clock_t fim = clock();
    double tempoMs = double(fim - ini) / CLOCKS_PER_SEC * 1000.0;
    cout << "Sequencia final: ";
    for (int i = 0; i < n; i++)
        cout << lista[i] << " ";
    cout << "\n";
    cout << "Comparacoes feitas: " << comps << endl;
    cout << "Trocas registradas: " << trocas << endl;
    cout << "Tempo gasto: " << tempoMs << " ms\n";

    return 0;
}
*/
