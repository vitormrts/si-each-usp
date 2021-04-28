#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura {
    int chave;
    struct estrutura *esq;
    struct estrutura *dir;
} NO;



// inicializa a �rvore
void inicializarArvore(NO* *raiz) {
    *raiz = NULL;
}

// verifica se a arvore est� vazia
int arvoreVazia(NO* raiz) {
    if (!raiz) return 1;
    else return 0;
}

// inserir n�
void inserirNo(NO* *raiz, int ch) {
    if (!raiz) {
        (*raiz) = (NO*) malloc(sizeof(NO));
        (*raiz)->chave = ch;
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
    }
    else {
        if (ch < (*raiz)->chave) inserirNo(&((*raiz)->esq), ch);
        //else inserirNo(&((*raiz)->dir), ch);
    }
}

/*NO* inserirNo(NO* raiz, int ch) {
    if (!raiz) {
                printf("a");
        raiz = (NO*) malloc(sizeof(NO));
        raiz->chave = ch;
        raiz->dir = NULL;
        raiz->esq = NULL;
    }
    else {

        if (ch < raiz->chave) inserirNo(&(raiz->esq), ch);
        //else inserirNo(&((*raiz)->dir), ch);
    }
    return raiz;
}*/


/*Escrever uma fun��o que, dado um elemento p garantidamente existente em uma �rvore bin�ria,
 crie um novo filho esquerdo com o valor de chave correspondente � chave do pai (p) mais a chave do filho direito, se houver.
 Se j� houver filho esquerdo, nada deve ser executado.*/
void novoEsquerdo(NO* p) {

}
int main()
{
    NO* raiz;
    inicializarArvore(&raiz);
    inserirNo(&raiz, 4);
    inserirNo(&raiz, 3);
    printf("Hello world!\n");
    return 0;
}
