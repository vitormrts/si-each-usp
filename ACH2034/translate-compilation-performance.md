# Traducao, compilacao e desempenho
Temos 4 etapas para transformar um programa de uma linguagem de alto nivel para uma linguagem de baixo nivel. Considerarei a linguagem C como alto nivel.

Primeiro temos a compilacao, onde saimos da linguagem de alto nivel para a linguagem Assembly. O Assembly faz a montagem dos objectos associados ao codigo para executa-lo no processador (linker). Com isso temos o executavel, onde podemos executar o programa compilado.

## Compilador
O compilador transforma o codigo em C para um programa em assembly, uma linguagem de maquina (linguagem que o computador entende).

## Montador
A linguagem assembly é a interface com o software de nivel superior, traduzindo as instruções em uma linguagem que a máquina consiga entender. Precisamos criar os objetos e ligá-los para nosso programa funcionar.

O montador faz o objeto que possui as caracteristicas seguintes:
- Head => descreve tamanho e posicao das outras partes do objeto
- Segmento de texto => codigo na linguagem de maquina
- Segmento de dados estaticos => dados alocados por toda a vida do programa
- Informacoes de relocaçao => identificao das instrucoes e palavras de dados que dependem de endereços quando o programa é carregado na memoria
- Tabela de simbolos => referencias externas, rotulos que nao estão definidos
- Informações de depuração => debug do programa, descrição da compilação do programa...

## Ligando objetos
Agora podemos ligar os objetos criados, ligando as bibliotecas utilizadas no programa, por exemplo
- 1. Juntar segmentos
- 2. Resolver rotulos (determinar enderecos)

## Link-editor
A conexão desses objetos é feita por meio de um link-editor. Esse link-editor permite que os objetos não seja mtodos compilados de uma unica vez (o que é ruim para desempenho), mas sejam compilados de acordo com a sua necessidade. Para realizar um link-editor temos 3 etapas:
- 1. Colocar os modulos de codigo e dados simbolicamente na memoria
- 2. Determinar os enderecos dos rotulos de dados e isntrucoes
- 3. Remendar as referencias internas e externas

O link editor gera um arquivo executavel que permite rodar o programa.

## Loader
Com o executavel em maos, agora precisamos roda-lo. Isso ocorre por meio de um loader que realiza as seguintes etapas:
- 1. Le o HEAD para determinar o tamanho dos segmentos de texto e de dados
- 2. Cria um espaco de endereçamento grande o suficiente para texto e os dados
- 3. Copia as instrucoes e os dados do arquivo executavel para a memoria
- 4. Copia os parametros (se tiver) do programa principal para a pilha
- 5. Inicializa os registradores da maquina e define o stack pointer para o primeiro local livre
- 6. Desvia para a rotina principal. Quando a rotina principal retorna, temos um exit.
