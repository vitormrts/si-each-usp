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

## 2. Correção de erro
Um sistema de memória semicondutora está sujeito a erros, os quais podem ser:
- Uma falha permanente => defeito físico permanente em que as células de memória não armazenam os dados de forma confiável. Normalmente é causada por defeito de fabricação, uso intenso em um ambiente impróprio ou até mesmo desgaste.
- Falha não permanente => altera o conteúdo de uma ou mais células de memória (não é destrutivo)

Sabendo que esses erros são indesejáveis, sistemas modernos possuem sistemas com uma lógica que detecta e os corrige.
De modo geral, quando os dados são lidos, é aplicado um cálculo que produz um código. O tamanho real da palvra armazenada é de `M + K bits`, onde `M é o tamanho dos dados` e `K é o tamanho do código`. Após isso, quando essa palavra for lida, o código aplicado a ela é utilizado p/ detectar e corrigir erros. A comparação entre os K bits de código anteriormente armazenados e os novos K bits gera possíveis resultados:
- Sem erros detectados => bits de dados armazenados enviados
- Erro detectado e pode ser corrigido
- Erro detectado, mas não é possível corrigi-lo

Um exemplo de código de correção de erro é o `Código de Hamming`, mas não vou abordá-lo por sua complexidade.

## 3. Organizações avançadas de DRAM
Um dos principais gargalos do sistema é a interface do processador com a memória interna principal. Pelo fato de essa interface ser o caminho mais importante na computação, são necessárias alternativas para abordar esse tema, como inserir caches SRAM entre a DRAM e o processador. Contudo, essa possibilidade se torna complicada devido ao alto custo da SRAM e não é tão interessante aumentar o tamanho da cache. Sendo assim, atualmente vem surgindo melhorias na arquitetura básica das DRAMs, como:
- SDRAM
- DDR-DRAM
- RDRAM

### DRAM Síncrona (SDRAM)
Enquanto a DRAM é assíncrona, a SDRAM é síncrona. Isto é, a SRAM faz a troca de dados com o processador baseado no sinal de clock externo no nível de barramento do processador e memória, sem estado de espera.
A DRAM tradicional precisa fazer a configuração do endereço, ativação das fileiras de linha e coluna, verificação dos dados etc, e tudo isso demanda tempo de espera para o processador. Sabendo disso, a SRAM possui um sistema de `burst`, que elimina esse tempo de configuração e pré-carga de fileira de linha e coluna APÓS o primeiro acesso. Isso se torna extremamente vantajoso para dados armazenados em sequência, como arrays e grandes blocos de dados em série como textos, planilhas e multimidia.

### DRAM RamBus (RDRAM)
A memoria RDRAM tornou-se a principal concorrente da SDRAM. Nela os chips são encapsulados verticalmente com todos os pinos de um lado. Ela possui um barramento que oferece até 320 chips de RDRAM a uma velocidade de 1,6 GB p/s, além de que esse barramento transmite informações de endereço e controle usando um protocolo assíncrono (diferente da SDRAM) orientado a bloco.

Esse tipo de memoria trouxe um aumenta na latencia, maior produção de calor, complexidade de fabricação e um custo maior.

### Double Data Rate SDRAM (DDR-SDRAM)
Sabe-se que por um lado a SDRAM envia dados ao processado uma vez por ciclo de clock no barramento. Por outro lado, a DDR-SDRAM envia dados ao processador duas vezes por ciclo de clock, i. e., uma vez na subida do pulso de clock, outro na transição de descida. Isso aumenta a velocidade da DRAM, além de que esse tipo de memória possui um `buffer` que pré-posiciona os bits a serem colocados na base de dados o mais rápido possível. Temos diferentes tipos de gerações de DDR-SDRAM, como:
- DDR => envia 2 bits por chip no buffer de pré busca
- DDR2 => envia 4 bits por chip no buffer de pré busca
- DDR3 => envia 8 bits por chip no buffer de pre busca
- DDR4 => envia 16 bits por chip no buffer ed pre busca
- DDR5 => envia 32 bits por chip no buffer de pre busca

Além disso, as versões mais recentes possuem uma frequência maior que as anteriores.

### Cache DRAM (CDRAM)
Por ultimo, mas não menos importante, temos a CDRAM. Como o próprio nome diz, esse tipo de memória integra uma cache SRAM pequena a um DRAM genérico.

## 4. Exercícios
### Quais são as principais propriedades da memória semicondutora?
Toda memória semicondutora possui o elemento básico, que é a célula de memória. Além disso, mesmo que a memória varie, temos propriedades compartilhadas, como:
- Estados estáveis que são representados por 1 e 0
- Capacidade de ser escrita ao menos uma vez
- Capacidade de ser lida
- Possui acesso aleatorio

### Quais são os dois sentidos em que o termo memória de acesso aleatório é usado?
A memória de acesso aleatório é a RAM (Random Access Memory), sendo que o acesso dessa memória, como o próprio nome diz, é aleatório.

### Qual é a diferença entre DRAM e SRAM em termos de aplicação?
Temos a memória DRAM e SRAM. A DRAM é usada para memória principal, a SRAM para cache.

### Qual é a diferença entre DRAM e SRAM em termos das características como velocidade, tamanho e custo?
- SRAM => mais rápida, menor capacidade de armazenamento e maior custo
- DRAM => menos rápida, maior capacidade de armazenamento e menor custo

### Explique por que um tipo de RAM é considerado como analógico e o outro digital.
A memória DRAM é analógica, pois armazena os dados como cargas em capacitores que descarregam sua energia naturalmente, havendo a necessidade de um refresh para não haver a perda de dados.
Já a memória SRAM é digital, pois utiliza uma lógica de flip-flop para não perder a informação com o tempo.

### Quais são algumas aplicações para a ROM?
Pela ROM não ser volátil e ser utilizada principalmente para leitura de dados, armazenamos aplicações extremamente importantes que não podem ser perdidas ao desligarmos a máquina, como:
- Bibliotecas frequentemente utilizadas
- Programas do sistema
- Tabelas de funções

### Quais são as diferenças entre EPROM, EEPROM e memória flash?
- EPROM (memoria somente de leitura programavel e apagavel) => leitura e escrita elétricas, igual a PROM. Contudo, antes de uma escrita, todas as celulas de armazenamento precisam ser apagadas, o que pode demorar até 20 min.
- EEPROM (memoria somente de leitura programavel e apagavel eletricamente) => pode ser escrita a qualquer momento sem a necessidade de apagar o conteudo anterior, sendo mais flexivel para atualizações locais. É mais cara que a EPROM e é menos densa.
- Flash => é a memória intermediaria entre a EPROM e EEPROM no custo e funcionalidade. Utiliza eletricidade p/ apagar uma memória inteira em poucos segundos, além de ser possível apagar somente um bloco de memória.
