#include <iostream>
#include <ctime>
using namespace std;

void misturar(int v[], int ini, int meio, int fim, int &comp, int &troca) {
    int t1 = meio - ini + 1, t2 = fim - meio; // define o tamanho de cada subvetor
    int a[100000], b[100000]; // vetores temporários para armazenar as metades
    for (int i = 0; i < t1; i++) a[i] = v[ini + i]; // copia a primeira metade
    for (int j = 0; j < t2; j++) b[j] = v[meio + 1 + j]; // copia a segunda metade
    int i = 0, j = 0, k = ini; // índices para percorrer os vetores
    // compara e intercala os elementos de cada metade
    while (i < t1 && j < t2) {
        comp++; // incrementa a contagem de comparações
        if (a[i] <= b[j]) { // se o elemento da esquerda for menor
            v[k] = a[i];
            i++;
        } else { // caso contrário, pega o elemento da direita
            v[k] = b[j];
            j++;
            troca++; // registra a movimentação
        }
        k++; // avança no vetor principal
    }
    // copia os elementos restantes da primeira metade, se houver
    while (i < t1) v[k++] = a[i++];
    // copia os elementos restantes da segunda metade, se houver
    while (j < t2) v[k++] = b[j++];
}

void mergesort(int v[], int n, int &comp, int &troca) {
    // loop para controlar o tamanho dos blocos de ordenação (1, 2, 4, 8, ...)
    for (int passo = 1; passo < n; passo *= 2) {
        // percorre o vetor unindo as partes de tamanho "passo"
        for (int comeco = 0; comeco < n - passo; comeco += 2 * passo) {
            int meio = comeco + passo - 1; // define o meio do bloco
            int fim = comeco + 2 * passo - 1; // define o final do bloco
            if (fim >= n) fim = n - 1; // ajusta o limite para não ultrapassar o vetor
            misturar(v, comeco, meio, fim, comp, troca); // realiza a junção ordenada
        }
    }
}

/*
int main() {
    int dados[] = {38, 27, 43, 3, 9, 82, 10};
    int tam = sizeof(dados) / sizeof(dados[0]);
    int c = 0, t = 0;

    cout << "Antes: ";
    for (int i = 0; i < tam; i++) cout << dados[i] << " ";
    cout << endl;

    clock_t ini = clock();
    mergesort(dados, tam, c, t);
    clock_t fim = clock();

    double tempo = double(fim - ini) / CLOCKS_PER_SEC * 1000.0;

    cout << "\n--- RESULTADOS ---\n";
    cout << "Total de elementos: " << tam << endl;
    cout << "Comparacoes feitas: " << c << endl;
    cout << "Trocas realizadas: " << t << endl;
    cout << "Tempo gasto: " << tempo << " ms\n\n";

    cout << "Depois: [ ";
    for (int i = 0; i < tam; i++) {
        cout << dados[i];
        if (i < tam - 1) cout << ", ";
    }
    cout << " ]" << endl;

    return 0;
}
*/
