#include <stdio.h>

/*
  Considerando o arquivo cidades.txt, formado por três colunas (Nome da cidade, População e UF), 
  gere um programa que leia o arquivo e mostre o conteúdo na tela.

  Mostre o conteúdo do Arquivo na ordem inversa a leitura do arquivo 
  (mostrar do final para o inicio). 
*/
int main()
{
  int quantidadeLinha = 40; //Quantidade de cidades no arquivo

  char cidade[quantidadeLinha][20];
  int populacao[quantidadeLinha];
  char uf[quantidadeLinha][3];
  int indice = 0;
  FILE *cidadesFile;

  if ((cidadesFile = fopen("cidades.txt", "r")) == NULL)
  {
    printf("Erro ao abrir arquivo");
  }
  else
  {
    while(!feof(cidadesFile)) {
      fscanf(cidadesFile, "%s %d %s ", cidade[indice], &populacao[indice], uf[indice]);
      indice++;
    }

    printf("%-15s %s %s\n", "CIDADE", "UF", "POPULACAO");
    for (indice = quantidadeLinha - 1; indice >= 0; indice--)
    {
      printf("%-15s %s %d\n", cidade[indice], uf[indice], populacao[indice]);
    }
    
    fclose(cidadesFile);
  }
}