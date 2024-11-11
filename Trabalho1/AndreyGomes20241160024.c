// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Andrey Gomes da Silva Nascimento
//  email: gomes.andrey.dev@gmail.com
//  Matrícula: 20241160024
//  Semestre: 2024.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "AndreyGomes20241160024.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#ifdef _WIN32 
  #include <windows.h>
#endif

DataQuebrada quebraData(char data[]);
int isLeap(int year);
int daysInM(int m, int y);
void noSpecials(char *text);

/*
## função utilizada para testes  ##

  somar = somar dois valores
  @objetivo
      Somar dois valores x e y e retonar o resultado da soma
  @entrada
      dois inteiros x e y
  @saida
      resultado da soma (x + y)
 */
int somar(int x, int y){
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
  @objetivo
      calcular o fatorial de um número
  @entrada
      um inteiro x
  @saida
      fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a){
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]){
  int datavalida = 1;
  // printf("%s\n", data);

  //quebrar a string data em strings sDia, sMes, sAno
  DataQuebrada newData = quebraData(data);
  if(newData.valido){
    int day = newData.iDia, month = newData.iMes, year = newData.iAno;

    if(day<1||day>31||month<1||month>12)datavalida=0;
    if(day==31&&daysInM(month,year)!=31)datavalida=0;
    if(month==2&&day>29)datavalida=0;
    if(month==2&&day==29&&daysInM(month,year)!=29)datavalida=0;

    // printf("%d %d %d\n", newData.iDia, newData.iMes, newData.iAno);
  }else datavalida = 0;

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]){
  //calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;
  if (q1(datainicial) == 0){
    dma.retorno = 2;
    return dma;
  }
  if (q1(datafinal) == 0){
    dma.retorno = 3;
    return dma;
  }
  DataQuebrada inicio, fim; 
  inicio = quebraData(datainicial);
  fim = quebraData(datafinal);
  //verifique se a data final não é menor que a data inicial
  if(fim.iAno < inicio.iAno || ( fim.iAno == inicio.iAno && fim.iMes < inicio.iMes) || ( fim.iAno == inicio.iAno && fim.iMes == inicio.iMes && fim.iDia < inicio.iDia)){
    dma.retorno = 4;
    return dma;
  }
  //verifique se ambas as datas são bissextas
  int leapStart = 0, leapEnd = 0;
  leapStart = isLeap(inicio.iAno);
  leapEnd = isLeap(fim.iAno);
  //calcule a distancia entre as datas

  //anos
  dma.qtdAnos = fim.iAno - inicio.iAno;

  //meses
  dma.qtdMeses = fim.iMes - inicio.iMes;
  if(dma.qtdMeses != 0){
    if(dma.qtdMeses < 0){
      dma.qtdMeses = dma.qtdMeses + 12;
      dma.qtdAnos--;
    }
  }
  //dias
  dma.qtdDias = fim.iDia - inicio.iDia;
  if(dma.qtdDias != 0){
    if(dma.qtdDias < 0){
      dma.qtdDias = dma.qtdDias + daysInM(inicio.iMes, inicio.iAno);
      if(leapStart == 1 && inicio.iMes == 2){
        dma.qtdDias--; //desconsiderar o bissexto nessa linha apenas
      }
      dma.qtdMeses--;
    }
    if((leapStart == 1 && inicio.iMes <= 2 && inicio.iDia < 29) 
      && ((fim.iAno==inicio.iAno&&fim.iMes>2)
        ||(fim.iAno>inicio.iAno&&fim.iMes<2))){
      dma.qtdDias++;
    }
    if((leapEnd == 1 && fim.iMes > 2)){
      dma.qtdDias++;
    }
  }

  // printf("Data inicial: %d/%d/%d\n", inicio.iDia, inicio.iMes, inicio.iAno);
  // printf("Data final: %d/%d/%d\n", fim.iDia, fim.iMes, fim.iAno);
  // printf("Diferenca em anos: %d\n", dma.qtdAnos);
  // printf("Diferenca em meses: %d\n", dma.qtdMeses);
  // printf("Diferenca em dias: %d\n", dma.qtdDias);
  //se tudo der certo
  dma.retorno = 1;
  return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
  int qtdOcorrencias = 0;
	char *checkText = malloc(sizeof(char)*strlen(texto));

	strcpy(checkText, texto);
	//retirar acentos
  noSpecials(checkText);

	if(isCaseSensitive==0){
		for(int i=0; checkText[i]!='\0'; i++){
			if(checkText[i]>='A'&&checkText[i]<='Z'){
				checkText[i]=checkText[i]+32;
			}
		}
		if(c>='A'&&c<='Z')c=c+32;
	}

	for(int i = 0; checkText[i]!='\0'; i++){
		if(checkText[i]==c)qtdOcorrencias++;
	}

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = 0;
    int posicao = 0;
    int len = strlen(strBusca);
    noSpecials(strTexto);
    noSpecials(strBusca);

    for(int i = 0; i<strlen(strTexto);){
      int achou = 0;
      if(strTexto[i]==strBusca[0]){
        achou=1;
        for(int j=i, k=0; k<len; j++,k++){
          if(strBusca[k]!=strTexto[j])achou=0;
        }
        if(achou){
          qtdOcorrencias++;
          posicoes[posicao] = i+1;
          posicao++;
          posicoes[posicao] = i+len;
          posicao++;

          i += len;
        }else{
          i++;
        }
      }
      if(!achou)i++;
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
	int numInvert=0;
	int digit=0;
	while(num!=0){
		digit = num%10;
		numInvert= numInvert*10+digit;
		num/=10;
	}
    return numInvert;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
  int qtdOcorrencias=0;
	int div = 1;
	while(numerobusca/div!=0)div*=10;
	while(numerobase!=0){
		if(numerobase%div==numerobusca){
			qtdOcorrencias++;
			numerobase/=div;
		}else numerobase/=10;
	}
    return qtdOcorrencias;
}




DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
    if(data[i]>='0'&&data[i]<='9'){
		  sDia[i] = data[i];	
    }else{
      dq.valido = 0;
      return dq;
    }
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
    if(data[j]>='0'&&data[j]<='9'){
		  sMes[i] = data[j];
		  i++;
    }else{
      dq.valido = 0;
      return dq;
    }
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
    if(data[j]>='0'&&data[j]<='9'){
      sAno[i] = data[j];
      i++;	
    }else{
      dq.valido = 0;
      return dq;
    }
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

int isLeap(int year){
    if(year%4 == 0 && year%100 != 0 || year%400 == 0)return 1;
    else return 0;
}

int daysInM(int m, int y){
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    else {
        if (m == 4 || m == 6 || m == 9 || m == 11)
            return 30;
        else if(m==2) {
            if (isLeap(y) == 1)
                return 29;
            else
                return 28;
        }else{
            return 0;
        }
    }
}

void noSpecials(char *text){
  int i, j=0;
  #ifdef _WIN32 
    SetConsoleOutputCP(CP_UTF8);
  #elif __linux__ 
	  setlocale(LC_ALL, "Portuguese");
  #else
  #endif

  const char *comAcentos[] = {"Ä", "Å", "Á", "Â", "À", "Ã", "ä", "á", "â", "à", "ã",
                                "É", "Ê", "Ë", "È", "é", "ê", "ë", "è",
                                "Í", "Î", "Ï", "Ì", "í", "î", "ï", "ì",
                                "Ö", "Ó", "Ô", "Ò", "Õ", "ö", "ó", "ô", "ò", "õ",
                                "Ü", "Ú", "Û", "ü", "ú", "û", "ù",
                                "Ç", "ç"};
                                
  const char *semAcentos[] = {"A", "A", "A", "A", "A", "A", "a", "a", "a", "a", "a",
                              "E", "E", "E", "E", "e", "e", "e", "e",
                              "I", "I", "I", "I", "i", "i", "i", "i",
                              "O", "O", "O", "O", "O", "o", "o", "o", "o", "o",
                              "U", "U", "U", "u", "u", "u", "u",
                              "C", "c"};

  char buffer[256];
  buffer[0] = '\0';

  for (int i = 0; i < strlen(text);) {
    int found = 0;
    // Tenta substituir cada caractere acentuado por seu equivalente
    for (int j = 0; j < sizeof(comAcentos) / sizeof(comAcentos[0]); j++) {
      int len = strlen(comAcentos[j]);

      if (strncmp(&text[i], comAcentos[j], len) == 0) {
        strcat(buffer, semAcentos[j]);
        i += len;
        found = 1;
        break;
      }
    }
    if (!found) {
      strncat(buffer, &text[i], 1);
      i++;
    }
  }
  strcpy(text, buffer);
}