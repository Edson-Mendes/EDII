#include <stdio.h>

int main()
{
  int valores[10] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
  int *ponteiro;
  ponteiro = valores;

  printf("-------------\n");
  printf("*ponteiro == valores[0]\n");
  printf("%d == %d\n", *ponteiro, valores[0]);

  printf("-------------\n");
  printf("ponteiro == &valores[0] == valores\n");
  printf("%p == %p == %p\n", ponteiro, &valores[0], valores);

  printf("-------------\n");
  printf("*(ponteiro + 5) == valores[5]\n");
  printf("%d == %d\n", *(ponteiro + 5), valores[5]);

  printf("-------------\n");
  printf("(ponteiro + 5) == &valores[5] == (valores + 5)\n");
  printf("%p == %p == %p\n", (ponteiro + 5), &valores[5], (valores + 5));
  return 0;
}