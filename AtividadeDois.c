#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct{

    int id;
    int rrn;

}Registro;

int main(){

    char buffer[5];

    int tamanho_vetor;

    FILE *arq;

    arq = fopen("entrada.txt", "r");

    fseek(arq,0,SEEK_END);
    tamanho_vetor = ftell(arq);
    tamanho_vetor = tamanho_vetor/56;
    fseek(arq,0,SEEK_SET);

    Registro vetor[tamanho_vetor+1];

    for(int i =0; i<tamanho_vetor; i++){

          fread(buffer, 4,1 ,arq);
          vetor[i].id = atoi(buffer);
          vetor[i].rrn = i;
          fseek(arq, 52, SEEK_CUR);
    }

/*
    for (size_t j = 0; j <tamanho_vetor ; j++) {
        printf("ID: %i\t", vetor[j].id );
        printf("RRN: %i\n", vetor[j].rrn );
    }
*/
    return 0;
}
