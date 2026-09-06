#include <stdio.h>

/*
  Considerando o Exemplo04.cpp, altere o Programa de modo que ao mostrar o conteúdo do Arquivo,
  coloque todas as vogais em Maiúsculas na tela e em uma novo arquivo, chamado Texto_Alterado.txt.
 */
int main()
{
  char caractere;
  FILE *inputFile;
  FILE *textoAlteradoFile;

  if ((inputFile = fopen("arquivo_texto.txt", "r")) == NULL ||
      (textoAlteradoFile = fopen("Texto_Alterado.txt", "w+")) == NULL)
  {
    printf("Erro ao abrir arquivo");
  }
  else
  {
    while (!feof(inputFile))
    {
      caractere = fgetc(inputFile);
      if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u')
      {
        caractere -= 32;
      }
      fprintf(textoAlteradoFile, "%c", caractere);
    }
    fclose(inputFile);
    fclose(textoAlteradoFile);
  }
}