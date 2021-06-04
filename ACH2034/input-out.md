# Entrada e Saída 
O sistema de entrada e saída é o meio de comunicação entre a máquina e o usuário.

Todo sistema de computação possui um conjunto de módulos de E/S, em que cada módulo contém a lógica para realizar uma funcao de comunicação entre o periférico e o barramento. Essa comunicação é extremamente necessária, pois a conexão direta entre o periférico e barramento tem varias complicações, como:
- Grande variedade de periféricos => necessitaria diversas lógicas para cada um no processador
- Taxa de transferencia de dados pode ser menor ou maior que a memória ou processador
- Palavras e formato de dados de diferentes tamanhos

## Dispositivos externos
Todo dispositivo conectado a um módulo de E/S é chamado de dispositivo periférico ou periférico. Essa conexão faz trocas de sinais de controle, estadas, dados e estado, permitindo a interação entre usuário e máquina.

Os dispositivos externos podem ser divididos em:
- Legíveis ao ser humano => comunica-se com o ser humano (monitores, impressoras)
- Legíveis à máquina => comunica-se com a máquina (HDs, fitas, sensores)
- Comunicação => comunica-se com dispositivos remotos 

A interface dispositivo-módulo de E/S ocorre por:
- Sinais de controle => enviar dados, aceitar dados, informar estado etc.
- Dados => bits a serem enviados/recebidos
- Sinais de estado => estado do dispositivo, por exemplo, se pode realizar a transf. de dados

Além disso, temos uma lógica. de controle entre o dispositivo e módulo de E/S, um transdutor que converte os dados (dado elétrico para outro tipo de energia, por exemplo), e um buffer associado ao transdutor.

### Teclado/monitor
Meio mais comum de interação entre usuário/computador é o monitor/teclado. O primeiro é a saída, o segundo a entrada.

A unidade de troca básica é o caractere representado por um código binário exclusivo com 7 bits, de modo que podemos ter até 128 caracteres diferentes. Temos caracteres do tipo imprimível e controle.

### Unidade de disco
Numa unidade de disco temos a possibilidade de leitura/escrita de dados.

## Módulos de E/S
### Função do módulo
- Controle e temporização => controle do fluxo de tráfego entre o processador e os diversos dispositivos conectados
- Comunicação com o processador => o módulo de E/S precisa se comunicar com o processador informando os dados, estado, endereço etc, para que o processador interprete a informação que chega da entrada ou enviar a informação para a saída
- Comunicação com o dispositivo => o próprio nome já diz
- Buffering de dados => como a taxa de transferencia é diferente entre os dispositivos e memória, a operação de buffering basicamente faz a regulação dessa disparidade
- Detecção de erro => detectar e relatar erros ao processador. Podemos ter erros mecânicos ou mudanças equivocadas no padrão de bits na transmissão do dispostivo ao módulo de E/S. Pode-se utilziar um bit de paridade em cada caractere de dados.

### Estrutura do módulo de E/S
Cada módulo de E/S tem uma complexidade e numero de dispositivos controlados por eles diferentes. De modo geral, o módulo se conecta ao restante do computador por meio de linhas de barramento do sistema. Temos tanto registradores de estado e controle, como também temos registradores de dados que armazenam os dados transferidos. A lógica do modulo interage com o processador por um conjunto de linhas de controle. Essas linhas de controle são utilizadas pelo processador para emitir comandos ao módulo. Elas podem ser utilizadas também pelo módulo. Cada módulo precisa reconhecer e gerar endereços aos dispositivos que ele controla, além de ter um endereço exclusivo. Por fim, o módulo tem uma lógica específica à interface c/ cada dispositivo controlado.

Vale ressaltar que temos módulos responsáveis por maior parte do processamento, os quais podem ser chamados de canal de E/S ou processador de E/S.

## E/S programada
Uma das três técnicas para as operações de E/S, temos a E/S programada, na qual os dados são trocados diretamente entre o processador e o módulo de E/S. Ao emitir um comando ao módulo de E/S, o processador precisa esperar até que essa operação acabe. Isso faz com que se o processador for mais rápido que o módulo, tenhamos perda de desempenho. Mais para frente veremos a E/S controlado por interrupção que supre essa questão, pois o processador emite um comando de E/S e continua a executar outras instrucoes até ser interrompido pelo modulo de E/S quando o ultimo tiver completado seu trabalho.

Em ambas as técnicas (programada e progamada por interrupção), o processador é responsável pela troca de dados entre a memoria principal e entrada/saida. Caso desejemos que essa troca de dados seja feita diretamente entre o módulo de E/S e memoria principal, temos a tecnica de acessos diretos a emmoria (DMA).

