// Merge Sort com contagem de comparações e trocas
#include <iostream>   // inclui a biblioteca de entrada e saída (cout)
using namespace std;  // permite usar cout e endl sem o prefixo std::

int comparacoes = 0;  // contador global de comparações
int trocas = 0;       // contador global de trocas (movimentações)

// intercala as duas metades ordenadas arr[esq..meio] e arr[meio+1..dir]
void intercalar(int arr[], int esq, int meio, int dir) {
    int tam = dir - esq + 1;                // quantidade de elementos do trecho
    int aux[tam];                           // array auxiliar para guardar o resultado da intercalação
    int i = esq;                            // i percorre a metade esquerda
    int j = meio + 1;                       // j percorre a metade direita
    int k = 0;                              // k é a posição de escrita no array auxiliar

    while (i <= meio && j <= dir) {         // enquanto as duas metades ainda têm elementos
        comparacoes++;                      // conta a comparação entre arr[i] e arr[j]
        if (arr[i] <= arr[j]) {             // se o da esquerda é menor ou igual
            aux[k++] = arr[i++];            // copia o da esquerda e avança i e k
        } else {                            // senão, o da direita é menor
            aux[k++] = arr[j++];            // copia o da direita e avança j e k
        }
    }
    while (i <= meio) {                     // sobraram elementos na metade esquerda
        aux[k++] = arr[i++];                // copia o restante da esquerda
    }
    while (j <= dir) {                      // sobraram elementos na metade direita
        aux[k++] = arr[j++];                // copia o restante da direita
    }
    for (int p = 0; p < tam; p++) {         // copia o resultado de volta para o array original
        arr[esq + p] = aux[p];              // escreve cada elemento na posição correta
        trocas++;                           // conta a movimentação
    }
}

// ordena o trecho arr[esq..dir] dividindo ao meio de forma recursiva
void mergeSort(int arr[], int esq, int dir) {
    if (esq >= dir) {                       // caso base: trecho com 0 ou 1 elemento já está ordenado
        return;                             // encerra esta chamada
    }
    int meio = (esq + dir) / 2;             // calcula o ponto médio
    mergeSort(arr, esq, meio);              // ordena a metade esquerda
    mergeSort(arr, meio + 1, dir);          // ordena a metade direita
    intercalar(arr, esq, meio, dir);        // intercala as duas metades ordenadas
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};         // array de entrada usado no teste de mesa
    int n = sizeof(arr) / sizeof(arr[0]);   // calcula a quantidade de elementos

    mergeSort(arr, 0, n - 1);               // chama a ordenação sobre todo o array

    cout << "Merge Sort: ";                 // imprime o título
    for (int i = 0; i < n; i++) {           // percorre o array ordenado
        cout << arr[i] << " ";              // imprime cada elemento
    }
    cout << endl;                           // quebra de linha
    cout << "Comparacoes: " << comparacoes << endl;   // imprime o total de comparações
    cout << "Trocas: " << trocas << endl;             // imprime o total de trocas
    return 0;                               // fim do programa
}
