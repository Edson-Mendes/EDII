#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define tamanho 100

/**
  Altere o código para usar imprimir a frase, 
  caractere por caractere, usando ponteiros. 
 */
int main()
{
  char frase[tamanho];
  strcpy(frase, "IFRS - Instituto Federal de Educação Tecnologia \n");

  char *ponteiroFrase = frase;
  
  while (*ponteiroFrase != '\0')
  {
    printf("%c", *ponteiroFrase);
    ponteiroFrase++;
  }
  return 0;
}