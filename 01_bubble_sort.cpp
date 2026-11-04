// Bubble Sort com contagem de comparações e trocas
#include <iostream>   // inclui a biblioteca de entrada e saída (cout)
using namespace std;  // permite usar cout e endl sem o prefixo std::

// ordena o array arr de tamanho n; comparacoes e trocas são passados por referência
void bubbleSort(int arr[], int n, int &comparacoes, int &trocas) {
    comparacoes = 0;                        // zera o contador de comparações
    trocas = 0;                             // zera o contador de trocas
    for (int i = 0; i < n - 1; i++) {       // cada passada coloca o maior elemento restante no fim
        bool houveTroca = false;            // marca se esta passada fez alguma troca
        for (int j = 0; j < n - 1 - i; j++) {   // percorre apenas a parte ainda não ordenada
            comparacoes++;                  // conta a comparação entre arr[j] e arr[j+1]
            if (arr[j] > arr[j + 1]) {      // se o par está fora de ordem
                int aux = arr[j];           // guarda arr[j] em uma variável auxiliar
                arr[j] = arr[j + 1];        // coloca o menor na posição j
                arr[j + 1] = aux;           // coloca o maior na posição j+1
                trocas++;                   // conta a troca realizada
                houveTroca = true;          // registra que houve troca nesta passada
            }
        }
        if (!houveTroca) {                  // se nenhuma troca ocorreu, o array já está ordenado
            break;                          // encerra o algoritmo antes do fim
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};         // array de entrada usado no teste de mesa
    int n = sizeof(arr) / sizeof(arr[0]);   // calcula a quantidade de elementos
    int comparacoes, trocas;                // variáveis que recebem os contadores

    bubbleSort(arr, n, comparacoes, trocas);    // chama a ordenação

    cout << "Bubble Sort: ";                // imprime o título
    for (int i = 0; i < n; i++) {           // percorre o array ordenado
        cout << arr[i] << " ";              // imprime cada elemento
    }
    cout << endl;                           // quebra de linha
    cout << "Comparacoes: " << comparacoes << endl;   // imprime o total de comparações
    cout << "Trocas: " << trocas << endl;             // imprime o total de trocas
    return 0;                               // fim do programa
}
