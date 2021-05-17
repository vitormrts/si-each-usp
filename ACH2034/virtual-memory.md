# Memória Virtual
A memória virtual é um modo de utilizar a memória principal como uma cache p/ a memória secundário. Essa técnica foi motivada por duas questôes:

- Compartilhamento de memória por diversos programas em tempo de execução simultaneo
- Permitir que um programa exceda o tamanho da memoria principal

Antes de tudo é necessário entender que embora cache e memória virtual tenham conceitos parecidos, são utilizadas diferentes terminologias.

- Bloco de memoria = página. Cada página possui um número de página e um offset de página (o nro de bits de offset determina o tamanho da pagina).
- Falha = falta de página

Além disso a memória virtual possui um endereçamento virtual, isto é, um endereço que corresponde a um local no espaço virtual que é mapeado um endereço físico quando é acessado. Como o numero de páginas endereçaveis não precisam coincidir em relação ao numero de paginas endereçaveis no endereço fisico, temos a ilusão de que a memória é infinita.

A falta de página é extremamente cara, pois pode levar milhões de ciclos de clock para ser processada. Com isso, são necessárias/desejadas técnicas para reduzir essa taxa de penalidade. Algumas dessas técnicas são:

- Tornar o posicionamento totalmente associativo, visto que esse posicionamento permite que uma página seja alocada em qualquer local da memória
- Criação de uma tabela de páginas (mais detalhada abaixo)

Embora a técnica de posicionamento associativo seja extremamente útil, temos uma dificuldade: localizar a entrada. Tendo isso em mente, cada programa possui uma tabela de páginas, isto é, uma tabela que indexa cada página de acordo com o número de página virtual, o que permite descobrir onde se localiza na memória física. Temos um registrador que aponta para o início dessa tabela de páginas, além de 1 bit que valida se a página está presente na memória física ou não.

Quando temos uma falta de página, isto é, o bit validador de uma página virtual na tabela de páginas é igual a 0, precisamos buscar essa página na memória secundária, pois ela não está presente na memória física. Em casos de substituição de páginas são utilizadas as técnicas de LRU e bit de referência.

Vale ressaltar que a única política escrita válida é a write-back, pois ela realiza escritas individuais que não são tão custosas.

As tabelas de páginas podem ser acessadas mais rapidamente por meio de uma cache dita TLB (translation-lookaside buffer). Essa cache utiliza o princípio da localidade temporal, ou seja, se uma página foi utilizada recentemente, provavelmente ela será utilizada e posteriormente traduzida novamente.

Quando fazemos uma referencia consultamos o numero de pagina virtual na TLB. Em caso de miss temos duas possibilidades:

- Falta de pagina
- Simples falha na TLB (não está registrada na cache)

Para identificar basta observar o bit validador. Se for 0, a página não está presente na memória física, então temos que buscá-la na memória secundária. Caso contrário, temos que criar a entrada de TLB para a página.