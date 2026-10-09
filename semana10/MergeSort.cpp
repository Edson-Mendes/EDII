#include <stdio.h>
#include <stdlib.h>

void mergeSort(int vec[], int vecSize);

void merge(int vec[], int vecSize);

main()
{
  // Inicializa�� do Vetor
  int v[5] = {1, 7, 4, 3, 5}, n = 5;
  int i, j = 0, aux;

  // Algoritmo de Ordena��o
  mergeSort(v, n);

  // La�o de impress�o do Vetor
  for (int q = 0; q < 5; q++)
  {
    printf("%d \n", v[q]);
  }
}

void mergeSort(int vec[], int vecSize)
{
  int mid;
  if (vecSize > 1)
  {
    mid = vecSize / 2;
    mergeSort(vec, mid);
    mergeSort(vec + mid, vecSize - mid);
    merge(vec, vecSize);
  }
}

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
