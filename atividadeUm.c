#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int comparacoes;  //varaivel global que armazena as comparaçoes realizadas por cada sort
int trocas;

//bubble sort
void organizabubble(int *V, int N){
    int aux;
    int aux2;
    bool troca;

    do{
        troca = false;
        for(int i = 0; i < N-1; i++){

            aux = V[i];
            aux2 = V[i+1];
            if(aux > aux2){
                comparacoes++;
                trocas++;
                V[i] = aux2;
                V[i+1] = aux;
                troca = true;
            }
            for (int k = 0; k < 10 ; ++k) {
                printf("%d \t", V[k]);
            }printf("\n");
        }
        N--;

    }while(troca);
}

//Selection Sort

void organizaSelection(int *V, int N){

    int aux;
    int min;

    for(int i = 0; i<N-1; i++){
        min = i;

        for(int j = i+1; j<N; j++){

            if(V[min]>V[j]){
                comparacoes++;
                min = j;
            }
        }

        if(min != i){

            aux = V[i];
            V[i] = V[min];
            V[min] = aux;
            trocas++;
        }

        for (int k = 0; k < 10 ; ++k) {
            printf("%d \t", V[k]);

        }printf("\n");
    }
}

//Insertion Sort

void organizaInsertion(int *V, int N){

    int aux;

    for(int i = 1; i<N; i++){
        aux = V[i];
        int j = i-1;

        while(j>=0 && V[j]>aux){
            comparacoes++;
            trocas++;
            V[j+1] = V[j];
            j--;
        }
        V[j+1] = aux;
        for (int k = 0; k < 10 ; ++k) {
            printf("%d \t", V[k]);

        }printf("\n");
    }
}

//merge sort

void merge(int *V, int inicio, int meio, int fim){

    int *V2 = malloc (((fim - inicio)+1) * sizeof(int));
    int p1 = inicio;
    int p2 = meio+1;
    int pv = 0;

    while(p1<=meio && p2<=fim){

        //copia menor
        if(V[p1] < V[p2]){
            comparacoes++;
            trocas++;
            V2[pv] = V[p1];
            p1++;
            pv++;

        }else{
            comparacoes++;
            trocas++;
            V2[pv] = V[p2];
            p2++;
            pv++;
        }
    }
    while(p1<=meio){
        comparacoes++;
        trocas++;
        V2[pv] = V[p1];
        pv++;
        p1++;
    }

    while(p2<=fim){
        comparacoes++;
        trocas++;
        V2[pv] = V[p2];
        pv++;
        p2++;
    }

    for(int i= inicio, j=0; i<=fim; i++,j++){
        V[i] = V2[j];
    }
    free(V2);
}

void mergesort(int *V, int inicio, int fim){

    int meio;

    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergesort(V, inicio, meio);
        mergesort(V, meio+1, fim);
        merge(V,inicio,meio,fim);
    }
}

//quick sort

int particiona(int *V, int inicio, int fim){

    int esquerda = inicio;
    int direita = fim;
    int pivo = V[inicio];

    while(esquerda<=direita){

        while(V[esquerda] <= pivo){
            comparacoes++;
            esquerda++;
        }

        while(V[direita] > pivo){
            comparacoes++;
            direita--;
        }

        if(esquerda < direita){
            trocas++;
            int aux = V[esquerda];
            V[esquerda] = V[direita];
            V[direita] = aux;
        }

        for (int k = 0; k < 10 ; ++k) {
            printf("%d \t", V[k]);

        }printf("\n");
    }
    trocas++;
    V[inicio] = V[direita];
    V[direita] = pivo;
    return direita;

} // função particiona

void quicksort(int *V, int inicio, int fim){
    int pivo;

    if(inicio < fim){
        pivo = particiona(V, inicio, fim);
        quicksort(V,inicio, pivo-1);
        quicksort(V, pivo+1, fim);
    }
}

void criaHeap(int *V, int pai, int fim){

    int filho = 2*pai+1;
    int aux = V[pai];

    while(filho <= fim){

        if(filho < fim ){

            if(V[filho] < V[filho+1]){
                comparacoes++;
                filho++;
            }//if
        }//if

        if(aux < V[filho]){
            comparacoes++;
            trocas++;
            V[pai] = V[filho];
            pai = filho;
            filho = 2*pai+1;

        }else{
            comparacoes++;
            filho = fim+1;
        }
        for (int k = 0; k < 10 ; ++k) {
            printf("%d \t", V[k]);

        }printf("\n");
    }//while
    V[pai] = aux;
}//função

void heapSort(int *V, int tamanho){
    int i, aux;

    for(i=(tamanho-1)/2; i>=0; i--){
        criaHeap(V, i, tamanho-1);
    }

    for(i = tamanho-1; i>=1; i--){
        aux = V[0];
        V[0] = V[i];
        V[i] = aux;
        trocas++;
        criaHeap(V, 0, i-1);
    }
}

int main() {
    int vetor[10] = {66, 9, 61, 75, 38, 30, 33, 14, 85, 69};
    heapSort(vetor, 10);
    printf("Quantidade de Comparações: %i \n", comparacoes);
    printf("Quantidade de trocas: %i \n", trocas);
    return 0;
}