### Visao geral da E/S programada
Ao receber uma instrução de E/S o processador executa um essa instrução emitindo um comando ao módulo de E/S apropriada. Após isso ele verifica periodicamente se o estado do módulo de E/S indica que a operação terminou.

### Comandos de E/S
Para executar uma instrução, o processador emite um endereço com o módulo de E/S e dispositivo externo especificados, e um comando de E/S. O módulo de E/S pode receber os seguintes comandos:
- Controle => ativar um perifico e designar o que fazer
- Teste => verifica as condicoes de estado associadas a um modulo de E/S e seus perifericos associados
- Leitura => modulo de E/S obtem um item de dados do perifico e coloca esse item de dados num buffer interno ou no barramento de dados
- Escrita => modulo de E/S apanha um dado do barramento de dados e transmite para o periferico

### Instrucoes de E/S
Normalmente para cada instrução relacionada à E/S o processador emite um comando a um módulo de E/S para executá-las. Isso representa uma relação um pra um, normalmente.

Como há diversos dipositivos conectados por meio de módulos de E/S ao sistema, a necessidade de um endereço exclusivo para eles faz-se necessário, o qual é utilizado quando o processador emite um comando de E/S. 

## E/S controlada por interrupcao
Como dito anteriormente, esse tipo de técnica realiza as operaçoes até que o comando anterior dado ao módulo seja concluído e esse módulo mande um sinal ao processador sinalizando este fim. Quando recebe esse final, o processador para o que está fazendo, conclui, e continua fazendo o que já estava em processo. Para saber o que estava sendo realizado o processador guarda todo o processo numa pilha de controle para não perder as informações.

Então, percebe-se que a técnica de E/S controlada por interrupcao é mais eficiente que a E/S programada, pois não tem tempo de espera em relação ao modulo de E/S.

### Aspectos de projeto
Precisamos detectar qual dispositivo emitiu a interrupção e qual interrupção o processador deve executar em caso de multiplas interrupções.

Para identificar quem emitiu o sinal de interrupção, utiliza-se:
- Multiplas linhas de interrupcao => mais simples, mas impraticavel do ponto de vista com multiplos modulos de E/S conectados as linhas. Por isso com essa técnica o processador apanha apenas a linha de interrupcao com prioridade mais alta
- Verificacao por software (polling) => ao detectar interrupcao o registrador de estado de cada módulo é lido e um tratamento de erro é submetido a ele. Isso faz com que a técnica seja mais demorada.
- Daisy (verificacao por hardware, vetorada) => eficiente em relação ao polling. Ao receber uma interrupção, o processador envia uma confirmação dela. O módulo correto responde colocando uma palavra das linhas de dados que denominamos vetor de interrupção, a qual é o endereço do módulo de E/S. Esse vetor é utilizado como ponteiro para a rotina de serviço de dispositivo apropriada, evitando a rotina de tratamento
- Arbitracao de barramento (vetorado) => utiliza interrupcoes vetorizadas como a Daisy. Porém, ela precisa primeiro ganhar controle do barramento antes de ativar a requisicao de interrupção.

## Acesso direto à memória
### Desvantagens da E/S programada e controlada por interrupção 
Mesmo que a E/S controlada por interrupção seja mais eficiente que a E/S programada, ainda temos a necessidade de o processador fazer a transferencia de dados entre a memoria e um modulo de E/S. Então temos duas desvantagens para ambas técnicas:
- Taxa de transferencia de E/S é limitada pela velocidade que o processador possui para testar e atender ao dispositivo
- Processador fica ocupada no gerenciamento de transferencia, enquanto diversas instrucoes precisam ser executadas para cada transferencia de E/S, sobrecarregando-o

Assim, para transferencia de um grande volume de dados recomen-dase utiliza o acesso direto a memoria (DMA).

### Acesso direto a memoria (DMA)
Essa técnica elimina a utilização do processador pela adição de um módulo adicional no barramento do sistema que faz a sua função. Ele faz a transferencia de dados por meio do barramento do sistema enquanto o processador não precisa dele (pode até mesmo interromper a atividade), o que chamamos de roubo de ciclo. Numa requisicao de leitura/escrita, o processador envia um comando ao modulo de DMA indicando:
- Indicacao de uma leitura ou escrita
- Endereco do dispositivo de E/S associado 
- Local inicial da memoria p/ ler ou escrever
- Numero de palavras a serem lidas ou gravadas

Enquanto o módulo de DMA faz isso, o processador continua com suas outras funções. Quando o módulo acabar de transferir os dados da memoria (para ela ou a partir dela), ele emite um sinal de interrupção, ficando claro que o processador é envolvido apenas no inicio e fim da transferencia.

Vale ressaltar que o processador não salva o contexto e faz algo mais, apenas é interrompido por um ciclo do barramento, tornando a próxima execução mais lenta.

