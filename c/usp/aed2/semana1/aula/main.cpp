#include <stdio.h>
#include <stdlib.h>


// Matrizes de Adjacencia

// typedef struct estrutura {
//     int vertices;
//     int arestas;

//     int **adj;
// } GRAFO;



// Listas de Adjacencia

typedef struct adjacencia {
    int vertice; // vertice de destino (NO final da aresta)
    int peso; // peso da aresta
    struct adjacencia *prox; // prox adj
} ADJACENCIA;

typedef struct vertice {
    ADJACENCIA *cabeca; // cabeca da lista ligada
} VERTICE;


typedef struct grafo {
    int vertices; // numero de vertices
    int arestas; // numero de arestas
    VERTICE *adj; // arranjo de vertices
} GRAFO;

// Estrutura de criacao de um grafo
GRAFO *criarGrafo(int vertices) {
    // Aloco memoria para o grafo
    GRAFO* grafo = (GRAFO*) malloc(sizeof(GRAFO));

    grafo->vertices = vertices; // defino a quantidade de vertices
    grafo->arestas = 0; // por enquanto nao temos arestas
    grafo->adj = (VERTICE*) malloc(vertices * sizeof(VERTICE)); // alocamos memoria para a lista de adjacencias

    int i;

    for (i = 0; i < vertices; i++) {
        grafo->adj[i].cabeca = NULL; // definimos o no cabeca como null
    }

    return grafo;
}

ADJACENCIA *criarAdjacencia(int vertice, int peso) {
    ADJACENCIA *adjacencia = (ADJACENCIA*) malloc(sizeof(ADJACENCIA));

    adjacencia->peso = peso;
    adjacencia->vertice = vertice;
    adjacencia->prox = NULL;

    return adjacencia;
}

bool criarAresta(GRAFO *grafo, int verticeInicial, int verticeFinal, int peso) {
    if (!grafo) return false;
    if (verticeInicial < 0 || verticeInicial >= grafo->vertices) return false;
    if (verticeFinal < 0 || verticeFinal >= grafo->vertices) return false;

    ADJACENCIA* novaAdjacencia = criarAdjacencia(verticeFinal, peso);
    novaAdjacencia->prox = grafo->adj[verticeInicial].cabeca;
    grafo->adj[verticeInicial].cabeca = novaAdjacencia;

    grafo->arestas++;

    return true;
}

void imprimirGrafo(GRAFO *grafo) {
    if (!grafo) return;

    printf("Vertices: %d. Arestas: %d\n", grafo->vertices, grafo->arestas);

    int i;
    for (i = 0; i < grafo->vertices; i++) {
        printf("v%d: ", i);

        ADJACENCIA *adjacencia = grafo->adj[i].cabeca;
        while (adjacencia) {
            printf("v%d(%d) ", adjacencia->vertice, adjacencia->peso);

            adjacencia = adjacencia->prox;
        }
        printf("\n");
    }
}

int main() {
    GRAFO *grafo = criarGrafo(5);

    criarAresta(grafo, 0, 1, 2);
    criarAresta(grafo, 1, 2, 4);
    criarAresta(grafo, 2, 0, 12);
    criarAresta(grafo, 2, 4, 40);
    criarAresta(grafo, 3, 1, 3);
    criarAresta(grafo, 4, 3, 8);

    imprimirGrafo(grafo);
}
