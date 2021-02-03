#include <stdio.h>
#include <stdlib.h>


void inverterLista(NO* *ini) {
    NO* ant, atual, prox;
    ant = NULL;
    atual = *ini;
    while (atual) {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    *ini = ant;
}

void exibirLista(NO* p) {
    if (p) {
        printf("%i ", p->chave);
        exibirLista(p->prox);
    }
}

void exibirListaInvertida (NO* p) {
    if (p) {
        exibirListaInvertida(p->prox);
        printf("%i ", p->chave);
    }
}

void inverterListaRec(NO* *ini, NO* ant, NO* atual) {
    if (atual) {
        inverterListaRec(ini, atual, atual->prox);
        atual->prox = ant;
    }
    else *ini = ant;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
