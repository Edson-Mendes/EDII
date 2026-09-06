#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	typedef struct Cpessoa
	{
		char nome[20];
 		int idade;
	};
	
	Cpessoa aluno[4];
	Cpessoa *paluno = aluno;
	
 	strcpy(aluno[0].nome, "Maria");
 	aluno[0].idade = 22;
 	strcpy(aluno[1].nome, "Augusto");
 	aluno[1].idade = 22;
 	strcpy(aluno[2].nome, "Julia");
 	aluno[2].idade = 23;
 	strcpy(aluno[3].nome, "Alberto");
 	aluno[3].idade = 24;
 	for (int i = 0; i<4 ; i++)
 	{
//		printf("%s - %d - endereco: %x\n", paluno->nome, paluno->idade, paluno);
		printf("%s - %d - endereco: %x\n", paluno->nome, paluno->idade, paluno);
		paluno++;
 	}
 	getchar();
}
