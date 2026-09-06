#include <stdio.h>
#include <stdlib.h>

int main() {	
	int *p = (int*) malloc(1000000);

	p[0] = 222;
	printf("%d%n", p[0]);
	return 0;
}
