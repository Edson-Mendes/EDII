#include <stdio.h>
#include <stdlib.h>
#include <ctime>

struct Produto
{
  int id;
  char nome[50];
  float preco;
};

/**
 * Imprimi o menu de opções na tela.
 */
void imprimirOpcoes()
{
  printf("---------------------------\n");
  printf("1 - Cadastrar produto\n");
  printf("2 - Listar produtos\n");
  printf("3 - Sair\n");
}

/**
 * Retorna uma opção numérica digitada pelo usuário.
 * 
 * TODO: Programa quebra se digitar qualquer coisa diferente de um número.
 */
int digitarOpcao()
{
  int opcao;
  printf("Digite a opção: ");
  scanf("%d", &opcao);
  return opcao;
}

/**
 * Gera um número entre 0 e 1000000 para servir como identificador do produto.
 */
int gerarID()
{
  srand((unsigned)time(NULL));
  return rand() % 1000000;
}

/**
 * Pega o nome e preço do produto digitados pelo usuário e 
 * atribui a um objeto Produto.
 */
Produto gerarProduto()
{
  Produto produto;
  printf("\nDigite o nome do produto (ex Banana): ");
  scanf(" %49[^\n]", produto.nome);
  printf("Digite o preco do produto (ex 5.99): ");
  scanf("%f", &(produto.preco));
  produto.id = gerarID();
  return produto;
}

/**
 * Abri (cria se não existir) o arquivo "estoque.dat", 
 * e retorna um ponteiro para o arquivo aberto/criado.
 */
FILE *abrirArquivo()
{
  FILE *file;
  if ((file = fopen("estoque.dat", "ab+")) == NULL)
  {
    printf("\nFalha ao abrir arquivo!\n");
    exit(1);
  }
  return file;
}

/**
 * Escreve o produto informado no arquivo "estoque.dat";
 */
void cadastrarProduto(Produto *produto)
{
  FILE *estoqueFile = abrirArquivo();
  fwrite(produto, sizeof(Produto), 1, estoqueFile);
  fclose(estoqueFile);
}

/**
 * Lista os produtos que estão salvos no arquivo "estoque.dat";
 */
void listarProdutos()
{
  Produto produto;
  int contador = 0;
  FILE *estoqueFile = abrirArquivo();
  printf("-------------------------\n");
  printf("PRODUTOS CADASTRADOS\n");
  while (fread(&produto, sizeof(Produto), 1, estoqueFile) == 1)
  {
    printf("---------------\n");
    printf("ID: %d\n", produto.id);
    printf("NOME: %s\n", produto.nome);
    printf("PREÇO: R$ %.2f\n", produto.preco);
    contador++;
  }
  printf("-------------------------\n");
  printf("TOTAL DE PRODUTOS CADASTRADOS: %d\n", contador);
  fclose(estoqueFile);
}

int main()
{
  int opcao = 1;
  while (opcao != 3)
  {
    imprimirOpcoes();
    opcao = digitarOpcao();
    switch (opcao)
    {
    case 1:
    {
      Produto produto = gerarProduto();
      cadastrarProduto(&produto);
      printf("\n%s cadastrado com sucesso!\n", produto.nome);
      break;
    }
    case 2:
      listarProdutos();
      break;
    case 3:
      printf("\nEncerrando programa...\n");
      break;
    default:
      printf("\nOpção inválida! Escolha 1, 2 ou 3!\n");
      break;
    }
  }
  return 0;
}