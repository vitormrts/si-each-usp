#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Estrutura de registro
typedef struct {
    int chave;
} REGISTRO;

// Estrutura de lista
typedef struct {
    REGISTRO A[MAX+1];
    int nroElem;
} LISTA;

// Função para inicializar a lista
void inicializarLista (LISTA *l) {
    l->nroElem = 0;
}

// Função que retorna o número de elementos da lista
int tamanho (LISTA *l) {

    printf("\n====================\nNúmero de elementos: ");
    return l->nroElem;
}

// Função que exibe os elementos da lista
int exibirLista (LISTA *l) {
    int i = 0;
    printf("\n====================\nElementos da lista:\n");
    for (i = 0; i < l->nroElem; i++) printf("%i\n", l->A[i].chave);
    return 1;

}

// Exibe o primeiro elemento da lista
int primeiroElem (LISTA *l) {
    if (l->nroElem > 0) return l->A[0].chave;
    return -1;
}

// Busca um elemento da lista
int buscaSequencial (LISTA *l, int ch) {
    int i = 0;

    if (l->nroElem == 0) return -1;

    while (i < l->nroElem) {
        if (l->A[i].chave == ch) return i;
        else i++;
    }
    return -1;
}

// Busca um elemento com a utilização de uma sentinela
int buscaSentinela(LISTA *l, int ch) {
    int i = 0;
    l->A[l->nroElem].chave = ch;

    while (l->A[i].chave != ch) i++;
    if (i == l->nroElem) return -1;
    return i;
}

// Insere um elemento numa lista ordenada
int inserirElemListaOrd(LISTA *l, REGISTRO reg) {
    if (l->nroElem >= MAX) return -1;
    int pos = l->nroElem;

    while (pos > 0 && l->A[pos-1].chave > reg.chave) {
        l->A[pos] = l->A[pos-1];
        pos --;
    }

    l->A[pos] = reg;
    l->nroElem++;
}

// Realiza a busca de um elemento binariamente
int buscaBinaria(LISTA *l, int ch) {
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem-1;

    while (esq <= dir) {
        meio = (dir+esq)/2;
        if (l->A[meio].chave == ch) return meio;
        else {
            if (l->A[meio].chave < ch) esq = meio + 1;
            else dir = meio - 1;
        }
    }

    return -1;
}

// Função para inserir elementos na lista
int inserirElemLista(LISTA *l, REGISTRO reg, int i) {
    int j;

    if (l->nroElem == MAX || i < 0 || i > l->nroElem) return -1;

    for (j = l->nroElem; j > i; j--) l->A[j] = l->A[j-1];

    l->A[i] = reg;
    l->nroElem++;

    return 1;
}

// Função que exclui um elemento da lista
int excluirElemLista (int ch, LISTA *l) {
    int pos = buscaSequencial(l, ch);
    if (pos == -1) return -1;
    int i;
    for (i = pos; i < l->nroElem; i++) l->A[i] = l->A[i+1];
    l->nroElem --;
    return 1;
}

// Função para reinicializar a lista
void reinicializarLista (LISTA *l) {
    l->nroElem = 0;
}

int main()
{
    LISTA l;

    inicializarLista(&l);

    REGISTRO a;
    a.chave = 12;

    REGISTRO b;
    b.chave = 1;

    REGISTRO c;
    c.chave = 8;

    REGISTRO d;
    d.chave = 54;

    inserirElemListaOrd(&l, b);
    inserirElemListaOrd(&l, a);
    inserirElemListaOrd(&l, d);
    inserirElemListaOrd(&l, c);

    exibirLista(&l);

    printf("Busca com sentinela: %i\nBusca binária: %i", buscaSentinela(&l, 123), buscaBinaria(&l, 123));

    return 0;
}
