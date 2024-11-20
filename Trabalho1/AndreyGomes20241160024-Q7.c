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
  // inicializa o tabuleiro
  for(i=0;i<3; i++){
    for(j=0; j<3; j++) board[i][j] = -1;
  }

  do{
    system("clear || cls");
    showBoard(board);
    int valid;
    do{
      valid = 0;
      if(player==0){
        printf("\nJogador X, informe sua jogada\\> ");
      }else{
        printf("\nJogador O, informe sua jogada\\> ");
      }
      gets(choice);
      if(choice[0]>='a' && choice[0]<='c') choice[0]-='a'-'A'; //forçar para maiuscula
      if(choice[0]>='A' && choice[0]<='C' && choice[1]>='1' && choice[1]<='3'){
        i = choice[0]-'A';
        j = choice[1]-'1';

        if(board[i][j]==-1){
          board[i][j] = player;
          valid = 1;
        }else{
          printf("\n\033[1;31mJogada inválida!\033[0m\n");
        }
      }else{
        printf("\n\033[1;31mJogada inválida!\033[0m\n");
      }
    }while(valid==0);

    player = !player;
    winner = checkBoard(board);
  }while (winner==-1);
  system("cls || clear");
  
  showBoard(board);
  if(winner==0) printf("\033[1;32m\nJogador X ganhou!\033[0m\n");
  else if(winner==1) printf("\033[1;32m\nJogador O ganhou!\033[0m\n");
  else printf("\033[1;32m\nEmpatou!\033[0m\n");
  return 0;
}

/*
 * Imprime o tabuleiro do jogo da velha em seu estado atual.
 * -1 representa uma celula vazia,
 * 0 representa uma celula ocupada pelo jogador X,
 * 1 representa uma celula ocupada pelo jogador O.
 */
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


/*
 * Verifica se houve um ganhador no jogo da velha.
 * Se houver um ganhador, retorna o número do jogador que ganhou (0 ou 1).
 * Se n o houver um ganhador, retorna -1.
 */
int checkBoard(int (*board)[3]){
  for(int i=0; i<3; i++){
    if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=-1) return board[i][0];
    if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=-1) return board[0][i];
  }
  if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=-1) return board[0][0];
  if(board[2][0]==board[1][1] && board[1][1]==board[0][2] && board[2][0]!=-1) return board[2][0];

  //verifica se houve empate
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(board[i][j]==-1) return -1;
    }
  }

  return 2;
}
