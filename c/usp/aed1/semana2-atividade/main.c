#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Estrutura de registro
typedef struct {
    int chave;
} REGISTRO;

// Estrutura de lista
typedef struct {
    REGISTRO A[MAX];
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

// Verifica quantas vezes x repetiu numa lista l
int ocorrencias(LISTA *l, int x) {
    int i;
    int contador = 0; // Conta a quantidade de x repetidos

    if (l->nroElem == 0) return 0;

    for (i = 0; i < l->nroElem; i++) if (l->A[i].chave == x) contador ++;
    return contador;
}

// Verificar se duas listas l1 e l2 são idênticas
int identicas(LISTA *l1, LISTA *l2) {
    int i;

    printf("%i, %i\n", l1->nroElem, l2->nroElem);

    if (l1->nroElem == l2->nroElem) {
            for (i = 0; i < l1->nroElem; i++) {
                if (l1->A[i].chave != l2->A[i].chave) return -1;
            }
    }
    else return -1;

    return 1;
}
int main()
{
    /*
    // Configuração da lista
    LISTA lista;

    inicializarLista(&lista);

    REGISTRO a;
    a.chave = 3;

    REGISTRO b;
    b.chave = 2;

    REGISTRO c;
    c.chave = 5;

    REGISTRO d;
    d.chave = 0;

    REGISTRO e;
    e.chave = 5;

    REGISTRO f;
    f.chave = 1;

    REGISTRO g;
    g.chave = 10;

    REGISTRO h;
    h.chave = 4;

    REGISTRO i;
    i.chave = 5;

    REGISTRO j;
    j.chave = 1;

    inserirElemLista(&lista, a, 0);
    inserirElemLista(&lista, b, 1);
    inserirElemLista(&lista, c, 2);
    inserirElemLista(&lista, d, 3);
    inserirElemLista(&lista, e, 4);
    inserirElemLista(&lista, f, 5);
    inserirElemLista(&lista, g, 6);
    inserirElemLista(&lista, h, 7);
    inserirElemLista(&lista, i, 8);
    inserirElemLista(&lista, j, 9);

    exibirLista(lista);

    int x = 5;

    // Verifica a qntd de x na lista
    printf("Quantidade de %i's na lista: %d", x, ocorrencias(&lista, x));
    */

    // Configurando a lista1
    LISTA lista1;

    inicializarLista(&lista1);

    REGISTRO a1;
    a1.chave = 3;

    REGISTRO b1;
    b1.chave = 2;

    REGISTRO c1;
    c1.chave = 5;

    REGISTRO d1;
    d1.chave = 0;

    REGISTRO e1;
    e1.chave = 5;

    inserirElemLista(&lista1, a1, 0);
    inserirElemLista(&lista1, b1, 1);
    inserirElemLista(&lista1, c1, 2);
    inserirElemLista(&lista1, d1, 3);
    inserirElemLista(&lista1, e1, 4);

    // Configurando a lista2
    LISTA lista2;

    inicializarLista(&lista2);

    REGISTRO a2;
    a2.chave = 3;

    REGISTRO b2;
    b2.chave = 2;

    REGISTRO c2;
    c2.chave = 5;

    REGISTRO d2;
    d2.chave = 0;

    REGISTRO e2;
    e2.chave = 5;

    inserirElemLista(&lista2, a2, 0);
    inserirElemLista(&lista2, b2, 1);
    inserirElemLista(&lista2, c2, 2);
    inserirElemLista(&lista2, d2, 3);
    inserirElemLista(&lista2, e2, 4);

    // Verificar se sao identicas
    printf("%i", identicas(&lista1, &lista2));

    return 0;
}
