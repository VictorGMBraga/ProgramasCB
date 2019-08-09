/***
Mostra na tela o número de casais de coelhos após um número de meses definido pelo usuário.
O número de casais é definido pela sequência de Fibonacci, onde: f(0)=0, f(1)=1 e f(n)=f(n-2)+f(n-1), se n>=2.
***/

#include <stdio.h>

int main ()
{
	int m,n1,n2,ntot,i;

	printf("\nInforme o numero de meses: ");
	scanf("%d",&m);
	if (m==0)
		printf("\nO numero de casais de coelhos apos 0 meses e: 0\n");
	else
	{
		if (m==1)
			printf("\nO numero de casais de coelhos apos 1 mes e: 1\n");
		else
		{
			n1=0;
			n2=1;
			for(i=2;i<=m;i++)
			{
				ntot=n1+n2;
				n1=n2;
				n2=ntot;
			}
			printf("\nO numero de casais de coelhos apos %d meses e: %d\n",m,ntot);
		}
	}
	getchar();
	getchar();
	return 0;
}
