#include <stdio.h>

struct Produto
{
  char nome[35];
  int quantidade;
  float valor;
};

int main()
{
  FILE *produtosFile;
  Produto *produto;

  if ((produtosFile = fopen("dados.dat", "rb")) == NULL)
  {
    printf("Falha ao ler arquivo\n");
  }
  else
  {
    printf("%-25s %-20s %-10s\n", "ITEM", "QUANTIDADE", "VALOR");
    while (fread(produto, sizeof(Produto), 1, produtosFile) == 1)
    {
      printf("%-25s %-20d R$ %-7.2f\n", produto->nome, produto->quantidade, produto->valor);
    }
  }
  fclose(produtosFile);
  return 0;
}