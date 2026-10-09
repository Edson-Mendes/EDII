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

int partition(char** vetor, int left, int right)
{
  int i, j;
  i = left;
  for (j = left + 1; j <= right; ++j)
  {
    if (strcmp(vetor[j], vetor[left]) < 0)
    {
      ++i;
      swap(&vetor[i], &vetor[j]);
    }
  }
  swap(&vetor[left], &vetor[i]);
  return i;
}

void quickSort(char** vetor, int left, int right)
{
  int r;
  if (right > left)
  {
    r = partition(vetor, left, right);
    quickSort(vetor, left, r - 1);
    quickSort(vetor, r + 1, right);
  }
}

int main()
{
  const int QUANTIDADE = 10;
  const int TAMANHO_PALAVRA = 21;
  char **vetor = alocarVetorDePalavras(QUANTIDADE, TAMANHO_PALAVRA);
  lerPalavras(vetor, QUANTIDADE, TAMANHO_PALAVRA);

  // selectionSort(vetor, QUANTIDADE);
  quickSort(vetor, 0, QUANTIDADE - 1);

  printf("---- Depois de ordenar ----\n");
  imprimirVetor(vetor, QUANTIDADE);
  return 0;
}