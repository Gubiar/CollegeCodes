#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{

    int id;
    int rrn;

}Registro;

int main(){

    int tamanho_vetor;

    FILE *arq;

    arq = fopen("entrada.txt", "r");

    fseek(arq,0,SEEK_END);
    tamanho_vetor = ftell(arq);
    tamanho_vetor = tamanho_vetor/56;
    fseek(arq,0,SEEK_SET);

    printf("%i", tamanho_vetor);

    Registro vetor[tamanho_vetor+1];

    
    return 0;


}
