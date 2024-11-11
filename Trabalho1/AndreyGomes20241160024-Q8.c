/*
8) Faça um programa que implemente o jogo de batalha naval.
Ver o jogo em http://www.ludijogos.com/multiplayer/batalha-naval/ 
a) O   número   de   navios   de   guerra   deve   ser   um   parâmetro   global.   Precisando   aumentar   a
quantidade de navios, o programador deve apenas mudar esse valor. b) Deve   ter   pelo   menos   1
barco   de   tamanho   4,   1   de   tamanho   3,   3   barcos   de   tamanho   1.   Os   demais   barcos,   se   existirem
devem ser obrigatoriamente de tamanho 2.  Desta forma, o número mínimo de barco é: 5 barcos. 
c) O tabuleiro de cada jogador deve ser uma matriz 10 x 10. d) Cada   jogador,   no   início   do
jogo  deve  dizer  onde  vai posicionar,  cada  um  dos  seus barcos.  O  programa  deve  controlar  se os
barcos estão posicionados de forma correta e) Use  a  seguinte  configuração  para  representar  o
mapa: 
i.   [       ]   espaço em branco -> posição do mar sem nada (e.g. barco, tiro do oponente,
tiro do jogador. 
ii. [ N ] Navio posicionado 
iii. [ 0 ] Posição do navio abatida 
iv. [ X ] Tiro inválido 
f) O programa deve ter uma função para o jogador poder Listar o tabuleiro.
i. Em seu tabuleiro ele deve ver seus barcos, os tiros do oponente e os espaços em
branco. 
ii. No tabuleiro do adversário deve ver seus tiros certeiros e seus tiros errados 
g) O programa deve ter a função para o jogador atirar, onde ele deve escolher uma célula da
matriz para jogar. 
h) Cada jogador joga uma vez, depois é a vez do oponente. 
i) Vence o jogador que acertar todos os navios do oponente primeiro.
*/