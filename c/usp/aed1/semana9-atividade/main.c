#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
    struct estrutura *ant;
} NO;

typedef struct {
    NO* inicio;
} LISTA;

// Inicializa a lista
void inicializarLista(LISTA* l) {
    l->inicio = NULL;
}

// Exibe o tamanho da lista
int tamanho(NO* p) {
    int tam = 0;

    // Incremente a variavel tam enquanto p existir.
    while (p) {
        tam ++;
        // Proximo elemento de p
        p = p->prox;
    }

    // Retorna o tamanho da lista apontada por p
    return tam;
}


void exibirLista(NO* inicio) {
    NO* p = inicio;
    printf("\nExibindo lista: ");
    while (p) {
        printf("%i ", p->chave);
        p = p->prox;
    }
}

void exibirInvertida(NO* inicio) {
    //NO* p = ultimoElemLista(inicio);
    NO* p = inicio;
    printf("\n");
   /* while (p) {
            printf("%i ", p->chave);
            p = p->prox;
    }*/
    printf("\nExibindo lista invertida: ");


    while (p) {
       // printf("%i ", p->chave);
       if (p->ant != NULL) printf("%i ", p->ant->chave);

        p = p->prox;
    }
}

void exibirListaL(LISTA l) {
    NO* p = l.inicio;
    printf("Exibindo a lista:\n");

    while (p) {
        printf("%i ", p->chave);
        p = p->prox;
    }
}

// Faz a busca sequencial de uma chave numa lista apontada por p
NO* buscaSeqOrd(NO* p, int ch, NO* *ant) {
    // Como ant � um ponteiro de ponteiro, dizemos que ant tamb�m ser� retornado
    *ant = NULL;

    // Enquanto p existir
    while (p) {
        // Se o chave apontado pelo ponteiro p for maior ou igual a chave, o la�o � interrompido
        if (p->chave >= ch) break;

        // O anterior apontar� para p e p aponta para seu proximo elemento
        *ant = p;
        p = p->prox;
    }

    // Verifica se p existe e se o chave apontado por ele � igual � da chave
    // Caso isso seja verdadeiro, a fun��o retorna o ponteiro de p
    if (p && p->chave == ch) return p;

    // Caso contr�rio, retorna NULL (ch n�o existe na lista apontada por p)
    return NULL;
}

// Insercao de chave sem repeticoes
int inserirElemListaOrd(NO* *inicio, int ch) {
    NO* novo;
    NO* ant;

    // Faz a busca sequencial de ch dentro da lista apontada por inicio
    novo = buscaSeqOrd(*inicio, ch, &ant);

    // Significa que h� um numero igual a ch
    if (novo) return -1;

    // Aloca um espa�o de mem�ria para o ponteiro novo
    novo = (NO*) malloc(sizeof(NO));
    // O chave apontado pelo ponteiro novo recebe o par�metro ch
    novo->chave = ch;

    // Se o ponteiro de ponteiro in�cio � NULL
    if (*inicio == NULL) { // 1a. inser��o em lista vazia

        // Aloca um espa�o de mem�ria para o ponteiro de ponteiro inicio
        *inicio = (NO*) malloc(sizeof(NO));

        // O ponteiro de ponteiro de inicio aponta para o ponteiro de novo
        // O prox elemento apontado pelo ponteiro de novo recebe NULL, pois ele � o primeiro elemento inserido
        *inicio = novo;
        novo->prox = NULL;
    }

    else {
        // Se n�o possui anterior
        if (!ant) { // inser��oo no in�cio da lista
            // O prox elemento apontado por novo ser� atualizado, recebendo o ponteiro de ponteiro inicio
            // O ponteiro de ponteiro inicio ser� atualizado, recebendo o novo ponteiro
            novo->prox = *inicio;
            *inicio = novo;
        }

        else { // inser��o ap�s um n� existente
            // O prox elemento apontado por novo ser� o prox elemento apontado pelo anterior
            // O prox elemento apontado pelo anterior ser� o ponteiro novo
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }
    return 1;
}

// Destruicao da lista
void destruirLista(NO* *inicio) {
    NO* atual;
    NO* prox;
    atual = *inicio;

    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}

// Retorna o ultimo elemento da lista
NO* ultimoElemLista(NO* inicio) {
    NO* p = inicio;

    if (p)
        while (p->prox) {
            printf("%i ", p->chave);
            p = p->prox;
    }
    return p;
}

// Anexa um novo elemento ao final da lista
void anexarElemLista(NO* *inicio, int ch) {

    NO* novo;
    NO* ant;
    ant = ultimoElemLista(*inicio);
    novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;
    if(!ant) *inicio = novo;
    else ant->prox = novo;
}

// Dado um inteiro n > 0, criar uma lista duplamente ligada sem cabe�a e sem circularidade de n elementos numerados de 1..n, retornando o ponteiro para o seu in�cio.
NO* listaNumerada(int n, NO* *arbitrario) {
    NO* inicio = NULL;
    NO* ant = NULL;
    *arbitrario = NULL;

    for (int i = 1; i <= n; i++) {

        if (!inicio) { // Primeira insercao
            inicio = (NO*) malloc(sizeof(NO));
            inicio->chave = i;
            inicio->prox = NULL;
            inicio->ant = NULL;
        }

        else {
            NO* novo = malloc(sizeof(NO));
            novo->chave = i;

            if (!ant) { // Insercao depois do inicio

                novo->prox = NULL;
                novo->ant = inicio;
                inicio->prox = novo;
            }

            else {
                novo->ant = ant;
                novo->prox = NULL;
                novo->ant->prox = novo;

            }
            ant = novo;
            if (i == n) *arbitrario = novo;
        }


    }
    return inicio;
}

// Dada uma lista do tipo anterior e um ponteiro p garantidamente v�lido, mover o elemento p para o fim da lista. Se p j� for o �ltimo elemento dda lista, n�o h� nada a fazer.

void moverParaFim(LISTA* l, NO* p) {
    NO* p1 = l->inicio;
    while (p1) {
        if (p1 == p && p1->prox != NULL) {
            p->ant->prox = p->prox; // proximo do anterior eh o proximo do atual
            p->prox->ant = p->ant; // anterior do proximo eh o anterior do atual
        }

        else if (p1->prox == NULL && p1 != p) {
            p1->prox = p;
            p1->prox->prox = NULL;
            p1->prox->ant = p1;
            break;
        }
        p1 = p1->prox;
    }
}

int main()
{
    NO* arbitrario;
    NO* p = NULL;
    p = listaNumerada(13, &arbitrario);

    LISTA l;
    inicializarLista(&l);

    l.inicio = p;


    exibirLista(p);
    printf("\n");
    exibirListaL(l);

    moverParaFim(&l, arbitrario);
    printf("\n\n\n");
    exibirListaL(l);



    return 0;
}
