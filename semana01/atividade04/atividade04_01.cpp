#include <stdio.h>

/*
  Considerando o Exemplo03.cpp, altere o programa que forma que leia dez (10) 
  nomes de pessoas e suas respectivas idades e grave em um arquivo chamado lista.txt. 
*/
int main()
{
  char nome[22];
  int idade;
  FILE *inputFile;
  FILE *listaFile;

  if ((inputFile = fopen("input_01.txt", "r")) == NULL || (listaFile = fopen("lista.txt", "w+")) == NULL)
  {
    printf("Erro ao abrir arquivo");
  }
  else
  {
    while (!feof(inputFile))
    {
      fscanf(inputFile, "%[^0123456789] %d ", nome, &idade);
      fprintf(listaFile, "%-15s %d\n", nome, idade);
    }
    fclose(inputFile);
    fclose(listaFile);
  }
}