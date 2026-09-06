#include <stdio.h>

void func(int aa, int bb)
{
  int temp;
  temp = aa;
  aa = bb;
  bb = temp;
}

void funcAlterado(int *aa, int *bb)
{
  int temp;
  temp = *aa;
  *aa = *bb;
  *bb = temp;
}

/**
 * O que imprime o programa a seguir? (Faça uma análise antes de executar).
 * 
 * O que deve ser alterado para realmente realizar a troca de valores? (apresente um código de exemplo). 
 */
int main()
{
  // EXECUÇÃO ANTES DA ALTERAÇÃO
  // Declara 'a' com valor 10 e 'b' com valor 20.
  // chama a função func com valores de 'a' e 'b' (10 e 20).
  // func recebe uma CÓPIA de 'a' e 'b'. 
  //    Realiza a troca entre as cópias.
  //    aa = 10, bb = 20 >>> aa = 20, b = 10.
  //    Sem impacto nas variáveis a e b dentro da main.
  // No momento do printf, a = 10 e b = 20, então vai imprimir "a = 10, b = 20".

  // O QUE FOI ALTERADO?
  // Agora os parâmetros de func são ponteiros, e a função passa a trocar os valores que aa e bb apontam.
  // 
  // EXECUÇÃO DEPOIS DA ALTERAÇÃO
  // Declara 'a' com valor 10 e 'b' com valor 20.
  // chama a função funcAlterado com valores dos ENDEREÇOS de 'a' e 'b'.
  // funcAlterado recebe os endereços de a e b. 
  //    Realiza a troca entre os valores que aa e bb apontam.
  //    *aa = 10, *bb = 20 >>> *aa = 20, *b = 10.
  //    Com impacto nas variáveis a e b dentro da main, pois elas são referenciadas por aa e bb;
  // No momento do printf, a = 20 e b = 10, então vai imprimir "a = 20, b = 10".

  int a = 10, b = 20;             
  // func(a, b);
  funcAlterado(&a, &b);
  printf("a = %d, b = %d", a, b); 
}