# Operação de unidade de controle
Uma execucao envolve subpassos chamados de ciclos. Esses ciclos sao uma sequencia de operacoes  basicas chamadas micro-operacoes. Uma micro-operacao envolve uma transferencia de registradores, ou transferencia entre um registrador e um barramento externo ou ate mesmo uma simples operacao da ALU.

Para definir o funcionamento do processador precisamos conhecer:
- 1. Operaçoes (opcode)
- 2. Modos de enderecamento
- 3. Registradores
- 4. Interface com modulos de E/S
- 5. Interface com o modulo de memoria
- 6. Interrupções

Os itens de 1 ate 3 sao definidos pelo conjunto de instrucoes. Os itens 4 e 5 sao definidos ao se especificar o barramento do sistema. O 6 é definido pelo barramento do sistema e pelo tipo de suporte oferecido pelo processador ao S.O.

## Micro-operações
A operacao de um computador consiste numa sequencia de ciclos de instrucao (busca, indireto, execucao, interrupcao), com uma instrucao de maquina por ciclo. Nao ocorre necessariamente na sequencia por conta das condicoes (instrucoes de desvio). Cada instrucao é executada durante um ciclo de instrucao feito de subciclos menores, e cada subciclo envolve uma ou mais operacoes mais curtas, ou seja, micro-operaçoes.

As micro-operacoes, como o proprio nome sugere, sao operacoes extremamente pequenas (atomicas) de um processador.

### Ciclo de busca
No inicio de cada ciclo de instrucao temos o ciclo de busca, onde a instrucao é obtida da memória. Utilizamos 4 registradores para esse ciclo:
- Registrador de endereço de memoria (MAR) => especifica o endereco na memoria para uma operaçao de leitura ou escrita. Está conectado as linhas de endereço do barramento do sistema
- Regstrador de buffer de memoria(MBR) => contem o valor a ser guardado na memoria ou armazena o ultimo valor lido da memoria. Conectado as linhas de dados do barramento do sistema.
- Contador de programa (PC) => guarda o endereço da proxima instrucao a ser lida
- Registrador de instrucao (IR) => guarda a ultima instrucao lida 

Primeiro é obtido o endereço da próxima instrucao a ser executada no início do ciclo de instrucao. Esse endereço está armazenado no PC. Precisamos mover esse endereco para o registrador de endereco de memoria (MAR). Apos isso, trazer o endereço, i. e., o endereço no MAR é colocado no barramento de endereços, a unidade de controle emite um READ no barramento de controle o resultado aparece no barramento de dados, onde é copiada para o registrador de buffer de memoria (MBR). Incrementamos o PC. Agora podemos mover o conteudo presente no MBR para o registrador de instrucao IR, liberando o MBR para uso de um possivel ciclo indireto.

Devemos separar em unidades de tempo diferentes as operacoes de escrita e leitura. Por exemplo, as micro-operacoes de carregar o valor da memoria e inserir no MBR e escrever o conteudo presente no MBR na IR nao devem ocorrer na mesma unidade de tempo.

```
t1 : MAR ← (PC)
t2 : MBR ← Memory
t3 : PC ← (PC) + I # no nosso caso o I eh 4 pois usamos MIPS
IR ← (MBR)
```

### Ciclo indireto
Ja lemos a instrucao, agora precisamos buscar os operandos fontes.

O campo de endereco da instrucao (IR) é transferido para o registrador de endereço da memória (MAR), que por sua vez obtem o endereço do operando. O campo de endereço de IR é atualizado a partir de MBR e agora contém um endereço direto em vez de indireto. Agora o IR esta pronto para ser usado no ciclo de execucao.

```
t1 : MAR ← (IR(Endereço))
t2 : MBR ← Memória
t3 : IR(Endereço) ← (MBR(Endereço))
```

### Ciclo de interrupcao
Ao terminar o ciclo de execucao verifica-se se houve qualquer interrupcao habilitada e, em caso positivo, ocorre o ciclo de interrupcao.

```
t1 : MBR ← (PC)
t2 : MAR ← Endereço_salvar
      PC ← Endereço_rotina
t3 : Memória ← (MBR)
```

Em t1 o conteudo do PC é transferido para o MBR salvando o retorno da interrupção. Em seguida, em t2 o MAR é carregado com o endereço onde o conteúdo de PC deve ser salvo e o PC é carregado com o endereço do início da rotina do tratamento de interrupcao. No final, o passo t3 armazena o conteúdo de MBR (que contem o valor antigo de PC) em memoria e, assim, o processador pode executar o proximo ciclo de instrucao.

### Ciclo de execucao
Os ciclos anteriores (busca, indireto e interrupcao) sao mais simples e previsiveis, com micro-operacoes repetidas e uma sequencia fixa. Ja o ciclo de execucao nao tem isso pela grande variedade de opcodes e diversas possibilidades.

### Ciclo de instrucao
Percebe-se que cada fase do ciclo de instrucao pode ser decomposto em varias micro-operacoes basicas. Agora precisamos ligar essas sequencias de micro-operacoes.

O ciclo indireto vem antes do ciclo de execução. O ciclo de interrupção é seguido do ciclo de busca. Para leitura e execução, o próximo ciclo depende do estado do sistema.

Busca -> Indireto -> Execução -> Interrupção

A unidade de controle cuida dessa sequencia de micro-operações.

## Controle do processador
### Requisitos funcionais
Reduzindo a operação do processador para seu nivel mais básico conseguimos analisar melhor o comportamento da unidade de controle e qual deve ser sua função. Uma UC se caracteriza por:
- 1. Definir elementos básicos do processador
- 2. Descrever quais sao as micro-operacoes que o processador pode executar
- 3. Determinar as funcoes que a unidade de controle deve realizar para fazer com que as micro-operacoes sejam executadas

Os elementos básicos do processador são:
- ALU => essencia funcional do computador
- Registradores => armazenar informacoes para gerenciar as instrucoes
- Caminho de dados internos => mover dados entre registradores e entre registrador e ALU
- Caminho de dados externos => ligam registradores com memoria e modulos de E/S
- Unidade de controle => faz com que as operacoes ocorram dentro do processador

As micro-operacoes tem diferentes funcoes, podendo ser de transferencia de dados entre registradores, de registrador para interface externa, de interface externa pra registrador ou até mesmo operações lógicas/aritméticas

A unidade de controle é responsável por sequenciar as micro-operações e executar cada micro-operação.

### Sinais de controle
Sinais de controle armazenam o estado da aplicação e o comportamento do sistema. As entradas permitem determinar o estado do programa, enquanto as saídas detemrinam o comportamento do sistema.

Algumas entradas sao:
- Clock => unidade para manter o tempo
- Registrador de instrucao => opcode e modo de enderecamento da instrucao
- Flag => determinar estado do processador e das saidas das operacoes anteriores da ALU
- Sinais de controle do barramento do controle => parte do barramento do sistema, fornece sinais p a UC
- Sinais de controle do processador => podem mover os dados de um registrador a outro ou ativar funcoes especificas da ALU
- Sinais de controle para barramento de controle =>podem ser sinais de controle para emmoria ou para modulos de E/S