#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define true 1
#define false 0

typedef int bool;

typedef struct {
    int chave;
} RegistroEstat;

typedef struct {
    int inicio;
    int fim;
    RegistroEstat A[MAX];
} FESTAT;

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
} NO;

typedef struct {
    NO* inicio;
    NO* fim;
} FDINAM;

void inicializarFdinam (FDINAM* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inicializarFestat (FESTAT* f) {
    f->inicio = -1;
    f->fim = -1;
}

int tamanhoFdinam (FDINAM* f) {
    NO* p = f->inicio;
    int tam = 0;

    while (p != NULL) {
        tam++;
        p = p->prox;
    }

    return tam;
}

int tamanhoFestat (FESTAT* f) {
    return f->fim;
}

void exibirFdinam (FDINAM* f) {
    NO* p = f->inicio;

    while (p != NULL) {
        printf("%i ", p->chave);
        p = p->prox;
    }
    printf("\n\n");
}

void exibirFestat (FESTAT* f) {
    int i = f->inicio;
    int temp;

    for (temp = 0; temp < f->fim; temp ++) {
        printf("%i ", f->A[i].chave);
        i = (i+1) % MAX; // não ultrapassa o numero max de elementos
    }
    printf("\n\n");
}

bool inserirElemFdinam (FDINAM* f, int ch) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;

    if (f->inicio == NULL) f->inicio = novo; // lista vazia
    else f->fim->prox = novo;

    f->fim = novo;

    return true;
}

bool inserirElemFestat(FESTAT* f, int ch) {
    if (f->fim >= MAX) return false;

    f->fim = (f->fim + 1) % MAX;
    f->A[f->fim-1].chave = ch;


    if(f->inicio < 0) f->inicio = 0;

    return true;
}

/*bool inserirElemFestat (FESTAT* f, int ch) {
    if (f->fim >= MAX) return false; // nro maximo de elementos

    f->fim = (f->fim + 1) % MAX; // detecta a posicao do ultimo elemento
    f->A[f->fim].chave = ch;

    if (f->inicio < 0) f->inicio = 0;

    return true;
}*/

int excluirElemFdinam (FDINAM* f) {
    if (f->inicio == NULL) return -1; // lista vazia

    NO* aux = f->inicio;
    int ch = f->inicio->chave;

    f->inicio = f->inicio->prox;
    free(aux);
    if (f->inicio == NULL) f->fim = NULL; // lista ficopu vazia

    return ch;
}

int excluirElemFestat (FESTAT* f) {
    if (f->inicio < 0) return -1;
    int ch = f->A[f->inicio].chave;
    if (f->inicio != f->fim) f->inicio = (f->inicio + 1) % MAX; // se nao for lista unitaria
    else {
        f->inicio = -1;
        f->inicio = -1;
    }
    return ch;
}

void reinicializarFdinam (FDINAM* f) {
    NO* p = f->inicio;

    while (p != NULL) {
        NO* aux = p;
        p = p->prox;
        free(aux);
    }

    f->inicio = NULL;
    f->fim = NULL;
}

void reinicializarFestat (FESTAT* f) {
    f->inicio = -1;
    f->fim = -1;
}


int main()
{
    FESTAT* fe;
    inicializarFestat(&fe);
    inserirElemFestat(&fe, 3);
    inserirElemFestat(&fe, 1);
    inserirElemFestat(&fe, 5);
    inserirElemFestat(&fe, 8);
    inserirElemFestat(&fe, 2);
    inserirElemFestat(&fe, 10);
    inserirElemFestat(&fe, 4);
    inserirElemFestat(&fe, 14);

    exibirFestat(&fe);

    /*FDINAM* fd;
    inicializarFdinam(&fd);
    inserirElemFdinam(&fd, 3);
    inserirElemFdinam(&fd, 1);
    inserirElemFdinam(&fd, 5);
    inserirElemFdinam(&fd, 8);
    inserirElemFdinam(&fd, 4);
    inserirElemFdinam(&fd, 10);
    inserirElemFdinam(&fd, 0);
    excluirElemFdinam(&fd);
    exibirFdinam(&fd);*/




    return 0;
}
