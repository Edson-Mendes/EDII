#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *a, *b;
//	a = (int * ) malloc ( sizeof(int) * 100 );
	a = (int * ) calloc (sizeof(int), 100);
//	b = (int * ) malloc ( sizeof(int) * 3 );
	b = (int * ) calloc (sizeof(int), 3);
	
	for (int i = 0; i< 100; i++)
	{
//	 	a[i] = i;
	}
	b[0] = 0;
	b[1] = 1;
	b[2] = 2;
	for (int i = 0; i< 100; i++)
	{
	 	printf("valor %zu - endereco %x \n",a[i] , &a[i]);
	}

	 printf("--------------\n");
	for (int i = 0; i< 3; i++)
	{
	 	printf("valor %d - endereco %x \n", b[i], &b[i]);
	}
	printf("--> a %d\n", sizeof *a);
	system("pause");
	return(0);
}

