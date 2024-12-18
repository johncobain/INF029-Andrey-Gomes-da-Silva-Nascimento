#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10

#include "EstruturaVetores.h"


typedef struct pos{
    int *arr;
    int lastPos;
    int size;
}Pos;

Pos *mainArr;


// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int pos){
    return (pos < 1 || pos > 10)? POSICAO_INVALIDA : SUCESSO;
}
/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/
void inicializar(){
    mainArr = malloc(sizeof(Pos) * TAM);
    // inicializar com NULL
    for(int i = 0; i < TAM; i++){
        mainArr[i].arr = NULL;
        mainArr[i].lastPos = 0;
        mainArr[i].size = 0;
    }
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int pos, int size){
    // se posição é um valor válido {entre 1 e 10}
    if (ehPosicaoValida(pos)==POSICAO_INVALIDA) return POSICAO_INVALIDA;

    // a posicao pode já existir estrutura auxiliar
    if (mainArr[pos-1].arr != NULL) return JA_TEM_ESTRUTURA_AUXILIAR;
    
    // o tamanho nao pode ser menor que 1 
    if (size <= 0) return TAMANHO_INVALIDO;

    // deu tudo certo, crie
    mainArr[pos-1].arr = malloc(sizeof(int) * size);
    
    // se o ponteiro for NULL, significa que não tem espaço de memória
    if (mainArr[pos-1].arr == NULL) return SEM_ESPACO_DE_MEMORIA;

    mainArr[pos-1].lastPos = 0;
    mainArr[pos-1].size = size;

    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int pos, int val){
    bool isPosCreated = false;
    bool isFull = false;

    // testar se a posicao eh valida
    if(ehPosicaoValida(pos)==POSICAO_INVALIDA) return POSICAO_INVALIDA;

    // testar se existe a estrutura auxiliar
    if (mainArr[pos-1].arr != NULL) isPosCreated = true;
    if (!isPosCreated)return SEM_ESTRUTURA_AUXILIAR;

    // testar se tem espaço
    if (mainArr[pos-1].lastPos == mainArr[pos-1].size) isFull = true;
    if (isFull) return SEM_ESPACO;

    // insere
    mainArr[pos-1].arr[mainArr[pos-1].lastPos] = val;
    mainArr[pos-1].lastPos++;
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int pos){
    if(ehPosicaoValida(pos)==POSICAO_INVALIDA) return POSICAO_INVALIDA;
    
    if(mainArr[pos-1].arr == NULL) return SEM_ESTRUTURA_AUXILIAR;
    
    if(mainArr[pos-1].lastPos == 0) return ESTRUTURA_AUXILIAR_VAZIA;
    
    mainArr[pos-1].lastPos--;
    
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    NUMERO_INEXISTENTE - Número não existe
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int pos, int val){
    if(ehPosicaoValida(pos)==POSICAO_INVALIDA) return POSICAO_INVALIDA;

    if(mainArr[pos-1].arr == NULL) return SEM_ESTRUTURA_AUXILIAR;

    if(mainArr[pos-1].lastPos == 0) return ESTRUTURA_AUXILIAR_VAZIA;

    for(int i = 0; i < mainArr[pos-1].lastPos; i++){
        if(mainArr[pos-1].arr[i] == val){
            for(int j = i; j < mainArr[pos-1].lastPos; j++){
                mainArr[pos-1].arr[j] = mainArr[pos-1].arr[j+1];
            }
            mainArr[pos-1].lastPos--;
            return SUCESSO;
        }
    }
    
    return NUMERO_INEXISTENTE;
    
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;

    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar(){
    for(int i = 0; i < TAM; i++){
        if(mainArr[i].arr != NULL){
            free(mainArr[i].arr);
            mainArr[i].arr = NULL;
        }
    }
    free(mainArr);
    mainArr = NULL;
}
