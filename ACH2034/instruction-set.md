# Conjunto de Instruções
Antes de tudo precisamos entender a diferença entre a organização e arquitetura de um computador. Esses conceitos, embora andem juntos, posuem diferenças.

A organização se refere aos atributos menos visíveis ao programador, como as unidades operacionais e suas interconexões, ou seja, os elementos do computador, como eles se comunicam etc, por exemplo, o modelo de von Neumann e arquitetura Harvard. Por outro lado, a arquitetura está mais próxima ao programador, como quais instrucoes podem ser executas, modelo de endereçamento de memória, quantos bits são usados para representar dados.

## ISA (Instruction Set Architecture)
A ISA define a arquitetura de diferentes computadores, mantendo uma padronização arquitetural. Assim, o mesmo conjunto de instruções, bits para representacao de dados, endereçamento de memoria são possíveis de executar em diversos computadores diferentes. Essas instrucoes de maquina determinam qual operacao o processador realiza.

Os 5 elementos principais da ISA são:
- Repertorio de operações => quantas e quais operacoes oferecer e qual a sua complexidade. Ex: operações lógicas e aritméticas, transferencia de dados (registradores, pilhas), controle (condições, laços, ordem do programa), E/S...
- Tipo e tamanho dos operandos (dados) => arquitetura de 8, 16, 32, 64 bits tem palavras de tamanhos diferentes. Assim temos dados de tamanhos diferentes para funcionar nas diversas plataformas (por exemplo, o int em C possui 16 bits)
- Endereçamento dos operandos => como os operandos será acessado? Apontaremos para um registrador que os contém? Apontar para um endereço de memória? Apontar para um registrador com endereço de memória onde o operando será carregado? Ou seja, modos pelos quais o endereco do operando é especificado
- Formato de instrução => tamanho da instrucao em bits, numero de enderecos, tamanho dos diversos campos (fixo ou variavel) etc
- Registradores => numero de registradores do processador que podem ser referenciados 

### Elementos de uma instrucao de maquina
Toda instrucao de maquina possui elementos que a definem, que sao:
- Codigo de operacao => especifica, por meio de um codigo binario, qual operacao deve ser realizada. Esse codigo e conhecido cmo opcode (operation code)
- Referencia a operando fonte => operandos de entrada
- Referencia a operando destino => resultado
- Referencia a proxima instrucao => onde o processador deve buscar a proxima instrucao apos o termino da atual (pode ser um endereco real ou virtual, dependendo da arquitetura)

Os operandos fonte e destino podem estar em:
- Memoria principal ou virtual => enderecos precisam ser fonecidos
- Registrador do processador => o processador pode ter um ou mais, se tiver mais de um, cada registrador recebe um nome/numero exclusivo, onde a instrucao precisa conter o numero do registrador desejado
- Imediato => valor do operando esta presente em um campo na instrucao executada
- Dispositivo de E/S => exige especificar o modulo e o dispositivo de E/S

### Representacao da instrucao
Cada instrucao e representada por uma sequencia de bits. A seguir temos alguns opcodes que indicam a operacao a ser realizada:
- ADD => adiciona
- SUB => subtrai
- DIV => divide
- LOAD => carrega dados da memoria
- STOR => armazena dados na memoria

### Tipos de instrucao
Cada instrucao possui um tipo, podendo ser:



### Numeros de endereco
Na maioria das arquiteturas, o numero de enderecos contidos em cada arquitetura pode ser de 1, 2 ou 3. Por exemplo, para calcular `Y = (A-B)/(C+(D*E))`, podemos calcular das seguintes formas:

- 1. Instrucoes de tres enderecos
```mips 
SUB Y,A,B # Y <- A - B
MPY T,D,E # T <- D * E
ADD T,T,C # T <- T + C
DIV Y,Y,T # Y <- Y / T
```

- 2. Instrucoes de dois enderecos
```mips
MOVE Y,A # Y <- A
SUB  Y,B # Y <- Y - B
MOVE T,D # T <- D
MPY  T,E # T <- T * E
ADD  T,C # T <- T + C
DIV  Y,T # Y <- Y / T
```

- 3. Instrucoes de um endereco
```mips
LOAD D # AC <- D 
MPY  E # AC <- AC * E
ADD  C # AC <- AC + C
STOR Y # Y  <- AC
LOAD A # AC <- A
SUB  B # AC <- AC - B
DIV  Y # AC <- AC / T 
STOR Y # Y <- AC
```

O numero de enderecos por instrucao é uma decisão básica de projeto.

