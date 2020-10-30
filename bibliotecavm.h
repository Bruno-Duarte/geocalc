/*
 *Trabalho 1 de Introdução à Ciência da Computação - 2017.1
 *Bacharelado em Ciência da Computação 
 *Universidade Estadual do Ceará.
 *Prof. Leonardo Rocha
 *Aluno: Francisco Bruno Duarte Castro
 */

#ifndef BIBLIOTECAVM_H_INCLUDED
#define BIBLIOTECAVM_H_INCLUDED
#endif  // BIBLIOTCAVM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


//BIBLIOTECA DE FUNÇÕES PARA MANIPULAÇÃO DE VETORES E MATRIZES

// Declaração das Structs

// Struct para Vetor

typedef struct
{
  int n;
  double *vetor;
}vetor;

// Struct para Matriz

typedef struct
{
 int linha;
 int coluna;
 double **matriz;
}matriz;

// Declarações das funções para operação com vetores

// Função para leitura de vetores
void lervetor(vetor *v);
// Função para somar dois vetores
void somavetor(vetor vX, vetor vY);
// Função para multiplicar um vetor por um escalar
void prodescalar(vetor vX, double escalar);
// Função que realiza o produto escalar entre dois vetores
void prodvetor(vetor vX, vetor vY);

// Declarações das funções para operação com matrizes

// Função para leitura de matrizes
void lermatriz(matriz *m);
// Função para imprimir uma matriz
void impmatriz(matriz m);
// Função para somar duas matrizes
void somatriz(matriz mA, matriz mB);
// Função para multiplicar duas matrizes
void prodmatriz(matriz mA, matriz mB);
// Função para calculo da trasposta de uma matriz
void transmatriz(matriz m, matriz *t);
// Função para calcular o determinante de uma matriz
void determatriz(matriz m);
// Função para verificar se uma matriz é simétrica
void simematriz(matriz m, matriz t);


// Definição das funções

// Função para Leitura de Vetores
void lervetor(vetor *v)
{
  int i; // variável de controle
  
  //pede ao usuário para introduzir o número de elementos do vetor e faz a captura
  printf("\nIntroduza o número de elementos do Vetor: "); scanf("%i", &v->n);
  putchar('\n');

  // Aloca um vetor de ponteiros
  v->vetor = (double*) malloc(v->n * sizeof(double));

  if(v->vetor == NULL) // Condições de preenchimento dos vetores
    printf("\n\nNão é possível operar com valores nulos ou com caracteres!!!\n\n");
  else
  //inicio do laço de preenchimento do vetor
  for(i=0; i<v->n; i++){
    //pede ao usuário para introduzir os valores do vetor e faz a captura
    printf("Introduza o valor do vetor na posição [%i]: ", i+1); scanf("%lf", &v->vetor[i]);
  }
}

//Função para somar dois Vetores
void somavetor(vetor vX, vetor vY)
{
  int i; // variável de controle
  double soma[vX.n]; //cria um vetor soma

  //inicio do laço que faz a soma vetorial
  for(i = 0; i<vX.n; i++)
    //calcula a soma e armazena no vetor
    soma[i] = vX.vetor[i] + vY.vetor[i];

  //imprime uma mensagem antes do inicio do vetor
  printf("\nVetor resultante: ");

  //inicio do laço for para imprimir o novo vetor
  for(i = 0; i<vX.n; i++)
    //imprime o vetor soma
    printf("%.1lf ", soma[i]);
  printf("\n");
}

//Função para realizar o Produto de um Escalar por um Vetor
void prodescalar(vetor vX, double escalar) 
{
  int i; // Variável de controle 
  double prod[vX.n]; //cria um vetor para produto

  //inicio do laço que percorre o vetor e calcula o produto
  for(i=0; i<vX.n; i++)
    //calcula o produto e armazena no vetor
    prod[i] = vX.vetor[i] * escalar;

  //imprime uma mensagem antes do inicio do vetor
  printf("\nVetor resultante: ");

  //inicio do laço que imprime o produto
  for(i = 0; i<vX.n; i++)
    //imprime o vetor produto
    printf("%.1lf ", prod[i]);
  printf("\n");
}

