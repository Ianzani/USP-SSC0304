# Jogo Batalha Naval

#### Autores:
Ian Zaniolo Sirbone (Ianzani)\
Lucas Daudt Franck  (LDFranck)

#### Descrição:
Projeto final da disciplina Introducao a Programacao para Eng. Elétrica (SSC0304).

Professor: Jo Ueyama\
Monitores: Erikson Julio de Aguiar & Ana Costa

#### Sobre o jogo:
As regras do jogo podem ser encontradas no site da [Hasbro](https://www.hasbro.com/common/instruct/battleship.pdf).

<i>Algumas modificações:</i>\
Numero de blocos de cada peça da armada foi alterada para se adequar ao tamanho do tabuleiro.\
Sistema de pontuação foi implementado para fins estatísticos (a vitória depende exclusivamente de afundar toda armada inimiga).\
Em ``ajuda`` você pode verificar o tamanho das peças assim como suas respectivas quantidades no jogo.

<i>Debug Helper: </i>\
Para utilizar o debug e terminar o jogo mais rapidamente é necessário compilar o arquivo ``debug_game.c`` com o nome de ``debug.exe`` e colocá-lo na mesma pasta do arquivo do jogo ``game.exe`` (``game.c`` pode ser compilado com qualquer nome).  
Uma vez feito isso, digitar dentro do jogo o comando: ``ssc0304``. Se as etapas anteriores foram feitas corretamente, todos os elementos da armada serão marcados com um ``x``. O jogador pode atirar manualmente em cada ``x`` ou rodar novamente o comando ``ssc0304``. Na segunda iteração o comando irá bombardear todos elementos marcados com ``x``, deixando apenas um último bloco.
