#include <stdio.h>

void gerar_multiplos(int atual, int passo, int limite)
{
  if (atual > limite)
    return;

  printf("%d\n", atual);
  gerar_multiplos(atual + passo, passo, limite);
}

void gerar_multiplos_regressivo(int atual, int passo, int limite)
{
  if (atual > limite)
    return;

  gerar_multiplos_regressivo(atual + passo, passo, limite);
  printf("%d\n", atual);
}

int main()
{
  printf("--- gerar_multiplos ---\n");
  gerar_multiplos(12, 12, 150);
  printf("-----------------------------\n");
  printf("--- gerar_multiplos_regressivo ---\n");
  gerar_multiplos_regressivo(12, 12, 150);
  return 0;
}