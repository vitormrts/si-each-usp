#include <stdio.h>
#include <stdlib.h>

#define COUNT 10

typedef struct estrutura {
    int chave;
    struct estrutura *esq;
    struct estrutura *dir;
} NO;

// Inicialização da árvore vazia
void inicializarArvore(NO* *raiz) {
    *raiz = NULL;
}

// Verificar se árvore é vazia
int arvoreVazia(NO* raiz) {
    if(!raiz) return(1);
    else return(0);
}

NO* buscaNo(NO* raiz, int ch, NO* *pai) {
    NO* atual = raiz;
    *pai = NULL;

    while (atual) {
        if (atual->chave == ch) return atual;
        *pai = atual;
        if (ch >= atual->chave) atual = atual->dir;
        else atual = atual->esq;
    }

    return NULL;
}

int inserir(NO* *raiz, int ch) {
    NO* pai;
    NO* atual = buscaNo(*raiz, ch, &pai);

    if (atual) return 0;
    NO* novo = (NO*) malloc(sizeof(NO));

    novo->chave=ch;
    novo->esq = NULL;
    novo->dir = NULL;

    if(!pai) {
        *raiz = novo;
        return(1);
    }
    if(ch > pai->chave)
        pai->dir = novo;
    else
        pai->esq = novo;
    return(1);
}

void horizontalArvore(NO *p, int d) {
    int i;
    if (p) {
        horizontalArvore(p->dir, d+1);
        for (i = 1; i<=d; i++) printf("    ");
        printf("%d\n", p->chave);
        horizontalArvore(p->esq, d+1);
    }
}

void ordem(NO* p) {
    if (p) {
        ordem(p->esq);
        printf("%d ", p->chave);
        ordem(p->dir);
    }
}

void imprimirArvore(NO* raiz, int espaco) {
    // Base case
    if (raiz == NULL)
        return;

    // Increase distance between levels
    espaco += COUNT;

    // Process dir child first
    imprimirArvore(raiz->dir, espaco);

    // Print current node after espaco
    // count
    printf("\n");
    for (int i = COUNT; i < espaco; i++)
        printf(" ");
    printf("%d\n", raiz->chave);

    // Process esq child
    imprimirArvore(raiz->esq, espaco);
}

// 1. Exibir todas as folhas de uma árvore, em qualquer ordem.
void exibirFolhas(NO* p) {
    if (!p) return;
    else {
        exibirFolhas(p->esq);
        exibirFolhas(p->dir);
        if (!p->esq && !p->dir) printf("%d ", p->chave);
    }
}

// 2. Em ABB, exibir os ancestrais de uma chave x, do seu pai até a raiz.
void exibeAncestrais(NO* p, int x) {
    if (p) {
        NO* pai;
        while (p) {
            buscaNo(p, x, &pai);
            if (pai) {
                    x = pai->chave;
                    printf("%d ", x);
            }
            else return;
        }
    }
}

int main()
{
    NO* p;
    inicializarArvore(&p);
    inserir(&p, -2);
    inserir(&p, -13);
    inserir(&p, -23);
    inserir(&p, -3);
    inserir(&p, 1);
    inserir(&p, 3);
    inserir(&p, -9);
    inserir(&p, -10);
    inserir(&p, 4);
    inserir(&p, 2);
    inserir(&p, 0);

    imprimirArvore(p, 0);
    //exibirFolhas(p);
    //horizontalArvore(p, 5);
    exibeAncestrais(p, 4);
    //ordem(p);

    return 0;
}
