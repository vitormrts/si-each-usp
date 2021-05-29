# Memória Externa
O principal componente da memória externa é o disco magnético. Esse disco magnético não é volátil, isto é, pode armazenar dados mesmo sem energia corrente. Entretanto, um dos principais problemas dos discos magnéticos é o seu desempenho. O desempenho pode ser aumentado por meio de sistemas que utilizam RAID. De modo geral, RAID é um conjunto de técnicas que consiste na utilização de múltiplos discos (como se fosse um array), sendo que essa técnica é normalmente mais utilizada em sistemas grandes e servidores.

## 1. Disco Magnético
Um disco magnético é um prato circular construído de material não magnético. Sua principal vantagem é o fato de ser não-volátil, mas seu desempenho não é o dos melhores.

### 1.1 Leitura magnética e mecanismos de gravação
A bobina condutora ou cabeça é o mecanismo que permite a gravação e recuperação de dados do disco. Normalmente em sistemas mais complexos há duas cabeças: uma para gravação, outra para leitura.

Ao ler ou gravar um determinado dado, a cabeça fica estacionário enquanto a placa gira por baixo dela. De modo geral, a leitura ou gravação explora a eletricidade e a produção de um campo magnético pela bobina.

### 1.2 Organização e formatação de dados
A cabeça, como dita anteriormente, é um dispositivo relativamente pequeno que pode ler e escrever em uma parte do brato que gira por baixo dela. Esses pratos são organizados em milhares de trilhas por superficies, um conjunto concentrico de aneis. Essas trilhas são delimitdas por lacunas intratrilhas.

Cada trilha possui centenas de setores (podendo ser fixos ou não, em média 512 bytes) que armazenam dados. Esses setores são delimitados por intersetores.

Vale destacar que os bits mais próximos do centro de um disco são mais lentos de serem lidos/gravados do que um bit na extremidade. Sabendo disso, aumenta-se o espaçamento entre os bits de informação gravados nos segmentos do disco, o que permite que os bits sejam lidos ao mesmo tempo (chamamos isso de velocidade angular constante, ou CAV).

Para suprir o fato de que a densidade (bits por polegada linear) aumenta da trilha mais externa para a mais interna, utiliza-se a técnica de gravação em múltiplas zonas, em que cada zona possui uma quantidade menor de bits (menos setores) quanto mais pŕoxima ao centro do disco, à medida que quanto mais longe do centro do disco, mais bits (mais setores).

### 1.3 Características físicas
Temos dois tipos de discos com cabeça:
- Fixa => uma cabeça de leitura-gravação para cada trilha, mas são raros hoje em dia
- Móvel => somente uma cabeça de leitura-gravacao

Além disso, temos discos:
- Removíveis => pode ser removido e substituido por outro disco. Ex: cartucho, disquetes...
- Não-removiveis => montados permanentemente na unidade de disco

Algumas unidades de discos podem ainda ter multiplas placas empilhadas verticalmente com uma distancia entre elas, onde sao utilizadas uma cabeça movel para cada placa (as cabeças sao sincronizadas). Nesse sistema de multiplas placas denominamos cilindro o conjunto de todas as trilhas na mesma posicao relativa na placa.

A cabeça pode estar mais perto da superficie da placa ou mais longe. Quanto mais perto, maior a probabilidade de termos erros, por conta de impurezas e imperfeições. Para corrigir isso, temos o disco Winchester em que as cabeças sao projetadas para operar mais perto dessa superfície.

### 1.4 Parâmetros de desempenho de disco
Primeiro é necessário entender que o disco está girando a todo momento. 

Para ler ou gravar um dado, é necessário que a cabeça esteja posicionada na trilha onde o setor está localizado. Isso é chamado de `seek time`. 

Alem disso, quando a trilha é selecionada, o controlador de disco opera até que o setor desejado fique alinhado com a cabeça. O tempo de espera disso é chamado de `atraso rotacional`. 

Apos isso temos a transferencia de dados, onde isso ocorre enquanto o setor se move sob a cabeca. Esse tempo de transferencia de dados pode ser calculado da seguinte forma:

```
T = b/rN, onde

T = tempo de transferencia
b = nro de bytes a serem transferidos
N = nro de bytes em uma trilha
r = velocidade de rotacao, em rotacoes por segundo
```

A proposito, para o tempo medio de busca temos:
`` Ta = Ts + 1/2r +b/rN ``, onde `Ts` é o tempo medio de busca.

## 2. RAID
Sabe-se que as melhorias da memoria secundaria nao sao tao exponenciais quanto as melhorias da memoria primaria ou processadores.

Sabendo disso, os projetistas propuseram o desenvolvimento de arrays de discos que operam independentemente e em paralelo, de modo a aumentar o desempenho. Isso permite as solicitacoes de E/S podem ser tratadas paralelamente.

Entretanto, isso leva ao fato de que os dados podem ser organizados de diferentes maneiras, podendo dificultar o desenvolvimento de db's. Para isso houve um combinado entre as empresas da produção de discos RAID (redundant array of indenpendent disks), os quais consistem em sete níveis com três características em comum:

