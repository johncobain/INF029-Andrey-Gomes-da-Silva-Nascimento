/*
7) Fazer um programa que implementa o jogo da velha. 
a) O   programa   deve   sempre   mostrar   o   tabuleiro   do   jogo   da   velha,   com   o   jogador   que   deve
jogar, da seguinte forma: 
    1    2    3
A     |     |
  ----+-----+----
B     |     |
  ----+-----+----
C     |     |

Jogador 2, informe sua jogada: 
b) Cada jogador (jogador 1 e jogador 2) terá sua vez de jogar. O jogador um tem a marca “X” e o
jogador 2 a marca “0”. 
c) O jogador deve informar a célula de interesse: ex: B3. O programa deve verificar se é uma
célula válida 
d) O programa deve informar qual foi o ganhador, ou se não houve ganhador
*/
#include <stdlib.h>
#include <stdio.h>

void showBoard(int (*board)[3]);
int checkBoard(int (*board)[3]);

int main(){
  int board[3][3];
  int winner = -1;
  int player = 0;
  char choice[2];

  int i, j;
  for(i=0;i<3; i++){
    for(j=0; j<3; j++) board[i][j] = -1;
  }

  do{
    showBoard(board);
    winner = checkBoard(board);
  }while (winner==-1);
  
  return 0;
}

void showBoard(int (*board)[3]){
  char columns[3] = {'A', 'B', 'C'};
  printf("\n     ------TIC-TAC-TOE------\n");
  printf("\t1\t2\t3\n\n");
  for(int i = 0; i<3; i++){
    printf("%c", columns[i]);
    for(int j=0; j<3; j++){
      if(board[i][j]==0){
        printf("\tX");
      }else if(board[i][j]==1){
        printf("\tO");
      }else{
        printf("\t ");
      }
      if(j<2)printf("   |");
      else printf("\n");
    }
    if(i<2)printf("     -------+-------+-------\n");
  }
}

int checkBoard(int (*board)[3]){
  return 0;
}