#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>

char* concat(char* str, char c, int i){
    char* strConcat;

    if (i >= 1) {
        size_t length = strlen(str);

        strConcat = (char*) malloc((length + 2) * sizeof(char));
    
        strcpy(strConcat, str);
        strConcat[length] = c;
        strConcat[length + 1] = '\0';
    } else {
        strConcat = (char*) malloc(2 * sizeof(char));
        strConcat[0] = c;
        strConcat[1] = '\0';
    }
    
    return strConcat;
}

bool textHasWord(char *str) {
    FILE *file = fopen("exercicio.txt", "rb");
    bool resp = false;
    if (!file) {
        printf("Erro ao abrir o arquivo.\n"); // erro ao abrir
    } else { // arquivo abriu
        char* text;
        char c;
        int i = 0;

        while (!feof(file)) { // enquanto houver caracter
            c = getc(file);
            
            if (isalpha(c)) {
                text = concat(text, c, i);
                i++;
            } else {
                if (strcmp(text, str) == 0) {
                    resp = true;
                    break;
                } else 
                    text[0] = '\0';   
            }
        }
        fclose(file);
    }

    return resp;    
}

int main() 
{
    char teste[10] = "notebooks";
    bool a = textHasWord(teste);
    printf("%d", a);
}