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

NO* inserirNo(NO *raiz, int chave) {
    NO* temp = (NO*) malloc(sizeof(NO));
    
    temp->chave = chave;
    temp->esq = NULL;
    temp->dir = NULL;

    if (!raiz) {
        raiz = temp;
    } else {
        NO* atual = raiz;
        NO* pai = NULL;

        while (1) {
            pai = atual;

            if (chave < atual->chave) {
                atual = atual->esq;

                if (!atual) {
                    pai->esq = temp;
                    return raiz;
                }
            } else {
                atual = atual->dir;

                if (!atual) {
                    pai->dir = temp;
                    return raiz;
                }
            }
        }
    }

    return raiz;
}

void emOrdem(NO* raiz) {
    if (raiz) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        emOrdem(raiz->dir);
    }
}

NO* procurarNo(NO* raiz, int chave) {
    NO* atual = raiz;
    printf("Procurando a chave %d: ", chave);

    while (atual) {
        printf("%d ", atual->chave);

        if (chave < atual->chave) {
            atual = atual->esq;
        } else if (chave > atual->chave) {
            atual = atual->dir;
        } else {
            return atual;
        }
    }
}



int main()
{
    int array[14] = { 34, 84, 15, 0, 2, 99, 79, 88, 89, 18, 31, 39, 100, 101};

    NO* raiz;
    inicializarArvore(&raiz);

    for (int i = 0; i <= 13; i++) {
        raiz = inserirNo(raiz, array[i]);
        printf("%d inserido\n", array[i]);
    }

    if (procurarNo(raiz, 88124124)) {
        printf("\nEncontrado.");
    } else {
        printf("\nNao encontrado.");
    }
}