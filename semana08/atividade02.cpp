#include <stdio.h>

int contarCaractere(char caractere, char *palavra)
{
  if (*palavra == '\0')
    return 0;
  if (*palavra == caractere)
    return 1 + contarCaractere(caractere, palavra+1);

  return contarCaractere(caractere, palavra+1);
}

int main()
{
  char *palavra = "abacate";
  char caractere = 'a';
  int quantidade = contarCaractere(caractere, palavra);

  printf("o caractere '%c' ocorre %d vezes em '%s'.\n", caractere, quantidade, palavra);
  return 0;
}