#include <iostream> // Incluindo biblioteca Iostream para uso do Cout e Cin
#include <stdlib.h>
// #include <stdio.h>
using namespace std; // Usando Namespace std para n�o repetir 'std::cout'

int geraAleatorio(int min, int max){
    return (rand() % (min - max) + min); // Retorna um valor do calculo feito pelo rand
}

void preencherVetor(int *vetor, int tam){
    for(int i = 0; i < tam; i++){
        vetor[i] = geraAleatorio(1, (tam*2)); // Meu vetor na posi��o i ir� receber o valor que a fun��o retorna
        // O (tam*2) serve para evitar alguns erros de memoria, ou acesso ao vetor
    }
}

/*int *copiaVetor(int *vetor, int tam){
    int *valorCopia = new int[tam]; // Aloca��o Dinamica do vetor.

    for(int i = 0; i < tam; i++){
        valorCopia[i] = vetor[i]; // Fa�o a copia do vetor em valorCopia
    }
    return valorCopia; // e retorno o meu valor da copia
}*/

int *copyArray(int *vetor, int tam){
    int *vCopia = new int[tam];

    // Copiar V em vCopia;
    for(int i = 0; i < tam; i++){
        vCopia[i] = vetor[i];
    }
    return vCopia;
}

//Inicio Função de Ordenação Quick Sort
void Quick_Sort(int *vetor, int inicio, int fim){ // Fun��o que
    int pivo, aux, i, j, meio;

    i = inicio;
    j = fim;

    meio = (int) ((i + j) / 2);
    pivo = vetor[meio]; // Escolha do meu pivo, ou seja, ele ir� ser o valor que est� no meio do vetor.

    do{
        while(vetor[i] < pivo)
            i++;
        while(vetor[j] > pivo)
            j--;

        if(i <= j){
            aux = vetor[i]; /// Fa�o um Swap para as trocas dos valores
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++; /// Incremento o I.
            j--; /// Decremento o J.
        }
    }while(j > i);

    if(inicio < j)
        Quick_Sort(vetor, inicio, j); /// Chamada recursiva para Fun��o Quick Sort
    if(i < fim)
        Quick_Sort(vetor, i, fim); /// Chamada recursiva da fun��o quick sort
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void insertionSort(int *vetor, int tam){
	int i, j, aux = 0;
	for(i = 1; i < tam; i++){
		aux = vetor[i];
		for(j = i-1; j >= 0 && vetor[j] > aux; j--){
			vetor[j+1] = vetor[j];
		}
		vetor[j+1] = aux;
	}
}
