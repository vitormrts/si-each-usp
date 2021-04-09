#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int boolean;

typedef struct estrutura {
    int chave;

    struct estrutura *primFilho;
    struct estrutura *proxIrmao;
} NO;

NO* buscaChave(int chave, NO* raiz) {
    if (!raiz)
        return NULL;
    if (raiz->chave == chave)
        return raiz;
    
    NO* p = raiz->primFilho;

    while (p) {
        NO* resp = buscaChave(chave, p);
        if (resp)
            return resp;
        p = p->proxIrmao;        
    }

    return NULL;
}

NO* criarNovoNo(int chave) {
    NO* p = (NO*) malloc(sizeof(NO));

    p->primFilho = NULL;
    p->proxIrmao = NULL;
    p->chave = chave;

    return p;
}

boolean inserirNo(NO* raiz, int novaChave, int chavePai) {
    // verificamos se tem pai
    NO* pai = buscaChave(chavePai, raiz);
    if (!pai)
        return false;

    NO* filho = criarNovoNo(novaChave);

    // verificamos o primogenito do pai
    NO* p = pai->primFilho;
    if (!p)
        pai->primFilho = filho;
    else {
        while (p->proxIrmao)
            p = p->proxIrmao;
        p->proxIrmao = filho;
    }
    
    return true;
}

void exibirArvore(NO* raiz) {
    if (!raiz)
        return;
    printf("%d(", raiz->chave);
    NO* p = raiz->primFilho;
    while (p) {
        exibirArvore(p);
        p = p->proxIrmao;
    }
    printf(")");
}


NO* inicializarArvore(int chave) {
    return criarNovoNo(chave);
}

int main() {
    // A Exclusao depende do contexto

    NO* raiz = inicializarArvore(8);
    inserirNo(raiz, 15, 8);

    inserirNo(raiz, 20, 15);
    inserirNo(raiz, 10, 15);
    inserirNo(raiz, 28, 15);

    inserirNo(raiz, 23, 8);

    inserirNo(raiz, 2, 8);
    inserirNo(raiz, 36, 2);
    inserirNo(raiz, 7, 2);

    exibirArvore(raiz);
    return 0;
}
