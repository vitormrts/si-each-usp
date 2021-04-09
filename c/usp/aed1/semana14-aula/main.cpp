#include <stdio.h>
#include <stdlib.h>

#define true 1;
#define false 0;

typedef int boolean;

typedef struct estrutura {
    int chave;

    struct estrutura *esq;
    struct estrutura *dir;
    int h;
} NO;

NO* criarNo(int ch) {
    NO* p = (NO*) malloc(sizeof(NO));

    p->chave = ch;
    p->esq = NULL;
    p->dir = NULL;
    p->h = 0;

    return p;
}

NO* inicializarArvore() {
    return NULL;
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int altura (NO* raiz) {
    if (!raiz) {
        return (-1);
    }

    return raiz->h;
}

NO* rotacaoDireita(NO* raiz) {
    NO* aux;
    aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;

    raiz->h = max(altura(raiz->dir), altura(raiz->esq)) + 1;
    aux->h = max(altura(aux->esq), raiz->h) + 1;

    return aux;
}

NO* rotacaoEsquerda(NO* raiz) {
    NO* aux;
    aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;
    
    raiz->h = max(altura(raiz->dir), altura(raiz->esq)) + 1;
    aux->h = max(altura(aux->dir), raiz->h) + 1;

    return aux;
}

NO* rotacaoEsquerdaDireita(NO* raiz) {
    raiz->esq = rotacaoEsquerda(raiz->esq);
    return rotacaoDireita(raiz->dir);
}

NO* rotacaoDireitaEsquerda(NO* raiz) {
    raiz->dir = rotacaoDireita(raiz->dir);
    return rotacaoEsquerda(raiz->esq);
}

NO* inserirNo(NO* raiz, int chave) {
    if (!raiz) return criarNo(chave);

    if (chave < raiz->chave) {
        raiz->esq = inserirNo(raiz->esq, chave);

        if (altura(raiz->esq) - altura(raiz->dir) == 2) {
            if (chave < raiz->esq->chave) { // insercao na subarvore esquerda do filho a esquerda
                raiz = rotacaoDireita(raiz); 
            } else {
                raiz = rotacaoEsquerdaDireita(raiz); // insercao na subarvore direita fo filho a esquerda
            }
        }
    } else if (chave > raiz->chave) {
        raiz->dir = inserirNo(raiz->dir, chave);

        if (altura(raiz->dir) - altura(raiz->esq) == 2) {
            if (chave > raiz->dir->chave) {
                raiz = rotacaoEsquerda(raiz); // insercao na subarvore direita do filho a direita
            } else {
                raiz = rotacaoDireitaEsquerda(raiz); // insercao na subarvore esquerda do filho a direita
            }
        }
    }

    raiz->h = max(altura(raiz->esq), altura(raiz->dir)) + 1;

    return raiz;
}

int main() {
    NO* raiz = inicializarArvore();
}