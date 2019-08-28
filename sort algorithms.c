#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//bubble sort
/*
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

                V[i] = aux2;
                V[i+1] = aux;
                troca = true;
            }
        }
        N--;
    }while(troca);
}
*/

//Selection Sort
/*
void organizaSelection(int *V, int N){

    int aux;
    int min;

    for(int i = 0; i<N-1; i++){

        min = i;

        for(int j = i+1; j<N; j++){

            if(V[min]>V[j]){
                min = j;
            }
        }

        if(min != i){

        aux = V[i];
        V[i] = V[min];
        V[min] = aux;

        }
    }
}

*/
//Insertion Sort
/*
void organizaInsertion(int *V, int N){

    int aux;

    for(int i = 1; i<N; i++){

        aux = V[i];
        int j = i-1;

        while(j>=0 && V[j]>aux){
            V[j+1] = V[j];
            j--;
        }
        V[j+1] = aux;
    }
}
*/

//merge sort
/*
void mergesort(int *V, int inicio, int fim){

    int meio;

    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergesort(V, inicio, meio);
        mergesort(V, meio+1, fim);
        merge(V,inicio,meio,fim);
    }
}

int merge(int *V, int inicio, int meio, int fim){

    int *V2 = malloc (((fim - inicio)+1) * sizeof(int));

    int p1 = inicio;
    int p2 = meio+1;
    int pv = 0;

    while(p1<=meio && p2<=fim){

        //copia menor
        if(V[p1] < V[p2]){

            V2[pv] = V[p1];
            p1++;
            pv++;

        }else{
            V2[pv] = V[p2];
            p2++;
            pv++;
        }
    }
    while(p1<=meio){

        //copia p1
        V2[pv] = V[p1];
        pv++;
        p1++;
    }

    while(p2<=fim){

        //copia p2
        V2[pv] = V[p2];
        pv++;
        p2++;
    }

    for(int i= inicio, j=0; i<=fim; i++,j++){
        V[i] = V2[j];

    }
    free(V2);

}

*/

//quick sort

void quicksort(int *V, int inicio, int fim){
    int pivo;

    if(inicio < fim){
        pivo = particiona(V, inicio, fim);
        quicksort(V,inicio, pivo-1);
        quicksort(V, pivo+1, fim);
    }
}

int particiona(int *V, int inicio, int fim){

    int esquerda = inicio;
    int direita = fim;
    int pivo = V[inicio];


    while(esquerda<=direita){

        while(V[esquerda] <= pivo){
        esquerda++;

        }

        while(V[direita] > pivo){
            direita--;

        }

        if(esquerda < direita){

            int aux = V[esquerda];
            V[esquerda] = V[direita];
            V[direita] = aux;
        }
    }

    V[inicio] = V[direita];
    V[direita] = pivo;

    return direita;

} // função particiona

//Gera vetor aleatorio

int* geraVetor(int tamanho){

    int *vetor = (int *) malloc(tamanho * sizeof(int));
    srand(time(NULL));

    for(int i=0; i< tamanho; i++){

        vetor[i] = rand()%tamanho;
    }
    return vetor;
}


int main(){

    int tamanho = 1000000;

    int *vetor = geraVetor(tamanho);

   //printa antes de arrumar
   for(int k=0; k<tamanho; k++){
        printf("[%i]\t", vetor[k]);
    }

    printf("\n-----------------\n");

    quicksort(vetor, 0, tamanho-1);

    //printa deppois de organizar
    for(int k=0; k<tamanho; k++){
       printf("[%i]\t", vetor[k]);
    }

}
