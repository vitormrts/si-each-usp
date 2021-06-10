// OBS: Esse codigo nao esta funcional, ele serve apenas para ilustracoes

/*
    Considerando uma tabela (arvore, vetor etc) com registros com dois campos:
        - int chave => chave do registro
        - int end => endereco, i. e., nro do registro no arquivo, tipicamente um longint
*/

// Criacao de tabela de indices
int prox = 0;
REGISTRO r;
FILE* arq = fopen("path.txt", "rb");
while (fread(&r, sizeof(REGISTRO), 1, arq) == 1) {
    inserirIndice(tabela, r.chave, prox)
}

// insercao de um registro r
fseek(arq, 0, SEEK_END); // se posiciona no final do arquivo, deslocando 0 bytes a partir do final do arquivo
fwrite(&r, sizeof(REGISTRO), 1, arq); 
inserirIndice(tabela, r.chave, prox);
prox++;

// leitura de um registro r dada sua chave
intend = buscarEndereco(tabela, chave);
if (end > -1) {
    fseek(arq, end * sizeof(REGISTRO), SEEK_SET);
    int lidos = fread(&r, sizeof(REGISTRO), 1, arq);
    if (lidos < 1) // nao encontrado
} 
else // registro nao encontrado => erro no indice?

// exclusao logica do registro contendo a chave => requer limpeza periodica do arquivo
REGISTRO rvazio;
rvazio.valido = false;
int end = excluirIndice(tabela, r.chave);
if (end>-1) {
    fseek(arq, end*sizeof(REGISTRO), SEEK_SET);
    fwrite(&rvazio, sizeof(REGISTRO), 1, arq);
} 
else // registro nao encontrado 

// atualizacao do campo nao chave => assume-se que os dados ja estao em r
int end = buscarIndice(tabela, r.chave);
fseek(arq, end*sizeof(REGISTRO), SEEK_SET);
fwrite(&r, sizeof(REGISTRO), 1, arq);

// atualizacao de campo chave para novaChave

end = excluirIndice(tabela, chave); 
chave = novaChave;
inserirIndice(tabela, chave, end);

fseek(arq, end*sizeof(REGISTRO), SEEK_SET);
int lidos = fread(&r, sizeof(REGISTRO), 1, arq);
if (lidos == 0) // ERRO

r.chave = novaChave;
fseek(arq, -sizeof(REGISTRO), SEEK_CUR);
fwrite(&r, sizeof(REGISTRO), 1, arq);