//Função para realizar o Produto Escalar entre dois Vetores
void prodvetor(vetor vX, vetor vY) 
{
  int i; // variável de controle
  double prodVet[vX.n]; //cria um vetor pra produto
  double soma=0; //cria uma variavel para armazenar a soma dos produtos

  //inicio do laço que faz as multiplicações
  for(i = 0; i<vX.n; i++)
    {

      //realiza as multiplicações em cada indice do vetor
      prodVet[i] = vX.vetor[i] * vY.vetor[i];

      //soma os produtos
      soma += prodVet[i];
    }

  //imprime o resultado
  printf("\nProduto entre os vetores: %.1lf\n\n", soma);
}

//Função para ler Matrizes
void lermatriz(matriz *m) 
{
  //pede pro usuário informar o numero de linhas da matriz e faz a captura
  printf("Introduza o número de linhas da Matriz: "); scanf("%i", &m->linha);

  //pede pro usuario informar o numero de colunas da matriz e faz a captura
  printf("Introduza o número de colunas da Matriz: "); scanf("%i", &m->coluna);
  putchar('\n');

  //variaveis de controles do for
  int i, j;

  // Aloca um vetor de ponteiros para as linhas
  m->matriz = (double**) malloc(m->linha * sizeof(double));

  if(m->matriz == NULL)
    {
      printf("Introduza valores válidos!\n\n");
    }
  else
    {
      //inicio do laço for i
      for(i = 0; i<m->linha; i++)
        {
          // Aloca um vetor de ponteiros para cada linha. (Colunas)
          m->matriz[i] = (double*) malloc(m->coluna * sizeof(double));

          if(m->matriz == NULL)
            {
              printf("Memória insuficiente.\n\n");
            }
          else
            {
              //inicio do laço for j
              for(j = 0; j<m->coluna; j++)
                {
                  //pede ao usuario para digitar o elemento [i][j] da matriz
                  printf("Introduza o valor do elemento [%i][%i]: ", i+1, j+1);

                  // lê o elemento [i][j] da matriz
                  scanf("%lf", &m->matriz[i][j]);
                }
            }
        }
    }
}

//Função para imprimir Matrizes
void impmatriz(matriz m)
{
  //variaveis de controles do for
  int i, j;

  printf("\n__________________________________________________________________________\n\n");

  //inicio do for i
  for(i=0; i<m.linha; i++)
    {
      //inicio do for j
      for(j=0; j<m.coluna; j++)
        //imprime o elemento [i][j] da matriz
        printf("%.1lf  ", m.matriz[i][j]);

        //Quebra de linha
        printf("\n");
  }

  //imprime uma linha de hifens
  puts("__________________________________________________________________________");
}

//Função para somar Matrizes
void somatriz(matriz mA, matriz mB)
{
  //variaveis de controle do for
  int i, j;

  //cria uma matriz para a soma
  double soma[mA.linha][mA.coluna];

  //inicio do laço for i
  for(i=0; i<mA.linha; i++)
    {
      //inicio do laço for j
      for(j=0; j<mA.coluna; j++)
      //armazena o valor da soma na matriz de soma
      soma[i][j] = mA.matriz[i][j] + mB.matriz[i][j];
    }
  //imprime uma linha de hifens
  printf("\n__________________________________________________________________________\n\n");
  puts("Soma entre as matrizes:\n");
  //inicio do laço for i
  for(i=0; i<mA.linha; i++)
    {
      //inicio do laço for j
      for(j=0; j<mA.coluna; j++)
        //imprime o elemento [i][j] da matriz soma
        printf("%.1lf  ", soma[i][j]);
        //imprime uma quebra de linha
        printf("\n");
    }
}


//Função para multiplicar Matrizes
void prodmatriz(matriz mA, matriz mB) 
{
  //variaveis de controle do for
  int i, j, k;

  //cria uma matriz para o produto
  double prod[mA.linha][mA.coluna];

  //inicio do laço for i
  for(i=0; i<mA.linha; i++)
{
    //inicio do laço for j
    for(j=0; j<mB.coluna; j++)
      {
        //inicializa o valor de [i][j] como 0
        prod[i][j] = 0;

          //inicio do laço for k
          for(k = 0; k<mB.linha; k++)

          //o elemento [i][j] da matriz produto recebe ele mesmo mais o produto das linhas pelas colunas
          prod[i][j] +=  mA.matriz[i][j] * mB.matriz[i][j];
    }
  }
  //imprime uma linha de hifens
  printf("\n__________________________________________________________________________\n\n");
  printf("Produto entre as matrizes:\n\n");

  //inicio do laço for i
  for(i=0; i<mA.linha; i++)
{
    //inicio do laço for j
    for(j=0; j<mB.coluna; j++)
      //imprime o elemento [i][j] da matriz produto
      printf("%.1lf  ", prod[i][j]);

      //imprime uma quebra de linha
      printf("\n");
  }
}

