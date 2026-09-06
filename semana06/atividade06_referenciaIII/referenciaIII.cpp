#include <stdlib.h>
#include <stdio.h>

void somaUm(int &x)
{
  x++;
}

/**
 * Considerando o programa abaixo, qual será o valor de I no final do programa?
 * 
 * RESPOSTA:
 * Declara a variável i com valor 0
 * percorre while até i ser igual ou maior que 10
 *    dentro do while chama a função somaUm(i)
 *    somaUm recebe uma referência para i, dessa forma, a variável x dentro de somaUm() 
 *    está associada com o mesmo espaço de memória que i.
 *    Então x (também conhecido como i) é incrementado em 1.
 *    A execução acima ocorre até i checar ao valor 10.
 * printf apresenta na tela "valor de i : 10".
 * 
 * Segue um vídeo que me ajudou a entender sobre passagem por refêrencia:
 * https://www.youtube.com/watch?v=KD8zanR034A
 */
main()
{
  int i=0;
  while (i<10)
  {
    somaUm(i);
  }
  printf("valor de i : %d \n",i);
}