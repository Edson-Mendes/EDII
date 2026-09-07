#include <stdio.h>
#include <stdlib.h>

typedef struct Cproduto
{
  char descricao[20];
  float preco;
};

/**
 * Considerando a estrutura Cproduto, como é possível armazenar os valores 
 * (fazer o usuário digitar o nome) e mostrar o que o usuário digitou, 
 * usando somente a estrutura já disponibilizada? 
 * (Faça um exemplo atribuindo valores e mostrando os valores atribuídos). 
 */
int main(void)
{
  Cproduto *palgumacoisa;
  
  palgumacoisa = (Cproduto*) malloc(sizeof(Cproduto));
  
  printf("--------\n");
  printf("Digite a descricao do produto: ");
  scanf("%s", palgumacoisa->descricao);
  printf("Digite o preco do produto: ");
  scanf("%f", &(palgumacoisa->preco));

  printf("--------\n");
  printf("DESCRICAO: %s\n", palgumacoisa->descricao);
  printf("PRECO: R$ %.2f\n", palgumacoisa->preco);
}