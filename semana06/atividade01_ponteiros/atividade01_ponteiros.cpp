#include <stdio.h>

/**
 * Do mesmo modo que dizemos que o endereço da variável x é E2, 
 * podemos dizer que o endereço do array a é E100. Isto é, 
 * o endereço do array é o endereço do primeiro byte que o array ocupa.
 */
int main() {
  int a[10];
  int *p;

  p = a;
  *p = 10; // Equivale a qual alternativa?
  // a) a[0] = 10; 
  // b) *a[0] = 10;
  // c) a= 10;
  // d) &a = 10;
  // e) NDA
  
  /** 
   * RESPOSTA:
   * *p = 10 equivale a a) a[0] = 10; Por que no momento a atribuição, p contém o endereço de a[0].
   *  int a[10];  // Cria um array de inteiros com 10 posições.
   * int *p;      // Cria um ponteiro de inteiro.
   * p = a;       // Atribui o endereço inicial do array 'a' para p. Endereço inicial de 'a' = &a[0];
   * *p = 10;     // Atribui o valor 10 para o lugar que 'p' aponta.
  */

  return 0;
}