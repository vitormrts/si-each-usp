#include <stdio.h>
#include <stdlib.h>

// Podemos armazenar diversas EDs em arquivos, como:
/*
    - Lista sequencial => implementada em vetor
    - Lista ligada => implem. dinamica ou estatica
    - Outros tipode de listas => filas, pilhas, deques, no cabeca...
    - Arvores binraias
    - Grafos em matriz e listas de adjacencias
*/

/* 
LISTA LIGADA DINAMICA => escrita em arquivo binarios de registros de tamanho fixo

typedef struct no_sem_ponteiro {
    int chave;
    int info;
    char nome[20];
};

void escreveListaDinamica() {
    no_sem_ponteiro aux;
    NO* p = l->inicio;

    while (p) {
        aux.chave = p->chave;
        aux.info = p->info;
        strcpy(aux.nome, p->nome);
        fwrite(&aux, sizeof(no_sem_ponteiro), 1, arq);
        p = p->prox;
    }
}
*/

typedef struct { 
	int v1;
	int v2;
	int custo;
} REGISTRO;

REGISTRO *criarRegistro(int v1, int v2, int custo) {
    REGISTRO *reg = (REGISTRO*) malloc(sizeof(REGISTRO));

    reg->v1 = v1;
    reg->v2 = v2;
    reg->custo = custo;

    return reg;
}
 
typedef struct adjacencia {
    int vertice;
    int peso;
    struct adjacencia *prox;
} NO;

typedef struct vertice {
    NO* inicio;    
} VERTICE;

VERTICE *criarGrafo(int n) {
    VERTICE* g = (VERTICE*) malloc(n * sizeof(VERTICE));

    int i;
    for (i = 0; i < n; i++) {
        g[i].inicio = NULL;
    }

    return g;
}

NO *criarAdjacencia(int vertice, int peso) {
    NO *adjacencia = (NO*) malloc(sizeof(NO));

    adjacencia->peso = peso;
    adjacencia->vertice = vertice;
    adjacencia->prox = NULL;

    return adjacencia;
}

bool criarAresta(VERTICE *grafo, int verticeInicial, int verticeFinal, int peso) {
    if (!grafo) return false;

    NO* novaAdjacencia = criarAdjacencia(verticeFinal, peso);
    novaAdjacencia->prox = grafo[verticeInicial].inicio;
    grafo[verticeInicial].inicio = novaAdjacencia;

    return true;
}

void imprimirGrafo(VERTICE *grafo, int vertices) {
    if (!grafo) return;

    int i;
    for (i = 0; i < vertices; i++) {
        printf("v%d: ", i);

        NO *adjacencia = grafo[i].inicio;
        while (adjacencia) {
            printf("v%d(%d) ", adjacencia->vertice, adjacencia->peso);

            adjacencia = adjacencia->prox;
        }
        printf("\n");
    }
}

bool removerAresta(VERTICE *grafo, int verticeInicial, int verticeFinal) {
    if (!grafo) return false;

    NO* adjacencia = grafo[verticeInicial].inicio;
    NO* ant = NULL;

    while (adjacencia) {
        if (adjacencia->vertice == verticeFinal) {
            if (!ant && !adjacencia->prox) {
                // printf("UNICA NO\n");
                adjacencia = NULL;
                grafo[verticeInicial].inicio = adjacencia;
                free(adjacencia);
            } else if (!ant && adjacencia->prox) {
                // printf("NAO TEM ANTERIOR, MAS NAO EH A UNICA NO\n");
                ant = adjacencia;
                adjacencia = ant->prox;
                grafo[verticeInicial].inicio = adjacencia;
                free(ant);
            } else {
                // printf("NO NO MEIO");
                ant->prox = adjacencia->prox;
                adjacencia = NULL;
                free(adjacencia);
            }

            return true;
        }

        ant = adjacencia;
        adjacencia = adjacencia->prox;
    }
    return true;
}

VERTICE *registrosParaGrafo(char* path) {
    FILE *arq = fopen(path, "rb");
    VERTICE* g = criarGrafo(10);

    if (!arq) {
        printf("Nao foi possivel abrir o arquivo.\n");
    } else {
        REGISTRO reg;

        int v1;
        int v2;
        int custo;
        int i = 0;

        while (!feof(arq)) {
            fseek(arq, i * sizeof(REGISTRO), SEEK_SET);
            fread(&reg, sizeof(REGISTRO), 1, arq);

            v1 = reg.v1;
            v2 = reg.v2;
            custo = reg.custo;

            criarAresta(g, v1, v2, custo);
            i++;
        }

        removerAresta(g, v1, v2);
    }

    return g;
}

void escreverRegistros(REGISTRO* *regs, int n, char* path) {
    FILE *arq = fopen(path, "w+");
    
    int i;

    if (!arq) {
        printf("ERRO: Nao foi possivel abrir o arquivo.\n");
    } else {
        for (i = 0; i < n; i++) {
            fwrite(regs[i], sizeof(REGISTRO), 1, arq);
        }

        fclose(arq);
    }
}



int main() {
    char* path = "exemplo.txt";

    REGISTRO *r1 = criarRegistro(0, 1, 4);
    REGISTRO *r2 = criarRegistro(1, 2, 5);
    REGISTRO *r3 = criarRegistro(2, 3, 9);
    REGISTRO *r4 = criarRegistro(3, 1, 2);
    REGISTRO *r5 = criarRegistro(2, 4, 1);
    REGISTRO *r6 = criarRegistro(6, 3, 10);
    REGISTRO *r7 = criarRegistro(3, 6, 10);
    REGISTRO *r8 = criarRegistro(0, 9, 17);
    REGISTRO* regs[8] = {r1, r2, r3, r4, r5, r6, r7, r8};
    escreverRegistros(regs, 8, path);

    VERTICE* g = registrosParaGrafo(path);
    imprimirGrafo(g, 10);
}