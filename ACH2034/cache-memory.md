# Memória Cache
A memória cache fica próxima ao processador, tendo um tempo de acesso baixo e uma capacidade baixa. Temos três diferentes formas de mapear os dados na cache, que são:

- Mapeamento direto => os blocos de dados possuem um endereço único, o que torna esse endereço passível de ter mais de um dado, gerando conflitos. Aqui o endereço possui bits para a tag, index e word.
- Mapeamento associativo => os blocos de dados não possuem posição fixa, i. e., podem ser mapeados em qualquer endereço de memória. Assim, não é necessário um index (linha) e, consequentemente, nosso endereço necessita de bits apenas para a tag e word.
- Mapeamento associativo por conjunto => os blocos de dados são referenciados por blocos em um determinado conjunto. Assim, o bloco pode assumir qualquer posição no seu conjunto.

No mapeamento associativo em conjunto e mapeamento temos a possibilidade de realizar a substituição de um bloco por outro. Para isso existem várias técnicas, como:

- LRU (least recently used) => retirar o bloco acessado menos recentemente (princípio da localidade temporal)
Aleatório
- FIFO (first in first out) => o primeiro bloco a entrar é o primeiro a sair
- LFU (least frequently used) => substituir o bloco com menos referencias

Para substituir temos duas diferentes formas de escrita:

- Write-through => atualiza os vários níveis abaixo do cache, mas com um custo alto, o que pode causar gargalos.
- Write-back => atualiza somente o nível seguinte (custo menor), mas precisamos de um bit de controle para sabermos se alteramos a informação ou não

## Exercícios
> pag. 118, Computer Organization and Architecture: Designing for Performance (8th Edition), Stallings 

## 4.10

- Tamanho do endereco: log2(tamanho da memoria) = log2 (16MB) = log2(2^4 * 2^20) = 24
- Numero de unidades enderecaveis: 2^24
- Tamanho do bloco: 4B = 2^2. 2 bits
- Numero de blocos na RAM: 4M = 2^2 * 2^20 = 2^22
- Numero de linhas na cache: 16K = 2^4 * 2^10 = 2^14
- Tamanho da tag = log2(nro blocos da ram/nro de linhas na cache) = log2(2^22 / 2^14) = 8 bits

## 4.12

- Tamanho do endereco: log2(tamanho da memoria) = log2 (16MB) = log2(2^4 * 2^20) = 24 bits
- Numero de unidades enderecaveis: 2^24
- Tamanho do bloco: 4B = 2^2. 2 bits
- Numero de blocos na RAM: 4M = 2^2 * 2^20 = 2^22
- Numero de linhas na cache: o mapeamento associativo nao permite linhas
- Tamanho da tag = log2(numero de unidades enderecaveis / tamanho do bloco) = log2 (2^24 / 2^2) = 22 bits 

## 4.13

- Tamanho do endereco: log2(tamanho da memoria) = log2 (16MB) = log2(2^4 * 2^20) = 24 bits
- Numero de unidades enderecaveis: 2^24
- Tamanho do bloco: 4B = 2^2. 2 bits
- Numero de blocos na RAM: 4M = 2^2 * 2^20 = 2^22
- Numero de linhas no conjunto: k = 2
- Numero de conjuntos: m = kv => 2^14 = 2 * v => v = 2^14/2 = 2^13 => 13 bits p/ o conjunto no endereco
- Numero de linhas na cache: m = 2^14
- Tamanho da tag = 24 - 13 - 2  = 9 bits
