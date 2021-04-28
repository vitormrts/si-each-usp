#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura {
    int chave;

    struct estrutura *dir;
    struct estrutura *esq;
    int altura;
} NO;

void inicializarArvore(NO* *raiz) {
    *raiz = NULL;
}

NO* criarNo(int chave) {
    NO* novoNo = (NO*) malloc(sizeof(NO));

    novoNo->chave = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->altura = 0;

    return (novoNo); 
}

void rotacaoDireita(NO* *pai) {
    NO* novoPai = (*pai)->esq;
    (*pai)->esq = novoPai->dir;
    novoPai->dir = *pai;
    *pai = novoPai;
}

void rotacaoEsquerda(NO* *pai) {
    NO* novoPai = (*pai)->dir;
    (*pai)->dir = novoPai->esq;
    novoPai->esq = *pai;
    *pai = novoPai;
}

void rotacaoDireitaEsquerda(NO* *pai) {
    NO* filho = (*pai)->dir;
    rotacaoDireita(&filho);
    (*pai)->dir = filho;
    rotacaoEsquerda(pai);
}

void rotacaoEsquerdaDireita(NO* *pai) {
    NO* filho = (*pai)->esq;
    rotacaoEsquerda(&filho);
    (*pai)->esq = filho;
    rotacaoDireita(pai);
}

int main() {
    NO* raiz;
    inicializarArvore(&raiz)
}