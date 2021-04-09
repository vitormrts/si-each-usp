#include <stdio.h>
#include <stdlib.h>

#define COUNT 10

typedef struct estrutura {
    int chave;
    struct estrutura *esq;
    struct estrutura *dir;
} NO;

// Inicializa��o da �rvore vazia
void inicializarArvore(NO* *raiz) {
    *raiz = NULL;
}

// Verificar se �rvore � vazia
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

// 1. Escreva um algoritmo que, dado um n� p em �rvore bin�ria, retorne a sua altura.

int altura(NO* p) {
    if (!p)
        return -1;
    else {
        int ae = 0;
        int ad = 0;

        if (p->esq) ae = altura(p->esq);
        if (p->dir) ad = altura(p->dir);

        if (ad > ae)
            return ad + 1;
        else
            return ae + 1;
    }
}

// 2. Dada uma �rvore comum (n�o ordenada) contendo apenas chaves entre 0 e 100 sem repeti��o, escreva um algoritmo que retorne a menor chave da estrutura. Se a �rvore esteja vazia, retorne um valor fora do intervalo v�lido.

int menorChave(NO* p) {
    if (!p) return 999;

    while (p->esq) {
        p = p->esq;
    }

    return p->chave;
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

    imprimirArvore(p, 0);

    copiar(&p);

    int h = altura(p);
    int m = menorChave(p);

    //printf("\n\n\n\n\n\nAltura: %d ", h);
    //printf("\nMenor Chave: %d ", m);
    return 0;
}
