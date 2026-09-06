#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dado
{
  int codigo;
  char produto[100];
  char categoria[20];
  float preco;
  int quantidade;
};

Dado mapearParaDado(char *linha)
{
  Dado novoDado;
  novoDado.codigo = atoi(linha);
  strncpy(novoDado.produto, linha + 6, 99);
  strncpy(novoDado.categoria, linha + 105, 19);
  novoDado.produto[99] = '\000';
  novoDado.categoria[19] = '\000';
  novoDado.preco = atof(linha + 125);
  novoDado.quantidade = atoi(linha + 130);
  return novoDado;
}

int main()
{
  FILE *dadosFile;
  Dado dado;
  char linha[200];

  if ((dadosFile = fopen("dados.txt", "r")) == NULL)
  {
    printf("Erro ao ler arquivo!\n");
  }
  else
  {
    while (fgets(linha, sizeof(linha), dadosFile) != NULL)
    {
      dado = mapearParaDado(linha);
      printf("------------\n");
      printf("CODIGO: %d\n", dado.codigo);
      printf("PRODUTO: %s\n", dado.produto);
      printf("CATEGORIA: %s\n", dado.categoria);
      printf("PRECO: %.2f\n", dado.preco);
      printf("QUANTIDADE: %d\n", dado.quantidade);
    }
  }
  fclose(dadosFile);
  return 0;
}