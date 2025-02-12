#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu(){
    int op;
    printf("Digite as opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar uma estrutura\n");
    scanf("%d", &op);
    return op;
}

int main(){

    inicializar();

    int op;
    int sair = 0;
    int ret;
    int pos,valor;

    while (!sair){
        op = menu();
        switch (op){
            case 0:{
                sair = 1;
                finalizar();
                break;
            }case 1:{
                printf("Digite uma posição da estrutura principal (1..10) e, em seguida, um número para inserir:\\> ");
                scanf("%d %d",&pos,&valor);
                criarEstruturaAuxiliar(pos,10);

                ret = inserirNumeroEmEstrutura(pos, valor);

                if (ret == SUCESSO){
                    printf("Inserido com sucesso\n");
                }else if (ret == SEM_ESPACO){
                    printf("Sem Espaço\n");
                }else if (ret == SEM_ESTRUTURA_AUXILIAR){
                    printf("Sem estrutura Auxiliar\n");
                }else if (ret == POSICAO_INVALIDA){
                    printf("Posição inválida para estrutura auxiliar\n");
                }
                break;
            }

            case 2:{
                printf("Insira a posição da estrutura principal da qual deseja remover um valor (1..10)\\> ");
                scanf("%d",&pos);
                ret = excluirNumeroDoFinaldaEstrutura(pos);
                if (ret == SUCESSO){
                    printf("Inserido com sucesso\n");
                }else if (ret == ESTRUTURA_AUXILIAR_VAZIA){
                    printf("estrutura vazia\n");
                }else if (ret == SEM_ESTRUTURA_AUXILIAR){
                    printf("Sem estrutura Auxiliar\n");
                }else if (ret == POSICAO_INVALIDA){
                    printf("Posição inválida para estrutura auxiliar\n");
                }
                break;
            }

            case 3:{
                int posicao, retorno;
                printf("Qual a estrutura a ser listada (1..10)\\> ");
                scanf("%d", &posicao);

                int qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

                if (qtd == POSICAO_INVALIDA){
                    printf("Posição inválida");
                }else{
                    int vetorAux[qtd];

                    retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

                    if (retorno == SUCESSO){
                        int i = 0;
                        for (; i < qtd; i++){
                            printf("%d ", vetorAux[i]);
                        }
                        printf("\n");
                    }
                }
                break;
            }

            default:{
                printf("opcao inválida\n");
            }
        }
    }
    return 0;
}