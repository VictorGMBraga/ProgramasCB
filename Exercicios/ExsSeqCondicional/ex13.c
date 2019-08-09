#include <stdio.h>

int main ()
{
	float n1,n2,result;
	char op;
	printf("\nInforme o 1o numero: ");
	scanf("%f",&n1);
	printf("Informe o 2o numero: ");
	scanf("%f",&n2);
	printf("Informe a operação a ser realizada: ");
	scanf("%c",op);
	if (op!='+' || op!='-' || op!='*' || op!='/')
	{
		printf("\nOperacao nao existente.\n\n");
	}
	if (n2==0 && op=='/')
	{
		printf("\nO 2o numero nao pode ser zero no caso de uma divisao.\n\n");
	}
	result=n1(op)n2;
	printf("O resultado da opreacao e: %.2f",result);
	return(0);
}
