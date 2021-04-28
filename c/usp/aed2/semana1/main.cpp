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
VERTICE *criarGrafo(int vertices) {
    // Aloco memoria para o grafo
    VERTICE* grafo = (VERTICE*) malloc(vertices * sizeof(VERTICE));

    int i;

    for (i = 0; i < vertices; i++) {
        grafo[i].cabeca = NULL; // definimos o no cabeca como null
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

bool criarAresta(VERTICE *grafo, int verticeInicial, int verticeFinal, int peso) {
    if (!grafo) return false;

    ADJACENCIA* novaAdjacencia = criarAdjacencia(verticeFinal, peso);
    novaAdjacencia->prox = grafo[verticeInicial].cabeca;
    grafo[verticeInicial].cabeca = novaAdjacencia;

    return true;
}

bool removerAresta(VERTICE *grafo, int verticeInicial, int verticeFinal) {
    if (!grafo) return false;

    ADJACENCIA* adjacencia = grafo[verticeInicial].cabeca;
    ADJACENCIA* ant = NULL;

    while (adjacencia) {
        if (adjacencia->vertice == verticeFinal) {
            if (!ant && !adjacencia->prox) {
                // printf("UNICA ADJACENCIA\n");
                adjacencia = NULL;
                grafo[verticeInicial].cabeca = adjacencia;
                free(adjacencia);
            } else if (!ant && adjacencia->prox) {
                // printf("NAO TEM ANTERIOR, MAS NAO EH A UNICA ADJACENCIA\n");
                ant = adjacencia;
                adjacencia = ant->prox;
                grafo[verticeInicial].cabeca = adjacencia;
                free(ant);
            } else {
                // printf("ADJACENCIA NO MEIO");
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

void imprimirGrafo(VERTICE *grafo, int vertices) {
    if (!grafo) return;

    int i;
    for (i = 0; i < vertices; i++) {
        printf("v%d: ", i);

        ADJACENCIA *adjacencia = grafo[i].cabeca;
        while (adjacencia) {
            printf("v%d(%d) ", adjacencia->vertice, adjacencia->peso);

            adjacencia = adjacencia->prox;
        }
        printf("\n");
    }
}

void adjacencia2incidencia(VERTICE* g, int n) {
    int i;
    int j = 0;
    int k = 0;

    int vertice;

    ADJACENCIA* adjacencia;
    ADJACENCIA* incidente;

    VERTICE novoGrafo[n];
    for (i = 0; i < n; i++) {
        novoGrafo[i].cabeca = NULL;
    }

    while (j < n) {
        adjacencia = g[j].cabeca;
        
        while (adjacencia) {
            incidente = adjacencia;

            vertice = adjacencia->vertice;
            adjacencia = adjacencia->prox;

            incidente->vertice = j;
            
            if (novoGrafo[vertice].cabeca) { // lista ja possui elementos
                incidente->prox = novoGrafo[vertice].cabeca;
            } else { // primeira insercao
                incidente->prox = NULL;
            }
            
            novoGrafo[vertice].cabeca = incidente;
        }

        j++;
    }

    while (k < n) {
        g[k].cabeca = novoGrafo[k].cabeca;
        k++;
    }
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
    

    imprimirGrafo(grafo, 5);

    // removerAresta(grafo, 0, 2);
    // removerAresta(grafo, 1, 2);
    // removerAresta(grafo, 2, 0);
    // removerAresta(grafo, 2, 4);
    // removerAresta(grafo, 3, 1);
    // removerAresta(grafo, 4, 3);
    // removerAresta(grafo, 4, 1);

    printf("==========\n");
    // imprimirGrafo(grafo, 5);

    adjacencia2incidencia(grafo, 5);

    imprimirGrafo(grafo, 5);

    
}
