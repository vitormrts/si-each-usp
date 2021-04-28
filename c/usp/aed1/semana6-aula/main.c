#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura {
    int chave;
    struct estrutura* prox;
} NO;

// Inicializa a lista
void inicializarLista(NO* *cabeca) {
    *cabeca = (NO*) malloc(sizeof(NO));
    NO* p = *cabeca;
    // O prox elemento de N� cabeca ser� ele mesmo
    p->prox = *cabeca;
}

// Exibe a lista
void exibirLista(NO* cabeca) {
    NO* p = cabeca->prox;
    if (p == cabeca) return NULL;
    while (p != cabeca) {
        printf("%d ", p->chave);
        p = p->prox;
    }
}

// 1o. elemento da lista
NO* primeiroElem(NO* cabeca) {
    // Se o prox de cabeca for cabeca, ele nao tem elementos, pois aponta para cabeca (que � apenas um "auxiliar")
    if (cabeca->prox == cabeca) return NULL;
    else return cabeca->prox;
}

// Ultimo elemento da lista
NO* ultimoElem(NO* cabeca) {
    NO* p = cabeca->prox;

    if (p == cabeca) return NULL;
    while (p->prox != cabeca) p = p->prox;
    return p;
}

// Posicao da chave de busca na lista ordenada
NO* buscaSeqOrd(int ch, NO* cabeca, NO* *ant) {
    NO* p = cabeca->prox;
    *ant = cabeca;
    cabeca->chave = ch;

    // Enquanto a chave de p for menor q a chave de cabeca
    while (p->chave < cabeca->chave) {
        *ant = p;
        p = p->prox;
    }

    // Se p for diferente de cabeca e a chave de p for igual a ch, retorna p
    if ((p != cabeca) && (p->chave == ch)) return p;
    else return NULL;
}

// Inserir elemento numa lista (sem repetir)
int inserirElemListaOrd(NO* *cabeca, int ch) {
    NO* novo;
    NO* ant;

    // Faz a busca sequencial
    novo = buscaSeqOrd(ch, *cabeca, &ant);
    // Se novo � diferente de NULL, ele existe, entao retorne -1
    if (novo != NULL) return -1;
    novo = (NO*) malloc(sizeof(NO));

    novo->chave = ch;
    novo->prox = ant->prox;
    ant->prox = novo;

    return 1;
}

// Exclusao de elemento
int excluirElemListaOrd(NO* *cabeca, int ch) {
    NO* ant;
    NO* pos;

    pos = buscaSeqOrd(ch, *cabeca, &ant);

    // Elemento nao consta
    if (pos == NULL) return -1;

    ant->prox = pos->prox;
    free(pos);

    return 1;
}

// Retorna o n-esimo elemento da lista
NO* enesimoElem(NO* cabeca, int n) {
    NO* p = cabeca->prox;

    if (p == cabeca) return NULL;
    int i = 0;

    while ((p != cabeca) && (i < n)) {
        p = p->prox;
        i++;
    }

    if (i != n) return NULL;
    else return p;
}

// Numero de elementos
int tamanho(NO* cabeca) {
    NO* p = cabeca->prox;
    int tam = 0;
    while (p != cabeca) {
        tam++;
        p = p->prox;
    }
    return tam;
}

void destruirLista(NO* cabeca) {
    NO* atual = cabeca->prox;
    NO* prox;

    if (atual == cabeca) return NULL;
    while (atual != cabeca) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    cabeca->prox = cabeca;
}

int main()
{
    NO* cabeca;

    inicializarLista(&cabeca);

    inserirElemListaOrd(&cabeca, 3);
    inserirElemListaOrd(&cabeca, 1);
    inserirElemListaOrd(&cabeca, 2);
    inserirElemListaOrd(&cabeca, 2);
    inserirElemListaOrd(&cabeca, 0);
    inserirElemListaOrd(&cabeca, 9);

    excluirElemListaOrd(&cabeca, 9);

    exibirLista(cabeca);

    destruirLista(cabeca);


    exibirLista(cabeca);

    return 0;
}
