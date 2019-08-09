/***
Imprime na tela os numeros de 1 a 10.
***/

#include <stdio.h>

int main ()
{
	int i;
	
	printf("\nOs numeros de 1 a 10 sao: ");
	i = 0;
	while (i < 10)
	{
		i++;
		printf("%d ",i);
	}
	printf("\n");
	getchar();
	return 0;
}
