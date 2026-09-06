#include <stdio.h>
#include <stdio.h>

int main()
{
  int vetor[10];
  int *p = vetor;
  *p = 100;
  *(p + 1) = 120;
  p[2] = 230;
  p = &vetor[3];
  *(p) = 410;
  p[1] = 510;
  p = p + 1;
  *(p + 0) = 160;
  p--;
  *(p + 2) = 66;
  p[3] = 170;
  p = vetor;
  *(p + 7) = 880;
  p[8] = 990;
  p++;
  *(p + 8) = 110;

  printf("Banana");
  return 0;
}