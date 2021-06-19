# Conjunto de instrucoes: modos e formatos de enderecamento
## Enderecamento
Temos varios tipos de enderecamento com diferentes tecnicas. A seguir temos as tecnicas mais utilizadas:
- Imediato
- Direto
- Indireto
- Registrador
- Indireto por registrador
- Deslocamento
- Pilha

### Imediato
Forma mais simples de enderecamento. O operando esta presente na instrucao, isto é, `Operando = A`. Normalmente utilizado para definir e utilizar constantes ou valores iniciais das variaveis. 

Sua vantagem é não ter nenhuma referencia de memoria, economizando um ciclo de memoria ou cache dentro da instrucao. Desvantagem é que o tamanho do numero é limitado ao tamanho do campo de endereço, que normalmente é pequeno.

### Endereçamento direto
Campo de endereço contém o endereço efetivo do operando: `EA = A`. A instrucao aponta para o operando dentro da memoria. 

Essa técnica é simples, mas o espaço de endereçamento é limitado.

### Endereçamento indireto
O tamanho do campo de endereço é normalmente menor que o tamanho da palavra, limitando o intervalo de endereços. POssui um campo de endereço que referencia o endereco de uma palavra na memoria que possui o endereço completo do operando. `EA = (A)`. 

O espaco de enderecamento é grande, mas requer multiplas referencias de memoria.

### Enderecamento de registradores
Semelhante ao enderecamento direto. A diferença é que o campo de endereço se refere a um registrador em vez um endereço da memoria principal. `EA = R`.

Apenas um campo de endereco é necessário e nenhuma referencia de memoria que consome tempo é necessária. Porém, o espaço de endereçamento é limitado.

### Endereçamento indireto por registradores
Analogo ao endereçamento indireto. A diferença é que o campo de endereço referencia um local de memoria ou um registrador, que fornece o endereço do operando na memoria principal. `EA = (R)`.

Tem um espaco de enderecamento grande, mas precisa de referencias extra de memoria em alguns casos.

Ela é flexível, mas como visto, complexa.

### Enderecamento por deslocamento
Forma muito boa que capta as melhores caracteristicas do enderecamento direto e indireto de registradores. `EA = A + (R)`. Requer uma instrucao com dois campos com pelo menos um explicito. O outro campo de endereco é somado a A, produzindo um endereco efetivo.

Temos tres tipos de endereçamento por deslocamento:
- Endereçamento relativo => registrador referenciado é o contador de programa (PC).
- Endereçamento por registrador base => registrador base possui um endereco de memoria principal e o campo de endereco contem um deslocamento (inteiro sem sinal) desse endereco.
- Indexacao => campo de endereco referencia um endereco da memoria principal e o registrador referenciado contem um deslocamento positivo desse endereço.

### Enderecamento de pilha
Pilha é um vetor linear de posições. Os itens sao adicionados no topo da pilha. Usa a tecnica de LIFO (last in first out). O ponteiro da pilha é mantido em um registrador.

## Formato de instrucoes
Deve incluir um opcode e, explicitamente ou implicitamente, zero ou mais operandos. O formato deve indicar o modo de enderecamento para cada operando.

### Tamanho da instrucao
Questão básica para o projeto. Afeta, e é afetada pelo tamanho de memoria, organizacao da memoria, estrutura do barramento, complexidade e velocidade do processador. Determina a riqueza e flexibilidade da maquina do ponto de vista do programador da linguagem de montagem.

Temos a troca de várias instruções com a necessidade de economizar espaço. São desejados:
- Mais opcodes e mais operandos => programas mais curtos podem ser escritos para executar uma determina tarefa
- Mais modos de endereçamento => maior flexibilidade ao programador para implementar certas funcoes
- Aumento do tamanho da memoria principal => poder endereçar intervalos de memorias maiores

É importante que o tamanho da instrucao seja multiplo do tamanho de um caractere.

