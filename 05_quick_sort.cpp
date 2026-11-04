// Quick Sort com contagem de comparações e trocas
#include <iostream>   // inclui a biblioteca de entrada e saída (cout)
using namespace std;  // permite usar cout e endl sem o prefixo std::

int comparacoes = 0;  // contador global de comparações
int trocas = 0;       // contador global de trocas

// troca os valores de duas posições do array e conta a troca
void trocar(int arr[], int a, int b) {
    int aux = arr[a];                       // guarda arr[a] em uma variável auxiliar
    arr[a] = arr[b];                        // copia arr[b] para a posição a
    arr[b] = aux;                           // coloca o valor antigo de arr[a] na posição b
    trocas++;                               // conta a troca realizada
}

// particiona arr[baixo..alto] usando o último elemento como pivô; retorna a posição final do pivô
int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];                   // escolhe o último elemento como pivô
    int i = baixo - 1;                      // i marca o fim da região de elementos menores que o pivô
    for (int j = baixo; j < alto; j++) {    // percorre todos os elementos antes do pivô
        comparacoes++;                      // conta a comparação entre arr[j] e o pivô
        if (arr[j] < pivo) {                // se o elemento é menor que o pivô
            i++;                            // aumenta a região dos menores
            trocar(arr, i, j);              // leva o elemento menor para dentro dessa região
        }
    }
    trocar(arr, i + 1, alto);               // coloca o pivô entre os menores e os maiores
    return i + 1;                           // retorna a posição final do pivô
}

// ordena o trecho arr[baixo..alto] de forma recursiva
void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {                     // só continua se o trecho tem mais de 1 elemento
        int p = particionar(arr, baixo, alto);  // particiona e obtém a posição do pivô
        quickSort(arr, baixo, p - 1);       // ordena os elementos à esquerda do pivô
        quickSort(arr, p + 1, alto);        // ordena os elementos à direita do pivô
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};         // array de entrada usado no teste de mesa
    int n = sizeof(arr) / sizeof(arr[0]);   // calcula a quantidade de elementos

    quickSort(arr, 0, n - 1);               // chama a ordenação sobre todo o array

    cout << "Quick Sort: ";                 // imprime o título
    for (int i = 0; i < n; i++) {           // percorre o array ordenado
        cout << arr[i] << " ";              // imprime cada elemento
    }
    cout << endl;                           // quebra de linha
    cout << "Comparacoes: " << comparacoes << endl;   // imprime o total de comparações
    cout << "Trocas: " << trocas << endl;             // imprime o total de trocas
    return 0;                               // fim do programa
}
