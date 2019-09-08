#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

                V[i] = aux2;
                V[i+1] = aux;
                troca = true;
            }
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


//Insertion Sort

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


//merge sort

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
                filho++;
            }//if
        }//if

        if(aux < V[filho]){

            V[pai] = V[filho];
            pai = filho;
            filho = 2*pai+1;

        }else{
            filho = fim+1;
        }

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
        criaHeap(V, 0, i-1);
    }
}

int main (int argc, char *argv[]){

    if(argc <2){
        printf("Argumentos insuficientes como parâmetros de entrada para execução do programa. \n");
        printf("Deve-se usar o padrão: nome do programa tipo de organização nome do arquivo. \n");
        printf("Exemplo: ordenador q dados.txt \n");
        return false;
    }

    FILE *arq = NULL;
    int tamanho = 0;

    printf("%s \n", argv[2]);
    arq = fopen(argv[2], "r");
    if(arq == NULL){
        printf("Arquivo não aberto");
        return false;
    }
    fscanf(arq, "%d", &tamanho);
    int *V;

    V= (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; ++i) {
        fscanf(arq, "%i", &V[i]);
    }
    fclose(arq);

    switch (argv[1][0]){

        case 'b': organizabubble(V,tamanho);break;//bubble sort
        case 'q': quicksort(V, 0, tamanho); break;  //quicksort
        case 'm': mergesort(V, 0, tamanho); break;  //merge sort
        case 's': organizaSelection(V, tamanho); break;   //selection sort
        case 'i': organizaInsertion(V, tamanho); break;  //insertion sort
        case 'h': heapSort(V, tamanho);  //heap sort
    }

    for (int j = 0; j < tamanho; ++j) {

        printf("%i \t", V[j]);
    }
    return 0;
}