- RAID é um conjunto de discos físicos, mas são vistas pelo sistema como uma única unidade lógica
- Dados são distribuidos pelo discos físicos de um array num esquema de intercalação de dados (striping)
- A capacidade de disco redundante é usada para armazenar infos de paridade => garante facilidade de recuperar dados em falhas de disco

Como temos múltiplos discos, a probabilidade de falha aumenta. Para isso, a RAID utiliza infos de paridade armazenadas (como citado), permitindo a recuperação desses dados quando há falhas de disco por meio dessa redundância.

### RAID nivel 0
Como nao inclui redundancia para melhorar o desempenho, nao consideramos um membro verdadeiro da familia RAID. Como os dados do usuario e sistema sao distribuidos por todos discos no array, o tempo de enfileiramento é menor, pois diferentes solicitações tem maiores chances de os blocos de dados estarem em discos diferentes.

Os dados são intercalados (striped) pelos discos diponíveis. O disco lógico é dividido em strips lógicos (blocos físicos, setores físicos etc). Em um array com n discos, os primeiros n strips logicos sao armazenados fisicamente como o primeiro strip em cada um dos n discos. Os proximos n strips seguem a mesma logica.

A vantagem disso tudo está presente principalmente no fato de que strips contíguos podem ser tratados em parelelo, o que reduz o tempo de transferencia de E/S.

Podemos ter tipos especificos de RAID 0:


- RAID 0 para alta capacidade de transferencia de dados => precisamos de uma alta capacidade de transf. ao longo do caminho inteiro entre a memoria do sistema principal e unidade de disco individuais, o que inclui barramentos internos, barramentos de E/S, adaptadores de E/S e barramentos de memoria do sistema principal. Alem disso, a aplicacao deve fazer que as solicitacoes de E/S sejam eficazes no que se refere ao controle do array de disco.
- RAID 0 para alta taxa de solitacao de E/S => quando temos mais preocupacao com o tempo de resposta em vez de tempo de transferencia, usamos esse RAID 0. O tempo de resposta normalmente é muito afetado pelo seektime e movimento do disco. Podemos ter um enfileiramento muito grande, entao tratar as solicitacoes de E/S paralelamente reduz o tempo de enfileiramento.

### RAID nível 1
A redundacia é obtida duplicando todos os dados, o que torna mais simples obte-la em comparacao as outras RAIDs. Ela tambem possui striping de dados como a RAID 0.  Contudo, cada strip logico é mapeado para dois discos físicos separados, o que permite um espelhamento (cada disco no array tem um disco espelho que contém os mesmos dados). Temos RAID 1 sem striping de dados, mas não é tão comum.

Aspectos da sua organização:
- Solicitação de leitura pode ser atendida pelos dois discos que ontem os dados => a com menor tempo é escolhida
- Gravar exige que os dois strips sejam atualizados, mas isso pode ser feito em paralelo
- Recuperação de falha simples => se um falha, basta acessar o outro

Contudo, seu custo é extremamente alto por conta desse espelhamento (mais discos consequentemente). Normalmente temos ganhos maiores em leitura em vez de gravação em relação a RAID 0. 

Além disso, temos melhor desempenho em relação a RAID 0 para aplicacoes com uso intenso de transferencia de dados, com uma alta taxa de leituras.

### RAID nivel 2
Utiliza a tecnica de acesso paralelo, assim como o RAID 3, onde todos os discos participam da execucao de cada solicitacao de E/S. As cabeças estão sincronizadas, isto é, na mesma posição em cada disco a qualquer instante.

O RAID 2 utiliza a tecnica de striping de dados, mas o strip é extremamente pequeno, representado muita das vezes como byte único ou palavra. Para corrigir o erro é calculado um código de correção em todos os bits correspondentes em cada disco de dados, diferente do RAID 1 que possui um simples calculo que duplica todos os dados para obter a redundancia. Esses bits de codigo de erro sao guardados nos varios disco de paridade correspondentes.

Exige menos discos que o RAID 1, mas é mais caro. Quando lemos um dado, acessamos todos os discos simultaneamente. Para escolher essa técnica recomenda-se que o ambiente esteja sujeito a vários erros de disco por sua alta confiabilidade.

### RAID nivel 3
Organizado de forma parecida ao RAID 2. No entanto, o RAID 3 exige apenas um único disco redundante. Além disso, utiliza acesso paralelo com dados distribuídos em pequenos strips. Um bit de paridade simples é calculado na mesma posicao em todos discos em vez de um código de correção de erro.

Quando temos uma falha de disco, a unidade de paridade é acessada e os dados são reconstruídos a partir do conteudo dos strips correspondentes.

O RAID 3 pode alcançar altas taxas de transferencia de dados pelo fato de os dados serem armazenados em strips muito pequenos. Logo, para transferencias grandes a melhoria no desempenho é considerável, mas para transferências únicas, o desempenho é menor (principalmente em transações).

