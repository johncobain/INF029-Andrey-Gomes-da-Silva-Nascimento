#include <stdio.h>
#include <stdlib.h>

int insereCaractere(char A[], int TAM, int *sent);
int trocaCaractere(char A[], int sent, char *ctroca);
int removeCaracteres(char A[], int *sent);
void listaCaracteres(char A[], int sent);
void printDistintos(char A[], int sent);   

int main(){
    int TAM = 10, sent = 0, option;
    char *A = malloc(TAM * sizeof(char));
    char cTroca = ' ';
    A[sent] = '\0';

    do{
        printf("\n1 - Inserir caractere\n2 - Trocar caractere\n3 - Remover caractere\n4 - Listar caracteres\n5 - Listar caracteres distintos\n0 - Sair\n");
        scanf("%d", &option);
        switch(option){
            case 0: printf("\nSaindo...\n"); break;
            case 1:{
                int inserido = insereCaractere(A, TAM, &sent); 
                inserido? printf("\nCaractere inserido com sucesso!\n") : printf("\nNao foi possivel inserir o caractere!\n");
                break;
            }
            case 2: {
                int trocado = trocaCaractere(A, sent, &cTroca); 
                if(trocado) printf("\nCaractere %c trocado com sucesso!\n", cTroca);
                else printf("\nNao foi possivel trocar o caractere!\n");
                break;
            }
            case 3:{
                int removido = removeCaracteres(A, &sent); 
                removido? printf("\nCaractere removido com sucesso!\n") : printf("\nNao foi possivel remover o caractere!\n");
                break;
            }
            case 4: listaCaracteres(A, sent); break;
            case 5: printDistintos(A, sent); break;
            default: printf("\nOpcao invalida!\n");
        }
    }while(option != 0);

    return 0;
}

int insereCaractere(char A[], int TAM, int *sent){
    char ch;
    if(*sent == TAM) return 0;
    printf("\nInsira o caractere\\> ");
    scanf(" %c", &ch);
    A[*sent] = ch;
    (*sent)++;
    A[*sent] = '\0';
    return 1;
}

int trocaCaractere(char A[], int sent, char *ctroca){
    char ch;
    printf("\nInsira o caractere que deseja trocar\\> ");
    scanf(" %c", &ch);
    for(int i = 0; i < sent; i++){
        if(ch>A[i]){
            *ctroca = A[i];
            A[i] = ch;
            return 1;
        }
    }
    return 0;
}

int removeCaracteres(char A[], int *sent){
    int qtd;
    printf("\nQuantos caracteres deseja remover\\> ");
    scanf("%d", &qtd);
    if(*sent-qtd<0) return 0;
    *sent -= qtd;
    A[*sent] = '\0';
    return 1;
}

void listaCaracteres(char A[], int sent){
    printf("\n");
    for(int i = 0; i < sent; i++) printf("%c ", A[i]);
    printf("\n");
}

void printDistintos(char A[], int sent){
    int *rep = malloc(sent * sizeof(int)); char *ch = malloc(sent * sizeof(char));
    for(int i = 0; i < sent; i++){ ch[i] = '\0'; rep[i] = 0; }
    for(int i = 0; i < sent; i++){
        int j = 0;
        for(j = 0; ch[j] != '\0'; j++)if(A[i] == ch[j]) break;
        ch[j] = A[i];
        rep[j]++;
    }
    for(int i = 0; ch[i] != '\0'; i++) printf("%c: %d\n", ch[i], rep[i]);
}