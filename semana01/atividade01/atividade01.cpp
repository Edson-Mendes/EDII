#include <stdio.h>

/*
  Considerando o arquivo cidades.txt, formado por três colunas (Nome da cidade, População e UF), 
  gere um programa que leia o arquivo e mostre o conteúdo na tela.
*/
int main()
{
  char cidade[20];
  int populacao;
  char uf[3];
  FILE *cidadesFile;

  if ((cidadesFile = fopen("cidades.txt", "r")) == NULL)
  {
    printf("Erro ao abrir arquivo");
  }
  else
  {
    printf("%-15s %s %s\n", "CIDADE", "UF", "POPULACAO");
    while(!feof(cidadesFile)) {
      fscanf(cidadesFile, "%s %d %s ", cidade, &populacao, uf);
      printf("%-15s %s %d\n", cidade, uf, populacao);
    }
    fclose(cidadesFile);
  }
}