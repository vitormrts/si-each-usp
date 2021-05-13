#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura {
    int chave;
    struct estrutura *esq;
    struct estrutura *dir;
} NO;

void inicializarArvore(NO* *raiz) {
    *raiz = NULL;
}

// insercao de um no em arvore comum (sem ordem) esq: pos = 1, dir: pos = 2
int inserirNo(NO* *raiz, NO* pai, int ch, int pos) {
    if (pai) {
        if ((pos == 1 && (pai->esq != NULL)) || pos == 2 && (pai->dir) != NULL) return -1;
    }
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->dir = NULL;
    novo->esq = NULL;
    if (!pai) *raiz = novo;
    else {
        if (pos == 1) pai->esq = novo; // insercao na esquerda
        else pai->dir = novo; // insercao na direita
    }
    return 1;
}

//Dado um elemento p garantidamente existente em uma árvore binária, crie um novo filho esquerdo com o valor de chave correspondente à chave do pai (p) mais a chave do filho direito, se houver. Se já houver filho esquerdo, nada deve ser executado.

void novoEsquerdo(NO* p) {
    if (!p->esq) {
        NO* novo = malloc(sizeof(NO));
        novo->dir = NULL;
        novo->esq = NULL;
        novo->chave = p->chave;
        if (p->dir) novo->chave += p->dir->chave;
    }
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
