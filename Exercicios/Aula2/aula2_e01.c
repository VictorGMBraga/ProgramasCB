#include <stdio.h>

int main ()
{
	int v1,v2;
	
	printf("\nInforme o valor 1: ");
	scanf("%d",&v1);
	printf("Informe o valor 2: ");
	scanf("%d",&v2);
	if (v1==v2)
		printf("\nValores iguais: %d\n\n",v1);
	else
		printf("\nValores diferentes: %d e %d\n",v1,v2);
	return(0);
}
