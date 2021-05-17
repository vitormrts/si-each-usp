# Arquiteturas

## Arquitetura de von Neumann

Inicialmente os computadores eram programadores manualmente e, sabendo disso, John von Neumann propôs uma solução baseada em programação na memória.

Esse modelo ficou conhecido como Modelo de von Neumann que define a maneira em como o computador será programado baseado em 4 princípios: simplicidade (operações elementares), linearidade e uniformidade (memória), sequencialidade e centralidade (sequencia de execuções), unicidade (os dados são armazenados na mesma memória).

Basicamente um computador é formado por 4 principais componentes:

- Memória
- Unidade lógica e aritmética (ALU)
- Unidade de controle
- Dispositivo de entrada e saída

## Arquitetura de Harvard

Ressalta-se que paralelamente outros engenheiros, mais especificamente de Harvard, propuseram um outro modelo. A principal diferença entre as duas arquiteturas é a memória. Enquanto na arquitetura de von Neumann a memória armazenava tanto as instruções quanto aos dados, a arquitetura de Harvard separou essas memória em duas: uma memória para as instruções e outra para os dados. Isso também afeta os barramentos, pois para a arquitetura de Harvard são necessários 2, enquanto na de von Neumann apenas 1, o que traz maiores margens a possíveis gargalos de desempenho.

Atualmente ambas arquiteturas não são tão viáveis para desktops. Em específico a arquitetura Harvard é amplamente utilizada em dispositivos embarcados (microprocessadores).

## Arquitetura ISA

Também temos a arquitetura do conjunto de instruções (ISA) que define o repertório de instruções de um computador, isto é, o numero de bits para representar os dados, modos de endereçamento de memória, numero de instruções etc. Toda arquitetura possui 5 aspectos principais, que são:

- Repertório de operações -> ALU, deslocamento de dados, transf de dados, sistema de entrada e saída, controle etc
- Tipo e tamanho dos operandos -> as arquiteturas de 64, 32, 16 e 8 bits representam os dados com um numero de bits diferentes
Endereçamento dos operandos -> forma de acesso aos operandos
- Formato de instrução -> como identificar se uma operação é soma, multiplicação... como é a sequência de operandos na instrução, fixo ou variável...
- Armazenamento de operandos -> busca do operando, seja no registrador, memória...

Dois dos tipos de arquiteturas são o CISC e o RISC. A primeira possui instruções complexas devido a necessidade de termos poucas instruções (memória era cara e pequena), multiplos modos de endereçamento e instruções com largura variável devido a essa complexidade, além de as instruções requisitarem multiplos ciclos de clock para sua execução. Já a segunda possui instruções mais simples, poucos endereços de memória, suas instruções possuem tamanho fixo, além de ter uma execução rápida (cada instrução exige apenas um ciclo de clock), aumentando o desempenho.