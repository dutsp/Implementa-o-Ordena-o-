// Insertion Sort com contagem de comparações e trocas
#include <iostream>   // inclui a biblioteca de entrada e saída (cout)
using namespace std;  // permite usar cout e endl sem o prefixo std::

// ordena o array arr de tamanho n; comparacoes e trocas são passados por referência
void insertionSort(int arr[], int n, int &comparacoes, int &trocas) {
    comparacoes = 0;                        // zera o contador de comparações
    trocas = 0;                             // zera o contador de trocas
    for (int i = 1; i < n; i++) {           // o elemento 0 já é uma parte ordenada; começa em 1
        int chave = arr[i];                 // guarda o elemento que será inserido na parte ordenada
        int j = i - 1;                      // j aponta para o último elemento da parte ordenada
        while (j >= 0) {                    // percorre a parte ordenada da direita para a esquerda
            comparacoes++;                  // conta a comparação entre arr[j] e a chave
            if (arr[j] > chave) {           // se o elemento é maior que a chave
                arr[j + 1] = arr[j];        // desloca o elemento uma posição para a direita
                trocas++;                   // conta o deslocamento
                j--;                        // move j para a posição anterior
            } else {                        // se o elemento não é maior que a chave
                break;                      // achou a posição correta, interrompe o laço
            }
        }
        arr[j + 1] = chave;                 // insere a chave na posição livre
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};         // array de entrada usado no teste de mesa
    int n = sizeof(arr) / sizeof(arr[0]);   // calcula a quantidade de elementos
    int comparacoes, trocas;                // variáveis que recebem os contadores

    insertionSort(arr, n, comparacoes, trocas); // chama a ordenação

    cout << "Insertion Sort: ";             // imprime o título
    for (int i = 0; i < n; i++) {           // percorre o array ordenado
        cout << arr[i] << " ";              // imprime cada elemento
    }
    cout << endl;                           // quebra de linha
    cout << "Comparacoes: " << comparacoes << endl;   // imprime o total de comparações
    cout << "Trocas: " << trocas << endl;             // imprime o total de trocas
    return 0;                               // fim do programa
}
