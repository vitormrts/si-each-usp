#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef struct NO {
    int vertice; // vertice de destino (NO final da aresta)
    int peso; // peso da aresta
    struct NO *prox; // prox adj
} NO;

typedef struct vertice {
    NO *inicio; // inicio da lista ligada
} VERTICE;

// Listas de Adjacencia

// Estrutura de criacao de um grafo
VERTICE *criarGrafo(int vertices) {
    // Aloco memoria para o grafo
    VERTICE *grafo = (VERTICE*) malloc(vertices * sizeof(VERTICE));

    int i;

    for (i = 0; i < vertices; i++) {
        grafo[i].inicio = NULL; // definimos o no inicio como null
    }

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


/*
    d => distancia
    p => predecessores
    s => ponto inicial
*/
void inicializaDijkstra(VERTICE *g, int vertices, int *d, int *p, int s) {
    int v;
    for (v = 0; v < vertices; v++) {
        d[v] = INT_MAX/2;
        p[v] = -1;
    }

    d[s] = 0;
}

/*
    d => distancia
    p => predecessores
    
    procurar distancia de (u, v)
*/

void relaxa(VERTICE *g, int *d, int *p, int u, int v) {
    NO *adj = g[u].inicio;

    while (adj && adj->vertice != v)
        adj = adj->prox;

    if (p) { // achei o vertice
        if (d[v] > d[u] + adj->peso) {
            d[v] = d[u] + adj->peso;
            p[v] = u;
        }
    } 
}

bool existeAberto(int vertices, bool *aberto) {
    int i;
    for (i = 0; i < vertices; i++) {
        if (aberto[i]) {
            return true;
        }
    }
    return false;
}

// Retorna o NO com menor distancia dentre os NO's abertos
int menorDist(VERTICE *g, int vertices, bool *aberto, int *d) {
    int i;
    for (i = 0; i < vertices; i++) 
        if (aberto[i]) break;

    if (i == vertices) return -1; // percorreu todo arranjo e nao encontrou

    int menor = i;
    for (i = menor + 1; i < vertices; i++) 
        if (aberto[i] && (d[i] < d[menor]))  
            menor = i;

    return menor;
}

/*
    s => ponto inicial
*/
int *dijkstra (VERTICE *g, int vertices, int s) {
    int *d = (int*) malloc(vertices * sizeof(int));
    int p[vertices];
    bool aberto[vertices];
    inicializaDijkstra(g, vertices, d, p, s);

    int i;
    for (i = 0; i < vertices; i++) 
        aberto[i] = true; // abrindo os vertices
    
    while (existeAberto(vertices, aberto)) {
        int u = menorDist(g, vertices, aberto, d);
        aberto[u] = false;

        NO* adj = g[u].inicio;

        while (adj) {
            relaxa(g, d, p, u, adj->vertice);
            adj = adj->prox;
        }
    }

    return d;
}

int main() {
    VERTICE *grafo = criarGrafo(5);

    criarAresta(grafo, 0, 1, 8);
    criarAresta(grafo, 0, 2, 3);
    criarAresta(grafo, 1, 3, 9);
    criarAresta(grafo, 2, 1, 4);
    criarAresta(grafo, 2, 4, 1);
    criarAresta(grafo, 3, 1, 3);
    criarAresta(grafo, 3, 2, 10);
    criarAresta(grafo, 3, 0, 6);
    criarAresta(grafo, 4, 3, 8);

    // criarAresta(grafo, 0, 1, 3);
    // criarAresta(grafo, 0, 4, 2);
    // criarAresta(grafo, 0, 3, 8);
    // criarAresta(grafo, 0, 2, 11);
    // criarAresta(grafo, 1, 2, 13);
    // criarAresta(grafo, 1, 4, 9);
    // criarAresta(grafo, 2, 0, 6);
    // criarAresta(grafo, 2, 4, 2);
    // criarAresta(grafo, 3, 1, 4);
    // criarAresta(grafo, 4, 1, 7);
    // criarAresta(grafo, 4, 3, 1);

    // criarAresta(grafo, 0, 1, 10);
    // criarAresta(grafo, 0, 2, 4);
    // criarAresta(grafo, 2, 1, 7);
    // criarAresta(grafo, 2, 4, 5);
    // criarAresta(grafo, 3, 1, 2);
    // criarAresta(grafo, 3, 2, 1);
    // criarAresta(grafo, 4, 3, 16);

    imprimirGrafo(grafo, 5);

    int *r = dijkstra(grafo, 5, 0);

    int i;
    for (i = 0 ; i < 5; i++) {
        printf("D(v0 -> v%d) = %d\n", i, r[i]);
    }


    /*
        OBSERVACOES:
        - Os pesos das arestas devem ser nao-negativos (ele pressupoe que todo caminho eh maior)
        - existeAberto e menorDist sao cruciais p/ a vel. do algoritmo
        - observar filas de prioridade p/ melhor desempenho
    */
}
