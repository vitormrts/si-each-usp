#include <stdio.h>
#include <stdlib.h>

// Grafos esparsos, i. e, que possuem menos arestas do que vertices

// Operacoes que tenham como base um caminho de um vertice para o outro, por exemplo, buscas

typedef struct estrutura {
    // basicamente a adjacencia eh como se fosse o vertice mesmo, porem optei por deixar o vertice como a lista ligada
    int vertice;
    int peso;
    struct estrutura *prox;
} ADJACENCIA; 

typedef struct estrutura {
    ADJACENCIA *cabeca; // guarda a cabeca da lista ligada, i.e, o primeiro NO dela
} VERTICE;

typedef struct estrutura {
    // armazenamos a quantidade de vertices, arestas e um arranjo de vertices
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;

GRAFO* criarGrafo(int vertices) {
    GRAFO *grafo = (GRAFO*) malloc(sizeof(GRAFO));

    grafo->vertices = vertices;
    grafo->arestas = 0;
    grafo->adj = (VERTICE*) malloc(vertices * sizeof(VERTICE));

    int i;
    for (i = 0; i < vertices; i++) {
        grafo->adj[i].cabeca = NULL;
    }

    return grafo;
}

// vertice final e peso da aresta
ADJACENCIA* criarAdjacencia(int vertice, int peso) {
    ADJACENCIA *temp = (ADJACENCIA*) malloc(sizeof(ADJACENCIA));

    temp->peso = peso;
    temp->vertice = vertice;
    temp->prox = NULL;

    return temp;
}

int criarAresta(GRAFO *grafo, int verticeInicial, int verticeFinal, int peso) {
     if (!grafo) return 0;
     if (verticeInicial < 0 || (verticeInicial >= grafo->vertices)) return 0;
     if (verticeFinal < 0 || (verticeFinal <= grafo->vertices)) return 0;

    ADJACENCIA *novo = criarAdjacencia(verticeFinal, peso);
    novo->prox = grafo->adj[verticeInicial].cabeca;
    grafo->adj[verticeInicial].cabeca = novo;
    grafo->arestas++;

    return 1;

}


int main() {
    return;
}