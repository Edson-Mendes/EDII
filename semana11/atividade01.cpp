#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **alocarVetorDePalavras(int quantidade, int tamanhoPalavra)
{
  char **vetor = (char **)malloc(quantidade * sizeof(char*));
  if (vetor == NULL)
  {
    printf("Nao foi possivel alocar vetor de tamanho %d\n", quantidade);
    exit(1);
  }
  for (int i = 0; i < quantidade; i++)
  {
    vetor[i] = (char *)malloc(tamanhoPalavra * sizeof(char));
    if (vetor[i] == NULL)
    {
      printf("Nao foi possivel alocar palavra de tamanho %d\n", tamanhoPalavra);
      exit(1);
    }
  }
  return vetor;
}

void lerPalavras(char **vetor, int quantidade, int tamanhoPalavra)
{
  printf("Digite %d palavras de ate %d caracteres:\n", quantidade, tamanhoPalavra - 1);
  for (int i = 0; i < quantidade; i++) {
    scanf("%s", vetor[i]);
  }
}

void imprimirVetor(char **vetor, int quantidade)
{
  printf("-----------------------------\n");
  for (int i = 0; i < quantidade; i++)
  {
    printf("%s\n", vetor[i]);
  }
  printf("-----------------------------\n");
}

void swap(char **a, char **b)
{
  char *temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(char **vetor, int tamanho)
{
  int i, j, min;
  for (i = 0; i < (tamanho - 1); i++)
  {
    min = i;
    for (j = i + 1; j < tamanho; j++)
    {
      if (strcmp(vetor[j], vetor[min]) < 0)
        min = j;
    }
    if (i != min)
    {
      swap(&vetor[i], &vetor[min]);
    }
  }
}

int main()
{
  const int QUANTIDADE = 10;
  const int TAMANHO_PALAVRA = 21;
  char **vetor = alocarVetorDePalavras(QUANTIDADE, TAMANHO_PALAVRA);
  lerPalavras(vetor, QUANTIDADE, TAMANHO_PALAVRA);

  selectionSort(vetor, QUANTIDADE);

  printf("---- Depois de ordenar ----\n");
  imprimirVetor(vetor, QUANTIDADE);
  return 0;
}