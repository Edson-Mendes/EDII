#include <stdio.h>
#include <stdlib.h>

int dadosSize()
{
  FILE *dadosFile;
  int size = 0;
  int dado;
  if ((dadosFile = fopen("dados.txt", "r")) == NULL)
  {
    printf("Erro ao abrir arquivo");
    return 0;
  }
  else
  {
    while (fscanf(dadosFile, "%d", &dado) == 1)
    {
      size++;
    }
  }
  fclose(dadosFile);
  return size;
}

int *criarArray(int tamanho)
{
  int *array = (int *)malloc(tamanho * sizeof(int));
  return array;
}

void popularArray(int *array)
{
  FILE *dadosFile;
  int dado;
  if ((dadosFile = fopen("dados.txt", "r")) == NULL)
  {
    printf("Erro ao abrir arquivo");
    return;
  }
  else
  {
    while (fscanf(dadosFile, "%d", &dado) == 1)
    {
      *array = dado;
      array++;
    }
  }
  fclose(dadosFile);
}

int acessosBuscaSequencial(int *array, int tamanho, int valor)
{
  int i = 0;
  int acessos = 1;
  while (i < tamanho && array[i] != valor)
  {
    i++;
    acessos++;
  }

  if (i == tamanho)
    acessos--;
  return acessos;
}

int acessosBuscaBinaria(int *array, int tamanho, int valor)
{
  int meio = 0, esquerda = 0, direita = tamanho - 1;
  int acessos = 0;

  while (esquerda <= direita)
  {
    acessos++;
    meio = (esquerda + direita) / 2;

    if (array[meio] == valor)
    {
      return acessos;
    }
    else if (array[meio] < valor)
      esquerda = meio + 1;
    else
      direita = meio - 1;
  }

  return acessos;
}

int main()
{
  int tamanho = dadosSize();
  int *array = criarArray(tamanho);
  popularArray(array);

  printf("%d\n", acessosBuscaSequencial(array, tamanho, 7341488));
  printf("%d\n", acessosBuscaSequencial(array, tamanho, 85));
  printf("%d\n", acessosBuscaSequencial(array, tamanho, 265654));
  printf("%d\n", acessosBuscaSequencial(array, tamanho, 732765));
  printf("%d\n", acessosBuscaSequencial(array, tamanho, 8313596));
  printf("%d\n", acessosBuscaSequencial(array, tamanho, 45744));
  printf("-----------------------------------\n");
  printf("%d\n", acessosBuscaBinaria(array, tamanho, 7341488));
  printf("%d\n", acessosBuscaBinaria(array, tamanho, 85));
  printf("%d\n", acessosBuscaBinaria(array, tamanho, 265654));
  printf("%d\n", acessosBuscaBinaria(array, tamanho, 732765));
  printf("%d\n", acessosBuscaBinaria(array, tamanho, 8313596));
  printf("%d\n", acessosBuscaBinaria(array, tamanho, 45744));
  return 0;
}