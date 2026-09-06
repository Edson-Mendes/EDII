#include <stdio.h>

/*
  Considerando o arquivo nomes.txt, composto por duas colunas (Nome e Idade), 
  desenvolva um programa que leia o arquivo e exiba seu conteúdo na tela.

  Atenção: a coluna Nome possui 22 caracteres. 
  Ajuste o programa para ler corretamente essa coluna de 22 caracteres seguida da idade. 
  Neste momento, evite utilizar inteligência artificial para gerar o código 
  (você pode, no entanto, usar a IA para entender como ler uma coluna com 20 caracteres).

  Todas as informações necessárias estão disponíveis no arquivo exemplo01.
*/
int main()
{
  char nomeCompleto[22];
  int idade;
  FILE *nomesFile;

  if ((nomesFile = fopen("nomes.txt", "r")) == NULL)
  {
    printf("Erro ao abrir arquivo");
  }
  else
  {
    while (!feof(nomesFile))
    {
      fscanf(nomesFile, "%[^0123456789] %d ", nomeCompleto, &idade);
      printf("%s %d\n", nomeCompleto, idade);
    }
    fclose(nomesFile);
  }
}