#include <stdio.h>
#include <stdlib.h>

#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef struct NO {
    int vertice; // vertice de destino (NO final da aresta)
    int peso; // peso da aresta
    struct NO *prox; // prox adj
} NO;

typedef struct fila {
    NO *inicio;
    NO *fim;
} FILA;

typedef struct vertice {
    NO *inicio; // inicio da lista ligada
    int flag;
    bool temChave;
} VERTICE;

void inicializarFila(FILA *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void inserirNaFila(FILA *fila, int chave) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->vertice = chave; 
    novo->prox = NULL;

    if (!fila->inicio) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
}

// void excluirDaFila(FILA *fila, int* chave) {
//     if (fila->inicio) {
//         (*chave) = fila->inicio->vertice;
//         NO* aux = fila->inicio;
//         fila->inicio = fila->inicio->prox;
//         free(aux);
//         if (!fila->inicio) {
//             fila->fim = NULL;
//         }
//     }
// }

int excluirDaFila(FILA *fila) {
    if (fila->inicio) {
        int chave = fila->inicio->vertice;
        NO* aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(aux);
        if (!fila->inicio) {
            fila->fim = NULL; // fila ficou vazia
        }
        return chave;
    }
    return 0;
}

void imprimirFila(FILA *fila) {
    NO* p = fila->inicio;

    while (p) {
        printf("%d ", p->vertice);
        p = p->prox;
    }
}

// Listas de Adjacencia

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

    // grafo[1].temChave = true;
    grafo[4].temChave = true;
    // grafo[4].temChave = true;
    // grafo[4].temChave= true;
    // grafo[0].temChave= true;

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

void buscaEmLargura(VERTICE *g, int i) {
    // for (int j = 0; j < v; j++) {
    //     g[j].flag = 0;
    // }
    FILA f;
    inicializarFila(&f);
    g[i].flag = 1;
    inserirNaFila(&f, i);
    // imprimirFila(&f);

    while (f.inicio) {
        // imprimirFila(&f);
        // printf("\n");
        i = excluirDaFila(&f);
        NO* p = g[i].inicio;

        while (p) {
            if (g[p->vertice].flag == 0) {
                g[p->vertice].flag = 1;
                printf("v%d(%d) ", p->vertice, p->peso);
                inserirNaFila(&f, p->vertice); 
            }
            p = p->prox;
        }
        
        printf("\n");
        g[i].flag = 2;
        
        // printf("%d\n", i);
    }
}

int custoChaveMaisProxima(VERTICE* g, int i) {
    FILA f;
    FILA pesos;

    inicializarFila(&f);
    inicializarFila(&pesos);

    g[i].flag = 1;
    inserirNaFila(&f, i);

    int total = 0;
    int j;
    int v;

    if (g[i].temChave) {
        return total;
    }

    while (f.inicio) {    
        i = excluirDaFila(&f);
        j = excluirDaFila(&pesos);

        int cont = 0;
        
        NO* p = g[i].inicio;

        while (p) {
            cont ++;
            v = p->vertice;

            if (g[v].flag == 0) {
                // if (cont == 1) 
                    total += j;
                    printf("%d ", total);
                
                if (g[v].temChave) {
                    // printf("v%d(%d) ", v, j);
                    printf("%d ", p->peso);
                     return total + p->peso;
                }
                    
                g[v].flag = 1;
                inserirNaFila(&f, v);
                inserirNaFila(&pesos, p->peso);
            } 
            p = p->prox;
        }
        g[i].flag = 2;
    }
    return -1;
}

// Encontra a chave mais proxima e retorna o seu custo
// int custoChaveMaisProxima(VERTICE* g, int i) {
//     FILA f;
//     inicializarFila(&f);
//     g[i].flag = 1;
//     inserirNaFila(&f, i);

//     int total = 0;
//     int parcial = 0;
//     int ant = 0;
//     int aux = 0;

//     if (g[i].temChave) {
//         return total;
//     }

