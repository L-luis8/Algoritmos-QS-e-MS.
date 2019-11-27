#include <iostream>
#include <chrono>
#include <unistd.h>
#include <fstream>
#include "Utilizavel.h"

using namespace std;
using namespace chrono;

int main(){
    srand(time(0));
    int tam = 0;
    int opcao = 0;
    int cont = 0;

    ///do{
    cout << "Digite o tamanho do vetor: ";
    cin >> tam;

    //int vetor[tam];
    int *vetor = new int[tam];

    cout << "Escolha a opcao que deseja:\n\n"
         << "1 - Quick_Sort\n"
         << "2 - Merge_Sort\n"
         << "3 - Insertion_Sort\n"
         << "0 - Sair.\n";
    cin >> opcao;

    if(opcao == 0) return 0;

    ofstream arquivo("Arquivo_250.000.txt", ios::app); /// ios::app Serve para não sobrecrever

    for(int i = 0; i < 100; i++){
        auto inicio = steady_clock::now();
        preencherVetor(vetor,tam);
        switch(opcao){
            case 1:
                Quick_Sort(vetor, 0, tam);
            break;

            case 2:
                mergeSort(vetor, 0, tam);
            break;

            case 3:
                insertionSort(vetor, tam);
            break;
        }

        steady_clock::time_point fim = steady_clock::now();
        cont += duration_cast<milliseconds>(fim-inicio).count();
    }
    arquivo << "\nMédia Quick_Sort: " << cont/100 << "\n";
    system("cls");
    delete vetor; ///Desalocando Memoria

    cout << "----------\n" << tam <<" Ordenou!\n";

    ///cout << "\nO Vetor foi Ordenado:\n";
    /*for(int i = 0; i < tam; i++){
        cout << vetor[i] << " ";
    }*/
}
