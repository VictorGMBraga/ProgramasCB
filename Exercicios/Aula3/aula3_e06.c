/***
Calcula e mostra na tela a média aritmética de um conjunto de idades fornecido pelo usuário.
O número de idades incluídas na média aumenta até o usuário fornecer a idade 0.
***/

#include <stdio.h>

int main ()
{
	int n,idade;
	float media,tot;
	 
	n=0;
	tot=0;
	printf("\nInforme as idades e, para finalizar a media, informe uma idade igual a 0: \n\n");
	do
	{
		printf("Informe a idade %d: ",n+1);
		scanf("%d",&idade);
		while (idade<0)
		{
			printf("A idade nao pode ser negativa:");
			printf("\nInforme a idade %d: ",n+1);
			scanf("%d",&idade);
		}
		n+=1;
		tot+=idade;
	}
	while (idade!=0);
	media=tot/(n-1);
	printf("\nA media das idades vale: %.2f\n",media);
	getchar();
	getchar();
	return 0;
}
