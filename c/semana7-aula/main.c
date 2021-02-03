#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define true 1
#define false 0

typedef int bool;

typedef struct {
    int chave;
} RegistroEstat;

typedef struct {
    RegistroEstat A[MAX];
    // topo é a posicao do elemento no arranjo
    int topo;
} PESTAT;

// inicilializa a pilha estatica
void inicializarPestat(PESTAT* p) {
    p->topo = -1;
}

// numero de elementos
int tamanhoPestat(PESTAT* p) {
    return p->topo + 1;
}

bool pestatCheia(PESTAT p) {
    if (p.topo >= MAX - 1) return true;
    return false;
}

// exibicao dos elementos da pilha
void exibirPestat(PESTAT* p) {
    printf("Pilha: \" ");
    int i;
    for (i=p->topo; i >= 0; i--) printf("%i ", p->A[i].chave);
    printf("\"\n");
}

bool push(PESTAT* p, int ch) {
    if (tamanhoPestat(&p) >= MAX) return false;

    p->topo = p->topo + 1;
    p->A[p->topo].chave = ch;
    return true;
}

int pop(PESTAT* p) {
    // Lista vazia
    if (p->topo < 0) return -1;

    int ch = p->A[p->topo].chave;
    p->topo --;

    return ch;
}

void reinicializarPestat(PESTAT* p) {
    p->topo = -1;
}





int main()
{
    PESTAT* p;
    inicializarPestat(&p);

    push(&p, 3);
    push(&p, 6);
    push(&p, 1);
    push(&p, 0);

    exibirPestat(&p);

    reinicializarPestat(&p);

    exibirPestat(&p);
    return 0;
}
