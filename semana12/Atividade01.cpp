#include <stdio.h>
#include <stdlib.h>
#include "arvoreAtividade01.h"

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

  printf("\nCaminhamentos na Arvore:\n");

  printf("\n - Pre-Ordem: \t");
  Caminhamento_Pre_Ordem(raiz);

  printf("\n - In-Fixado: \t");
  Caminhamento_In_Fixado(raiz);

  printf("\n - Pos-Fixado: \t");
  Caminhamento_Pos_Fixado(raiz);

  printf("\n----- Buscar -----");
  valor = -1;
  while (valor != 0)
  {
    printf("\nDigite o valor a ser buscado (0 para finalizar): ");
    scanf("%d", &valor);
    if (valor == 0) {
      continue;
    }
    int valorEncontrado = buscar(raiz, valor);
    if (valorEncontrado == -1)
      printf("%d nao foi encontrado!\n", valor);
    else
      printf("Valor %d encontrado!\n", valorEncontrado);
  }

  Destroi(raiz);

  return (0);
}