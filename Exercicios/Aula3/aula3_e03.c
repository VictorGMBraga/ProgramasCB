/***
Imprime na tela o valor de n fatorial, sendo n informado pelo usuario.
***/

#include <stdio.h>

int main ()
{
	int n,i;
	double fat;

	printf("\nInforme o numero: ");
	scanf("%d",&n);
	if (n==0)
		fat=0;
	else
	{
		fat=1;
		for (i=2; i<=n; i++)
			fat*=i;
	}
	printf("\nO valor de %d fatorial e: %.0f\n",n,fat);
	getchar();
	getchar();
	return 0;
}
