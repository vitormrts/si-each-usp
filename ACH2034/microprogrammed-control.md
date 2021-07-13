# Controle microprogramado
Um microprograma consiste de uma sequência de instruções em uma linguagem de microprogramação. Trata-se de instruções que especificam micro-operações. Capaz de sequenciar pelas microinstrucoes e gerar sinais de controle para executar cada microinsturcao.

## Conceitos basicos
### Microinstrucoes
Um microprograma implementa uma unidade de controle como uma interconexao de elementos logicos. Cada linha da microprogramacao descreve um conjunto de micro-operacoes ocorrendo ao mesmo tempo, chamado de microinstrucao. Uma sequencia de instrucoes forma um microprograma ou firmware, isto é, uma ponte entre hardware e software. Varios processadores CISC implementam uma unidade de controle microprogramada

### Unidade de controle microprogramada
A memoria de controle possui um programa que descreve o comportamenmto da unidade de controle, podendo implementar a unidade de controle simplesmente executando esse programa.

As microinstrucoes sao armazenadas na memoria de controle. O registrador de endereco de controle contem o endereco da proxima microinstrucao a ser lida. Quando uma microinstrucao é lida a partir da memoria de controle ela é transferida para um registrado buffer de controle.

A unidade de controle segue os passos:
- 1. Emite um comando READ para memoria de controle
- 2. Palavra cujo endereco especificado no registrador de endereço de controle é lida para dentro do registrador de buffer de controle
- 3. Conteudo do registrador de buffer de controle gera sinais de controle e a informação do proóximo endereço para a unidade lógica de sequenciamento
- 4. A unidade logica de sequenciamento carrega um novo endereco no registrador de endereco de controle. Podemos tomar algumas decisoes especificas dependendo das flags da unidade logico aritmetica, que sao:
  - Obter a proxima instrucao 
  - Saltar para uma nova rotina c/ base numa microinstrucao de salto
  - Saltar para uma rotina de instrucao de maquina

### Vantagens e desvantagens
Utilizar a microprogramacao simplifica o projeto da unidade de controle, ficando mais barata e menos propensa a erros. Uma unidade de controle por hardware possui uma logica complexa para sequenciamento por meio de varias microoperacoes do ciclo de instrucao, mas a unidade microprogramada é bem mais simples.

A principal desvantagem da unidade programada é ser um pouco mais lenta que uma unidade por hardware de tecnologia comparavel. Ela normalmente utilizava arquiteturas CISC pela sua facilidade de sua implementacao. Unidades de controle por hardware normalmente usam processadores RISC.

## Sequenciamento de microinstrucoes
A unidade de controle microprogramada tem duas tarefas basicas:
- Sequenciamento de microinstrucoes => obter proxima microinstrucao da memoria de controle
- Execucao de microinstrucoes => gerar sinais de controles p/ executar microinstrucao

Ambas afetam o formato da microinstrucao e temporizacao da unidade de controle e por isso precisamos saber como é o projeto.

Precisamos considerar o tamanho da microinstrucao e o tempo de geracao do endereço, para diminuir o espaço e tempos necessários de execucao. O endereco da proxima microinstrucao pode ser determinado pelo registrador de instrucao, ser o próximo endereço sequencial ou um desvio.

### Sequenciamento
Temos diferentes tecnicas de sequenciamento. A mais facil é fornecer dois campos de endereço em cada instrução, mas ela requer mais bits dentro da microinstrucao do que outras abordagens. Para diminuir esse consumo podemos utilizar um campo de endereço único ou fornecer dois formatos de instrucao totalmente diferente, onde um bit define qual formato vai ser usado.

### Geração de endereços
Podemos ter tecnicas de geraçao de endereço explicitas onde o endereço esta disponivel explicidade na microinstrucao, ou implicitas, que requerem logica adicional para obter esse endereço. Basicamente lidamos com explicitas. Temos a abordagem de dois campos, de desvio incondicional e desvio condicional. Algumas tecnicas implicitas sao o mapeamento, a de adição e de controle residual.

## Execucao de microinstrucoes
Uma microinstrucao consiste em buscar um endereco e executar uma microinstrucao. O efeito da sua execução gera sinais de controle, que podem apontar para dentro do processador, enquanto o restante vai para o barramento de controle externo ou para outras interfaces externas.

### Taxonomia de microinstrucoes
Podemos ter diferentes formas de microinstrucoes, como:
- Vertical/horizontal => tamanho relativo da microinstrucao (verticais possuem entre 16 e 40 bits e horizontal 40 a 100 bits)
- Empatcotada/nao empatocada => grau de identificacao entre uma determinada tarefa de controle e bits especificos de microinstrucoes
- Microprogramacao hard/soft => grau de proximidade com os sinais de controle e layout de hardware subjacentes. Hard normalmente sao fixos e dedicados para memoria ROM, soft mutais e sugestivos da microprogramacao do usuario
- Codificacao direta/indireta

Cada bit de uma microinstrucao produz um sinal de controle ou produz um bit do proximo endereco.

### Codificação de microinstruções
Unidades de controle microprogramadas nao sao projetadas usando um formato de microinstrucao puramente horizontal  ou nao codificado. É necessário um grau de codificação para reduzir o tamanho da memória de controle e simplificar a tarefa de microprogramação. A microinstrucao é organizada como um conjunto de campos, onde cada um contém um código que deposi de decodificado ativa um ou mais sinais de controle. 

Geralmente queremos que cada sinal de controle seja ativada por nao mais do que um campo. Podemos definir esse projeto como:
- Organizar o formato em campos independentes. Acoes em diferentes campos podem ocorrer ao mesmo tempo.
- Definir cada campo com ações podem ser especificads pelo campo de modo que sejam mutuamente exclusivas. Apenas uma dessas acoes ocorrem por vez.

## Exercicios
### 1. 

Uma unidade de controle por hardware possui uma logica complexa para sequenciamento por meio de varias microoperacoes do ciclo de instrucao, mas a unidade microprogramada é bem mais simples. A principal desvantagem da unidade programada é ser um pouco mais lenta que uma unidade por hardware de tecnologia comparavel. Ela normalmente utilizava arquiteturas CISC pela sua facilidade de sua implementacao. Unidades de controle por hardware normalmente usam processadores RISC.

### 2.
Todos sinais ficam na mesma microinstrucao sem codificacao. Cada microinstrucao possui um grande numero de campos nao codificados.

### 3
Possui o conjunto de microinstruções que define a funcionalidade da unidade de controle.

### 4 
As microinstruções em cada rotina devem ser executadas sequencialmente. Cada rotina pode ter uma instrucao de desvio ou saltar.

### 5 
Microinstrução horizontal => cada bit no campo de controle anexa a um controle linha.
Microinstrução vertical => código é usado para cada ação a ser realizada e o decodificador traduz este código em sinais de controle individuais