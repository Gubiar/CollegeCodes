#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanho;

void converte_maisculoMinusculo(char *vetor){

}

void inverteLinha(char *vetor){

}

void metadeVoltaUm(char *vetor){

}

void limpaBuffer(){
    char c;
    while((c = getchar()) != '\n' && c!= EOF) {}
}


int main() {

    int tam = 1000;

    char texto[tam];

    int textoNum[tam];

    char textoCrip[tam];

    fgets(texto, tam, stdin);

    texto[strcspn(texto, "\n")] = '\0';

    for (int i = 0; i <  strlen(texto); ++i) {
        
        textoNum[i] = (int) texto[i];

        textoNum[i] = textoNum[i]+3;

        textoCrip[i] = (char) textoNum[i];

        printf("%c", textoCrip[i]);
        tamanho++;

    }


    //int vetor[1000] = (int) texto[1000];

    return 0;
}
