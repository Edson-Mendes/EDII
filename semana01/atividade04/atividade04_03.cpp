#include <stdio.h>

/*
  Considerando o Exemplo05.cpp, altere o programa que modo que para
  cada parágrafo do arquivo seja impresso uma linha em branco.
 */
int main()
{
  char caractere;
  FILE *inputFile;
  FILE *textoAlterado_03_File;

  if ((inputFile = fopen("arquivo_texto.txt", "r")) == NULL ||
      (textoAlterado_03_File = fopen("Texto_Alterado_03.txt", "w+")) == NULL)
  {
    printf("Erro ao abrir arquivo");
  }
  else
  {
    while (!feof(inputFile))
    {
      caractere = fgetc(inputFile);
      if (caractere == '\n')
      {
        fprintf(textoAlterado_03_File, "\n");
      }
      fprintf(textoAlterado_03_File, "%c", caractere);
    }
    fclose(inputFile);
    fclose(textoAlterado_03_File);
  }
}