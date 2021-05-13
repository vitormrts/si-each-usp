#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Estrutura de registro
typedef struct {
    int key;
} REGISTER;

// Estrutura de lista
typedef struct {
    REGISTER A[MAX];
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
int excluirElemLista (int ch, LIST *l) {
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

// Verifica quantas vezes x repetiu numa lista l
int occurrences(LIST *l, int x) {
    int i;
    int count = 0; // Conta a quantidade de x repetidos

    if (l->length == 0) return 0;

    for (i = 0; i < l->length; i++) if (l->A[i].key == x) count ++;
    return count;
}

// Verificar se duas listas l1 e l2 s�o id�nticas
int identical(LIST *l1, LIST *l2) {
    int i;

    printf("%i, %i\n", l1->length, l2->length);

    if (l1->length == l2->length) {
            for (i = 0; i < l1->length; i++) {
                if (l1->A[i].key != l2->A[i].key) return -1;
            }
    }
    else return -1;

    return 1;
}
int main()
{
    /*
    // Configura��o da lista
    LIST lista;

    initList(&lista);

    REGISTER a;
    a.key = 3;

    REGISTER b;
    b.key = 2;

    REGISTER c;
    c.key = 5;

    REGISTER d;
    d.key = 0;

    REGISTER e;
    e.key = 5;

    REGISTER f;
    f.key = 1;

    REGISTER g;
    g.key = 10;

    REGISTER h;
    h.key = 4;

    REGISTER i;
    i.key = 5;

    REGISTER j;
    j.key = 1;

    insertElem(&lista, a, 0);
    insertElem(&lista, b, 1);
    insertElem(&lista, c, 2);
    insertElem(&lista, d, 3);
    insertElem(&lista, e, 4);
    insertElem(&lista, f, 5);
    insertElem(&lista, g, 6);
    insertElem(&lista, h, 7);
    insertElem(&lista, i, 8);
    insertElem(&lista, j, 9);

    showList(lista);

    int x = 5;

    // Verifica a qntd de x na lista
    printf("Quantidade de %i's na lista: %d", x, ocorrencias(&lista, x));
    */

    // Configurando a lista1
    LIST lista1;

    initList(&lista1);

    REGISTER a1;
    a1.key = 3;

    REGISTER b1;
    b1.key = 2;

    REGISTER c1;
    c1.key = 5;

    REGISTER d1;
    d1.key = 0;

    REGISTER e1;
    e1.key = 5;

    insertElem(&lista1, a1, 0);
    insertElem(&lista1, b1, 1);
    insertElem(&lista1, c1, 2);
    insertElem(&lista1, d1, 3);
    insertElem(&lista1, e1, 4);

    // Configurando a lista2
    LIST lista2;

    initList(&lista2);

    REGISTER a2;
    a2.key = 3;

    REGISTER b2;
    b2.key = 2;

    REGISTER c2;
    c2.key = 5;

    REGISTER d2;
    d2.key = 0;

    REGISTER e2;
    e2.key = 5;

    insertElem(&lista2, a2, 0);
    insertElem(&lista2, b2, 1);
    insertElem(&lista2, c2, 2);
    insertElem(&lista2, d2, 3);
    insertElem(&lista2, e2, 4);

    // Verificar se sao identicas
    printf("%i", identical(&lista1, &lista2));

    return 0;
}
