# Performance de uma máquina

Para medir o desempenho de uma máquina nós temos duas principais métricas de desempenho: 
- Tempo de resposta => tempo para executar uma determinada tarefa
- Vazão ou throughput => transações, quantidade de tarefas executadas em uma unidade de tempo, etc. 

Sendo assim, para aumentar o desempenho precisamos melhorar as duas medidas acima, isto é, para melhorar o tempo de resposta e vazão, podemos melhorar o processador. Porém, para melhorar a vazão, podemos aumentar a quantidade de processadores.

Sabendo que o tempo de execução Te é dado por:


```
Te = Ciclos de Clock x Tempo de Ciclo = Ciclo de Clock / Taxas de Clock
```

Fica evidente que para diminuirmos o tempo de execução temos duas opções:

- Diminuir a quantidade de ciclos de clock
- Aumentar a taxa de clock ou diminuir o tempo de clock

Por muito tempo as empresas focaram em aumentar a taxa de clock, mas está diretamente relacionado a dissipação de calor, isto é, quanto maior o clock, maior a dissipação. Esse problema, chamado Barreira de Potência, fez as empresas começarem a focar mais na quantidade de cores que um processador possui. Contudo, esta estratégia para ser efetiva necessita de algumas mudanças no software utilizando a técnica de paralelismo, de modo a dividir as tarefas funcionais, o que diminui o tempo de execução (eu fiz uma analogia na minha cabeça com o merge sort, o qual utiliza a técnica de dividir e conquistar, sei que não é o mais adequado, mas para mim fez sentido para fazer uma relaçao mais prática).

Para ser mais específico, o tempo de execução de uma tarefa é definida por três fatores:

- Quantidade de instruções (IC)
- Numero de ciclos por instrução (CPI)
- Tempo de execução de cada ciclo
Assim, `Tcpu = IC x CPI x Tempo de cada Ciclo = (IC x CPI) / Taxas de Clock`

Sabendo que `Te = Numero de Ciclos * Tempo de cada ciclo` e que o numero de ciclos por instrução pode ser escrito como `CPI = Numero de Ciclos / Instrução`, então `Numero de Ciclos = CPI x Instrução = CPI x IC`. Substituindo na formula inicial, temos `Te = CPI x IC x Tempo de cada ciclo`.

Cada vez mais é perceptível o quanto é importante analisar o contexto de um problema. Digo isso porque se desejamos velocidade, podemos optar por um processador com um clock maior, principalmente se tratando do lado do cliente. Enquanto isso, se desejamos utilizar transações, movimentação de dados, multiplas tarefas complexas, ou seja, tarefas que estão principalmente ligadas ao lado do servidor, podemos dar preferência a um processador com um numero maior de cores.

 