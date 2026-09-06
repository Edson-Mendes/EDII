#include <stdio.h>

int main()
{
  int valor = 10;
  int *ponteiro;
  ponteiro = &valor;

  printf("-------------\n");
  printf("*ponteiro == valor\n");
  printf("%d == %d\n", *ponteiro, valor);

  printf("-------------\n");
  printf("ponteiro == &valor\n");
  printf("%p == %p\n", ponteiro, &valor);

  printf("-------------\n");
  printf("&ponteiro\n");
  printf("%p\n", &ponteiro);
}