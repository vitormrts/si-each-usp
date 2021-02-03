#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
    struct estrutura *ant;
} NO;

typedef struct cabeca {
    NO* cabeca;
} DEQUE;

void inicializarDeque(DEQUE* d) {
    d->cabeca = (NO*) malloc(sizeof(NO));
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}

/*NO* buscaSeqOrd(int ch, DEQUE d, NO* *ant) {
    NO* p = d.cabeca->prox;
    *ant = d.cabeca;
    d.cabeca->chave = ch;

    // Enquanto a chave de p for menor q a chave de cabeca
    while (p->chave < ch) {
        *ant = p;
        p = p->prox;
    }
    // Se p for diferente de cabeca e a chave de p for igual a ch, retorna p
    if ((p != d.cabeca) && (p->chave == ch)) return p;
    else return NULL;
}

bool inserirElemDeque (DEQUE* d, int ch) {
    NO* novo;
    NO* ant;
    novo = buscaSeqOrd(ch, *d, &ant);

    novo->chave = ch;
    novo->prox = ant->prox;
    novo->ant = ant;
    novo->prox->ant = novo;
    ant->prox = novo;

    return true;
}*/

int tamanho(DEQUE* d) {
    int tam = 0;
    NO* fim = d->cabeca->prox;

    while (fim != d->cabeca) {
        tam++;
        fim = fim->prox;
    }

    return tam;
}

void exibirDeque(DEQUE *d) {
    NO* fim = d->cabeca->prox;

    while (fim != d->cabeca) {
        printf("%i ", fim->chave);
        fim = fim->prox;
    }
}

NO* exibirInvertida(DEQUE* l) {
    NO* p = l->cabeca->ant;

    while (p != l->cabeca) {
        printf("%i ", p->chave);
        p = p->ant;
    }
}

void inserirAntes(DEQUE* l, int ch, NO* atual) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;

    atual->ant->prox = novo;
    novo->ant = atual->ant;
    atual->ant = novo;
    novo->prox = atual;
}

NO* anexarElem (DEQUE* d, int ch){
    NO* novo = (NO*) malloc(sizeof(NO));

    novo->chave = ch;
    novo->prox = d->cabeca;
    novo->ant = d->cabeca->ant;
    d->cabeca->ant = novo;
    novo->ant->prox = novo;

    return novo;
}
int excluirElemDequeInicio (DEQUE* d) {
    if (d->cabeca->prox == d->cabeca) return false; // vazio
    NO* aux = d->cabeca->prox;

    d->cabeca->prox = aux->prox;
    aux->prox->ant = d->cabeca;

    free(aux);
}

void reinicializarDeque (DEQUE* d) {
    NO* p = d->cabeca->prox;

    while (p != d->cabeca) {
        NO* aux = p;
        p = p->prox;
        free(aux);
    }

    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}



int main()
{
    DEQUE* d;
    inicializarDeque(&d);

    NO* a = anexarElem(&d, 3);
    anexarElem(&d, 2);
    anexarElem(&d, 6);
    anexarElem(&d, 8);
    NO* atual = anexarElem(&d, 9);
    anexarElem(&d, 2);
    anexarElem(&d, 1);
    NO* x = anexarElem(&d, 0);
    exibirDeque(&d);
    printf("\n");

    //exibirInvertida(&d);

    inserirAntes(&d, 76, a);
    exibirDeque(&d);


    //excluirElemDequeInicio(&d);
    //exibirDeque(&d);
    //printf("\n");

    //reinicializarDeque(&d);
    //exibirDeque(&d);
    return 0;
}
