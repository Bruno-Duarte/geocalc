/*
 *Trabalho 1 de Introdução à Ciência da Computação - 2017.1
 *Bacharelado em Ciência da Computação 
 *Universidade Estadual do Ceará.
 *Prof. Leonardo Rocha
 *Aluno: Francisco Bruno Duarte Castro
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecavm.h"

void OpcoesVetores();
void OpcoesMatrizes();
void MenuInicial();
void MenuVetores();
void MenuMatrizes();
void Linha();

int main()
{
  int opcao;
  char opc [5];

  Linha(73);
  putchar('\n');
  puts("B E M - V I N D O !");
  puts("Realize calculos com vetores e matrizes");

  do {
      Linha(73);
      MenuInicial();
      putchar('\n');
      printf("Introduza sua opção: ");
      scanf("%s", opc);
      printf("\n");
      opcao = atoi(opc);
      Linha(73);
      switch (opcao) {
        case 1 : OpcoesVetores();  break;
        case 2 : OpcoesMatrizes(); break;
        case 3 : puts("Saindo do programa..."); break;
        default: puts("\nOpção INVÁLIDA!!!");
      }
    }
  while(opcao != 3);
}

void OpcoesVetores()
{
  vetor vX;
  vetor vY;
  int opcaov, num;
  char opcv[5];
  double escalar;

  do {
       Linha(73);
       MenuVetores();
       putchar('\n');
       printf("Introduza sua opção: ");
       scanf("%s", opcv);
       opcaov = atoi(opcv);
       putchar('\n');
       Linha(73);
       switch (opcaov) {
         case 1 : // Ler vetores
           Linha(73);
           printf("\nVETOR A\n"); 
           lervetor(&vX);
           Linha(73);
           printf("\nVETOR B\n");
           lervetor(&vY); break;
         case 2 : // Soma os vetores
           if (vX.n != vY.n)
             puts("\nImpossível realizar operação com vetores de tamanhos diferentes.\nPreencha novamente os vetores.");
           else 
             somavetor(vX, vY); break;
         case 3 : // Multiplica um dos vetores por um escalar
           puts("\nQue vetor você deseja multiplicar?\n\n1. VETOR A\n2. VETOR B");
           printf("\nIntroduza sua opção: ");
           scanf("%i", &num);
           if (num != 1 && num != 2)
             {
               puts("Opção INVÁLIDA!!!\nDigite Novamente.");
               break;
             }
           printf("\nIntroduza agora o escalar: ");
           scanf("%lf", &escalar);
           if (num==1)
             {
               Linha(73);
               prodescalar(vX, escalar);
             }
           else if (num==2)
             {
               Linha(73);
               prodescalar(vY, escalar);
             }
           break;
         case 4 : // Produto escalar entre dois vetores
           if (vX.n != vY.n)
             puts("\nImpossível realizar operação com vetores de tamanhos diferentes.\nPreencha novamente os vetores.");
           else
             prodvetor(vX, vY); break;
         case 5 : // Volta para o MENU INICIAL
           free(vX.vetor);
           free(vY.vetor); 
           puts("\nVoltando ao MENU INICIAL"); break;
         default: puts("\nOpção INVÁLIDA!!!");
         }
     }
  while(opcaov != 5);
}

void OpcoesMatrizes()
{
  matriz mA;
  matriz mB;
  matriz tA;
  matriz tB;
  int num, opcaom;
  char opcm[5];

  do { 
       Linha(73);
       MenuMatrizes();
       putchar('\n');
       printf("Introduza sua opção: ");
       scanf("%s", opcm);
       opcaom = atoi(opcm);
       Linha(73);
       switch (opcaom) {
         case 1 : // Ler matrizes
           printf("\nPreencha a MATRIZ A:\n\n");
	   lermatriz(&mA);
	   printf("\nPreencha a MATRIZ B:\n\n");
	   lermatriz(&mB);
	   printf("\nMATRIZ A:");
	   impmatriz(mA);
	   printf("\nMATRIZ B:");
	   impmatriz(mB); break;
         case 2 : // Somar matrizes
           if(mA.linha != mB.linha || mA.coluna != mB.coluna)
             puts("\nOpção INVÁLIDA!!!\nAs matrizes não possuem a mesma dimensão.");
           else
             somatriz(mA, mB); break;
         case 3 : // Produto entre matrizes
           if(mB.linha != mA.coluna)
             puts("\nComando INVÁLIDO!!!\nNão é possível realizar a multiplicação");
	   else
             prodmatriz(mA, mB); break;
         case 4 : // Transporta Matriz
           puts("\nQue matriz você deseja utilizar?\n\n1. MATRIZ A\n2. MATRIZ B");
           printf("\nIntroduza sua opção: "); scanf("%d", &num);
           if(num!=1 && num!=2)
             {
               puts("\nOpção INVÁLIDA!!!"); break;
             }
           else if(num==1)
             transmatriz(mA, &tA);
           else
             transmatriz(mB, &tB); break;
         case 5 : // Determinante de uma Matriz
           puts("\nQue matriz você deseja utilizar?\n\n1. MATRIZ A\n2. MATRIZ B");
           printf("\nIntroduza sua opção: "); scanf("%d", &num);
           if(num!=1 && num!=2)
             {
               printf("\nComando INVÁLIDO!!!\n"); break;
             } 
           else if(num==1)
             {
               if(mA.linha == mA.coluna)
                 determatriz(mA);
               else
                 {
                   puts("\nNão é possível calcular o determinante de matrizes onde a\nquantidade de linhas difere da quantidade de colunas.");
                   break;
                 }
             }
           else
             {
               if(mB.linha == mB.coluna)
                 determatriz(mB);
               else
                 {
                   puts("\nComando INVÁLIDO!!! Não é possível calcular o determinante"); break;
                 }
             }
           break;
         case 6 : // Verifica se a Matriz é simétrica
           puts("\nQue matriz você deseja utilizar?\n\n1. MATRIZ A\n2. MATRIZ B");
           printf("\nIntroduza sua opção: "); scanf("%d", &num);
           if(num != 1 && num != 2)
             {
               puts("\nDigite uma opção valida!!!"); break;
             }
           else if(num == 1)
             {
               transmatriz(mA,&tA);
               simematriz(mA,tA);
             }
           else
             {
               transmatriz(mB,&tB);
               simematriz(mB,tB);
             }
           break;
         case 7 : // Volta ao MENU INICIAL
           free(mA.matriz);
           free(mB.matriz);
           puts("\nVoltando ao MENU INICIAL");break;
         default: puts("\nOpção INVÁLIDA!!!");
         }
     } 
  while(opcaom != 7);
}

// Função que exibe o menu inicial do programa
void MenuInicial()
{
  printf("\nMENU INICIAL\n");
  printf("\n1. Operações com vetores");
  printf("\n2. Operações com matrizes");
  printf("\n3. SAIR\n");
}

// Função que exibe o menu de operações com vetores
void MenuVetores()
{
  printf("\nOPERAÇÕES COM VETORES\n");
  printf("\n1. Ler vetores");
  printf("\n2. Somar dois vetores");
  printf("\n3. Multiplicar um dos vetores por um escalar");
  printf("\n4. Realizar o produto escalar entre dois vetores");
  printf("\n5. VOLTAR\n");
}

// Função que exibe o menu operações com matrizes
void MenuMatrizes() 
{
  printf("\nOPERAÇÕES COM MATRIZES\n");
  printf("\n1. Ler matrizes");
  printf("\n2. Somar duas matrizes");
  printf("\n3. Multiplicar duas matrizes");
  printf("\n4. Calcular a transposta de uma matriz");
  printf("\n5. Calcular o determinante de uma matriz (Somente matriz 1X1, 2X2, 3X3)");
  printf("\n6. Verificar se uma matriz é simétrica");
  printf("\n7. VOLTAR\n");
}

// Função para imprimir uma linha de hífens
void Linha(int n)
{
  int i;
  for (i=0; i<=n; i++)
    putchar('_');
  putchar('\n');
}

