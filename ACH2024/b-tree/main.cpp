


int main() {
  /*
    ARVORES B
    - Armazena colecoes imensas de chaves (e seus ponteiros de registro) para uso como indice de acesso ao arquivo (tambem imenso) da aplicacao.
    - Somente uma pequena porcao da estrutura de indice fica deresidente em emmoria, o resto esta no arquivo de arvore B.
    - Desempenho logk(i), onde i eh a qntd de registros do arquivo alvo e k o numero de registros por pagina
    - Estrutura que so faz sentido para memoria secundaria
    - A arvore B ejh um indice armazenado em MEMORIA SECUNDARIA para acesso a outro arquivo
    - Ordenada por chave, mas nao eh binaria
    - Nao possui paginas vazias ou folhas com alturas diferentes

    REGRAS
    - Cada pagina eh um vetor de k chaves ordenadas e k+1 links para paginas inferiores (e logo paginas nao contem arvores)
    - temos ponteiros para registros do arquivos
    - uma pagina contendo n chaves possui OBRIGATORIAMENTE n+1 links para seus filhos (ou -1 se for folha)
    - o link esquerdo de uma chave aponta para chaves menores e o direito para maiores
    - o numero m de links possiveis (ou k+1) eh a ORDEM da arvore, onde k eh a qntd de chaves por pagina

    IMPLEMENTACAO DA PAGINA
    - A pagina eh composta por dois vetores: um de chaves e outro de links, ambos numerados de 1..k
    - Um link[i] eh, por definicao, o caminho a direita da chave[i] correspondente, ou seja, eh o que leva às chaves maiores do que chave[i]
    - O link esquerdo d euma chave ch[i] eh na verdade o link[i-1], o que exige a criacao de uma posicao 0 sem chave, contenado apenas o link mais a esquerda da chave[1]

    BUSCA EM ARVORE B
    - Como em uma arvore ordenada qualquer
    - A chave de busca eh comparada com todas as chaves da pagina atual
    - Se encontrou, fim
    - Se for menor do que a chave encontrada na pagina, segue o link esquerdo
    - Caso contrario, segue o link direito

    INSERCAO
    A arvore B eh construida sempre da folha para a raiz (de baixo para cima), estando assim permanentemente balanceada. Evita a necessidaed de rotacoes complexas e resolve o problema de escolha de separadores otimos
    - Buscar a pagina e, se houver espaco, inserir e FIM
    - Quando necessario (overflow), pagina pode ser dividida em duas (divisao ou SPLIT) promovendo-se um separador (a chave mediana e seu link direito) para a pagina pai
    - Se houver promocao de separador, a chave em questao eh reinserida (recursivamente) na pagina pai

    Exemplo para m = 3 (3 links, 2 chaves)
    1. Inserir 10,20 => [10, 20]
    2. Inserir 30 => overflow divide a pagina em duas
      [10 -] [30 -] a chave mediana (20) eh promovida ao nivel superior
    3. A promocao de (20) ao nivel superior, que nao existe, leva a criacao de uma nova pagina pai
        [20 -]
    [10 -] [30 -]  

  */
}