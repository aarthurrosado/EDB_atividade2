# Estruturas de Dados - Atividade 2
**Autor:** Arthur Luiz Rosado Alves  
**Professor:** João Guilherme  
**Disciplina:** IMD0029 - Estruturas de Dados  
**Instituição:** UFRN  

---

## Descrição do Trabalho
Este repositório contém a implementação e análise de desempenho de **algoritmos de ordenação**, desenvolvidos para a Atividade 2 da disciplina **Estruturas de Dados**.  
O objetivo principal é comparar o tempo de execução entre os métodos de ordenação clássicos, aplicados a diferentes tamanhos e tipos de vetores.

---

## Algoritmos Implementados
Foram implementados os seguintes algoritmos de ordenação:

- **Bubble Sort**
- **Insertion Sort**
- **Selection Sort**
- **Merge Sort**
- **Quick Sort**

Cada algoritmo foi desenvolvido em um arquivo separado, dentro da pasta `codigos/`, permitindo modularidade e fácil manutenção.

---

## Metodologia
Os testes foram realizados variando:
- O **tamanho do vetor** (1.000, 5.000, 10.000 e 20.000 elementos);
- O **tipo de ordenação inicial** do vetor:
  - Aleatório;
  - Crescente;
  - Decrescente.

Os tempos de execução foram coletados e armazenados no arquivo `resultados.csv`, com as colunas:
- **Algoritmo**
- **Tamanho do vetor**
- **Tipo de vetor**
- **Tempo de execução (ms)**

---
## Estrutura esperada 
```
EDB_atividade2/
│
├── codigos_implementados/       # Implementações dos algoritmos de ordenação (.cpp)
│   ├── bubblesort.cpp
│   ├── insertionsort.cpp
│   ├── mergesort.cpp
│   ├── quicksort.cpp
│   └── selectionsort.cpp
│
├── dados/                       # Arquivos de resultados (.csv)
│   └── resultados.csv
│
├── imagens/                     # Gráficos e visualizações geradas
│   ├── comparativo_tempo.png
│   └── desempenho_algoritmos.png
│
├── output/                      # Pasta para os executáveis gerados
│   └── teste.exe
│
├── teste.cpp                    # Arquivo principal que executa os testes

```
##  Compilação e Execução
###  Via Terminal (Windows/PowerShell)
No diretório raiz do projeto, execute:
```bash
 g++ .\teste.cpp -o teste.exe
```
depois execute:
```bash
.\teste.exe
```
