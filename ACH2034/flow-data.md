# Fluxo de dados

## Organizacao do processador
Um processador deve ser capaz de
- Buscar instrucao
- Interpretar a instrucao
- Obter os dados
- Processar os dados
- Gravar os dados

O processador deve tambem poder armazenar alguns dados temporariamente e lembrar da posicao da ultima instrucao para obter a proxima instrucao que deve ser executada. Esse armazenamento é feito por meio de registradores. Alem disso, ele deve possui uma unidade logica e aritmetica (ALU) que faz os calculos e processamento de dados, alem de uma unidade de controle que movimenta os dados e as instrucoes que entram e saem do processador, controlando tabem a operacao de ALU. A transferencia de dados e controle lógica são feitos por meio do barramento interno do processador.

## Organizacao dos registradores
Os registradores sao memorias pequenas, mas muito rapidas. Dentro do processador possuimos varios registradores que funcionam em um nivel acima da memoria principal e cache. Temos dois papeis para eles:
- Visiveis ao usuario => minimiza as referencias a memoria. Ele pode ser utilizado na construcao de programas pelo programador, estando disponiveis a eles.
- Controle e estado => utilizados pelo SO para controlar a execucao de programas. Alguns dos exemplos sao o PC, IR, MAR e MBR. Sao utilizados para otimizar o sistema.

## Desempenho
O desempenho de um computador é determinado por três fatores principais: contagem de instrucoes, tempo de ciclo de clock e CPI (ciclos de clock por instrucao). As intrucoes são determinadas pela ISA, enquanto o ciclo de clock e CPI são determinadas pelo hardware.

A implementação para fluxo de dados envolverá as intruções seguintes:
- Referencia a memoria principal => load word (lw) e store word (sw)
- Logicas e aritmeticas => add, sub, OR e slt
- Controle => brench equal (beq) e jump (j)

Isso são apenas as instruções simplificadas, não estamos utilizando instrucoes mais complexas nesse conjunto. Porém, essa versão simplificada possui a mesma lógica de outras instruções.

## Logica combinatoria
Para realizar o fluxo de dados criamos um circuito logico. Na implementação MIPS temos dois tipos de elementos lógicos: os que operam nos valores dos dados e os que contem estado. Chamamos de combinacionais os elementos que possuem uma saída dependendo das entradas atuais. Já o elemento de estado é um elemento da memoria que possui armazenamento interno, como um registrador ou uma memória. 

Alguns exemplos de elementos de lógica combinatória são as portas AND, somador, multiplexador e a ALU.

## Metodologia de clocking
É necessário uma lógica de clocking que define quando os dados devem ser lidos e escritos, afim de haver uma sincronização. Quando um elemento de estado é lido, no momento da borda de clock ele é armazenado. Quando houver outra borda de clock, outro elemento de estado é lido. Assim, durante o intervalo entre essas duas bordas de clock ocorre a lógica combinatória, isto é, o processador executa um dado de entrada e produz uma saída para ser armazenada no ciclo seguinte. É necessário entender que o caminho com maior intervalo entre bordas de clock determina a frequencia do clock

## Ciclo de execução
O ciclo de execução de uma instrução na arquitetura MIPS se baseia nos seguintes passos: 
- 1. Observar o endereço armazenado no contador de programa (PC). No PC temos a instrucao a ser executada. Buscamos essa instrucao, atualizamos o PC para a proxima instrucao (somar 4 a PC, pois a memoria é endereçada por byte).
- 2. Leitura dos registradores
- 3. Usar ULA p/ calcular (unidade logica aritmetica)
  - a) Resultado aritmetico
  - b) Endereço da memoria para load/store
  - c) Endereço de desvio condicional (branch)
- 4. Acessar memoria de dados para load/store
- 5. Escrever resultado no registrador destino 

Vale ressaltar que a instrucao do load envolve os 5 elementos acima, entao ela determina o período de clock, pois é o maior atraso.

## Exercicios
### 1. Quais papéis gerais são desempenhados pelos registradores do processador?
Devem ser rapidos e de facil acesso. Funcionam em um nivel acima da memoria principal e da cache. Temos registradores visiveis ao usuario e de controle/estado.

### 2. Quais categorias de dados são normalmente suportadas pelos registradores visíveis ao usuário?
- Uso geral
- Dados
- Enderecos
- Codigos condicionais

### 3. Qual é a função de códigos condicionais?
Uma condicao define qual é o caminho que o programa deve seguir. Duas entradas produzem uma saída, e esta saida é o resultado final. 

### 4. O que é uma palavra de estado do programa?
A palavra de dados do programa (PSW) contem as informacoes de estado do programa. A PSW é um (ou conjunto) de registradores que vão justamente armazenar o estado do pgrama, contendo codigos condicionais e outras informacoes de estado.