//Função para calcular transposta
void transmatriz(matriz m, matriz *t)
{
  //variaveis de controle laço do for
  int i, j;

  //inicializa o numero de linhas e colunas da matriz transposta
  t->linha = m.coluna;
  t->coluna = m.linha;

  // Aloca um vetor de ponteiros para as linhas
  t->matriz = (double**) malloc(t->linha * sizeof(double));

  //inicio do laço for i
  for(i=0; i<t->linha; i++)
    {
      // Aloca um vetor de ponteiros para cada linha. (Colunas)
      t->matriz[i] = (double*) malloc(t->coluna * sizeof(double));

      //inicio do laço for j
      for(j=0; j<t->coluna; j++)
        {
            //inicializa o elemento [i][j] da transposta como sendo igual ao elemento [j][i] da matriz original
            t->matriz[i][j] = m.matriz[j][i];
        }
    }
  //printa uma linha de hifens
  printf("\n__________________________________________________________________________\n\n");
  printf("Matriz Transposta:\n\n");

  //inicio do for i
  for(i=0; i<m.coluna; i++)
    {
      //inicio do for j
      for(j=0; j<m.linha; j++)
        //imprime o elemento [i][j] da transposta
        printf("%.1lf  ", t->matriz[i][j]);

        //imprime uma quebra de linha
        printf("\n");
    }
}

//Função para calcular determinante
void determatriz(matriz m)
{
  //caso o numero de linhas e colunas seja 1, imprime o único elemento
  if(m.linha == 1)
    printf("\nDeterminante da matriz %dX%d: %.1f \n", m.linha,m.coluna, m.matriz[0][0]);

  //caso o numero de linhas e colunas seja 2, imprime o determinante
  else if(m.linha == 2)
    printf("\nDeterminante da matriz %dX%d: %.1f \n", m.linha, m.coluna, m.matriz[0][0] * m.matriz[1][1] - (m.matriz[0][1] * m.matriz[1][0]));

  //caso o numero de linhas e colunas seja 3, imprime o determinante
  else if(m.linha == 3)
    {
      double determinante;
      determinante = (m.matriz[2][0] * m.matriz[0][1] * m.matriz[1][2] +
                      m.matriz[0][0] * m.matriz[1][1] * m.matriz[2][2] +
                      m.matriz[1][0] * m.matriz[2][1] * m.matriz[0][2] -
                      m.matriz[2][2] * m.matriz[0][1] * m.matriz[1][0] -
                      m.matriz[0][2] * m.matriz[1][1] * m.matriz[2][0] -
                      m.matriz[1][2] * m.matriz[2][1] * m.matriz[0][0]);
      printf("\nDeterminante da matriz [%d][%d]: %.1lf \n", m.linha, m.coluna, determinante);
    }
  else
    {
      puts("\nNão é possível calcular o determinante da matriz\n");
    }
}

//Função para verificar se a matriz é simétrica
void simematriz(matriz m, matriz t)
{
  //variaveis de controle do for e uma variavel auxiliar inicializa como 0
  int i, j, aux=0;

  //testa se a matriz é quadrada
  if(m.linha != m.coluna)
    {
      //caso não seja, a matriz não é simétrica
      printf("\nA Matriz não é simétrica\n");
    }
  else
    {
      //caso seja quadrada:
      //inicio do for i
      for(i = 0; i<m.linha; i++)
        {

          //inicio do for j
          for(j = 0; j<m.coluna; j++)
            {

              //se o elemento [i][j] da matriz for igual ao elemento [i][j] da sua transposta
              if(m.matriz[i][j] == t.matriz[i][j])

                aux++; //caso seja, soma 1 na variavel auxiliar
            }
        }
  //testa se a variavel auxiliar é igual ao produto de linhas x colunas da matriz
  if(aux == (m.linha * m.linha))
    {

      //imprime que é simétrica
      puts("\nA Matriz é simétrica");
    }
  else
    {

        //imprime que não é simétrica
        puts("\nA Matriz não é simétrica");
    }
  }
}

