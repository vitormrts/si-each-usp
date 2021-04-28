#include <stdio.h>
#include <stdlib.h>

#define BRANCO 0
#define CINZA 1
#define PRETO 2

// Listas de Adjacencia

typedef struct adjacencia {
    int vertice; // vertice de destino (NO final da aresta)
    int peso; // peso da aresta
    struct adjacencia *prox; // prox adj
} NO;

typedef struct vertice {
    NO *inicio; // inicio da lista ligada
    int flag;
    bool temChave;
} VERTICE;

// Estrutura de criacao de um grafo
VERTICE *criarGrafo(int vertices) {
    // Aloco memoria para o grafo
    VERTICE *grafo = (VERTICE*) malloc(vertices * sizeof(VERTICE));

    int i;

    for (i = 0; i < vertices; i++) {
        grafo[i].inicio = NULL; // definimos o no inicio como null
        grafo[i].flag = 0;
        grafo[i].temChave = false;
    }

    grafo[1].temChave = true;
    grafo[3].temChave = true;
    grafo[2].temChave = true;

    return grafo;
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

void visitaEmProfundidade(VERTICE *grafo, int i) {
    grafo[i].flag = 1;

    NO* p = grafo[i].inicio;

    while (p) {
        if (grafo[p->vertice].flag == 0) 
            visitaEmProfundidade(grafo, p->vertice);
        p = p->prox;
    }

    grafo[i].flag = 2;
}


/*
void visitaEmProfundidade(VERTICE *grafo, int u, int *cor) {
    cor[u] = CINZA;

    NO *v = grafo[u].inicio;

    while (v) {
        if (cor[v->vertice] == BRANCO) {
            visitaEmProfundidade(grafo, v->vertice, cor);
        }
        v = v->prox;
    }

    cor[u] = PRETO;
}

void buscaEmProfundidade(VERTICE *grafo, int vertices) {
    int cor[vertices];
    int i;

    for (i = 0; i < vertices; i++) {
        cor[i] = BRANCO;
    }

    for (i = 0; i < vertices; i++) {
        if (cor[i] == BRANCO) {
            visitaEmProfundidade(grafo, i, cor);
        }
        printf("%d ", cor[i]);
    }
} 
*/

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

void imprimirLista(NO* p) {
    while (p) {
        printf("%d ", p->vertice);
        p = p->prox;
    }
}

// EXERCICIOS

// ex 1 => contar vertices alcancaveis a partir de um vertice i
void contarVertices(VERTICE *g, int i, int *cont) {
    g[i].flag = 1;
    
    NO *p = g[i].inicio;

    while (p) {
        if (g[p->vertice].flag == 0) {
            contarVertices(g, p->vertice, cont);
        }
        p = p->prox;
    }

    g[i].flag = 2;
    (*cont) = (*cont) + 1;
}

// ex 2 => procurar vertice com informacao x (no caso buscaremos se um vertice possui chave ou nao)
void buscarChave(VERTICE *g, int i, int *resp) {
    if (g[i].temChave) (*resp) = i;

    g[i].flag = 1;

    NO *p = g[i].inicio;

    while (p) {
        if (g[p->vertice].flag == 0) { // se nao achou, continue
            buscarChave(g, p->vertice, resp);
        }
        p = p->prox;
    }

    g[i].flag = 2;
}

// ex semanal => encontrar todas salas alcancaveis (que possuam chaves) a partir de i
void salasComChaves(VERTICE *g, int i, NO* *sala) {
    if (g[i].temChave) {
        NO* novo = (NO*) malloc(sizeof(NO));

        novo->vertice = i;

        if (!(*sala)) {
            novo->prox = NULL;
        } else {
            novo->prox = *sala;
        }

        (*sala) = novo;
    }

    g[i].flag = 1;

    NO *p = g[i].inicio;

    while (p) {
        if (g[p->vertice].flag == 0) {
            salasComChaves(g, p->vertice, sala);
        }
        p = p->prox;
    }

    g[i].flag = 2;
}

int main() {
    VERTICE *grafo = criarGrafo(5);

    criarAresta(grafo, 0, 1, 1);
    criarAresta(grafo, 0, 2, 1);
    criarAresta(grafo, 2, 1, 1);
    criarAresta(grafo, 2, 4, 1);
    criarAresta(grafo, 3, 1, 1);
    criarAresta(grafo, 3, 2, 1);
    criarAresta(grafo, 4, 3, 1);

    // criarAresta(grafo, 0, 1, 1);
    // criarAresta(grafo, 0, 4, 1);
    // criarAresta(grafo, 0, 3, 1);
    // criarAresta(grafo, 0, 2, 1);
    // criarAresta(grafo, 1, 2, 1);
    // criarAresta(grafo, 1, 4, 1);
    // criarAresta(grafo, 2, 0, 1);
    // criarAresta(grafo, 2, 4, 1);
    // criarAresta(grafo, 3, 1, 1);
    // criarAresta(grafo, 4, 1, 1);
    // criarAresta(grafo, 4, 3, 1);

    // criarAresta(grafo, 0, 2, 1);
    // criarAresta(grafo, 0, 1, 1);
    // criarAresta(grafo, 2, 4, 1);
    // criarAresta(grafo, 3, 1, 1);
    // criarAresta(grafo, 3, 2, 1);
    // criarAresta(grafo, 4, 3, 1);

    imprimirGrafo(grafo, 5);

    NO* p = NULL;
    salasComChaves(grafo, 0, &p);
    imprimirLista(p);

    // int contador = 0;
    // contarVertices(grafo, 4, &contador);

    // printf("Quantidade de vertices: %d\n", contador);

    // int resposta = -1;
    // buscarChave(grafo, 0, &resposta);
    
    // if (resposta == -1) {
    //     printf("Chave nao esta presente em nenhum vertice\n");
    // } else {
    //     printf("Vertice com a chave: %d", resposta);
    // }

    
    // buscaEmProfundidade(grafo, 5);

    // printf("==========\n");
    // imprimirGrafo(grafo, 5);

    // imprimirGrafo(grafo, 5);

    
}