### Alocação de bits
Como alocar os bits nesse formato? Para determinar o uso de bits de enderecamento temos os seguintes fatores:
- Numero de modos de enderecamento => modo de enderecamento pode ser implicito.
- Numero de operandos => menos enderecos podem produzir programas mais longos e "estranhos". 
- Registrador vs memoria => precisamos de registradores para que os dados possam ser tratados dentro do processador para serem processados. Com um registrador não consumimos nenhum bit de instrucao, mas requer muitas instrucoes. Com varios tambem nao consumimos tantos bits. Quanto mais registradores forem usados para referenciar operandos, menos bits sao necessarios (maioria das arquiteturas usam pelo menos 32 reg)
- Nro de conjuntos de registradores => atualmente as maquinas possuem 32 ou mais registradores dentro do conjunto. Podem ser usados para armazenar dados e enderecos p/ enderecamento por deslocamento.
- Intervalo de enderecos => para endecamento de memoria, o intervalo de enderecos que pode ser referenciado esta relacionado com o numero de bits de endereco. Isso impoe uma limitacao seria, que implica no desuso do enderecamento direto, No enderecamento por deslocamento esse intervalo esta aberto ate o tamanho do registrador de endereco, mas ainda é conveniente permitir deslocamento grandes.
- Granularidade do endereço => fator para endereços que referenciam memoria no lugar de registradores. Exige mais bits de endereço para um tamanho fixo de memoria

O projetista deve equilibrar esses fatores. Além disso para projetar o conjunto de instrucoes temos os principios de:
- Ortogonalidade => duas variaveis sao independentes. Outros elementos de instrucao não são determinados pelo opcode.
- Integridade => os tipos aritmeticos de dados devem ter um conjunto de operações completo e identico
- Enderecamento direto => o enderecamento com deslocamento deixa a organizacao da memoria a cargo do programador, o que fez com que fosse substituido pelo enderecamento direto

Isso implica em maior facilidade de programação.

### Instrucoes de tamanho variavel
Os exemplos vistos utilizavam um tamanho de instrucao fixo. Poderiamos ter optado por uma maior varidade de formatos de instrucoes de tamanhos diferentes. Instrucao de tamanho variavel permitem isso, um maior repertorio de instrucoes com diferentes combinacoes de referencias a registradores e a memoria e com modos de enderecamento, com varios opcodes de tamanhos diferentes. Essas variacao podem ser fornecidas de forma eficiente e compacta.

Porém, como é de se imaginar, essas instruçoes sao mais complexas que instrucao de tamanho fixo.

## Exercicios
1. O operando esta presente na propria instrucao. `Operando = A`

2. Campo de endereco contem o endereco efetivo do operando. A instrucao aponta para o operando dentro da memoria principal. `EA = A`

3. A instrucao possui um campo de endereco de uma palavra na memoria que por sua vez possui o endereco completo do operando presenta na memoria. `EA = (A)`

4. Semelhante ao enderecamento direto. A diferenca consiste no fato de que o campo de endereco se refere a um registrador em vez de um endereco na memoria principal. `EA = R`

5. Semelhante ao enderecamento indireto. A diferenca é que o campo de endereco referencia um registrador em vez de uma palavra na memoria, que por sua vez fornece o endereco do operando na meoria principal. `EA = (R)`

6. `EA = A + (R)`. Requer uma instrucao com dois campos com pelo menos um explicito. O outro campo de endereco é somado a A, produzindo um endereco efetivo.

7. Registrador referenciado é o contador de programa (PC). O endereco da proxima instrucao é adicionado ao campo de endereco para produzir EA.

8. É típico que haja uma necessidade de aumentar ou diminuir o registro de índice após cada referência a ele. Por ser uma operação tão comum, alguns sistemas irão faça isso automaticamente como parte do mesmo ciclo de instrução, usando a indexação automática.

9. Na pre indexacao, a indexacao é executada antes da instrução. Na pós indexacação, a indexação é executada após a instrução.

10. 
- Numero de modos de enderecamento 
- Numero de operandos 
- Registrador vs memoria 
- Nro de conjuntos de registradores
- Intervalo de enderecos 
- Granularidade do endereço

11. Temos um maior repertorio de opcodes com diferentes comprimentos. Maior combinacao de registros e mais modos de enderecamento a memoria principal, gerando um enderecamento mais flexivel. Porém, temos um aumento na complexidade da CPU.
