#include "stdio.h"

/**
 * Altere que modo que na impressão, 
 * seja usado ponteios ao invés de vetores. 
 */
int main()
{
  int vetor[50] = {
      10, 20, 30, 40, 50,
      60, 70, 80, 90, 100,
      110, 120, 130, 140, 150,
      160, 170, 180, 190, 200,
      210, 220, 230, 240, 250,
      260, 270, 280, 290, 300,
      310, 320, 330, 340, 350,
      360, 370, 380, 390, 400,
      410, 420, 430, 440, 450,
      460, 470, 480, 490, 500};
  
  int *ponteiroVetor = vetor;

  for (int i = 0; i < 50; i++, ponteiroVetor++)
  {
    printf("Vetor[%d] = %d\n", i, *ponteiroVetor);
  }

  return 0;
}