### RAID nivel 4
Os RAIDs 4, 5 e 6 utilizam a tecnica de acesso independente, diferente dos RAIDs 2 e 3 que utilizam acesso paralelo. Esse acesso indendente se baseia em cada disco membro operar independentemente, assim as solicitacoes de E/S separadas sao realizadas em paralelo. Isso torna os RAIDs de nivel 4 a 6 mais utilizados em aplicacoes com alta taxa de solicitacao de E/S, mas menos adequados para altas taxas de transferencias de dados.

Utiliza a tecnica de striping de dados, mas os strips sao grandes se comparados aos outros RAIDs. O strip de paridade é calculado e armazenado em um disco de paridade correspondente.

Ao gravar um dado precisamos que os dados de usuario sejam atualizados assim como os bits de paridade correspondentes no disco de paridade. Assim, cada operacao precisa envolver o disco de paridade, o que pode vir a ser um gargalo.

### RAID nivel 5
Como dito anteriormente, utiliza a tecnica de acesso independente. Parecido com o RAID 4, mas o RAID 5 distribui os strips de paridade por todos os discos, evitando um disco de paridade. Isso evita o gargalo de E/S encontrado no RAID 4, pois nao envolvemos o disco de paridade.


### RAID nivel 6
Temos dois calculos de paridade diferentes armazenados em blocos separados em discos diferentes. A quantidade de discos consiste em N + 2, onde N é a quantidade de discos.

Como temos dois discos a mais, entao a disponibilidade de dados é extremamente alta. Entretanto, como é de se esperar, para a gravação de dados temos uma penalidade, pois cada gravação afeta dois blocos de paridade. Já a leitura é parecida em comparação ao RAID 5.

## 3. Memória óptica
### CD (Compact disk)
De modo geral, um CD é um disco não apagável que pode armazenar mais de 60 minutos de informações de áudio digitalizadas.

Temos diferentes tipos de CDs, por exemplo:

- CD-ROM (Compact disk read-only memory) => disco nao apagavel para armazenar dados do computador. Pode conter mais de 650 Mb e é de 12 cm.
- CD-R => CD Gravável. Pode gravar no disco apenas uma vez.
- CD-RW => CD Regravável. Como o nome diz, pode apagar e regravar no disco várias vezes. 

### DVD (Digital versatile disk)
O DVD substituiu a fita de vídeo usadas em videocassete, além de substituir o CD-ROM nos computadores pessoas e servidores.

Os DVDs possuem uma qualidade de imagem melhores que as fitas, além de aumentar a capacidade de armazenamento em relação aos CDs. 

Alguns tipos de DVDs sao:
- DVD-R => DVD Gravável. Podemos gravar no disco apenas uma vez.
- DVD-RW => DVD Regravável. Podemos gravar/apagar no disco quantas vezes quisermos.

### Blu-Ray DVD
Esse tipo de disco possui uma alta definicao e capacidade muito maior em comparacao aos DVDs.

## 4. Fita magnética
Também temos a possibilidade de armazenar dados em um sistemas de fita, os quais utilizam as mesmas técnicas de leitura e gravação que os times de disco utilizam.

Os dados gravados nelas são organizados em trilhas paralelas no sentido do comprimento da fita. Esse tipo de gravação é chamado de gravação paralela. Em sistemas maiores, utiliza-se a gravação serial, i. e., os dados sao dispostos em uma sequencia de bits ao longo de cada trilha.

Uma fita é um dispositivo de acesso sequencial. Por isso é necessário rebobinar a fita por uma certa distância para voltar a um determinado ponto. 

## 5. Exercícios
### Pergunta 6.10 do livro Computer Organization and Architecture: Designing for Performance (8th Edition), Stallings 8ed

### a.
Precisamos de três discos com 1 TB cada. 500GB custam US$150. Então, 2 * US$ 150 * 3 = US$ 900

### b.
Uma unidade de fita vale US$ 2500 e fitas de 400 GB valem US$ 50 a peça. Assim, US$ 2500 + (3 * 3 * US$ 50) = US$ 2950

### c.
Para saber quanto a estrategia de fita fosse valer mais a pena que a estrategia de backup para discos, precisamos igualar as duas equaçoes com a quantidade N de GB necessarias. Assim,

Pd = (N/500) * 3 * US$150, onde Td é o preço de backup para N GB para discos

Pf = 2500 + ((N/400) * 3 * US$ 50), onde Pf é o preço de backup para N GB para fitas

De modo que: 

Pd = Pf 
=> (N/500) * 3 * US$150 = 2500 + ((N/400) * 3 * US$ 50)
=> N * 450/500 = 2500 + (N * 150)/400
=> N * (9/10) = 2500 + N * (3/8)
=> N * (9/10) - N * (3/8) = 2500
=> (36 * N - 15 * N)/40 = 2500
=> (21 * N)/40 = 2500
=> 21 * N = 2500 * 40
=> N = 100000 / 21
=> N = 4762

Portanto, a partir de 4762 GB a tatica de utilizar fitas como backup é mais em conta que utilizar discos.

### d.
Quando a quantidade de gigas para backup começa a ficar muito grande.
