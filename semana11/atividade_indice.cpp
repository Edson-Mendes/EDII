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

// --- Assinaturas de Funcoes ---
int comparaCodigoIndice(void *primeiro, void *segundo);

int comparaNomeIndice(void *primeiro, void *segundo);

Pessoa criarPessoa(int codigo, char *nome, int idade);

// Cria um vetor indice do campo codigo de Pessoa.
CodigoIndice *criarIndiceDeCodigo(Pessoa *pessoas, int tamanho);

// Cria um vetor indice do campo nome de Pessoa.
NomeIndice *criarIndiceDeNome(Pessoa *pessoas, int tamanho);

// Imprimi pessoa
void imprimirPessoa(Pessoa *pessoa);

// Imprimi Pessoas na ordem que foram salvas.
void imprimirPessoas(Pessoa *pessoas, int tamanho);

// Imprimi ordenado por codigo
void imprimirPorCodigo(CodigoIndice *codigoIndice, Pessoa *pessoas, int tamanho);

// Imprimi ordenado por nome
void imprimirPorNome(NomeIndice *codigoIndice, Pessoa *pessoas, int tamanho);

// QuickSort
void quickSort(void *vetor, size_t tamanhoBytes, int left, int right, int (*compara)(void *, void *));

// Busca por codigo.
Pessoa *searchByCodigo(CodigoIndice *codigoIndice, int codigo, int start, int end, Pessoa *pessoas);

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

  CodigoIndice *codigoIndice = criarIndiceDeCodigo(pessoas, TAMANHO);
  NomeIndice *nomeIndice = criarIndiceDeNome(pessoas, TAMANHO);

  printf("----- Ordenado por ordem de insercao -----\n");
  imprimirPessoas(pessoas, TAMANHO);

  printf("\n----- Ordenado por indice de codigo -----\n");
  imprimirPorCodigo(codigoIndice, pessoas, TAMANHO);

  printf("\n----- Ordenado por indice de nome -----\n");
  imprimirPorNome(nomeIndice, pessoas, TAMANHO);

  // Aplicar busca por codigo.
  int cod = 1006;
  Pessoa *pessoa = searchByCodigo(codigoIndice, cod, 0, TAMANHO - 1, pessoas);
  if (pessoa == NULL)
    printf("\nCodigo %d nao encontrado!\n\n", cod);
  else
  {
    printf("\nCodigo %d encontrado!\n", cod);
    imprimirPessoa(pessoa);
  }
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
  if (indices == NULL)
  {
    printf("Não foi possivel alocar vetor de CodigoIndice!");
    exit(1);
  }
  for (int i = 0; i < tamanho; i++)
  {
    indices[i].codigo = pessoas[i].codigo;
    indices[i].indice = i;
  }

  quickSort(indices, sizeof(CodigoIndice), 0, tamanho - 1, comparaCodigoIndice);

  return indices;
}

NomeIndice *criarIndiceDeNome(Pessoa *pessoas, int tamanho)
{
  NomeIndice *indices = (NomeIndice *)malloc(tamanho * sizeof(NomeIndice));
  if (indices == NULL)
  {
    printf("Não foi possivel alocar vetor de NomeIndice!");
    exit(1);
  }
  for (int i = 0; i < tamanho; i++)
  {
    indices[i].nome = pessoas[i].nome;
    indices[i].indice = i;
  }

  quickSort(indices, sizeof(NomeIndice), 0, tamanho - 1, comparaNomeIndice);

  return indices;
}

void imprimirLabels()
{
  printf("%-4s %-20s %s\n", "COD", "NOME", "IDADE");
}

void imprimirPessoa(Pessoa *pessoa)
{
  printf("%04d %-20s %02d\n", pessoa->codigo, pessoa->nome, pessoa->idade);
}

void imprimirPessoas(Pessoa *pessoas, int tamanho)
{
  imprimirLabels();
  for (int i = 0; i < tamanho; i++)
  {
    imprimirPessoa(&pessoas[i]);
  }
}

void imprimirPorCodigo(CodigoIndice *codigoIndice, Pessoa *pessoas, int tamanho)
{
  imprimirLabels();
  for (int i = 0; i < tamanho; i++)
  {
    imprimirPessoa(&pessoas[codigoIndice[i].indice]);
  }
}

void imprimirPorNome(NomeIndice *nomeIndice, Pessoa *pessoas, int tamanho)
{
  imprimirLabels();
  for (int i = 0; i < tamanho; i++)
  {
    imprimirPessoa(&pessoas[nomeIndice[i].indice]);
  }
}

int comparaNomeIndice(void *primeiro, void *segundo)
{
  NomeIndice *nome1 = (NomeIndice *)primeiro;
  NomeIndice *nome2 = (NomeIndice *)segundo;
  return strcmp(nome1->nome, nome2->nome);
}

int comparaCodigoIndice(void *primeiro, void *segundo)
{
  CodigoIndice *cod1 = (CodigoIndice *)primeiro;
  CodigoIndice *cod2 = (CodigoIndice *)segundo;
  return cod1->codigo - cod2->codigo;
}

// QUICKSORT
void swap(void *a, void *b, size_t tamanhoBytes)
{
  char *p1 = (char *)a;
  char *p2 = (char *)b;

  for (int i = 0; i < tamanhoBytes; i++)
  {
    char temporario = p1[i];
    p1[i] = p2[i];
    p2[i] = temporario;
  }
}

int partition(void *vetor, size_t tamanhoBytes, int left, int right, int (*compara)(void *, void *))
{
  int i, j;
  i = left;
  char *elementoLeft = (char *)vetor + tamanhoBytes * left;
  for (j = left + 1; j <= right; ++j)
  {
    char *elementoJ = (char *)vetor + tamanhoBytes * j;
    if (compara(elementoJ, elementoLeft) < 0)
    {
      ++i;
      char *elementoI = (char *)vetor + tamanhoBytes * i;
      swap(elementoI, elementoJ, tamanhoBytes);
    }
  }
  char *elementoI = (char *)vetor + tamanhoBytes * i;
  swap(elementoLeft, elementoI, tamanhoBytes);
  return i;
}

void quickSort(void *vetor, size_t tamanhoBytes, int left, int right, int (*compara)(void *, void *))
{
  int r;
  if (right > left)
  {
    r = partition(vetor, tamanhoBytes, left, right, compara);
    quickSort(vetor, tamanhoBytes, left, r - 1, compara);
    quickSort(vetor, tamanhoBytes, r + 1, right, compara);
  }
}

// Busca Pessoa por codigo.
Pessoa *searchByCodigo(CodigoIndice *codigoIndice, int codigoBuscado, int start, int end, Pessoa *pessoas)
{
  if (start > end)
  {
    return NULL;
  }
  int mid = (start + end) / 2;
  if (codigoBuscado == codigoIndice[mid].codigo)
  {
    return &pessoas[codigoIndice[mid].indice];
  }
  if (codigoBuscado > codigoIndice[mid].codigo)
  {
    return searchByCodigo(codigoIndice, codigoBuscado, mid + 1, end, pessoas);
  }
  return searchByCodigo(codigoIndice, codigoBuscado, start, mid - 1, pessoas);
}