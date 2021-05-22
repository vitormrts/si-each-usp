# Memória Interna

## 1. Memória principal semicondutora
Há tempos o armazenamento de acesso aleatório era feito com uma matriz de loops ferromagnéticos em forma de anel, o que foi denominado core.
Contudo, atualmente a microeletrônica permitiu a troca desse sistema por meio do uso de chips semicondutores p/ a memoria principal.

### Organização
A célula de memória é o elemento básico da memoria principal semicondutora. Dentre as possibilidades, são compartilhadas as propriedades seguintes:
- Estados estaveis => 1 e 0
- Capacidade de ser escrita p/ definir o estado da célula de memória
- Capacidade de ser lida p/ verificar o estado da celula de memoria

Além disso, uma célula de memória possui 3 terminais:
- Seleção => seleciona a celula
- Controle => determina se é uma celula de escrita ou leitura
- Terminal variavel, isto é, se for leitura => saída do estado, c. c, define o estado.

### RAM
Temos duas memórias de acesso aleatório (utiliza a lógia de endereçamento interno), a DRAM e SRAM. Ambas memórias fazem a leitura e escrita por meio de sinais elétricos, além de serem voláteis, i. e., é necessário energia elétrica p/ manter o dado de ambas.
- DRAM (Dynamic Random Access Memory) => os dados sao cargas armazenadas em capacitores, o que implica na necessidade de refresh p/ manter os dados, pois esse material naturalmente faz descargas elétricas
. Além disso, ela é amplamente utilizada na memória principal por ter uma capacidade de armazenamento razoável e uma velocidade boa.
- SRAM (Static Random Access Memory) => portas lógicas que usam flip-flop para armazenar valores binários. Diferente da DRAM, não necessita de refresh, então os dados são mantidos enquanto tem energia (a DRAM tambem, mas sem o refresh os dados sao perdidos). É mais utilizada no cache e processador por sua baixa capacidade de armazenamento e sua alta velocidade.

### Tipos de ROM
ROM = Read Only Memory. Ou seja, memórias do tipo ROM são memórias de leitura. Essas memórias não são voláteis, então os dados são armazenados mesmo sem energia elétrica, além de não ser possível escrever algo novo nela. Normalmente armazenamos aplicações importantes nela, como:
- Bibliotecas frequentemente utilizadas
- Promgramas do sistema
- Tabelas de funções

Pelo fato de os dados serem gravados fisicamente no chip, temos problemas:
- Inserção de dados é custosa
- Sem espaço p/ erro, pois um bit mal colocado faz que seja necessário a remoção do lote inteiro de ROM

Temos diferentes tipos de ROMs, como a PROM (ROM programável), que possui o processo de escrita elétrica feita com um equipamento especial.
Além disso, para casos onde operações de leitura são extremamente frequentes:
- EPROM (memoria somente de leitura programavel e apagavel) => leitura e escrita elétricas, igual a PROM. Contudo, antes de uma escrita, todas as celulas de armazenamento precisam ser apagadas, o que pode demorar até 20 min.
- EEPROM (memoria somente de leitura programavel e apagavel eletricamente) => pode ser escrita a qualquer momento sem a necessidade de apagar o conteudo anterior, sendo mais flexivel para atualizações locais. É mais cara que a EPROM e é menos densa.
- Flash => é a memória intermediaria entre a EPROM e EEPROM no custo e funcionalidade. Utiliza eletricidade p/ apagar uma memória inteira em poucos segundos, além de ser possível apagar somente um bloco de memória.

### Lógica do chip
Sabe-se que a memória semicondutora vem em chips empacotados. Esses chips são arrays de células de memória com W palavras e B bits. É fundamental saber o numero de bits que podem ser lidos ou escrito a cada vez.

### Empacotamento do chip
Um circuito integrado é um conjunto de pinos. Cada pino possui as seguintes linhas de sinal:
- Endereço da palavra sendo acessada. O tamanho da palavra define a qntd de pinos necessarios p/ isso (log2 tamanho_da_palavra).
- Os dados a serem lidos
- Fonte de alimentacao p o chip
- Pino de terra
- Pino CE => indica se o endereço é válido ou nao para o chip
- Voltagem de programa => fornecida na escrita

### Organização do módulo


## 2. Correção de erro


## 3. Organizações avançadas de DRAM

## 4. Exercicios
