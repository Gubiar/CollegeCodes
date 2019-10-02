#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char *nome;
    char *endereco;
    int idade;
    char *curso;
}Aluno;

int main() {

    Aluno cadastro[1];
    char buffer[100];

    for (size_t i = 0; i < 1; ++i) {

        FILE *arq;
        arq = fopen("saida.txt", "r");

        if (arq == NULL) {
            return false;
        }

        printf("Lendo o nome do Aluno:\n");

        fscanf(arq, "%50s", buffer);
        printf("%s\n", buffer);

        printf("------------------- \n");

        fscanf(arq, "%5s", buffer);
        printf("%s\n", buffer);

        printf("---------------------\n");

        fscanf(arq, "%50[^\n]s", buffer);
        printf("%s\n", buffer);

        printf("---------------------\n");

        fscanf(arq, "%50[^\n]s", buffer);
        printf("%s\n", buffer);



    }
}
