#include <iostream>
#include <ctime>
using namespace std;

void quicksort(int v[], int tam, int &comp, int &troca) {
    int pilha[10000]; // pilha usada para simular a recursão
    int topo = -1;    // controla o topo da pilha

    // empilha os índices inicial e final do vetor
    pilha[++topo] = 0;
    pilha[++topo] = tam - 1;

    // enquanto houver subvetores a serem processados
    while (topo >= 0) {
        int fim = pilha[topo--]; // desempilha o índice final
        int ini = pilha[topo--]; // desempilha o índice inicial

        int pivo = v[(ini + fim) / 2]; // escolhe o elemento central como pivô
        int i = ini, j = fim;          // ponteiros para percorrer o vetor

        // particiona o vetor em torno do pivô
        while (i <= j) {
            while (v[i] < pivo) { i++; comp++; } // avança i até achar valor maior que o pivô
            while (v[j] > pivo) { j--; comp++; } // recua j até achar valor menor que o pivô

            if (i <= j) {
                // realiza a troca entre os elementos fora de posição
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
                j--;
                troca++; // conta a troca realizada
            }
        }

        // empilha as novas partições geradas (lado esquerdo e direito)
        if (ini < j) {
            pilha[++topo] = ini;
            pilha[++topo] = j;
        }

        if (i < fim) {
            pilha[++topo] = i;
            pilha[++topo] = fim;
        }
    }
}

/*
int main() {
    int numeros[] = {64, 23, 91, 12, 45, 10, 3, 77};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    int comparas = 0, trocas = 0;

    cout << "Antes da ordenacao:\n";
    for (int i = 0; i < n; i++) cout << numeros[i] << " ";
    cout << "\n\n";

    clock_t ini = clock();
    quicksort(numeros, n, comparas, trocas);
    clock_t fim = clock();

    double tempo = double(fim - ini) / CLOCKS_PER_SEC * 1000.0;

    cout << "Depois da ordenacao:\n";
    for (int i = 0; i < n; i++) {
        cout << numeros[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "\n\n";

    cout << "Comparacoes feitas : " << comparas << endl;
    cout << "Trocas registradas : " << trocas << endl;
    cout << "Tempo aproximado   : " << tempo << " ms" << endl;

    return 0;
}
*/