## Canais e processadores de E/S
### A evolução da função de E/S
Assim como outros componentes, a função de E/S também evoluiu ao passar do tempo. Algumas dessas evoluções são:
- CPU controla diretamente o periférico, exemplo os sistemas embutidos
- Acréscimo de controlador ou módulo de E/S, não requisitando tanto o processador
- Possibilidade de utilizar o fato anterior sem que a CPU tenha que esperar a operação de E/S ser concluída
- Módulo de E/S recebe acesso direto a memoria por meio de DMA => pode mover bloco de dados sem envolver a CPU (exceto para receber/mandar informações de controle)
- Módulo de E/S aprimorado para tornar-se um processador por conta própria => designado pela CPU para executar um programa de E/S armazenado na memória
- Módulo de E/S tem uma memória local própria => grande conjunto de dispositivos de E/S pode ser controlado com pouco envolvimento da CPU

Com o tempo é percepeptível que a CPU é cada vez menos requisitada para as operações de E/S. A penúltima etapa introduziu o canal de E/S, isto é, um modulo de E/S capaz de executar um programa.

### Canais de E/S
De modo geral, um canal de E/S é uma extensão do conceito de DMA, pois ele tem a capacidade de executar instruções de E/S, o que permite que ele tenha um controle ainda maior sobre operações de E/S, consequentemente, a CPU não precisa mais executar instrucoes de E/S.

## Interface externas: FireWire e InfiniBand
### Tipos de interfaces
Cada interface é ajustada de acordo com o periférico. É importante saber se ela é:
- Interface paralela => multiplas linhas que conectam o modulo de E/S e o perifico, onde diversos bits/palavras sao transferidos ao mesmo tempo pelo barramento de dados. Ideal para perifericos de alta velocidade, como fita e disco
- Interface serial => apenas uma linha usada para transmissao de dados, logo os bits sao transmitindo um de cada vez. Mais utilizadas em impressoras, terminais... Contudo, temos interfaces seriais de alto desempenho, tornando as paralelas menos comuns.

A operação de escrita é assim:
- 1. Modulo de E/S envia sinal de controle requisitando permissao para envio de dados
- 2. Periferico reconhece o sinal
- 3. MOdulo de E/S envia dados
- 4. Periferico confirma o recebimento dos dados

Dentro do modulo de E/S temos um buffer que armazena os dados que estão sendo passados entre o perifico e o restante do sistema.
Essa técnica elimina a utilização do processador pela adição de um módulo adicional no barramento do sistema que faz a sua função. Ele faz a transferencia de dados por meio do barramento do sistema enquanto o processador não precisa dele (pode até mesmo interromper a atividade), o que chamamos de roubo de ciclo. Numa requisicao de leitura/escrita, o processador envia um comando ao modulo de DMA indicando:
As tecnologias de E/S de alta velocidade para sistemas de mainframe são caras e volumosas para sistemas menores. Sabendo disso, a indústria propos o desenvolvimento de uma alternativa mais rápida para sistemas pequenos que não seja tão volumosa e tão cara. Assim, surgiu o FireWire.

O FireWire tem velocidade mais alta, baixo custo e é de fácil implementação. Mais favorável para sistemas de computação modernos e eletrônicos comuns. Ele utiliza transmissao serial em vez de paralela, exigindo menos fios e menos pinos (diminuindo o custo e possibilidades de quebras), além de ser menor (fundamental para os tempos atuais onde os computadores são cada vez menores).

Assim, temos uma unica interface de E/S com um conector unico, que trata varios dispositivos numa porta unica e, assim, mouse, monitor, teclado etc podem ser conectados num unico conector.

É possível conectar e desconectar periféricos sem a necessidade de desligar o computador ou reconfigurar o sistema, além de programar automaticamente a configuração de instalação dos dispositivos.

O sistema principal interage com os dispositivos perifericos de modo padronizado, baseado em tres camadas:
- Camada fisica => define meios de tranmissao permitidos sob FireWire, conversão de dados binários em sinais elétricos...
- Camada de enlace => descreve transmissao de dados nos pacotes
- Camada de transacao => define um protocolo de req-res 

### Infiniband
Voltada para mercado de servidores de ponta. Normalmente utilizadas em redes de armazenamento grandes, permitindo que servidores, armazenamento remoto e outros dispositivos de rede estejam conectados em uma fabrica central de comutadores e links.

Temos uma velocidade extremamente grande nesse sistema de até 4Gbps, além da possibilidade de uma central de dados expansível e flexível, podendo adicionar mais recursos conforme a necessidade.

