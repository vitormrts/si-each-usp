// OBS: Esse codigo nao esta funcional, ele serve apenas para ilustracoes

/*
    Considerando uma tabela (arvore, vetor etc) com registros com dois campos:
        - int chave => chave do registro
        - int end => endereco, i. e., nro do registro no arquivo, tipicamente um longint
*/

/*
// Criacao de tabela de indices
int prox = 0;
REGISTRO r;
FILE* arq = fopen("path.txt", "rb");
while (fread(&r, sizeof(REGISTRO), 1, arq) == 1) {
    inserirIndice(tabela, r.chave, prox)
}

// insercao de um registro r
fseek(arq, 0, SEEK_END); // se posiciona no final do arquivo, deslocando 0 bytes a partir do final do arquivo
fwrite(&r, sizeof(REGISTRO), 1, arq); 
inserirIndice(tabela, r.chave, prox);
prox++;

// leitura de um registro r dada sua chave
int end = buscarEndereco(tabela, chave);
if (end > -1) {
    fseek(arq, end * sizeof(REGISTRO), SEEK_SET);
    int lidos = fread(&r, sizeof(REGISTRO), 1, arq);
    if (lidos < 1) // nao encontrado
} 
else // registro nao encontrado => erro no indice?

// exclusao logica do registro contendo a chave => requer limpeza periodica do arquivo
REGISTRO rvazio;
rvazio.valido = false;
int end = excluirIndice(tabela, r.chave);
if (end>-1) {
    fseek(arq, end*sizeof(REGISTRO), SEEK_SET);
    fwrite(&rvazio, sizeof(REGISTRO), 1, arq);
} // OBS: Esse codigo nao esta funcional, ele serve apenas para ilustracoes

/*
    Considerando uma tabela (arvore, vetor etc) com registros com dois campos:
        - int chave => chave do registro
        - int end => endereco, i. e., nro do registro no arquivo, tipicamente um longint
*/

/*
// Criacao de tabela de indices
int prox = 0;
REGISTRO r;
FILE* arq = fopen("path.txt", "rb");
while (fread(&r, sizeof(REGISTRO), 1, arq) == 1) {
    inserirIndice(tabela, r.chave, prox)
}

// insercao de um registro rmpo chave para novaChave

end = excluirIndice(tabela, chave); 
chave = novaChave;
inserirIndice(tabela, chave, end);

fseek(arq, end*sizeof(REGISTRO), SEEK_SET);
int lidos = fread(&r, sizeof(REGISTRO), 1, arq);
if (lidos == 0) // ERRO

r.chave = novaChave;
fseek(arq, -sizeof(REGISTRO), SEEK_CUR);
fwrite(&r, sizeof(REGISTRO), 1, arq);
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct { 
	int v1;
	int v2;
	int custo;
} REGISTRO_ARQUIVO;

typedef struct {
    int v1;
    int v2;
    int nroRegistro;
} REGISTRO_ESTATICO;

typedef struct {
    REGISTRO_ESTATICO A[MAX][MAX];
} MATRIZ;

MATRIZ criacaoDeIndice(char* path, MATRIZ m) {
    FILE *arq = fopen(path, "rb");
    if (!arq) {
        printf("ERRO: Nao foi possivel abrir o arquivo...\n");
    } else {
        REGISTRO_ARQUIVO r;
        int prox = 0;
        while (fread(&r, sizeof(REGISTRO_ARQUIVO), 1, arq)) {
            m.A[r.v1][r.v2].v1 = r.v1;
            m.A[r.v1][r.v2].v2 = r.v2;
            m.A[r.v1][r.v2].nroRegistro = prox;
            prox++;
        }
    }
    return m;
}

int main() {
    char* path = "exemplo.txt";
    MATRIZ m;
    m = criacaoDeIndice(path, m);
}   