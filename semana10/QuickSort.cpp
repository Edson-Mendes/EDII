#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

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

void quickSort(int vec[], int left, int right)
{
  int r;
  if (right > left)
  {
    r = partition(vec, left, right);
    quickSort(vec, left, r - 1);
    quickSort(vec, r + 1, right);
  }
}

main()
{

  // Inicializa��o do Vetor
  int v[5] = {1, 7, 4, 3, 5}, n = 5;
  int i, j = 0, aux;

  // Algoritmo de Ordena��o
  quickSort(v, 0, 4);

  // La�o de impress�o do Vetor
  for (int q = 0; q < 5; q++)
  {
    printf("%d \n", v[q]);
  }
}