Menos endereços resultam em instruções mais primitivas, exigindo um processador menos complexo, e instruções menores. Entretanto, programas com mais instrucoes tendem a ter maiores tempos de execucao e serem mais complexos. Além disso o programador tem normalmente apenas um registrador (acumulador).

Com multiplos enderecos há a utilizacao de varios registradores, o que permite que as operacoes sejam feitas somente eles. Temos mais rapidez na execução justamente por isso, pois não utilizamos referencias a memoria. Atualmente a maioria das maquinas utilizam dois ou tres endereços.

### CISC (Complex Instruction Set Computer)
Como tinhamos memórias pequenas e caras há tempos atrás, ter instruções complexas, compactas e eficientes para diminuiro consumo. Essas instruções possuiam uma grande quantidade de instrucoes com multiplos modos de endereçamento. 

Assim, uma unica codificacao executava mais de uma instrucao, por exemplo:
- CAS (compare and swap operands) => comparar e trocar de posicao os operandos
- RTR (return and restore codes) => retornar e restaurar códigos
- SWAP (swap register codes) => trocar registradores de codigo

No modelo CISC, o formato de dois operandos é o mais comum. Temos diferentes modos de trabalhar com essa arquitetura, como:
- Registrador-registrador
- Registrador-memoria
- Memoria-registrador

Temos múltiplos modos de endereçamento, permitindo que as instruções sejam ainda mais complexas. Essas instruções possuem largura variável, isto é, instruções menores e maiores, além de requerirem múltiplos ciclos de clock (afinal temos varias instruções), o que torna a execução mais lenta. Por fim, o hardware do CISC possui poucos registradores.

### RISC (Reduced Instruction Set)
Ao contrário do CISC, o RISC possui um conjunto de instruções reduzido. Assim, temos instruções mais simples, sendo necessário mais instruções para realizar uma tarefa. Além disso, as instruções tem tamanho fixo, tornando o processo mais simples. Essa simplicidade exige menos modos de endereçamento, além de proporcionar uma execução mais rápida e otimizada para cada instrução. 

### CISC X RISC
Atualmente temos computadores CISC e RISC. A implementação de cada arquitetura foi alterada, pois nossos hardwares estão muito melhores que antigamente. Temos memorias com maior capacidade, computadores mais eficientes, por exemplo. 

## Arquitetura MIPS
O MIPS é um processador normalmente utilizados em sistemas embarcados, ainda é produção. Esse processador utiliza as caracteristicas da arquitetura RISC. 

### Principios de projeto
- 1. Simplicidade favorece a regularidade => quanto maior a simplicidade/regular a instrução, mais simples é o hardware e maior o desempenho
        - Todas operações aritméticas tem a mesma forma => tres operandos: duas origens e um destino, exemplo `add a, b, c -> a = b + c`.
- 2. Menor é mais rápido
    - Instrucoes aritmeticas usam registradores como operandos
    - MIPS tem um conjunto de 32 registradores de 32 bits numerados de 0 a 31
    - Dados de 32 bits sao chamados `word`
- 3. Faca o caso comum mais rapido
    - Constantes pequenas sao comuns
    - Operandos imediatos evitam instrucao de load
    - Constante especificada na propria instrucao
    ```
    addi $s3, $s3, 4
    ```
    - Nao existe instrucao de subtracao com imediato, entao use constante negativa
    ```
    addi $s2, $s1, -1
    ```
- 4. Um bom projeto implica em bons compromissos
    - Importante manter instrucoes uniformes, respeitando os 32 bits
    - Ter uma estrutura proxima uma a outra
    
        

### Registradores

- $t0, $t1, ..., $t9 => valores temporários
- $s0, $s1, ..., $s7 => variáveis a serem salvas

OBS: Registrador 0 ($zero) do MIPS é a constante 0 e não pode ser sobrescrita. Exemplo: mover conteudo de registradores => `add $t2, $s1, $zero`

### Memória

- Endereço por byte
- Palavras (words) precisão estar alinhadas na memória (ocupando uma linha toda)
- Endereços precisam ser múltiplos de 4 (pelo fato de as words estarem alinhadas, i. e., ocuparem uma linha toda)

O MIPS é Big Endian, ou seja, o byte mais significativo está no endereço menos significativo da palavra. O byte que está na posição 0 possui o byte mais significativo, por exemplo.

