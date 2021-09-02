# Introducao

## Definicao

Uma rede de computadores é um sistema que liga dois ou mais computadores com o objetivo de realizar o compartilhamento de recursos, como arquivos, dados, programas etc.

## Componentes

Uma rede é composta por:

- Hardware: computadores, smartphones, roteadores, switches, servidores etc
- Software: TCP/IP, OpenFlow, HTTP, E-mail, Browsers, etc

Uma rede de computadores é o conjunto de hardware e software.

## Internet

A internet, por exemplo, é um exemplo de implementação de uma rede, onde temos os elementos de computação interligados. Essa rede é feita por enlaces de comunicação por fibra, rádio, satélite etc

<img src="https://lh3.googleusercontent.com/proxy/Yfhp8We-zD4BZUDHJmpAxcuMcWHlL6cjDMHathnchgunRVu7XNPUInmmZN2gaQPxjy_R-HkDHdMtTrUaP20DStiZM2fG9ddK-Q3fY3EQLed_6r_JH-RssH_e">

## Protocolo

As redes precisam de protocolos para padronizar a comunicação. Os protocolos definem as regras que estabelecem os formatos e a ordem das mensagens, assim como as ações que serão tomadas quando o usuário recebe a mensagem.

<img src="https://i.ytimg.com/vi/taL4GQ6E-Jw/maxresdefault.jpg">

## Estrutura da rede

Uma rede de computadores é composta por:

- Nucleo da rede: roteadores e rede de redes
- Borda da rede: aplicações e usuários
- Redes de acesso, meio físico: enlances de comunicação

### Borda da rede

Existem dois tipos de serviço numa borda de rede:

- Orientado à conexão: utiliza um protocolo que envia uma requisição que pode ser aceita ou não, por exemplo, o procolo TCP, onde a conexão deve ser criada antes da comunicação.
- Sem conexão: não há a necessidade de estabelecer uma conexão, por exemplo, o protocolo UDP.

TCP (com conexão): HTTP (Web), FTP (transferencia de arquivo), SMTP (e-mail) etc.

UDP (sem conexão): streaming media, teleconferencia, telefonia IP etc.

### Núcleo da rede

O núcleo da rede faz a interligação entre as redes, disponibilizando uma conexão/comunicação. São multiplos roteadores interconectados, podendo transferir dados das seguintes formas:

- Comutação de circuitos: usa um canal dedicado para cada conexão com uma rota fixa, definida antes da comunicação.

<img src="https://lh3.googleusercontent.com/proxy/G1vODMNwXbf4o15aTIjpw1IpFvOI91wMiZTXvcJT-SCvmZAf2gNQTGlN2-i3Pn7ZHrkd5z6tZa8-4kanSu7xErH5vo1soq8b3gG5NfHVmRcW853uFp8xGAfGnw">

- Comutação de pacotes: dados são enviados em "blocos" discretos, podendo mudar as rotas durante a comunicação.

<img src="https://lh3.googleusercontent.com/proxy/CsoiczpmvwPmNBZdsb6FrM9HgWDEOXmXdzVl99msiyy8yOUoqygfGbUKSa_npek_6_2oa7_G9gscF9SFICEcx8tdHQugXXvK8Xoinl-HIrSyWj97SIMWtMY">

### Roteamento

O objetivo do roteamento é mover pacotes entre roteadores da origem ao destino. Temos dois tipos diferentes de roteamento, em que um usa o endereço de destino enquanto o outro o ID do circuito para rotear pacotes.

- Redes de datagrama:

  - Endereço de destino determina o proximo salto
  - Rotas podem mudar durante uma sessão
  - Analogia: dirigir perguntando o caminho

- Rede de circuitos virtuais:

  - Cada pacote leva um número que determina o próximo salto
  - O caminho é fixo e escolhido no instante de estabelecimento da conexão, permanecendo fixo durante toda a conexão
  - Analogia: dirigir já sabendo a rota

Ambos possuem vantagens e desvantagens, por exemplo, numa rede de circuitos virtuais há a possibilidade de algumas rotas não serem utilziadas.
