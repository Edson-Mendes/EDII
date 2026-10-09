#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
  char nome[50];
  int idade;
  int codigo;
};

Pessoa* alocarVetorPessoas(int quantidade) {
  Pessoa* pessoas = (Pessoa*)malloc(quantidade * sizeof(Pessoa));
  if (pessoas == NULL) {
    printf("Erro ao alocar vetor de pessoas.\n");
    exit(1);
  }

  return pessoas;
}

void imprimirPessoas(Pessoa* pessoas, int quantidade) {
  printf("-----------------------------\n");
  for (int i = 0; i < quantidade; i++) {
    printf("Nome: %-10s Idade: %02d Codigo: %04d\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].codigo);
  }
  printf("-----------------------------\n");
}

void lerPessoas(Pessoa* pessoas, int quantidade) {
  printf("Digite os dados de %d pessoas:\n", quantidade);
  for (int i = 0; i < quantidade; i++) {
    printf("Pessoa %d:\n", i + 1);
    printf("Nome: ");
    scanf("%s", pessoas[i].nome);
    printf("Idade: ");
    scanf("%d", &pessoas[i].idade);
    printf("Codigo: ");
    scanf("%d", &pessoas[i].codigo);
  }
}

void swap(Pessoa *a, Pessoa *b)
{
  Pessoa temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(Pessoa *vetor, int tamanho)
{
  int i, j, min;
  for (i = 0; i < (tamanho - 1); i++)
  {
    min = i;
    for (j = i + 1; j < tamanho; j++)
    {
      if (strcmp(vetor[j].nome, vetor[min].nome) < 0)
        min = j;
    }
    if (i != min)
    {
      swap(&vetor[i], &vetor[min]);
    }
  }
}

int main() {
  const int QUANTIDADE = 10;
  Pessoa* pessoas = alocarVetorPessoas(QUANTIDADE);
  
  // lerPessoas(pessoas, QUANTIDADE);
  strcpy(pessoas[0].nome, "Zilda");
  pessoas[0].idade = 55;
  pessoas[0].codigo = 100;
  strcpy(pessoas[1].nome, "Amanda");
  pessoas[1].idade = 29;
  pessoas[1].codigo = 200;
  strcpy(pessoas[2].nome, "Edson");
  pessoas[2].idade = 32;
  pessoas[2].codigo = 300;
  strcpy(pessoas[3].nome, "Sergio");
  pessoas[3].idade = 40;
  pessoas[3].codigo = 400;
  strcpy(pessoas[4].nome, "Mario");
  pessoas[4].idade = 30;
  pessoas[4].codigo = 800;
  strcpy(pessoas[5].nome, "Fernando");
  pessoas[5].idade = 30;
  pessoas[5].codigo = 600;
  strcpy(pessoas[6].nome, "Maria");
  pessoas[6].idade = 30;
  pessoas[6].codigo = 700;
  strcpy(pessoas[7].nome, "Barbara");
  pessoas[7].idade = 34;
  pessoas[7].codigo = 500;
  strcpy(pessoas[8].nome, "Fernanda");
  pessoas[8].idade = 22;
  pessoas[8].codigo = 900;
  strcpy(pessoas[9].nome, "Debora");
  pessoas[9].idade = 30;
  pessoas[9].codigo = 1000;

  imprimirPessoas(pessoas, QUANTIDADE);
  printf("------ Depois de ordenar ------\n");

  selectionSort(pessoas, QUANTIDADE);
  imprimirPessoas(pessoas, QUANTIDADE);

  return 0;
}