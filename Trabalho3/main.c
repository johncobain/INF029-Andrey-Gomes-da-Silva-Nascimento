#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu();

void dobrar(int *x);

int menu()
{
    int op;
    printf("Digite as opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar uma estrutura\n");
    printf("5 - \n");
    scanf("%d", &op);
    return op;
}

int main()
{
    // ***Abertura do arquivo***
    const char *save = "dados.txt"; // ponteiro para armazenar o nome do arquivo
    FILE *fp; // ponteiro para apontar para o arquivo
    fp = fopen(save, "r"); // Abre o arquivo no modo leitura para verificar se existe
    if(fp == NULL){
        printf("Arquivo '%s' não encontrado. Criando um novo arquivo.\n", save);
        fopen(save, "w"); // Abre o arquivo no modo escrita para criar ele
        if (fp == NULL) {
            perror("Erro ao criar o arquivo");
            return 1;
        }
        printf("Arquivo '%s' criado com sucesso.\n", save);
    }
    fclose(fp); // Fecha o arquivo aberto

    inicializar();
    
    // ***Leitura do arquivo***
    lerArquivo(save);

    int op;
    int sair = 0;
    int ret;
    int pos,valor;

    while (!sair)
    {
        op = menu();
        switch (op)
        {
        case 0:
        {
            sair = 1;
            
            // ***Salvamento dos dados no arquivo***
            ret = salvarArquivo(save);
            if(ret == 1){
                printf("Arquivo salvo com sucesso\n");
            }
            else{
                printf("Erro ao salvar\n");
            }

            finalizar();
            break;
        }
        case 1:
        { //inserir
            printf("Digite uma posição da estrutura principal (1..10) e, em seguida, um número para inserir:\t");
            scanf("%d %d",&pos,&valor);
            // criar estrutura
            criarEstruturaAuxiliar(pos,10);

            ret = inserirNumeroEmEstrutura(pos, valor);

            if (ret == SUCESSO)
            {
                printf("Inserido com sucesso\n");
            }
            else if (ret == SEM_ESPACO)
            {
                printf("Sem Espaço\n");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura Auxiliar\n");
            }
            else if (ret == POSICAO_INVALIDA)
            {
                printf("Posição inválida para estrutura auxiliar\n");
            }
            break;
        }

        case 2:
        { //excluir
            printf("Insira a posição da estrutura principal da qual deseja remover um valor (1..10):\t");
            scanf("%d",&pos);
            ret = excluirNumeroDoFinaldaEstrutura(pos);
            if (ret == SUCESSO)
            {
                printf("Inserido com sucesso\n");
            }
            else if (ret == ESTRUTURA_AUXILIAR_VAZIA)
            {
                printf("estrutura vazia\n");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura Auxiliar\n");
            }
            else if (ret == POSICAO_INVALIDA)
            {
                printf("Posição inválida para estrutura auxiliar\n");
            }
            break;
        }

        case 3:
        { //recuperar dados estrutura auxiliar
            int posicao, retorno;
            printf("Qual a estrutura a ser listada (1..10)?");
            scanf("%d", &posicao);

            int qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

            if (qtd == POSICAO_INVALIDA)
            {
                printf("Posição inválida");
            }
            else
            { // existe elemento
                int vetorAux[qtd];

                retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

                if (retorno == SUCESSO)
                {
                    //imprimir para os dados para o usuário
                    int i = 0;
                    for (; i < qtd; i++)
                    {
                        printf("%d", vetorAux[i]);
                    }
                }
            }
            break;
        }

        default:
        {
            printf("opcao inválida\n");
        }
        }
    }

    return 0;
}