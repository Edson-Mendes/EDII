#include <stdio.h>
#include <stdlib.h>

/**
 * Quantos bytes ocupam o ponteiro p?
 * Qual é resultado de impressão de *(i) no final do programa?
 * (Justifique a resposta, apresentando a execução com os valores).
 * 
 * RESPOSTA:
 * Houve a alocação de 30 unidades de inteiros de 4 bytes, assim 120 bytes de memória foram alocados.
 * Mas ponteiros são de tamanho de 8 bytes em sistemas operacionais de 64 bits (meu caso), então p ocupa 8 bytes.
 */
int main()
{
  int *p, a, *i;
  i = &a;
  p = &a;
  a = 30;
  p = (int *)malloc(a * sizeof(int));
  if (!p)
  {
    printf("** Erro: Memoria Insuficiente **");
    exit(1);
  }
  printf("p ocupa %zu bytes\n", sizeof(p));
  // Houve a alocação de 30 unidades de inteiros de 4 bytes, assim 120 bytes de memória foram alocados.
  // Mas ponteiros são de tamanho de 8 bytes em sistemas operacionais de 64 bits (meu caso), então p ocupa 8 bytes.
  return 0;
}