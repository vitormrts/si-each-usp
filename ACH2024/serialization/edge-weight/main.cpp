#include <stdio.h>
#include <stdlib.h>

typedef struct { 
	int v1;
	int v2;
	int custo;
} REGISTRO;

int custoDaAresta(int v1, int v2, char *path) {
    FILE *arq = fopen(path, "rb");

    if (!arq) {
        printf("Nao foi possivel abrir o arquivo.");
    } else {
        REGISTRO reg;

        while (fread(&reg, sizeof(REGISTRO), 1, arq) == 1) {
            if (reg.v1 == v1 && reg.v2 == v2) {
                return reg.custo;
            }
        }
    }

    return -1;
}

int main() {
    char* path = "exemplo.txt";
    int v1 = 9;
    int v2 = 1;

    int custo = custoDaAresta(v1, v2, path);
    
    if (custo == -1) {
        printf("A aresta %d->%d não existe\n.", v1, v2);
    } else {
        printf("O custo da aresta %d->%d é %d\n", v1, v2, custo);   
    }
}