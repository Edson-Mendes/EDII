#include <stdio.h>

void contarCrescente(int inicio, int fim)
{
  if (inicio > fim)
    return;
  printf("%d\n", inicio);
  contarCrescente(inicio + 1, fim);
}

void contarDecrescente(int inicio, int fim)
{
  if (inicio > fim)
    return;
  contarDecrescente(inicio + 1, fim);
  printf("%d\n", inicio);
}

int main()
{
  contarCrescente(1, 10);
  printf("-----------------------------\n");
  contarDecrescente(1, 10);
  return 0;
}