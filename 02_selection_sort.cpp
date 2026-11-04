// Selection Sort com contagem de comparações e trocas
#include <iostream>   // inclui a biblioteca de entrada e saída (cout)
using namespace std;  // permite usar cout e endl sem o prefixo std::

// ordena o array arr de tamanho n; comparacoes e trocas são passados por referência
void selectionSort(int arr[], int n, int &comparacoes, int &trocas) {
    comparacoes = 0;                        // zera o contador de comparações
    trocas = 0;                             // zera o contador de trocas
    for (int i = 0; i < n - 1; i++) {       // i é a posição que vai receber o menor elemento
        int menor = i;                      // assume que o menor valor está na posição i
        for (int j = i + 1; j < n; j++) {   // procura o menor na parte ainda não ordenada
            comparacoes++;                  // conta a comparação entre arr[j] e arr[menor]
            if (arr[j] < arr[menor]) {      // se achou um valor menor que o atual menor
                menor = j;                  // atualiza o índice do menor
            }
        }
        if (menor != i) {                   // só troca se o menor não já está na posição i
            int aux = arr[i];               // guarda arr[i] em uma variável auxiliar
            arr[i] = arr[menor];            // coloca o menor valor na posição i
            arr[menor] = aux;               // coloca o valor antigo de arr[i] onde estava o menor
            trocas++;                       // conta a troca realizada
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};         // array de entrada usado no teste de mesa
    int n = sizeof(arr) / sizeof(arr[0]);   // calcula a quantidade de elementos
    int comparacoes, trocas;                // variáveis que recebem os contadores

    selectionSort(arr, n, comparacoes, trocas); // chama a ordenação

    cout << "Selection Sort: ";             // imprime o título
    for (int i = 0; i < n; i++) {           // percorre o array ordenado
        cout << arr[i] << " ";              // imprime cada elemento
    }
    cout << endl;                           // quebra de linha
    cout << "Comparacoes: " << comparacoes << endl;   // imprime o total de comparações
    cout << "Trocas: " << trocas << endl;             // imprime o total de trocas
    return 0;                               // fim do programa
}
