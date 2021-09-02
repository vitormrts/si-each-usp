# Estruturas do sistema operacional

- Servicos
- Interface do usuario
- Chamadas de sistema
- Tipos de chamadas de sistema
- Programas do sistema
- Projeto e implementacao
- Estrutura
- Maquinas virtuais
- Geracao
- Boot

## Servicos

Um sistema operacional deve oferecer:

- Interface com o usuario (UI) => CLI, interface grafica c/ o usuario (GUI), batch
- Execucao de um programa => carregar, executar, terminar o processo normalmente ou anormalmente (erro)
- Operacoes de E/S => dispositivo de E/S (teclado, monitor, mouse etc)
- Manipulacao do sistema de arquivos => permissao p/ ler, gravar arquivos e diretorios, criar, excluir, pesquisar, listar, etc.
- Comunicacoes => poder trocar informacoes no mesmo computador ou numa rede
- Deteccao de erro => capacidade de monitorar, detectar, tomar a decisao necessaria, depurar...
- Alocacao de recursos => varios programas sao executados simultaneamente. Com isso, o SO deve ser capaz de gerenciar esses recursos
- Contabilidade => registro de recursos utilizados, permitindo melhorar a qualidade do sistema por meio dessa monitoracao
- Protecao e seguranca => Ter protecao significa ter a capacidade de controlar os recursos, garantindo o acesso restrito a determinadas operacoes, arquivos etc. Ja a seguranca se relaciona a ataques externos, como virus, malwares etc.

## Interface com o usuario

### Interface de comando - CLI

CLI permite a entrada direto de comando. As vezes isso e implementacao diretamente no kernel, outras vezes pelo SO. Podemos ter diversos tipos implementados (shells)

### Interface grafica - GUI

Interface mais amigavel e intuitiva ao usuario. Utilizacao de mouse, teclado, monitor. Representa os arquivos por meio de icones, alem de possuir diversos botoes interativos que permitem executar uma tarefa com alguns clicks, por exemplo.

## Chamadas do sistema

A chamada de sistema e uma interface de programacao p/ os servicos fornecidos pelo SO. Muitas vezes dentro de um programa desejamos realizar uma determinada funcao do sistema e, para isso, o SO disponibiliza uma API.

Essas chamadas normalmente sao escritas em uma linguagem de alto nivel (C ou C++), podendo ser chamadas por meio de uma API (Application Program Interface) de alto nivel, evitando a chamada direta do sistema. As tres APIs mais comuns sao a Win32 API para Windows, POSIX API para sistemas POSIX (UNIX, Linux e Mac OS) e Java API para a JVM.

### Tipos de chamada

- Controle de processo
- Gerenciamento de processo
- Gerenciamento de dispositivo
- Manutencao de informacoes
- Comunicacoes

## Programas do sistema

Os programas do sistema oferecem um ambiente de desenvolvimento e execucao do programa, podendo ser dividido em:

- Manipulacao de arquivo => criar, excluir, copiar, renomear, imprimir, listar
- Informacao de status => data, hora, memoria disponivel, desempenho, log, depuracao
- Modificacao de arquivo => editores de texto para criar e modificar arquivos, comandos especiais para pesquisar conteudo de arquivos ou realizar transformacoes do texto
- Suporte a linguagem de programacao => compiladores, assemblers, depuradores, interpretadores
- Carga e execucao do programa => carregadores, editores de vinculo e sistemas de depuracao para linguagem de alto nivel e de maquina
- Comunicacoes => conexoes virtuais entre processos, usuarios e sistemas de computacao
- Programas de aplicacao

## Projeto e implementacao

Inicialmente e necessario identificar os objetivos do usuario e os objetivos do sistema. Devemos escolher o hardware corretamente, pois ele vai ser afetado diretamente por ele.

O usuario espera que o SO seja conveniente de usar, facil de aprender, confiavel, seguro e rapido.

Alem disso, o sistema deve ser facil de projetar, implementar e manter, alem de ser flexivel, confiavel, livre de erro e eficiente.

Devemos separar a politica do mecanismo, isto e, o que sera feito e como fazer isso. A separacao da politica e do mecanismo e um principio muito importante, pois permite o maximo de flexibilidade se decisoes politicas tiverem que ser alteradas mais tarde, visto que o mecanismo pode ser reutilizado.

## Estrutura

### MS-DOS

Oferecer o maximo de funcionalidade no menor espaco.
Percebe-se que nao ha camadas bem definidas, podendo o aplicativo "conversar" diretamente com os drivers de dispositivos da BIOS, por exemplo.

<img src="https://image.slidesharecdn.com/ch02-130527092648-phpapp01/95/viso-geral-estruturas-do-sistema-operacional-27-638.jpg?cb=1370336734">

### Tecnica em camadas

O SO eh dividido em uma serie cde camadas. A camada mais baixa (camada 0) e o hardware, a mais alta (camada N) e a interface com o usuario.

<img src="https://aulas.nkosi.org/ipd/kernel.png">

### Sistema UNIX

Separado em Kernel, shell e a interface com o usuario. De modo geral, o usuario interage com o shell fazendo uma chamada de sistema, o qual interage com o kernel (mais baixo nivel no software) que conversa com os controladores de dispositivo (hardware).

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/6/6c/Unix-kernel.png/250px-Unix-kernel.png">

### Mac OS

<img src="https://slideplayer.com.br/slide/353191/2/images/31/Estrutura+do+Mac+OS+X.jpg">

## Modulos

Os SOs implementam modulos do kernel, que implementam determinadas tarefas utilizando orientacao a objetos, separando as responsabilidades e se comunicando com outros modulos por meio de interfaces conhecidas. Esses modulos sao carregados de acordo com a necessidade dentro do kernel.

<img src="https://2.bp.blogspot.com/-Q4z79I8Tmpo/Wqgju13lsNI/AAAAAAAABcg/vaGKsxd6JS83C_VLeRdBklhYDB6y_7HfACPcBGAYYCw/s1600/rwtw.png">

## Maquinas virtuais

Uma marquina virtual simula um ambiente computacional, ou seja, ela trata o hardware e o kernel do sistema operacional como se fossem somente um hardware.

Alem disso, ela cria a ilusao de multiplos processos, cada um executando em seu proprio processador com sua propria memoria (virtual).

Para utilizar esse metodo os recursos do computador fisico sao compartilhados para criar as maquinas virtuais.
