#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define MAX 200

struct tipo_registro {
    char nrousp[9];
    char nome[20];
    int idade;
    int valido; // 1 = ok; 0 = excluido
};

void imprime(struct tipo_registro aluno) {
    printf("\n%7s ", aluno.nrousp);
    printf("%20s ", aluno.nome);
    printf("%2d ", aluno.idade);
    printf("%d", aluno.valido);
}

void imprimeArquivoFixo(char* pathSaida, int nroRegs) {   
    FILE *arqSaida = fopen(pathSaida, "rb");

    struct tipo_registro vetor_alunos[nroRegs];
    int i;

    if (!arqSaida) {
        printf("Nao foi possivel abrir o arquivo.\n");
    } else {
        fread(&vetor_alunos, sizeof(struct tipo_registro), nroRegs, arqSaida);
        for (i = 0; i < nroRegs; i++) {
            printf("\n%s ", vetor_alunos[i].nrousp);
            printf("%s ", vetor_alunos[i].nome);
            printf("%d ", vetor_alunos[i].idade);
            printf("%d", vetor_alunos[i].valido);
        }
    }
}

// quando inserir um elemento => vetor_alunos[proximo].valido = 1;
 
// Salva o arquivo registro a registro evitando os registros invalidos
void salvarArquivo(char* path, int proximo, struct tipo_registro vetor_alunos[]) {
    FILE *arq = fopen(path, "w");
    // fread(&vetor_alunos, sizeof(tipo_registro), proximo, ...);

    int i = 0;
      
    for (i = 0; i < proximo; i++) {
            if (vetor_alunos[i].valido == 1) {
                fwrite(&vetor_alunos[i], sizeof(tipo_registro), 1, arq);
        }
    }
    fclose(arq);
};

// Procura item sequencialmente pelo codigo e marca como excluido
bool marcarComoExcluido(struct tipo_registro vetor_alunos[], char *codigo, int proximo) {
    int i; 
    for (i = 0; i < proximo; i++) {
        if (strcmp(codigo, vetor_alunos[i].nrousp) == 0) { // codigo eh igual ao nrousp
            vetor_alunos[i].valido = 0; // "apaga" o registro
            return true; // sucesso => encontrou
        }
    }
    return false; // nao encontrou
}

// Exercicio: usando o struct da aula arquivos parte 3, escreva um programa que recebe como entrada um arquivo com registros deste tipo 
// (ou seja, de tamanho fixo) e dois endereços (bytes iniciais) de registro r1 e r2, e faça a troca
// destes dois registros, ou seja, escrevendo r1 na posição r2 e vice-versa. 

void atualizarRegistros(FILE *arq, int r1, int r2) {
    rewind(arq); // coloca o ponteiro no inicio do arquivo previamente aberto
    struct tipo_registro aluno;

    struct tipo_registro aluno_r1;
    struct tipo_registro aluno_r2;
    
    fseek(arq, r1 * sizeof(tipo_registro), SEEK_SET);
    fread(&aluno_r1, sizeof(tipo_registro), 1, arq);

    fseek(arq, r2 * sizeof(tipo_registro), SEEK_SET);
    fread(&aluno_r2, sizeof(tipo_registro), 1, arq);

    fseek(arq, r1 * sizeof(tipo_registro), SEEK_SET);
    fwrite(&aluno_r2, sizeof(tipo_registro), 1, arq);

    fseek(arq, r2 * sizeof(tipo_registro), SEEK_SET);
    fwrite(&aluno_r1, sizeof(tipo_registro), 1, arq);
}


// Exemplo 1: exclusao logica em arquivo nao residente na memoria
bool excluirRegistro(char* path) {
    bool ok = false;
    FILE *arq = fopen(path, "r+"); // ler e escrever
    // rewind(arq) => nao necessario se acabou de abrir

    if (!arq) {
        printf("\nERRO: Nao foi possivel abrir o arquivo.\n");
    } else {
        char* codigo = (char*) malloc(sizeof(char));
        
        struct tipo_registro aluno;
        printf("\nInforme o nro. USP do aluno a excluir: ");
        
        fgets(codigo, 9, stdin);

        fflush(stdin);

        while (fread(&aluno, sizeof(tipo_registro), 1, arq) == 1) { // leia 1 registro com tamanho tipo_registro e coloque na estrutura aluno
            if (strcmp(codigo, aluno.nrousp) == 0) { // achou
                aluno.valido = 0; // registro deixa de existir => LOGICA, NAO FISICO.
                fseek(arq, -sizeof(tipo_registro), SEEK_CUR); // a partir da posicao atual, anda um registro para tras
                fwrite(&aluno, sizeof(tipo_registro), 1, arq);
                ok = true;
                break;
            }
        }

        if (!ok) {
            printf("\nERRO: registro nao encontrado...");
        } else {
            printf("\nRegistro excluido!\n");
        }
        
    }

    return ok;
    

}



int main() {
    char* path = (char*) "fixo.txt";

    FILE *arq = fopen(path, "r+"); // ler e escrever
    if (arq) {
        atualizarRegistros(arq, 9, 10);
    }

    imprimeArquivoFixo(path, 10);
        

    

    // excluirRegistro(path);
}

