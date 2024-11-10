#include <stdio.h>
#include "AndreyGomes20241160024.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>

DiasMesesAnos q2(char datainicial[], char datafinal[]){
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
        dma.retorno = 2;
        return dma;
    }else if (q1(datafinal) == 0){
        dma.retorno = 3;
        return dma;
    }else{
        DataQuebrada dataFinalQ, dataInicialQ; //variáveis tipo DataQuebrada que irão armazenar os valores separados
        dataInicialQ = quebraData(datainicial); //chamada da função quebraData para quebrar data em dia, mês e ano
        dataFinalQ = quebraData(datafinal); //chamada da função quebraData para quebrar data em dia, mês e ano
        //verificando se a data final não é menor que a data inicial
        if(dataFinalQ.iAno < dataInicialQ.iAno || ( dataFinalQ.iAno >= dataInicialQ.iAno && dataFinalQ.iMes < dataInicialQ.iMes) || ( dataFinalQ.iAno >= dataInicialQ.iAno && dataFinalQ.iMes >= dataInicialQ.iMes && dataFinalQ.iDia < dataInicialQ.iDia )){
            dma.retorno = 4;
            return dma;
        }
        else{//calculando a distancia entre as datas
            int bissextoInicial = 0, bissextoFinal = 0;
            if(dataInicialQ.iAno %400 == 0||(dataInicialQ.iAno %4 == 0 && dataInicialQ.iAno %100 !=0)){ //testa se o ano inicial é bissexto
                bissextoInicial = 1;
            }
            if(dataFinalQ.iAno %400 == 0||(dataFinalQ.iAno %4 == 0 && dataFinalQ.iAno %100 !=0)){ //testa se o ano inicial é bissexto
                bissextoFinal = 1;
            }

            //Diferença de dias - 

            dma.qtdDias = dataFinalQ.iDia - dataInicialQ.iDia; // contabiliza o número de dias
            if(bissextoInicial==1 && dataInicialQ.iMes<=2 && dataInicialQ.iDia<29 && bissextoFinal == 0 && dataFinalQ.iMes>2){//aumenta em 1 a quantidade de dias caso o ano inicial seja bissexto e a data inicial seja antes do fim de fevereiro
                dma.qtdDias++;
            }
            if(bissextoFinal==1 && dataFinalQ.iMes>2 && dma.qtdDias !=0){//reduz em 1 a quantidade de dias caso o ano Final seja bissexto e a data Final seja após do fim de fevereiro
                dma.qtdDias--;
            }
            if(dma.qtdDias<0){//caso a diferença seja negativa (dia final < dia inicial), retira o sinal negativo
                dma.qtdDias= (-1)*dma.qtdDias;
            }

            //Diferença de meses - Validado

            dma.qtdMeses = dataFinalQ.iMes - dataInicialQ.iMes; // contabiliza o número de meses
            if(dataInicialQ.iDia>dataFinalQ.iDia && dma.qtdMeses==1){//exclui casos onde o mês é diferente entre as datas, mas não se completou um mês de diferença
                dma.qtdMeses = 0;
            }

            if(dma.qtdMeses<0){//caso a diferença seja negativa (mês final < mês inicial), retira o sinal negativo
                dma.qtdMeses= (-1)*dma.qtdMeses;
            }

            //Diferença de anos - Validado

            dma.qtdAnos = dataFinalQ.iAno - dataInicialQ.iAno; // contabilizando o número de anos
            if(dataInicialQ.iAno>dataFinalQ.iAno && dma.qtdAnos==1){//exclui casos onde o ano é diferente entre as datas, mas não se completou um ano de diferença
                dma.qtdAnos = 0;
            }

            if(dma.qtdAnos<0){//caso a diferença seja negativa (ano final < ano inicial), retira o sinal negativo
                dma.qtdAnos = 0;
            }

            dma.retorno = 1;
            return dma;
        }

    }
    
}