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
    REGISTRO_ESTATICO A[MAX];
    int tam;
} LISTA_ESTATICA;

void inicializarTabela(LISTA_ESTATICA* l) {
    for (int i = 0; i < MAX - 1; i++) {
        l->A[i].v1 = -1;
        l->A[i].v2 = -1;
        l->A[i].nroRegistro = -1;
    };

    l->tam = 0;
}

void inserirIndice(LISTA_ESTATICA* l, int v1, int v2, int nroRegistro) {
    l->A[l->tam].v1 = v1;
    l->A[l->tam].v2 = v2;
    l->A[l->tam].nroRegistro = nroRegistro;

    l->tam++;
}

void imprimirTabela(LISTA_ESTATICA *l) {
    for (int i = 0; i < l->tam - 1; i++) {
        printf("index: %d\nv1: %d\nv2: %d", l->A[i].nroRegistro, l->A[i].v1, l->A[i].v2);
        printf("\n================\n");
    }
}

LISTA_ESTATICA* criacaoDeIndice(char* path, LISTA_ESTATICA* l) {
    FILE *arq = fopen(path, "rb");
    if (!arq) {
        printf("ERRO: Nao foi possivel abrir o arquivo...\n");
    } else {
        REGISTRO_ARQUIVO r;
        int prox = 0;
        while (fread(&r, sizeof(REGISTRO_ARQUIVO), 1, arq)) {
            inserirIndice(l, r.v1, r.v2, prox);
            prox++;
        }
    }

    return l;
}

int main() {
    LISTA_ESTATICA* lista;
    inicializarTabela(lista);

    char* path = "exemplo.txt";
    lista = criacaoDeIndice(path, lista);
    imprimirTabela(lista);
}   