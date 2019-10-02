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

    for (size_t i = 0; i < 1 ; ++i) {

        FILE *arq;
        arq = fopen("saida.txt", "w");

        if(arq == NULL){
            return false;
        }

        printf("Digite o nome do Aluno: \n");
        scanf("%[^\n]s", buffer);
        cadastro->nome = (char*) malloc(sizeof(char)*strlen(buffer));
        strcpy(cadastro[i].nome, buffer);
        __fpurge(stdin);

        printf("Digite a idade do Aluno: \n");
        scanf("%i", &cadastro[i].idade);
        __fpurge(stdin);

        printf("Digite o endereço do Aluno: \n");
        scanf("%[^\n]s", buffer);
        cadastro->endereco = (char*) malloc(sizeof(char)*strlen(buffer));
        strcpy(cadastro[i].endereco, buffer);
        __fpurge(stdin);

        printf("Digite o curso do Aluno: \n");
        scanf("%[^\n]s", buffer);
        cadastro->curso = (char*) malloc(sizeof(char)*strlen(buffer));
        strcpy(cadastro[i].curso, buffer);
        __fpurge(stdin);

        fprintf(arq, "%-50.50s", cadastro[i].nome);
        fprintf(arq, "%-5i", cadastro[i].idade);
        fprintf(arq, "%-50.50s", cadastro[i].endereco);
        fprintf(arq, "%-50.50s", cadastro[i].curso);
        fprintf(arq, "\n");

        fflush(arq);
        fclose(arq);

    }
}
