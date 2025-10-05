#include <iostream>
#include <ctime>
using namespace std;

void selectionSort(int v[], int tam, int &comp, int &troca) {
    comp = 0;   // zera o contador de comparações
    troca = 0;  // zera o contador de trocas
    // percorre o vetor até o penúltimo elemento
    for (int i = 0; i < tam - 1; i++) {
        int posMenor = i; // guarda a posição do menor elemento encontrado
        // procura o menor elemento no restante do vetor
        for (int j = i + 1; j < tam; j++) {
            comp++; // incrementa a contagem de comparações
            if (v[j] < v[posMenor]) { // verifica se encontrou um valor menor
                posMenor = j; // atualiza a posição do menor elemento
            }
        }
        // troca o elemento atual pelo menor encontrado
        if (posMenor != i) {
            int temp = v[i];
            v[i] = v[posMenor];
            v[posMenor] = temp;
            troca++; // incrementa o número de trocas realizadas
        }
    }
}

/*
int main() {
    int nums[] = {32, 11, 45, 8, 19, 27, 2, 6};
    int n = sizeof(nums) / sizeof(nums[0]);
    int comparas, troc;

    cout << "ANTES -> ";
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << "\n\n";

    clock_t ini = clock();
    selectionSort(nums, n, comparas, troc);
    clock_t fim = clock();

    double t = double(fim - ini) / CLOCKS_PER_SEC * 1000;

    cout << "Depois da ordenacao:\n";
    for (int i = 0; i < n; i++) {
        cout << nums[i];
        if (i < n-1) cout << ",";
    }
    cout << "\n";

    cout << "Comparacoess : " << comparas << endl;
    cout << "Troca(s) : " << troc << endl;
    cout << "Tempo total aproximado : " << t << " ms" << endl;

    return 0;
}
*/
