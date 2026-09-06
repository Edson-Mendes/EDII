#include <stdio.h>
#include <string.h>

typedef struct Cpessoa
{
	char nome[20];
	int idade;
};

int main(void)
{
	Cpessoa aluno;
	FILE *bin;

	if ((bin = fopen("arquivo_binario.txt", "a+")) == NULL)
	{
		printf("Erro ao abrir arquivo");
	}
	else
	{
		// while (!feof(bin))
		// {
		// 	fread(&aluno, sizeof(Cpessoa), 1, bin);
		// 	printf("%s - %d\n", aluno.nome, aluno.idade);
		// }
		while (fread(&aluno, sizeof(Cpessoa), 1, bin) == 1)
		{
			printf("%s - %d\n", aluno.nome, aluno.idade);
		}
	}

	return 0;
}
