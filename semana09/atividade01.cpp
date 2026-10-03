#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Gera números aleatórios de 0 a 100_000 e salva no arquivo "Arquivo.txt".
 *
 * @param quantidade É a quantidade de números a serem gerados.
 */
void gerarNumerosAleatorios(int quantidade)
{
  int i;
  unsigned int seed;
  FILE *file;

  if ((file = fopen("Arquivo.txt", "w")) == NULL)
  {
    printf("Erro ao abrir arquivo");
    exit(1);
  }
  else
  {
    seed = ((unsigned)time(NULL));
    srand(seed);
    i = 0;
    while (i < quantidade)
    {
      float c = rand() % 100000;
      fprintf(file, "%.0f\n", c);
      ++i;
    }
    fclose(file);
  }
}

/**
 * Le os números salvos no arquivo "Arquivo.txt" e grava em um vetor.
 *
 * @param quantidade É a quantidade de números a serem lidos.
 */
int *lerNumerosDoArquivo(int quantidade)
{
  FILE *file;
  if ((file = fopen("Arquivo.txt", "r")) == NULL)
  {
    printf("Falha ao abrir arquivo");
    exit(1);
  }
  int *vetor = (int *)malloc(quantidade * sizeof(int));
  for (int i = 0; i < quantidade; i++)
  {
    fscanf(file, "%d", &vetor[i]);
  }
  fclose(file);
  return vetor;
}

/**
 * Grava os valores do vetor no arquivo "dados_ordenados_bubblesort.txt".
 * 
 * @param vetor Array que contém os elementos a serem gravados.
 * @param quantidade quantidade de elementos a serem gravados. 
 */
void salvarNumerosNoArquivo(int *vetor, int quantidade) {
  FILE *file;

  if ((file = fopen("dados_ordenados_bubblesort.txt", "w")) == NULL)
  {
    printf("Erro ao abrir arquivo 'dados_ordenados_bubblesort.txt'");
    exit(1);
  }
  else
  {
    for (int i = 0; i < quantidade; i++)
    {
      fprintf(file, "%d\n", vetor[i]);
    }
    fclose(file);
  }
}

/**
 * Algoritmo BubbleSort.
 *
 * @param vetor Array a ser ordenado.
 * @param tamanho Indica o tamanho do array.
 * @return O tempo em segundos que levou para ordenar o vetor
 */
time_t bubbleSort(int *vetor, int tamanho)
{
  time_t inicioExecucao = time(NULL);
  int j = 0;
  int aux;
  while (j < tamanho)
  {
    for (int i = 0; i < tamanho - 1; i++)
      if (vetor[i] > vetor[i + 1])
      {
        aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
      }
    j++;
  }
  time_t fimExecucao = time(NULL);
  return fimExecucao - inicioExecucao;
}

int main()
{
  const int QUANTIDADE = 500000;
  printf("Gerando numeros aleatorios...\n");
  gerarNumerosAleatorios(QUANTIDADE);

  printf("Lendo numeros do arquivo...\n");
  int *vetor = lerNumerosDoArquivo(QUANTIDADE);

  printf("\nOrdenando com BubbleSort...\n");
  time_t tempoExecucao = bubbleSort(vetor, QUANTIDADE);

  printf("\nSalvando no arquivo os valores ordenados...\n");
  salvarNumerosNoArquivo(vetor, QUANTIDADE);
  printf("\nOrdenou %d elementos em %ld segundos\n", QUANTIDADE, tempoExecucao);
  return 0;
}