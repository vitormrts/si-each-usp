# Arquitetura de Memoria

De antemao ressalta-se que o tempo de acesso de memória implica positivamente ou negativamente no desempenho do programa. Basicamente temos três diferentes tipos de memória:

- SRAM => Static Random Access Memory. Esta memória possui uma velocidade de acesso baixíssima, estando mais próxima do processador. Contudo, o seu preço por bit é alto.
- DRAM => Dynamic Random Access Memory. Esta memória é a dita memória principal. Possui uma velocidade de acesso razoável e um armazenamento razoável.
- HD => Hard Disk. Velocidade de acesso baixíssimo, mas com uma alta capacidade de armazenamento (baixo custo por bit)

Percebe-se que temos uma relação entre o custo por bit, velocidade de acesso e quantidade de bits:

- Quanto maior a velocidade de acesso, maior a velocidade por bit
- Quanto maior a capacidade, menor o custo por bit e tempo de acesso mais lento

Para "contornar" esses problemas utilizamos o conceito de Hierarquia de Memória, a qual dá a impressão p/ o processador que temos uma memória grande e rápido. Isso faz com que o cache, memoria principal e disco rigido se complementem conforme as suas necessidades: a baixa capacidade de armazenamento do cache é complementada pelo HD, a velocidade baixa do HD é sobrescrita pelo cache etc.

Essa Hierarquia de Memória baseia-se no princípio da localidade:

- Temporal => reconhecimento de loops, reutilização de operandos. Isso permite que os dados mais acessados sejam armazenados para uso posterior.
- Espacial => arrays, matrizes etc. Por exemplo, se utilizamos um valor de uma matriz, traremos essa matriz por completo, pois há grandes chances de mais valores serem utilizados. Temos um agrupamento de dados.

No funcionamento da memória temos acertos e erros (hits e misses). Quanto mais hits, maior o desempenho. Um `hit` significa que encontramos o dado no nível superior, ou seja, não precisamos acessar um dado que está no HD e trazê-lo para o nível superior. Se isso não ocorrer, temos um `miss` acompanhado de uma penalidade que afetará o ciclo de clock (o clock pode ter que esperar para ser executado). Logo, um bom acesso a memória terá muito mais hits, consequentemente menos misses, o que diminui a parada de ciclos de clock.

Com isso em mente, percebe-se que o tempo de execução de um programa também deve levar em conta o tempo de hits e misses. A quantidade de ciclos de parada p/ a memória (memory stall cycles) é dada por:

```
MSC = Instruções/Programa * Erros/Instrução * Penalidade por Erro
```

Além disso, o tempo de acesso médio é dado pelo `tempo de acesso + taxa de erro (i.e, 1 - taxa de acerto) vezes a penalidade por erro`.

## Perguntas de verificação
> Final do Cap. 4. Computer Organization and Architecture: Designing for Performance (8th Edition), Stallings 8ed

###  1) 
- Acesso sequencial: os dados são armazenados sequencialmente na memória física, i. e, em uma sequência linear específica.
- Acesso direto: cada bloco e registro possui um endereço específico na memória física, por exemplo, os discos. Ou seja, o acesso é feito por blocos.
- Acesso aleatório: cada local da memoria possui um método de endereçamento exclusivo.

### 2) 
- Quanto maior a capacidade, menor o custo por bit e maior tempo de acesso. 
- Quanto maior a velocidade de acesso, maior o custo por bit.

### 3) 
Os dados acessados recentemente são armazenados no nível superior de memória.

### 4) 
- Mapeamento direto: mapeia cada bloco de memória a apenas uma linha de cache. Como o tamanho de local de cache é fixo p/ cada bloco, se referenciarmos blocos diferentes mapeados p/ a mesma linha, teremos uma alta taxa de miss (fenomeno thrashing).
- Mapeamento associativo: permite que cada bloco de memória possa ser mapeado em qualquer linha de cache.
- Mapeamento associativo em conjunto: junta os pontos mais fortes de ambos mapeamentos anteriores. A cache é uma série de conjuntos, e cada conjunto contem uma serie de linha. Assim, cada bloco é mapeado a qualquer linha de um conjunto.

### 5) 
Tag, linha, palavra

### 6) 
Tag, palavra

### 7) 
Tag, conjunto, palavra

### 8) 
- Espacial: se um item foi referenciado, itens com o endereços próximos tendem a ser utilizados em seguida
- Temporal: se um item foi referenciado recentemente, ele tende a ser referenciado novamente.

### 9) 
Acertos e falhas. Se encontramos um dado perto nos níveis superiores, temos um hit. Senão, um miss.