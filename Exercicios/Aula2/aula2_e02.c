#include <stdio.h>

int main ()
{
	int v1, v2;
	
	printf("\nInforme o valor 1: ");
	scanf("%d",&v1);
	printf("Informe o valor 2: ");
	scanf("%d",&v2);
	if (v1==v2)
		printf("\nValores iguais: %d\n",v1);
	else
	{
		if (v1>v2)
			printf("\nValor 1 maior que valor 2: %d > %d\n",v1,v2);
		else
			printf("\nValor 2 maior que valor 1: %d > %d\n",v1,v2);
	}
	return(0);
}
