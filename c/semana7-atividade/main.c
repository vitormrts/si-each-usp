#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef struct estrutura {
    int chave;
    struct estrutura* prox;
} NO;

typedef struct {
    NO* topo;
} PDINAM;

void exibirLista(NO* inicio) {
    NO* p = inicio;
    printf("\nExibindo lista: ");
    while (p) {
        printf("%i ", p->chave);
        p = p->prox;
    }
}

// Faz a busca sequencial de uma chave numa lista apontada por p
NO* buscaSeqOrd(NO* p, int ch, NO* *ant) {
    // Como ant é um ponteiro de ponteiro, dizemos que ant também será retornado
    *ant = NULL;

    // Enquanto p existir
    while (p) {
        // Se o chave apontado pelo ponteiro p for maior ou igual a chave, o laço é interrompido
        if (p->chave >= ch) break;

        // O anterior apontará para p e p aponta para seu proximo elemento
        *ant = p;
        p = p->prox;
    }

    // Verifica se p existe e se o chave apontado por ele é igual à da chave
    // Caso isso seja verdadeiro, a função retorna o ponteiro de p
    if (p && p->chave == ch) return p;

    // Caso contrário, retorna NULL (ch não existe na lista apontada por p)
    return NULL;
}

// Insercao de chave sem repeticoes
int inserirElemListaOrd(NO* *inicio, int ch) {
    NO* novo;
    NO* ant;

    // Faz a busca sequencial de ch dentro da lista apontada por inicio
    novo = buscaSeqOrd(*inicio, ch, &ant);

    // Significa que há um numero igual a ch
    if (novo) return -1;

    // Aloca um espaço de memória para o ponteiro novo
    novo = (NO*) malloc(sizeof(NO));
    // O chave apontado pelo ponteiro novo recebe o parâmetro ch
    novo->chave = ch;

    // Se o ponteiro de ponteiro início é NULL
    if (*inicio == NULL) { // 1a. inserção em lista vazia

        // Aloca um espaço de memória para o ponteiro de ponteiro inicio
        *inicio = (NO*) malloc(sizeof(NO));

        // O ponteiro de ponteiro de inicio aponta para o ponteiro de novo
        // O prox elemento apontado pelo ponteiro de novo recebe NULL, pois ele é o primeiro elemento inserido
        *inicio = novo;
        novo->prox = NULL;
    }

    else {
        // Se não possui anterior
        if (!ant) { // inserçãoo no início da lista
            // O prox elemento apontado por novo será atualizado, recebendo o ponteiro de ponteiro inicio
            // O ponteiro de ponteiro inicio será atualizado, recebendo o novo ponteiro
            novo->prox = *inicio;
            *inicio = novo;
        }

        else { // inserção após um nó existente
            // O prox elemento apontado por novo será o prox elemento apontado pelo anterior
            // O prox elemento apontado pelo anterior será o ponteiro novo
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }
    return 1;
}

// inicializacao da pilha
void inicializarPdinam(PDINAM* p) {
    p->topo = NULL;
}

// quantidade de elementos
int tamanhoPdinam(PDINAM* p) {
    NO* fim = p->topo;
    int tam = 0;

    while (fim) {
        tam ++;
        fim = fim->prox;
    }

    return tam;
}

// verifica se a pilha esta vazia
bool vaziaPdinam(PDINAM* p) {
    // Se nao tem topo, entao ela é vazia
    if (p->topo == NULL) return true;
    return false;
}

// exibe os elementos
void exibirPdinam(PDINAM* p) {
    NO* p1 = p->topo;
    printf("Pilha: \" ");
    while (p1) {
        printf("%i ", p1->chave);
        p1 = p1->prox;
    }
    printf("\"\n");
}

// insere elementos
void push(PDINAM* p, int ch) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;

    // novo assumira o topo, ou seja, ele precisara apontar para o topo atual, e atualizar o ponteiro de topo apos isso
    novo->prox = p->topo;
    p->topo = novo;
}

// exclui um elemento
int pop(PDINAM* p) {
    int ch;
    NO* aux;

    // não há elementos
    if (!p->topo) return -1;

    aux = p->topo;
    ch = aux->chave;

    p->topo = p->topo->prox;
    free(aux);

    return ch;
}

void reinicializarPdinam(PDINAM* p) {
    NO* aux;
    NO* pos = p->topo;

    while (pos) {
        aux = pos;
        pos = pos->prox;
        free(aux);
    }

    p->topo = NULL;
}

// Copia uma lista dinamica apontada por *p
NO* copia(NO* p) {
    NO* inicio = NULL;
    NO* fim = NULL;

    while (p) {
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = p->chave;
        novo->prox = NULL;

        if (fim) fim->prox = novo;
        else inicio = novo;

        fim = novo;
        p = p->prox;
    }
    return inicio;
}

NO* copiaInvertida(NO* p) {
    PDINAM* pilha;
    inicializarPdinam(&pilha);

    NO* aux = p;
    NO* inicio = NULL;
    NO* fim = NULL;

    while (p) {
        push(&pilha, p->chave);
        p = p->prox;
    }

    while (aux) {

        NO* novo = (NO*) malloc(sizeof(NO));

        int ch = pop(&pilha);
        novo->chave = ch;
        novo->prox = NULL;

        // Guarda o fim, para nao ficar percorrendo o laco varias vezes
        if (fim) fim->prox = novo;
        else inicio = novo;

        fim = novo;
        aux = aux->prox;
    }
    return inicio;
}

int main()
{
    /*PDINAM* p;
    inicializarPdinam(&p);

    push(&p, 3);
    push(&p, 4);
    push(&p, 1);
    push(&p, 2);
    push(&p, 8);
    push(&p, 7);

    exibirPdinam(&p);

    printf("\n");

    reinicializarPdinam(&p);

    exibirPdinam(&p);*/

    NO* p = NULL;

    inserirElemListaOrd(&p, 3);
    inserirElemListaOrd(&p, 1);
    inserirElemListaOrd(&p, 4);
    inserirElemListaOrd(&p, 5);
    inserirElemListaOrd(&p, 8);
    inserirElemListaOrd(&p, 9);
    inserirElemListaOrd(&p, 0);

    exibirLista(p);

    NO* a = copiaInvertida(p);
    exibirLista(a);


    return 0;
}
