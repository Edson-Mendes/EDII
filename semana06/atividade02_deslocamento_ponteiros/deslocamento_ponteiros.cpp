#include <stdio.h>

/**
 * Qual é a alternativa Correta? Justifique e apresente um exemplo de código.
 *
 * Se você quiser usar o conteúdo do ponteiro *p 15 posições adiante, deverá escrever:
 * a)    *(p+15);
 * b)    *P[15];
 * c)    &p[15];
 * d)    (*p+15);
 * e)    NDA;
 */
int main()
{
  int valores[20] = {
      1000, 1001, 1002, 1003,
      1004, 1005, 1006, 1007,
      1008, 1009, 1010, 1011,
      1012, 1013, 1014, 1015,
      1016, 1017, 1018, 1019};
  int *ponteiro;
  ponteiro = valores;
  printf("*(ponteiro + 15) == valores[15]\n");
  printf("%d == %d\n", *(ponteiro + 15), valores[15]);
  
  return 0;
}