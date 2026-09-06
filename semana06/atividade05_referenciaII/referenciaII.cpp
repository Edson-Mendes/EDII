#include <stdio.h>

void func(int *aa, int *bb)
{
  int temp;
  temp = *aa;
  *aa = *bb;
  *bb = temp;
}

/**
 * O que imprime o programa a seguir?
 * 
 * RESPOSTA:
 * Declara as variáveis 'a' = 10 e 'b' = 20
 * Chama func passando os endereços de 'a' e 'b'.
 *    func realiza a troca dos valores que 'aa' e 'bb' apontam
 *    *aa = 10 e *bb = 20 >>> *aa = 20 e *bb = 10
 * printf apresenta "a = 10, b = 20", isso por que é passado 'b' para o primeiro especificador de formato %d
 * e 'a' para o segundo especificador de formato %d.
 */
int main()
{
  int a = 10, b = 20;
  func(&a, &b);
  printf("a = %d, b = %d", b, a);
}