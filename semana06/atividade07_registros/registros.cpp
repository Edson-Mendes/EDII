#include <stdio.h>
#include <string.h>

typedef struct Cproduto
{
  char descricao[20];
  float preco;
};

/**
 * Considerando a estrutura Cproduto, como é possível acessar via ponteiro a propriedade descricao?
 * 
 * RESPOSTA:
 * Para acessar via ponteiro as propriedades de uma struct é necessário usar 
 * o operador de acesso a membro '->'.
 * Cproduto produto;
 * Cproduto *ponteiroProduto = &produto;
 * ponteiroProduto->preco = 7.50;
 */
int main(void)
{
  Cproduto algumacoisa;
  Cproduto *palgumacoisa;
  palgumacoisa = &algumacoisa;

  // Modo de acesso através ponteiro
  strcpy(palgumacoisa->descricao, "Batata");
  palgumacoisa->preco = 7.45;

  printf("-----\n");
  printf("algumacoisa.descricao: %s\n", algumacoisa.descricao);
  printf("palgumacoisa->descricao: %s\n", palgumacoisa->descricao);
  printf("-----\n");
  printf("algumacoisa.preco: %f\n", algumacoisa.preco);
  printf("palgumacoisa->preco: %f\n", palgumacoisa->preco);
}