#include <stdio.h>
#include <string.h>

typedef struct Cproduto
{
  char descricao[20];
  float preco;
};

/**
 * Considerando a estrutura Cproduto, como é possível acessar a propriedade descrição, sem usar ponteiro?
 *
 * RESPOSTA:
 * Acessando o valor que o ponteiro palgumacoisa aponta e depois acessar
 * diretamente a propriedade descricao.
 * (*palgumacoisa) acessa o valor armazenado no endereço para o qual aponta.
 * (*palgumacoisa).descricao e depois acessa a propriedade.
 *
 * A ideia é a mesma da dereferenciação feita com outros tipos de ponteiros
 * int valor = 10;
 * int *ponteiro = &valor;
 * *ponteiro = 44;
 * printf("%d\n", valor);       //44
 * printf("%d\n", *ponteiro);   //44
 */
int main(void)
{
  Cproduto algumacoisa;
  Cproduto *palgumacoisa;
  palgumacoisa = &algumacoisa;

  strcpy((*palgumacoisa).descricao, "Banana");
  (*palgumacoisa).preco = 5.67;

  printf("-----\n");
  printf("algumacoisa.descricao: %s\n", algumacoisa.descricao);
  printf("(*palgumacoisa).descricao: %s\n", (*palgumacoisa).descricao);
  printf("-----\n");
  printf("algumacoisa.preco: %f\n", algumacoisa.preco);
  printf("(*palgumacoisa).preco: %f\n", (*palgumacoisa).preco);

  printf("-------------------------------------------------\n");
  Cproduto produtos[4];
  Cproduto *pProduto = produtos;

  strcpy(produtos[0].descricao, "Arroz");
  produtos[0].preco = 1.11;
  strcpy(produtos[1].descricao, "Banana");
  produtos[1].preco = 2.22;
  strcpy(produtos[2].descricao, "Coco");
  produtos[2].preco = 3.33;
  strcpy(produtos[3].descricao, "Dedo");
  produtos[03].preco = 4.44;

  for (int i = 0; i < 4; i++)
  {
    printf("%s - R$ %.2f\n", (pProduto + i)->descricao, (pProduto + i)->preco);
    printf("%s - R$ %.2f\n", (*(pProduto + i)).descricao, (*(pProduto + i)).preco);
  }
  
}