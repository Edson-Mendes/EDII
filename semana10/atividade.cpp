#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * Gera números aleatórios de 0 a 100_000 e retorna em um vetor.
 *
 * @param quantidade É a quantidade de números a serem gerados e o tamanho
 * do vetor alocado.
 */
int *gerarNumerosAleatorios(int quantidade)
{
  unsigned int seed;
  int *vetor = (int *)malloc(quantidade * sizeof(int));

  if (vetor == NULL)
  {
    printf("Nao foi possivel alocar vetor de tamanho %d\n", quantidade);
    exit(1);
  }

  seed = ((unsigned)time(NULL));
  srand(seed);

  for (int i = 0; i < quantidade; i++)
  {
    vetor[i] = rand() % 100000;
  }
  return vetor;
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
 * Grava os valores do vetor em um arquivo.
 *
 * @param vetor Array que contém os elementos a serem gravados.
 * @param quantidade quantidade de elementos a serem gravados.
 * @param nomeArquivo Nome do arquivo que receberá os dados do vetor.
 */
void salvarNumerosNoArquivo(int *vetor, int quantidade, char *nomeArquivo)
{
  FILE *file;

  if ((file = fopen(nomeArquivo, "w")) == NULL)
  {
    printf("Erro ao abrir arquivo %s\n", nomeArquivo);
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
 * Retorna uma copia do vetorOrigem.
 */
int *copiarVetor(int *vetorOrigem, int quantidade)
{
  int *vetorDestino = (int *)malloc(quantidade * sizeof(int));
  if (vetorDestino == NULL)
  {
    printf("copyVetor ::: Não foi possivel alocar vetor");
    exit(1);
  }

  for (int i = 0; i < quantidade; i++)
  {
    vetorDestino[i] = vetorOrigem[i];
  }
  return vetorDestino;
}

/**
 * Mostra o vetor na tela no formato [n1, n2, n3, ...].
 */
void imprimirVetor(int *vetor, int quantidade)
{
  printf("[");
  for (int i = 0; i < quantidade; i++)
  {
    if (i != quantidade - 1)
      printf("%d, ", vetor[i]);
    else
      printf("%d", vetor[i]);
  }
  printf("]\n");
}

// ------------ Algoritmos de ordenação ------------

/**
 * Algoritmo BubbleSort.
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

/**
 * Algoritmo SelectionSort.
 */
time_t selectionSort(int *vetor, int tamanho)
{
  time_t inicioExecucao = time(NULL);
  int i, j, min;
  for (i = 0; i < (tamanho - 1); i++)
  {
    min = i;
    for (j = i + 1; j < tamanho; j++)
    {
      if (vetor[j] < vetor[min])
        min = j;
    }
    if (i != min)
    {
      int swap = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = swap;
    }
  }

  time_t fimExecucao = time(NULL);
  return fimExecucao - inicioExecucao;
}

/**
 * Algoritmo InsertionSort.
 */
time_t insertionSort(int *vetor, int tamanho)
{
  time_t inicioExecucao = time(NULL);
  int i, j, chave;
  for (j = 1; j < tamanho; j++)
  {
    chave = vetor[j];
    i = j - 1;
    while (i >= 0 && vetor[i] > chave)
    {
      vetor[i + 1] = vetor[i];
      i--;
    }
    vetor[i + 1] = chave;
  }

  time_t fimExecucao = time(NULL);
  return fimExecucao - inicioExecucao;
}

/**
 * Algoritmo CountSort.
 */
time_t countSort(int *vetor, int tamanho)
{
  time_t inicioExecucao = time(NULL);
  int i, min, max;
  int j = 0;
  min = max = vetor[0];
  // Identifica o Maior Elemento
  for (i = 1; i < tamanho; i++)
  {
    if (vetor[i] < min)
      min = vetor[i];
    else if (vetor[i] > max)
      max = vetor[i];
  }
  int range = max - min + 1;
  int *count = (int *)malloc(range * sizeof(int));
  // Marca Todas as posi��es com Zero
  for (i = 0; i < range; i++)
    count[i] = 0;
  // Marca as posi��es ocupadas
  for (i = 0; i < tamanho; i++)
    count[vetor[i] - min]++;
  int indice;
  indice = 0;
  // Array recebe as posicoes ocupadas
  for (i = min; i <= max; i++)
    for (j = 0; j < count[i - min]; j++)
    {
      vetor[indice] = i;
      indice++;
    }
  free(count);
  time_t fimExecucao = time(NULL);
  return fimExecucao - inicioExecucao;
}

// --------- QUICKSORT ---------
void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int vec[], int left, int right)
{
  int i, j;
  i = left;
  for (j = left + 1; j <= right; ++j)
  {
    if (vec[j] < vec[left])
    {
      ++i;
      swap(&vec[i], &vec[j]);
    }
  }
  swap(&vec[left], &vec[i]);
  return i;
}

/**
 * Algoritmo QuickSort.
 */
time_t quickSort(int vec[], int left, int right)
{
  time_t inicioExecucao = time(NULL);
  int r;
  if (right > left)
  {
    r = partition(vec, left, right);
    quickSort(vec, left, r - 1);
    quickSort(vec, r + 1, right);
  }
  time_t fimExecucao = time(NULL);
  return fimExecucao - inicioExecucao;
}
// -----------------------------

// --------- MERGESORT ---------
// Kernell do Algoritmo
void merge(int vec[], int vecSize)
{
  int mid;
  int i, j, k;
  int *tmp;
  tmp = (int *)malloc(vecSize * sizeof(int));
  if (tmp == NULL)
  {
    exit(1);
  }
  mid = vecSize / 2;
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < vecSize)
  {
    if (vec[i] < vec[j])
    {
      tmp[k] = vec[i];
      ++i;
    }
    else
    {
      tmp[k] = vec[j];
      ++j;
    }
    ++k;
  }
  if (i == mid)
  {
    while (j < vecSize)
    {
      tmp[k] = vec[j];
      ++j;
      ++k;
    }
  }
  else
  {
    while (i < mid)
    {
      tmp[k] = vec[i];
      ++i;
      ++k;
    }
  }
  for (i = 0; i < vecSize; ++i)
  {
    vec[i] = tmp[i];
  }
  free(tmp);
}

/**
 * Algoritmo MergeSort.
 */
time_t mergeSort(int vec[], int vecSize)
{
  time_t inicioExecucao = time(NULL);
  int mid;
  if (vecSize > 1)
  {
    mid = vecSize / 2;
    mergeSort(vec, mid);
    mergeSort(vec + mid, vecSize - mid);
    merge(vec, vecSize);
  }
  time_t fimExecucao = time(NULL);
  return fimExecucao - inicioExecucao;
}
// -----------------------------

int main()
{
  const int QUANTIDADE = 1000000;
  printf("Gerando numeros aleatorios...\n");
  int *vetor = gerarNumerosAleatorios(QUANTIDADE);

  printf("\nOrdenando com BubbleSort...\n");
  time_t tempoBubbleSort = bubbleSort(copiarVetor(vetor, QUANTIDADE), QUANTIDADE);
  printf("Ordenou %d elementos em %ld segundos\n", QUANTIDADE, tempoBubbleSort);

  printf("\nOrdenando com SelectionSort...\n");
  time_t tempoSelectionSort = selectionSort(copiarVetor(vetor, QUANTIDADE), QUANTIDADE);
  printf("Ordenou %d elementos em %ld segundos\n", QUANTIDADE, tempoSelectionSort);

  printf("\nOrdenando com InsertionSort...\n");
  time_t tempoInsertionSort = insertionSort(copiarVetor(vetor, QUANTIDADE), QUANTIDADE);
  printf("Ordenou %d elementos em %ld segundos\n", QUANTIDADE, tempoInsertionSort);

  printf("\nOrdenando com CountSort...\n");
  time_t tempoCountSort = countSort(copiarVetor(vetor, QUANTIDADE), QUANTIDADE);
  printf("Ordenou %d elementos em %ld segundos\n", QUANTIDADE, tempoCountSort);

  printf("\nOrdenando com QuickSort...\n");
  time_t tempoQuickSort = quickSort(copiarVetor(vetor, QUANTIDADE), 0, QUANTIDADE - 1);
  printf("Ordenou %d elementos em %ld segundos\n", QUANTIDADE, tempoQuickSort);

  printf("\nOrdenando com MergeSort...\n");
  time_t tempoMergeSort = mergeSort(copiarVetor(vetor, QUANTIDADE), QUANTIDADE);
  printf("Ordenou %d elementos em %ld segundos\n", QUANTIDADE, tempoMergeSort);

  return 0;
}