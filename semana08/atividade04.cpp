#include <stdio.h>

int quantidade(int *vetor, int tamanho, int valor) {
  if (tamanho == 0) 
    return 0;
  if (*vetor == valor)
    return 1 + quantidade(vetor + 1, tamanho - 1, valor);

  return quantidade(vetor + 1, tamanho - 1, valor);
}

#define TAMANHO 20
int main() {
  int vetor[TAMANHO] = {1, 0, 6, 1, 0, 3, 1, 2, 3, 4, 4, 1, 2, 6, 8, 2, 3, 1, 2, 3};

  printf("Valor %d apareceu %d vez(es) no vetor!\n", 1, quantidade(vetor, TAMANHO, 1));
  printf("Valor %d apareceu %d vez(es) no vetor!\n", 2, quantidade(vetor, TAMANHO, 2));
  printf("Valor %d apareceu %d vez(es) no vetor!\n", 3, quantidade(vetor, TAMANHO, 3));
  printf("Valor %d apareceu %d vez(es) no vetor!\n", 4, quantidade(vetor, TAMANHO, 4));
  printf("Valor %d apareceu %d vez(es) no vetor!\n", 5, quantidade(vetor, TAMANHO, 5));
}