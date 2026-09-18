#include <stdio.h>

void contarParesImpares(int *vetor, int indice, int tamanho, int &pares, int &impares) {
  if (indice == tamanho)
    return;
  if (*(vetor + indice) % 2 == 0)
    pares++;
  else 
    impares++;

  contarParesImpares(vetor, indice+1, tamanho, pares, impares);
}

int contarPares(int *vetor, int indice, int tamanho)
{
  if (indice == tamanho)
    return 0;
  if (*(vetor + indice) % 2 == 0)
    return 1 + contarPares(vetor, indice + 1, tamanho);
  return contarPares(vetor, indice + 1, tamanho);
}

int contarImpares(int *vetor, int indice, int tamanho) {
  return tamanho - contarPares(vetor, indice, tamanho);
}

#define TAMANHO 20
int main()
{
  int vetor[TAMANHO] = {1, 0, 6, 1, 0, 3, 1, 2, 3, 4, 4, 1, 2, 6, 8, 2, 3, 1, 2, 3};

  printf("Quantidade de numeros PARES no vetor: %d\n", contarPares(vetor, 0, TAMANHO));
  printf("Quantidade de numeros IMPARES no vetor: %d\n", contarImpares(vetor, 0, TAMANHO));

  printf("----- USANDO REFERENCIA -----\n");
  int pares = 0;
  int impares = 0;
  contarParesImpares(vetor, 0, TAMANHO, pares, impares);
  printf("PARES: %d\n", pares);
  printf("IMPARES: %d\n", impares);
  return 0;
}