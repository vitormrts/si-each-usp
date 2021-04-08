#include <stdio.h>
#include <stdlib.h>

void f2(char hello[]) {
    printf("Endereco f2: %d\n", &hello);

    printf("%s\n", hello);
}

void f1(char hello[]) {
    printf("Endereco f1: %d\n", &hello);

    f2(hello);
}

int main() {
    char hello[] = "Hello World";
    printf("Endereco main: %d\n", &hello);
    f1(hello);

    return 0;
}