//     while (f.inicio) {    
//         ant = 0;
//         // imprimirFila(&f); 
//         // printf("%d ", parcial);
//         // parcial = 0;   
//         i = excluirDaFila(&f);

//         // if (!f.inicio) {
//         //     ant = i;
//         //     printf("\nfila vazia vertice %d \n", i);
//         // }
        
//         NO* p = g[i].inicio;

//         // if (p) {
//         //     printf("%d ", p->peso);
//         // }
//         // total = p->peso;
//         // parcial = 0;
        
//         while (p) {
            
//             int v = p->vertice;

            

//             // parcial = total;
            
//             // printf("v%d(%d) ", v, p->peso);
//             if (g[v].flag == 0) {
//                 total += p->peso;
                


//                 if (g[v].temChave) {
//                     // if (camada == 1) return p->peso; 
//                     // printf("tot%d\nparc %d\n", total, parcial);
//                     // while (f.inicio) {
//                     //     i = excluirDaFila(&f);
//                     //     total -= i;
//                     // }
//                     imprimirFila(&f); 
//                     return total - parcial - ant;
//                 }
//                 ant += p->peso;
//                 if ((!g[v].inicio && !g[v].temChave)) 
//                     parcial += p->peso;
                
//                 g[v].flag = 1;
//                 inserirNaFila(&f, v);
//             }
            
//             aux = p->peso;
//             p = p->prox;
//         }
        
        
//         g[i].flag = 2;
//         printf("\n");
        
//     }
//     return -1;
// }

// s eh o ponto inicial
// void visitaEmLargura(VERTICE *grafo, int s, bool *explorado) {
//     FILA f;
//     inicializarFila(&f);
//     explorado[s]= true;

//     int u = s;

//     inserirNaFila(&f, s);

//     while (f.inicio) {
//         excluirDaFila(&f, &u);

//         NO *v = grafo[u].inicio;
//         while (v) {
//             if (!explorado[v->vertice]) {
//                 explorado[v->vertice] = true;
//                 u = v->vertice;
//                 inserirNaFila(&f, u); 
//             }
//             v = v->prox;
//         }
//     }
// }

// void buscaEmLargura(VERTICE *grafo, int vertices) {
//     bool explorado[vertices];
//     int u;

//     for (u = 0; u < vertices; u++) {
//         explorado[u] = false;
//     }

//     for (u = 0; u < vertices; u++) {
//         if (!explorado[u]) {
//             visitaEmLargura(grafo, u, explorado);
//         }
//         printf("%d ", explorado[u]);
//     }
// }

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

int main() {
    VERTICE *grafo = criarGrafo(5);

    criarAresta(grafo, 0, 1, 8);
    criarAresta(grafo, 0, 2, 3);
    // criarAresta(grafo, 1, 3, 9);
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

    imprimirGrafo(grafo, 5);

        printf("\n");
    int resposta = custoChaveMaisProxima(grafo, 0);

    // criarAresta(grafo, 0, 1, 10);
    // criarAresta(grafo, 0, 2, 4);

    // criarAresta(grafo, 2, 1, 7);
    // criarAresta(grafo, 2, 4, 5);

    // criarAresta(grafo, 3, 1, 2);
    // criarAresta(grafo, 3, 2, 1);

    // criarAresta(grafo, 4, 3, 16);

    


    

    // buscaEmLargura(grafo, 0);


    printf("\n=======\n%d\n", resposta);

    // FILA fila;
    // inicializarFila(&fila);

    // inserirNaFila(&fila, 1);
    // inserirNaFila(&fila, 2);
    // inserirNaFila(&fila, 3);
    // inserirNaFila(&fila, 4);
    // inserirNaFila(&fila, 5);
    // inserirNaFila(&fila, 6);

    // int i = excluirDaFila(&fila);
    // imprimirFila(&fila);
    // printf("\n");

    // i = excluirDaFila(&fila);
    // imprimirFila(&fila);
    // printf("\n");

    // printf("%d ", i);
}
