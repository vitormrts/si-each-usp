# Sistemas Operacionais

O sistema de computacao pode ser dividido em:

- Hardware: CPU, memoria, dispositivos de E/S
- Sistema operacional: controlar e coordenar o uso do hardware e de diversas aplicacoes
- Programas de aplicacao: processadores de texto, compiladores, navegadores web, sistemas de banco de dados, jogos etc
- Usuarios: pessoas, maquinas, outros computadores

## Definicao

O Sistema Operacional é um `alocador de recursos`, isto é, gerencia todos os recursos ao mesmo tempo que lida com solicitações em conflito p/ um uso eficaz e justo desse recurso.

Além disso, ele também é um `programa de controle`, o qual controla a execução dos programas p/ impedir erros e mau uso do computador.

O único programa que roda o tempo todo no computador é o `kernel`, o núcleo do SO. O restante são programas do sistema nativos ou instalados.

## Inicializacao do Computador

O programa de `bootstrap` é carregado na inicialização. Ele busca o endereço de memória do SO, como se fosse um "pontapé inicial", carregando o kernel do sistema operacionais e iniciando a execução. O bootstrap é armazenado, geralmente, na ROM ou EPROm, locais conhecidos como firmware.

## Organizascao do sistema de computacao

A CPU, HDs, dispositivos de E/S são conectados por meio de um barramento comum, oferecendo acesso à memória compartilhada.

- Os dispositivos de E/S e a CPU podem ser executados simultaneamente
- Cada controlador de dispositivo está encarregado de um tipo de dispositivo em particular
- Cada controlador de dispositivo possui um buffer
- A CPU move da memoria principal p/ os buffers locais e vice-versa
- E/S move do dispositivo p/ o buffer local do controlador e vice-versa
- O controlador de dispositivo informa a CPU que terminou a operação causando uma `interrupção`.

## Funcoes comuns das interrupções

A interrupção transfere o controle para a rotina de atendimento de interrupção, por meio do vetor de interrupçao, que contem os endereços de todas rotinas de servico.

Por se tratar de uma fila de interrupçao, a interrupcao que chega é desativada enquanto outra interrupcao está sendo processada, evitando uma interrupção perdida.

O sistema operacional preserva o estado da CPU, isto é, armazena o conteúdo dos registradores e o PC quando é gerada a interrupção, salvando o processo anteriormente a realizar esse processo. Cada tipo de interrupção deve ser tratada de forma específica.

## Estrutura de armazenamento

- Memoria principal: CPU acessa diretamente. É um acesso rápido e limitado.
- Armazenamento secundário: extensão da memóra principal que oferece grande capacidade de armazenamento não volátil
- Discos magnéticos: placas rígidas de metal ou vidro, cobertas com maerial de gravação magnética

Os sistemas de armazenamento sao organizados em velocidade, custo e volatidade.

Um outro método p/ garantir uma maior velocidade é o `caching`, uma cópia de informações num sistema de armazenamento mais rápido. Esse cache é armazenado, por exemplo, no processador, e armazena os dados mais utilizados ou recentemente utilizados. A memória RAM pode ser vista como um cache p/ a memória secundária, por exemplo.

## Estrutura do SO

A multiprogramacao é necessária para a eficiência. Ela pode mudar de um processo p/ outro, sem precisar encerrar o atual ou completar para iniciar outro.

A CPU alterna os jobs com uma certa frequência por meio do swap, permitindo uma computação interativa ao usuário, permitindo que ele intereja com várias aplicações simultaneamente.
