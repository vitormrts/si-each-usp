#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Estrutura de registro
typedef struct {
    int key;
} REGISTER;

// Estrutura de lista
typedef struct {
    REGISTER A[MAX+1];
    int length;
} LIST;

// Fun��o para inicializar a lista
void initList (LIST *l) {
    l->length = 0;
}

// Fun��o que retorna o n�mero de elementos da lista
int getLength (LIST *l) {

    printf("\n====================\nN�mero de elementos: ");
    return l->length;
}

// Fun��o que exibe os elementos da lista
int showList (LIST *l) {
    int i = 0;
    printf("\n====================\nElementos da lista:\n");
    for (i = 0; i < l->length; i++) printf("%i\n", l->A[i].key);
    return 1;

}

// Exibe o primeiro elemento da lista
int firstElem (LIST *l) {
    if (l->length > 0) return l->A[0].key;
    return -1;
}

// Busca um elemento da lista
int sequentialSearch (LIST *l, int ch) {
    int i = 0;

    if (l->length == 0) return -1;

    while (i < l->length) {
        if (l->A[i].key == ch) return i;
        else i++;
    }
    return -1;
}

// Busca um elemento com a utiliza��o de uma sentinela
int findWithSentinel(LIST *l, int ch) {
    int i = 0;
    l->A[l->length].key = ch;

    while (l->A[i].key != ch) i++;
    if (i == l->length) return -1;
    return i;
}

// Insere um elemento numa lista ordenada
int insertElemByOrder(LIST *l, REGISTER reg) {
    if (l->length >= MAX) return -1;
    int pos = l->length;

    while (pos > 0 && l->A[pos-1].key > reg.key) {
        l->A[pos] = l->A[pos-1];
        pos --;
    }

    l->A[pos] = reg;
    l->length++;
}

// Realiza a busca de um elemento binariamente
int binarySearch(LIST *l, int ch) {
    int left, right, mid;
    left = 0;
    right = l->length-1;

    while (left <= right) {
        mid = (right+left)/2;
        if (l->A[mid].key == ch) return mid;
        else {
            if (l->A[mid].key < ch) left = mid + 1;
            else right = mid - 1;
        }
    }

    return -1;
}

// Fun��o para inserir elementos na lista
int insertElem(LIST *l, REGISTER reg, int i) {
    int j;

    if (l->length == MAX || i < 0 || i > l->length) return -1;

    for (j = l->length; j > i; j--) l->A[j] = l->A[j-1];

    l->A[i] = reg;
    l->length++;

    return 1;
}

// Fun��o que exclui um elemento da lista
int deleteElem(int ch, LIST *l) {
    int pos = sequentialSearch(l, ch);
    if (pos == -1) return -1;
    int i;
    for (i = pos; i < l->length; i++) l->A[i] = l->A[i+1];
    l->length --;
    return 1;
}

// Fun��o para reinicializar a lista
void clearList (LIST *l) {
    l->length = 0;
}

int main()
{
    LIST l;

    initList(&l);

    REGISTER a;
    a.key = 12;

    REGISTER b;
    b.key = 1;

    REGISTER c;
    c.key = 8;

    REGISTER d;
    d.key = 54;

    insertElemByOrder(&l, b);
    insertElemByOrder(&l, a);
    insertElemByOrder(&l, d);
    insertElemByOrder(&l, c);

    showList(&l);

    printf("Busca com sentinela: %i\nBusca bin�ria: %i", findWithSentinel(&l, 123), binarySearch(&l, 123));

    return 0;
}
