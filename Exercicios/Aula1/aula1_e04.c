#include <stdio.h>

int main ()
{
	int a,b,c;
	
	printf("\nDigite um numero inteiro a: ");
	scanf("%d",&a);
	printf("Digite um numero inteiro b: ");
	scanf("%d",&b);
	c=b;
	b=a;
	a=c;
	printf("\nO numero inteiro a agora vale: %d\n",a);
	printf("O numero inteiro b agora vale: %d\n",b);
	return (0);
}