A arquitetura do InfiniBand conta com:
- Host channel adapter (HCA) => HCA se conecta ao servidor em um controlador de memoria que tem acesso ao barramento do sistema
- Target channel adapter (TCA) => usado para conectar os sistemas de armazenamento, roteadores etc a um computador InfiniBand. Eles tratam as funcoes de E/S sem interromper o processador do servidor.
- Comutador InfiniBand => comutador (switches) que oferece conexoes entre os dispositivos e direciona o trafego de conexoes, permitindo a comunicacao
- Conexoes => conexao entre o computador e um adaptador de canal
- Sub-rede => conexao entre comutadores com links que conectam outros dispositivos conectados a eles
- Roteador => faz a conexao entre sub-redes, conecta um comutador InfiniBand a uma rede

Não há disputa de capacidade ao processador, pois podemos acrescentar dispositivos a configuração, conectando o TCA de cada dispositivo ao comutador.Essa técnica elimina a utilização do processador pela adição de um módulo adicional no barramento do sistema que faz a sua função. Ele faz a transferencia de dados por meio do barramento do sistema enquanto o processador não precisa dele (pode até mesmo interromper a atividade), o que chamamos de roubo de ciclo. Numa requisicao de leitura/escrita, o processador envia um comando ao modulo de DMA indicando:
- Legíveis ao ser humano => comunicação com o ser humano (monitores, impressoras)
- Legíveis à máquina => comunicação com a máquina (HDs, fitas, sensores)
- Comunicação => comunicação com dispositivos remotos 

### 2.
Na interação do usuario/computador a principal comunicacao é teclado/monitor. Esse tipo de comunicacao tem o caractere como unidade de troca basica. Cada caractere tem um código de 7 ou 8 bits, e o código de texto mais usado é o International Reference Alphabet. Podemos ter até 128 caracteres diferentes representados.

### 3.
- Controle e temporização => controle do fluxo de tráfego entre o processador e os diversos dispositivos conectados
- Comunicação com o processador => o módulo de E/S precisa se comunicar com o processador informando os dados, estado, endereço etc, para que o processador interprete a informação que chega da entrada ou enviar a informação para a saída
- Comunicação com o dispositivo => o próprio nome já diz
- Buffering de dados => como a taxa de transferencia é diferente entre os dispositivos e memória, a operação de buffering basicamente faz a regulação dessa disparidade
- Detecção de erro => detectar e relatar erros ao processador. Podemos ter erros mecânicos ou mudanças equivocadas no padrão de bits na transmissão do dispostivo ao módulo de E/S. Pode-se utilziar um bit de paridade em cada caractere de dados.

### 4.
- E/S Programada => utiliza o processador para transferencia de dados. Manda a instrucao de E/S para o módulo de E/S e após isso o processador monitora o módulo de E/S, verificando se o processo acabou. Após isso, dá continuidade a outras instruções.
- E/S controlada por interrupção => o processador emite um comando de E/S ao modulo de E/S e continua a executar outras instrucoes até ser interrompido pelo modulo de E/S quando ele mandar um bit de interrupção, logo após terminar de executar a instrução dada a ele.
- Acesso direto a memoria => elimina a utilização do processador pela adição de um módulo adicional no barramento do sistema que faz a sua função. Faz a transferencia de dados por meio do barramento do sistema enquanto o processador não precisa dele (pode até mesmo interromper a atividade), o que chamamos de roubo de ciclo.

### 5.
- E/S mapeada na memoria => existe um único espaço de endereço para locais de memória e dispositivos de E/S. Nela, uma única linha de leitura e uma única linha de escrita são necessárias no barramento
- E/S independente => pode ter linhas de leitura e escrita na memoria alem das linhas de comando de entrada e saida. A linha de comando especifica se o endereço se refere a um local de memória ou a um dispositivo de E/S. Chamamos isso de E/S independente, pois o espaço de endereço é independente do espaço da memória.

### 6.
- Multiplas linhas de interrupcao => mais simples, mas impraticavel do ponto de vista com multiplos modulos de E/S conectados as linhas. Por isso com essa técnica o processador apanha apenas a linha de interrupcao com prioridade mais alta
- Verificacao por software (polling) => ao detectar interrupcao o registrador de estado de cada módulo é lido e um tratamento de erro é submetido a ele. Isso faz com que a técnica seja mais demorada.
- Daisy (verificacao por hardware, vetorada) => eficiente em relação ao polling. Ao receber uma interrupção, o processador envia uma confirmação dela. O módulo correto responde colocando uma palavra das linhas de dados que denominamos vetor de interrupção, a qual é o endereço do módulo de E/S. Esse vetor é utilizado como ponteiro para a rotina de serviço de dispositivo apropriada, evitando a rotina de tratamento
- Arbitracao de barramento (vetorado) => utiliza interrupcoes vetorizadas como a Daisy. Porém, ela precisa primeiro ganhar controle do barramento antes de ativar a requisicao de interrupção.

### 7.
O processador pausa para cada ciclo de barramento roubado pelo módulo DMA (roubo de ciclo).







