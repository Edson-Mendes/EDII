#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 20

/**
 * Considerando o código existente do programa abaixo, Quantos acessos ao vetor são necessários para localizar o valor 20?
 * 
 * RESPOSTA:
 * acesso 1:
 *  - esquerda = -1, direita = 20, meio = 9
 *  - vetor[meio] = 16 então é menor que x = 20
 *  - esquerda = 9
 * acesso 2:
 *  - esquerda = 9, direita = 20, meio = 14
 *  - vetor[meio] = 33 então é maior que x = 20
 *  - direita = 14
 * acesso 3:
 *  - esquerda = 9, direita = 14, meio = 11
 *  - vetor[meio] = 20 então é igual a x = 20
 *  - direita = 11
 * acesso 4:
 *  - esquerda = 9, direita = 11, meio = 10
 *  - vetor[meio] = 19 então é menor que x = 20
 *  - esquerda = 10
 * 
 *  - esquerda = 10, direita = 11 >>> Sai do while
 * 
 * vetor[direita] = vetor[11] = 20 == x = 20
 * - imprimi "Valor Localizado".
 * 
 * Foram necessários 4 acessos ao array.
 */
main()
{
  int x, i = 0, vetor[20] = {3, 5, 6, 7, 8, 9, 10, 12, 14, 16, 19, 20, 21, 22, 33, 35, 37, 39, 44, 50};

  printf("Qual Numero deseja localizar?:");
  scanf("%d", &x);
  int meio = 0, esquerda = -1, direita = TAMANHO;
  while (esquerda < direita - 1)
  {
    int meio = (esquerda + direita) / 2;
    if (vetor[meio] < x)
      esquerda = meio;
    else
      direita = meio;
  }
  if (vetor[direita] == x)
    printf("Valor Localizado");
  else
    printf("Valor NAO Localizado");
}