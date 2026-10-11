#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ------ Structs ------
struct Pessoa
{
  char nome[50];
  int idade;
  int codigo;
};

struct CodigoIndice
{
  int codigo;
  int indice;
};

struct NomeIndice
{
  char *nome;
  int indice;
};

// --- Funcoes ---
Pessoa criarPessoa(int codigo, char *nome, int idade);

// Imprimi na ordem que foram salvas.
void imprimirPessoas(Pessoa *pessoas, int tamanho);

// Imprimi ordenado por codigo
void imprimirPorCodigo(CodigoIndice *codigoIndice, Pessoa *pessoas, int tamanho);

// Imprimi ordenado por nome
void imprimirPorNome(NomeIndice *codigoIndice, Pessoa *pessoas, int tamanho);

// Cria um indice do campo codigo de Pessoa.
CodigoIndice *criarIndiceDeCodigo(Pessoa *pessoas, int tamanho);

// Cria um indice do campo nome de Pessoa.
NomeIndice *criarIndiceDeNome(Pessoa *pessoas, int tamanho);

// QuickSort por Codigo
void quickSortByCodigo(CodigoIndice *indices, int left, int right);

// QuickSort por Nome
void quickSortByNome(NomeIndice *indices, int left, int right);

int main()
{
  const int TAMANHO = 10;
  Pessoa pessoas[TAMANHO];
  pessoas[0] = criarPessoa(1005, "Carlos Amaral", 22);
  pessoas[1] = criarPessoa(1003, "Joao Oliveira", 40);
  pessoas[2] = criarPessoa(1008, "Maria de Belem", 30);
  pessoas[3] = criarPessoa(1004, "Ana Costa", 28);
  pessoas[4] = criarPessoa(1009, "Zilda da Silva", 83);
  pessoas[5] = criarPessoa(1007, "Ana Maria", 60);
  pessoas[6] = criarPessoa(1010, "Roberto Carlos", 19);
  pessoas[7] = criarPessoa(1002, "Maria Silva", 25);
  pessoas[8] = criarPessoa(1001, "Edson Mendes", 32);
  pessoas[9] = criarPessoa(1006, "Beatriz Santos", 42);

  printf("----- Ordenado por ordem de insercao -----\n");
  imprimirPessoas(pessoas, TAMANHO);

  CodigoIndice *codigos = criarIndiceDeCodigo(pessoas, TAMANHO);
  NomeIndice *nomes = criarIndiceDeNome(pessoas, TAMANHO);

  printf("\n----- Ordenado por indice de codigo -----\n");
  imprimirPorCodigo(codigos, pessoas, TAMANHO);

  printf("\n----- Ordenado por indice de nome -----\n");
  imprimirPorNome(nomes, pessoas, TAMANHO);

  printf("\n----- Ordenado por ordem de insercao -----\n");
  imprimirPessoas(pessoas, TAMANHO);

  return 0;
}

Pessoa criarPessoa(int codigo, char *nome, int idade)
{
  Pessoa pessoa;

  pessoa.codigo = codigo;
  strcpy(pessoa.nome, nome);
  pessoa.idade = idade;

  return pessoa;
}

CodigoIndice *criarIndiceDeCodigo(Pessoa *pessoas, int tamanho)
{
  CodigoIndice *indices = (CodigoIndice *)malloc(tamanho * sizeof(CodigoIndice));
  for (int i = 0; i < tamanho; i++)
  {
    indices[i].codigo = pessoas[i].codigo;
    indices[i].indice = i;
  }

  quickSortByCodigo(indices, 0, tamanho - 1);

  return indices;
}

NomeIndice *criarIndiceDeNome(Pessoa *pessoas, int tamanho)
{
  NomeIndice *indices = (NomeIndice *)malloc(tamanho * sizeof(NomeIndice));
  for (int i = 0; i < tamanho; i++)
  {
    indices[i].nome = pessoas[i].nome;
    indices[i].indice = i;
  }

  quickSortByNome(indices, 0, tamanho - 1);

  return indices;
}

void imprimirPessoas(Pessoa *pessoas, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    printf("%04d %-20s %02d\n", pessoas[i].codigo, pessoas[i].nome, pessoas[i].idade);
  }
}

void imprimirPorCodigo(CodigoIndice *codigoIndice, Pessoa *pessoas, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    Pessoa *pessoa = &pessoas[codigoIndice[i].indice];
    printf("%04d %-20s %02d\n", pessoa->codigo, pessoa->nome, pessoa->idade);
  }
}

void imprimirPorNome(NomeIndice *nomeIndice, Pessoa *pessoas, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    Pessoa *pessoa = &pessoas[nomeIndice[i].indice];
    printf("%04d %-20s %02d\n", pessoa->codigo, pessoa->nome, pessoa->idade);
  }
}

// QUICKSORT POR CODIGO
void swapByCodigo(CodigoIndice *a, CodigoIndice *b)
{
  CodigoIndice tmp = *a;
  *a = *b;
  *b = tmp;
}

int partitionByCodigo(CodigoIndice *indices, int left, int right)
{
  int i, j;
  i = left;
  for (j = left + 1; j <= right; ++j)
  {
    if (indices[j].codigo < indices[left].codigo)
    {
      ++i;
      swapByCodigo(&indices[i], &indices[j]);
    }
  }
  swapByCodigo(&indices[left], &indices[i]);
  return i;
}

void quickSortByCodigo(CodigoIndice *indices, int left, int right)
{
  int r;
  if (right > left)
  {
    r = partitionByCodigo(indices, left, right);
    quickSortByCodigo(indices, left, r - 1);
    quickSortByCodigo(indices, r + 1, right);
  }
}

// QUICKSORT POR NOME
void swapByNome(NomeIndice *a, NomeIndice *b)
{
  NomeIndice tmp = *a;
  *a = *b;
  *b = tmp;
}

int partitionByNome(NomeIndice *indices, int left, int right)
{
  int i, j;
  i = left;
  for (j = left + 1; j <= right; ++j)
  {
    if (strcmp(indices[j].nome, indices[left].nome) < 0)
    {
      ++i;
      swapByNome(&indices[i], &indices[j]);
    }
  }
  swapByNome(&indices[left], &indices[i]);
  return i;
}

void quickSortByNome(NomeIndice *indices, int left, int right)
{
  int r;
  if (right > left)
  {
    r = partitionByNome(indices, left, right);
    quickSortByNome(indices, left, r - 1);
    quickSortByNome(indices, r + 1, right);
  }
}