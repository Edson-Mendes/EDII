#include <stdio.h>
#include <stdlib.h>
#include <ctime>

/**
 * Considerando o algoritmo abaixo e analisando o seu comportamento,
 * qual será o conteúdo do arquivo Arquivo.txt no final da execução?
 * 
 * RESPOSTA:
 * Declara uma variável int i
 * Declara uma variável int sem sinal ex
 * Declara um ponteiro para FILE txt
 * Atribui a ex o timestamp atual em segundos.
 * Usa o horário atual como semente para gerar números aleatórios, 
 *  isso garante que o programa gere uma sequência diferente de números a cada nova execução.
 * Atribui o valor 0 a i
 * Laço while de 0 a 99
 *    Abre (cria se não existir) o arquivo "Arquivo.txt", 
 *      como o modo é "w" ele apaga o que estava no arquivo anteriormente
 *    Declara a variável c e atribui o resto da divisão do número gerado por rand() por 100.
 *    Escreve no arquivo (ex com i = 2) "2 - Execução - 3"
 *    Incrementa i em 1
 *    Fecha o arquivo.
 *
 * Ao final da execução, o conteúdo do arquivo será "99 - Execução - 100"
 */
int main()
{
  int i;
  unsigned int ex;

  FILE *txt;
  ex = ((unsigned)time(NULL));
  srand(ex);

  i = 0;
  while (i < 100)
  {
    txt = fopen("Arquivo.txt", "w");
    float c = rand() % 100;
    fprintf(txt, "%d - Execução - %d\n", i, i + 1);
    ++i;
    fclose(txt);
  }
}