#include <stdio.h>
#include <stdlib.h>
#include "arvoreAtividade02.h"

int buscar(TArvore *arvore, int valor);

int main(void)
{
  TArvore *raiz;
  int valor;

  printf("Informe o \nValor da Raiz: ");
  scanf("%d", &valor);

  raiz = Cria(NULL, valor, NULL);

  while (valor != 0)
  {
    printf("Digite o \nValor da Folha: ");
    scanf("%d", &valor);

    if (valor != 0)
      raiz = insere_binario(raiz, valor);
  }

  printf("\n---- ordem crescente ----");
  printf("\nVALOR   OCORRENCIAS\n");
  OrdemCrescente(raiz);

  Destroi(raiz);

  return (0);
}