#include <stdio.h>
#include <string.h>

typedef struct Cpessoa
{
	char nome[20];
	int idade;
};

int main(void)
{
	char condicao = 's';
	Cpessoa aluno;
	FILE *bin;

	if ((bin = fopen("arquivo_binario.txt", "ab")) == NULL)
	{
		printf("Erro ao abrir arquivo");
	}
	else
	{
		while (condicao == 's' || condicao == 'S')
		{
			printf("Informe o nome:");
			scanf("%s", aluno.nome);

			printf("Informe a idade:");
			scanf("%d", &aluno.idade);
			fflush(stdin);
			
			printf("Continuar S/N?:");

			fwrite(&aluno, sizeof(aluno), 1, bin);

			condicao = getchar();
		}
	}
}
