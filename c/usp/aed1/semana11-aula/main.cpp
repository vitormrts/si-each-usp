#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura {
    struct estrutura *esq;
    struct estrutura *dir;
    struct estrutura *prox;
    int chave;
} NO;

typedef struct {
    NO* inicio;
    NO* fim;
} FILA;

void inicializarArvore (NO* *raiz) {
    *raiz = NULL;
}

void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

NO* inserirArvore(NO* *raiz, int ch) {
    if (!(*raiz)) {
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->dir = NULL;
        novo->esq = NULL;
        novo->chave = ch;
        *raiz = novo;
    }
    else if (ch < (*raiz)->chave) (*raiz)->esq = inserirArvore(&(*raiz)->esq, ch);
    else (*raiz)->dir = inserirArvore(&(*raiz)->dir, ch);

    return *raiz;
}

void entrarFila (FILA* f, int ch) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;

    if (f->inicio == NULL) f->inicio = novo; // lista vazia
    else f->fim->prox = novo;

    f->fim = novo;
}

// Exclui um nó folha
void excluirFolha(NO* *raiz, int ch) {
    if (*raiz) {
        if (ch > (*raiz)->chave)
            excluirFolha(&(*raiz)->dir, ch); // vai para a direita
        else if (ch < (*raiz)->chave)
            excluirFolha(&(*raiz)->esq, ch); // vai para a esquerda
        else { // achou a chave
            NO *aux = *raiz; // utiliza um auxiliar
            if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
                free(aux); // libera memoria
                (*raiz) = NULL; // raiz null
            }
        }
    }
}


int sairFila (FILA* f) {
    if (f->inicio == NULL) return -1; // lista vazia

    NO* (*raiz) = f->inicio;
    int ch = f->inicio->chave;

    f->inicio = f->inicio->prox;
    free((*raiz));
    if (f->inicio == NULL) f->fim = NULL; // lista ficopu vazia

    return ch;
}

void imprimirArvore(NO* raiz) {
    if (raiz) {
        printf("%d ", raiz->chave);
        imprimirArvore(raiz->esq);
        imprimirArvore(raiz->dir);
    }
}

/*void exibirArvoreEmNivel(NO* raiz) {
    FILA f;
    NO* p = raiz;
    inicializarFila(&f);
    while( (p) || (f.inicio) ) {
        if(p->esq) entrarFila(p->esq, &f);
        if(p->dir) entrarFila(p->dir, &f);
        printf("%d", p->chave);
        p = NULL;
        if(f.inicio) p = sairFila(f);
    }
}*/

void preOrdem(NO* p) {
    if (p) {
        printf("%d ", p->chave);

        preOrdem(p->esq);
        preOrdem(p->dir);
    }
}

int main()
{
    NO* r;
    inicializarArvore(&r);

    inserirArvore(&r, 23);
    inserirArvore(&r, 12);
    inserirArvore(&r, 15);
    inserirArvore(&r, 25);
    inserirArvore(&r, 8);

    excluirFolha(&r, 8);

    imprimirArvore(r);


    //inserirArvore(&r, 18);
    //inserirArvore(&r, 17);
    //inserirArvore(&r, 16);
    //inserirArvore(&r, 6);
    //inserirArvore(&r, 5);
    //inserirArvore(&r, 15);
    //inserirArvore(&r, 12);
    //inserirArvore(&r, 3);
    //inserirArvore(&r, 9);
    //inserirArvore(&r, 2);
    //inserirArvore(&r, 13);

    /*inserirArvore(&raiz, 10);
    inserirArvore(&raiz, 15);
    inserirArvore(&raiz, 20);
    inserirArvore(&raiz, 12);
    inserirArvore(&raiz, 5);*/
    //inserirElemArvore(&raiz, 13);

    //preOrdem(raiz);
    //imprimirArvore(raiz);

    return 0;
}
