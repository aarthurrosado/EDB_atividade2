#include <iostream>
#include <ctime>
using namespace std;

void selectionsort(int v[], int tam, int &comp, int &troca) {
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
    int nums[] = {32, 18, 45, 5, 3, 22, 21, 90, 99, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int comparas, troc;

    cout << "antes ";
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << "\n\n";

    clock_t ini = clock();
    selectionsort(nums, n, comparas, troc);
    clock_t fim = clock();

    double t = double(fim - ini) / CLOCKS_PER_SEC * 1000;

    cout << "Apos a ordenação \n";
    for (int i = 0; i < n; i++) {
        cout << nums[i];
        if (i < n-1) cout << ",";
    }
    cout << "\n";

    cout << "Comparacoes : " << comparas << endl;
    cout << "Trocas : " << troc << endl;
    cout << "Tempo total: " << t << " ms" << endl;

    return 0;
}
*/
