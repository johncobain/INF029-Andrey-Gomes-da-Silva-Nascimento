#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int A[], int size);
void descobreMaiorMenor(int A[], int size, int *bigger, int *smaller);
void imprimeMaiorMenor(int num1, int num2);

int main(){
    int size = 10;
    int *A = malloc(size * sizeof(int));
    int bigger, smaller;

    preencherVetor(A, size);
    descobreMaiorMenor(A, size, &bigger, &smaller);
    imprimeMaiorMenor(bigger, smaller);
    
    return 0;
}

void preencherVetor(int A[], int size){
    for(int i = 0; i < size; i++){
        printf("Insira o valor na posicao %d: ", i);
        scanf("%d", &A[i]);
    }
}

void descobreMaiorMenor(int A[], int size, int *bigger, int *smaller){
    *bigger = A[0];
    *smaller = A[0];
    for(int i = 0; i < size; i++){
        if(A[i] > *bigger) *bigger = A[i];
        if(A[i] < *smaller) *smaller = A[i];
    }
}

void imprimeMaiorMenor(int num1, int num2){
    num1 > num2? printf("Maior: %d\nMenor: %d\n", num1, num2) : printf("Maior: %d\nMenor: %d\n", num2, num1);
}