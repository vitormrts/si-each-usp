#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <limits.h>

#define MAX 200

struct registro {
    char nroUsp[9];
    char nome[21];
    // int nota;
    int idade;
    int valido;
};

void imprime(struct registro vetor_alunos[], int nroRegs) {
    int i;
    printf("\n===================================\n");
    printf("Há %d alunos cadastrados.\n", nroRegs);
    for (i = 0; i < nroRegs; i++) {
        printf("\n%7s ", vetor_alunos[i].nroUsp);
        printf("%20s ", vetor_alunos[i].nome);
        printf("%d ", vetor_alunos[i].idade);
        printf("%d", vetor_alunos[i].valido);
    }
    printf("\n===================================\n");
}

void variavelParaFixo(char* pathEntrada) {
    FILE *arqEntrada = fopen(pathEntrada, "rb");
    FILE *arqSaida;

    int i;
    
    char nroUsp[9];
    char nome[20];
    int idade;
    int valido;

    struct registro alunos[MAX];
    struct registro aluno;

    if (!arqEntrada) {
        printf("Arquivo nao encontrado.\n");
    } else {
        i = 0;
        FILE *arqSaida = fopen("fixo.txt", "w+");

        while (!feof(arqEntrada)) {
            // fscanf(arqEntrada, "%[^/]%*c/%[^/]%*c/%d/%d", nroUsp, nome, &idade, &valido);
            // fgets(aluno.nroUsp, 8, arqEntrada);
            // fgets(aluno.nome, 21, arqEntrada);
            fscanf(arqEntrada, "%[^/]%*c", nroUsp);
            fscanf(arqEntrada, "%[^/]%*c", nome); // le ate `/` e pula esse caracter
            fscanf(arqEntrada, "%d/", &idade);
            fscanf(arqEntrada, "%d\n", &valido);
            
            strcpy(alunos[i].nroUsp, nroUsp);
            strcpy(alunos[i].nome, nome);
            alunos[i].idade = idade;
            alunos[i].valido = valido;

            // printf("%s", alunos[i].nroUsp);
            // printf("     %s", alunos[i].nome);
            // printf(" %d", alunos[i].idade);
            // printf("     %d\n", alunos[i].valido);
            
            i++;
        } 

        fwrite(&alunos, sizeof(struct registro), MAX, arqSaida);
        fclose(arqEntrada);
    }
}

void imprimeArquivoFixo(char* pathSaida, int nroRegs) {   
    FILE *arqSaida = fopen(pathSaida, "rb");

    struct registro vetor_alunos[nroRegs];
    int i;

    if (!arqSaida) {
        printf("Nao foi possivel abrir o arquivo.\n");
    } else {
        fread(&vetor_alunos, sizeof(struct registro), nroRegs, arqSaida);
        for (i = 0; i < nroRegs; i++) {
            printf("\n%s ", vetor_alunos[i].nroUsp);
            printf("%s ", vetor_alunos[i].nome);
            printf("%d ", vetor_alunos[i].idade);
            printf("%d", vetor_alunos[i].valido);
        }
    }
}

int main ()
{
    char *pathEntrada = (char*) "variavel.txt";
    char *pathSaida = (char*) "fixo.txt";

    variavelParaFixo(pathEntrada);
    imprimeArquivoFixo(pathSaida, 10);



}

