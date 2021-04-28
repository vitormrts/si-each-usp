#include <stdio.h>
#include <stdlib.h>

#define MAX 50
typedef struct {
    int chave;
    int prox;
} REGISTRO;

typedef struct {
        REGISTRO A[MAX];
        int inicio;
        int dispo;
} LISTA;

// Inicilializa a lista ligada
void inicializarListaLigada(LISTA *l) {
    // Posi��o do �ndice dispon�vel
    for (int i = 0; i < MAX-1; i++) l->A[i].prox = i + 1;

    l->dispo = 0;
    l->inicio = -1;
    l->A[MAX-1].prox = -1;
}

// Retorna o tamanho da lista
int tamanho (LISTA *l) {
    int i = l->inicio;
    int tam = 0;

    while (i != -1) {
        tam ++;
        i = l->A[i].prox;
    }

    return tam;
}

// Exibe os elementos da lista
int exibirLista (LISTA l) {
    int i = l.inicio;
    printf("\n=====================\nExibindo lista\n");


    while (i > -1) {
        printf("%i ", l.A[i].chave);
        i = l.A[i].prox;
    }
}

// Busca sequencial que terona a posicao da chave e do anterior
int buscaSeqOrd(int ch, LISTA l, int *ant) {
    int i = l.inicio;


    *ant = -1;

    while (i != -1) {
        if (l.A[i].chave >= ch) break;
        *ant = i;
        i = l.A[i].prox;
    }

    if (i == -1) return -1;
    if (l.A[i].chave==ch) return i;
    else return -1;
}

// Retira o 1� elemento dispon�vel e retorna a sua posi��o
int obterNo (LISTA *l) {
    int resultado = l->dispo;

    if (l->dispo > -1) l->dispo = l->A[l->dispo].prox;

    return resultado;
}

// Devolve um elemento para a lista de dispon�veis
int devolverNo (LISTA *l, int j) {
    // O pr�ximo elemento de j ser� o anterior dispon�vel
    l->A[j].prox = l->dispo;

    // j assume a posicao de disponivel
    l->dispo = j;
}

// Insere um elemento numa lista ordenada (sem duplica��o)
int inserirElemListaOrd(LISTA *l, int ch) {

    int i, ant;

    i = buscaSeqOrd(ch, *l, &ant);
    if ((l->dispo < 0) || (i != -1)) return -1;

    i = obterNo(l);
    l->A[i].chave = ch;

    if (l->inicio<0) {
        l->inicio = 1;
        l->A[i].prox = -1;
    }

    else {
        if (ant < 0) {
            l->A[i].prox = l->inicio;
            l->inicio = i;
        }

        else {
            l->A[i].prox = l->A[ant].prox;
            l->A[ant].prox = i;
        }
    }

    return 1;
}

// Exclui um elemento de uma determinada chave
int excluirElemLista(LISTA *l, int ch) {
    int ant = -1;
    int i = l->inicio;

    while ((i != -1) && (l->A[i].chave < ch)) {
        ant = i;
        i = l->A[i].prox;
    }

    if ((i == -1) || (l->A[i].chave != ch)) return -1;
    if (ant == -1) l->inicio = l->A[i].prox;
    else l->A[ant].prox = l->A[i].prox;

    devolverNo(l, i);

    return 1;
}

// Troca de lugar a primeira e ultima chave da estrutura
void trocar(LISTA* l) {
    int i = l->inicio;
    int fim = -1;

    while (i != -1) {
        if (l->A[i].prox == -1) {
            fim = i;
            break;
        }
        i = l->A[i].prox;
    }

    if (fim == -1) return(-1);

    int aux = l->A[l->inicio].chave;

    l->A[l->inicio].chave = l->A[fim].chave;
    l->A[fim].chave = aux;

    /*int tam = tamanho(l);

    if (tam > 2) {
        int i = l->inicio;
        int ant;

        while (l->A[i].prox != -1) {
            ant = i;
            i = l->A[i].prox;
        }

        l->A[ant].prox = l->inicio;

        l->A[i].prox = l->A[l->inicio].prox;
        l->A[l->inicio].prox = -1;

        int fimChave = l->A[i].chave;
        int inicioChave = l->A[l->inicio].chave;

        l->A[i].chave = inicioChave;
        l->A[l->inicio].chave = fimChave;

        l->inicio = i;*/


}

// Sobrescreve o sucessor de uma chave em uma posicao i
void sobrescrever(LISTA* l, int i) {
    if (l->A[i].prox != -1) {
        int j = l->inicio;
        int ant;

        while (j != i) {
            ant = j;
            j = l->A[j].prox;
        }

        l->A[ant].prox = l->A[i].prox;
        l->A[l->A[i].prox].chave = l->A[i].chave;

    }
}
int main()
{
    LISTA l;

    inicializarListaLigada(&l);


    REGISTRO a;
    a.chave = 2;

    REGISTRO b;
    b.chave = 8;

    REGISTRO c;
    c.chave = 4;

    REGISTRO d;
    d.chave = 10;

    REGISTRO e;
    e.chave = 1;

    REGISTRO f;
    f.chave = 0;

    l.dispo = 1;
    inserirElemListaOrd(&l, a.chave);

    l.dispo = 4;
    inserirElemListaOrd(&l, b.chave);

    l.dispo = 0;
    inserirElemListaOrd(&l, c.chave);

    l.dispo = 2;
    inserirElemListaOrd(&l, d.chave);

    l.dispo = 7;
    inserirElemListaOrd(&l, e.chave);

    l.dispo = 10;
    inserirElemListaOrd(&l, f.chave);

    //printf("=============\n%i", l.A[5].prox);
    exibirLista(l);

    trocar(&l);
    //exibirLista(l);

    //sobrescrever(&l, 2);
    exibirLista(l);

    return 0;
}
