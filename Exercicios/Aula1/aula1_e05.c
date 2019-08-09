#include <stdio.h>

int main ()
{
	int n1,n2;
	float media;
	
	printf("\nDigite o numero 1: ");
	scanf("%d",&n1);
	printf("Digite o numero 2: ");
	scanf("%d",&n2);
	media=(n1+n2)/2.0f;
	printf("\nA media entre os numeros vale: %.2f\n",media);
	return (0);
}
