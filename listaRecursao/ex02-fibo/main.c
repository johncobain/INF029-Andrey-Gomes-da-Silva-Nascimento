#include <stdio.h>
#include <stdlib.h>

long int fibo(int n){
  if(n<=1) return n;
  return fibo(n-1) + fibo(n-2);
}

int main(){
  int n;
  long int ret;
  printf("Insira o número\\> ");
  scanf("%d", &n);
  ret = fibo(n);
  printf("O %dº termo da sequencia é %ld\n", n, ret);
  return 0;
}