### Operandos em memória
#### Tipos de operandos
Os dados operados podem ser:
- Enderecos
- Numeros => inteiros binarios ou ponto fixo binario, ponto flutuante binario, decimal.
- Caracteres => texto ou strings de caracteres. Nao podem ser facilmente armazenados ou transmitidos por sistemas de processamento de dados e comunicacoes. O codigo de caracteres mais utilizado é o IRA (International Reference Alphabet) mais conhecido como ASCII, onde cada caractere é representado por um padrao de 7 bits, e 128 caracteres podem ser representados
- Dados logicos => unidades de n bits, 1 ou 0. Um exemplo é um array de tamanho n, onde temos bits 0 ou 1 (falso ou verdadeiro).

#### Codigo em C
```sh
g = h + A[8]
```
Podemos mapear `g` em `$s1`, `h` em `$s2`, endereco base de `A` em `$s3`

#### Codigo compilado MIPS

Primeiro precisamos buscar A[8] na memoria. Assim, consideramos o endereco base e deslocamos 8 posicoes. Portanto, index 8 requer offset de 32 (4 * 8, pois 4 bytes por word)

```mips
lw $t0, 32($s3) # load word
add $s1, $s2, $t0
```

### Formato de instrucoes

Temos 32 bits para cada instrucao (palavra = word), mas temos tres tipos de instrucao.

#### Instrucao Tipo R

Denominada instrucoes com registradores como operandos.
- op => codigo da operacao opcode (6 bits)
- rs => registrador com primeiro operando origem (5 bits)
- rt => registrador com segundo operando origem (5 bits)
- shamt => quantia de deslocamento (5 bits)
- funct => codigo de funcao, estende opcode (6 bits)

```mips
add $t0, $s1, $s2
```

#### Instrucao Tipo I

Instrucoes aritmeticas com imediato e load/store.
- op => codigo da operacao opcode (6 bits)
- rs => registrador com primeiro operando origem (5 bits)
- rt => registrador com segundo operando origem (5 bits)
- constant/address => imediato (16 bits)

Temos dentro de instrucoes do tipo I os desvios condicionais, isto é:
```mips
beq rs, rt, L1
if (rs == rt) # desvie para instrucao L1

bne rs, rt, L1
if (rs != rt) # desvie para instrucao L2
```

#### Instrucoes Tipo J

Instrucoes de jump (salto) => j, jal. Essas instrucoes fazem o programar mudar de endereco.

- op => 6 bits
- address => 26 bits

Temos apenas 26 bits de endereco, entao os projetistas criaram um outro modulo de enderecamento, o enderecamento no jump, que combina os bits mais significativos do registrador contador de instrucao, concatenando com o endereco de 26 bits
- Endereco alvo = PC31...28: (endereco * 4)

## Exercicios
### Perguntas de Revisao

1. 
- Codigo de operacao => especifica, por meio de um codigo binario, qual operacao deve ser realizada. Esse codigo e conhecido cmo opcode (operation code)
- Referencia a operando fonte => operandos de entrada
- Referencia a operando destino => resultado
- Referencia a proxima instrucao => onde o processador deve buscar a proxima instrucao apos o termino da atual (pode ser um endereco real ou virtual, dependendo da arquitetura)

2.
- Memoria principal ou virtual => enderecos precisam ser fonecidos
- Registrador do processador => o processador pode ter um ou mais, se tiver mais de um, cada registrador recebe um nome/numero exclusivo, onde a instrucao precisa conter o numero do registrador desejado
- Imediato => valor do operando esta presente em um campo na instrucao executada
- Dispositivo de E/S => exige especificar o modulo e o dispositivo de E/S

3.
Poderia ser uma instrucao do tipo I com um endereco de 32 bits, onde:
- op => codigo da operacao opcode (6 bits)
- rs => registrador com primeiro operando origem (5 bits)
- rt => registrador com segundo operando origem (5 bits)
- constant/address => imediato (16 bits)

4.
- Repertorio de operacoes => quantas, quais operacoes sao oferecidas e quais sao suas complexidades
- Tipos de dados => tipos de dados sobre os quais as operacoes sao realizadas
- Formato de instrucao => tamanho da instrucao em bits, numero de enderecos, tamanho dos diversos campos etc
- Registradores => numero de registradores do processador que podem ser referenciados 
- Enderecamento => modos pelos quais o endereco de um operando é especificado

5.
- Numeros
- Caracteres
- Dados logicos
- Endereco
 
### Problema
Com menos enderecos temos instrucoes mais primitivas, exigindo um processador menos complexo, mas com tempo de execucao maior pelo fato de possuir somente um registrador.

COm mais enderecos temos instrucoes mais complexas por meio da utilizacao de varios registradores, permitidindo que as operacoes sejam feitas somente por eles, com uma maior rapidez na execucao.





