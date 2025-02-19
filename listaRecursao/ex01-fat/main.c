#include <stdio.h>
#include <stdlib.h>

long int fat(int n){
  if(n==0) return 1;
  return n * fat(n-1);
}

int main(){
  int n;
  long int fatRet;
  printf("Insira um número\\> ");
  scanf("%d", &n);
  fatRet = fat(n);
  printf("O fatorial de %d é %ld\n", n, fatRet);
  return 0;
}