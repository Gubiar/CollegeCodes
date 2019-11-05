#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    int id;
    int rrn;
}Registro;

int particiona(Registro *V, int inicio, int fim){

    int esquerda = inicio;
    int direita = fim;
    int pivo = V[inicio].id;

    while(esquerda<=direita){

        while(V[esquerda].id <= pivo){
            esquerda++;
        }

        while(V[direita].id > pivo){
            direita--;
        }

        if(esquerda < direita){

            Registro aux = V[esquerda];
            V[esquerda] = V[direita];
            V[direita] = aux;
        }
    }

    Registro aux =V[inicio];
    V[inicio] = V[direita];
    V[direita] = aux;

    return direita;
}

void quicksort(Registro *V, int inicio, int fim){
    int pivo;

    if(inicio < fim){
        pivo = particiona(V, inicio, fim);
        quicksort(V,inicio, pivo-1);
        quicksort(V, pivo+1, fim);
    }

}


int main(){

    //Ordenas struct com os ID e RRN ***************************************
    char buffer[5];
    int tamanho_vetor;

    FILE *arq;

    arq = fopen("entrada.txt", "r");

    fseek(arq,0,SEEK_END);
    tamanho_vetor = ftell(arq);
    tamanho_vetor = tamanho_vetor/56;
    fseek(arq,0,SEEK_SET);

    Registro vetor[tamanho_vetor];

    for(int i =0; i<tamanho_vetor; i++){

        fread(buffer, 4,1 ,arq);
        vetor[i].id = atoi(buffer);
        vetor[i].rrn = i;
        fseek(arq, 52, SEEK_CUR);
    }

    quicksort(vetor,0,tamanho_vetor-1);
    fclose(arq);

    printf("%i %i",vetor[0].id,vetor[0].rrn);

    //**********************************************************************

    //Tarefa 2 *************************************************************
    arq = fopen("indicePrimario_ID", "w");

    for (int j = 0; j < tamanho_vetor ; ++j) {

        fprintf(arq, "%i|%i \n", vetor[j].id, vetor[j].rrn);
    }

    fflush(arq);
    fclose(arq);

    //***************************************************************************

    //Tarefa 1 *****************************************************************

    FILE *arq2;

    arq = fopen("entrada.txt", "r");
    arq2 = fopen("DadosPilotoID.txt", "w");

    char registro[57];

    for (int k = 0; k < tamanho_vetor ; ++k) {

        fseek(arq, 56 * vetor[k].rrn, SEEK_SET);
        fgets(registro, 57, arq);
        fprintf(arq2, "%s", registro);
    }
    fflush(arq2);
    fclose(arq);
    fclose(arq2);

    bool controle = true;
    int op;
    do {
        printf(" ========= Pilotos de Fórmula 1 ===========\n1 – Listar todos os dados em uma tabela\n2 – Pesquisar por Nome\n3 – Pesquisar por País\n4 – Sair do programa\nDigite sua opção: ");
        scanf("%i", &op);

        switch (op)
        {
        case 1:


        case 2:

            break;

        case 3:

            break;

        case 4:
            controle = false;
            printf("Saindo...");
            break;
        default:
            printf ("\nOpcao invalida, tente novamente\n");             //controle de erro para opções inválidas
            break;
        }

    } while (controle);
    

    return 0;
}
